#include "Band_Details.h"
#include "SecondaryUser.h"
#include "FusionCenter.h"
#include "Performance.h"
#include <time.h>
bool cooperative = false;

int main()
{
	clock_t start, end, duration;
	//Constant value which may change in the future
	start = clock();
	int NumberOfBands = 100;
	int NumberOfSUs = 10;
	int NumberOfBandsReqForEachSU = 10;
	int timeSlots = 20000;
	double PFA = .1;
	double PMD = .1;
	double PPU[3] = {0 , .15 , .25};
	int succVsTimeSUId = 4;
	std::vector<int> loadsChange = {5,8,10,12,15};
	double timeVSuccessfulReq = timeSlots / 2;
	int successfulVsTimePUActiveForBandN = 50;
	std::vector<int> bandsOccByPUs;	//bands occupied by PUs
	bandsOccByPUs.reserve(NumberOfBands+1);
	FusionCenter FC(NumberOfSUs, NumberOfBands, PFA , PMD , NumberOfBandsReqForEachSU,loadsChange.size());
	std::vector<DeterministicBand> BandVectorDeterministic(NumberOfBands,
		DeterministicBand(timeVSuccessfulReq, successfulVsTimePUActiveForBandN));
	BandVectorDeterministic.reserve(NumberOfBands+1);
	std::vector<int> SuccessfulVsTime(timeSlots , 0); //successful VS time output vector intilization
	SuccessfulVsTime.reserve(timeSlots);
	std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(PPU[0], loadsChange.size()));
	std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSU, cooperative));
	//std::vector<Band_Details> BandVector;
	//std::vector<SecondaryUser> SU;
	BandVector.reserve(NumberOfBands + 1);
	SU.reserve(NumberOfSUs + 1);
	std::vector<Band_Details>::iterator bandConstruct;
	std::vector<SecondaryUser>::iterator SUConstruct;
	bool count = true;
	for (auto ProbPU : PPU)
	{
		for (bandConstruct = BandVector.begin(); bandConstruct != BandVector.end(); bandConstruct++)
		{
			*bandConstruct = Band_Details(ProbPU, loadsChange.size());
		}
		for (int T = 0; T < timeSlots; T++)
		{
			for (int i = 0; i < NumberOfBands; i++)
			{

				if (T != 0)
				{
					BandVector[i].clearBands();
					BandVectorDeterministic[i].clearBands();
				}
				BandVector[i].randomPUState();		//Randomizes PUState each timeSlot
				if (!BandVector[i].isEmpty())
				{
					bandsOccByPUs.push_back(i);
				}
			}
			for (int i = 0; i < NumberOfSUs; i++)
			{
				SU[i].scanningBands(BandVector , bandsOccByPUs.size(), i);
				FC.getSUID(i);
				//FC.getEmptyBands(SU[i].emptyBands);
				SU[i].SUsTransmitting(BandVector, i , loadsChange);
				//FC.bandsOccupiedBySU(SU[i].SUOccupants);
				//clear all vectors
				SU[i].emptyAllResult();
				if (count)
					SU[i].successfulVSTime(BandVectorDeterministic, timeVSuccessfulReq, T, i);
				SU[i].emptyAllResult();


			}
			FC.performanceCalculation(bandsOccByPUs, BandVector, BandVectorDeterministic, succVsTimeSUId
				, timeVSuccessfulReq, T, SuccessfulVsTime, count, loadsChange , cooperative);
			FC.majority(bandsOccByPUs , SU , BandVector);	//this band do cooperative decision on the empty band 
			FC.changingLoad(loadsChange);
			FC.clearVectors();
			std::vector<int>().swap(bandsOccByPUs);

		}
		FC.successfulSUTrans(timeSlots);
		std::vector<double> FAvsSUID;
		std::vector<double> MDvsSUID;
		for (int i = 0; i < NumberOfSUs; i++)
		{
			FC.falseAlarm(SU[i].NumFACoop);
			FC.missDetection(SU[i].NumMDCoop);
			
			FAvsSUID.push_back(SU[i].FAVsSU);
			MDvsSUID.push_back(SU[i].MDVsSU);
			//std::cout << SU[i].FaVsSUId << " ";
			SU[i].emptyFAandMD();
		}
		for (int i = 0; i < NumberOfBands; i++)	//PU interference 
		{
			if (ProbPU == 0.0)
			{
				FC.PUInterfere.push_back(0);
				FC.PUInterfereCooperative.push_back(0);
			}
			else
			{
				FC.PUInterfere.push_back(FC.PUInterfereNum[i] / double(FC.PUInterfereDen[i]));
				FC.PUInterfereCooperative.push_back(FC.PUInterfereNumCooperative[i] / double(FC.PUInterfereDen[i]));
			}
		}
		Performance result(timeSlots, ProbPU, succVsTimeSUId, NumberOfSUs);
		result.outputFAFile(FAvsSUID); //this function outputs the file which contain PFA VS SUId
		result.outputMDFile(MDvsSUID);
		result.outputCollision(FC.collisionVsSU);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		result.outputSuccSUTrans(FC.succSUTrans);
		result.outputPUInterference(FC.PUInterfere);
		result.outputChangingLoad(FC.successfulVsLoads);
		//cooperative sensing
		if (cooperative)
		{
			result.outputFAFileCoop(FC.FaVsSUIdCoop);
			result.outputMDFileCoop(FC.MdVsSUIdCoop);
			result.outputCollisionCoop(FC.collisionVsSUCooperative);
			result.outputUtilizationCoop(FC.utilizationVsBandCooperative);
			result.outputThroughputCoop(FC.throughputCooperative);
			result.outputSuccSUTransCoop(FC.succSUTrans);
			result.outputPUInterferenceCoop(FC.PUInterfereCooperative);
			result.outputChangingLoadCoop(FC.successfulVsLoads);
		}
		FC.clearPerformanceOut();
		count = false;
		FAvsSUID.clear();
		MDvsSUID.clear();
	}
	Performance result(succVsTimeSUId);
	result.outputSuccessfulVsTime(SuccessfulVsTime);
	end = clock();
	duration =(end - start);
	printf("Decoding time in ms = %d\n", duration);
	system("pause");
	return 0;
}
