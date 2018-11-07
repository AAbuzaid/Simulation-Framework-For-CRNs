#include "Band_Details.h"
#include "SecondaryUser.h"
#include "FusionCenter.h"
#include "Performance.h"
#include <time.h>
bool cooparitive = true;

int main()
{
	clock_t start, end, duration;
	//Constant value which may change in the future
	start = clock();
	int NumberOfBands = 100;
	int NumberOfSUs = 10;
	int NumberOfBandsReqForEachSUs = 10;
	int timeSlots = 20000;
	double PFA = .1;
	double PMD = .1;
	double PPU[3] = {0 , .15 , .25};
	int succVsTimeSUId = 4;
	std::vector<int> loadsChange = {5,8,10,12,15};
	double timeVSuccessfulReq = timeSlots / 2;
	int successfulVsTimePUActiveForBandN = 50;
	std::vector<int> bandOccByPus;	//bands occupied by PUs
	bandOccByPus.reserve(NumberOfBands+1);
	FusionCenter FC(NumberOfSUs, NumberOfBands, PFA , PMD , NumberOfBandsReqForEachSUs,loadsChange.size());
	std::vector<DeterministicBand> BandVec(NumberOfBands,
		DeterministicBand(timeVSuccessfulReq, successfulVsTimePUActiveForBandN));
	BandVec.reserve(NumberOfBands+1);
	std::vector<int> SuccessfulVsTime(timeSlots , 0); //successful VS time output vector intilization
	SuccessfulVsTime.reserve(timeSlots);
	std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(PPU[0], loadsChange.size()));
	std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSUs, cooparitive));
	//std::vector<Band_Details> BandVector;
	//std::vector<SecondaryUser> SU;
	BandVector.reserve(NumberOfBands + 1);
	SU.reserve(NumberOfSUs + 1);
	std::vector<Band_Details>::iterator bandConstruct;
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
					BandVec[i].clearBands();
				}
				BandVector[i].randomPUState();		//Randomizes PUState each timeSlot
				if (!BandVector[i].isEmpty())
				{
					bandOccByPus.push_back(i);
				}
			}
			for (int i = 0; i < NumberOfSUs; i++)
			{
				SU[i].scanningBands(BandVector , bandOccByPus.size(), i);
				FC.getSUsIds(i);
				//FC.getEmptyBands(SU[i].emptyBands);
				SU[i].SUsTransmitting(BandVector, i , loadsChange);
				//FC.bandsOccupiedBySU(SU[i].SUsOccupants);
				//clear all vectors
				SU[i].emptyAllResult();
				if (count)
					SU[i].successfulVSTime(BandVec, timeVSuccessfulReq, T, i);
				SU[i].emptyAllResult();


			}
			FC.performanceCalculation(bandOccByPus, BandVector, BandVec, succVsTimeSUId
				, timeVSuccessfulReq, T, SuccessfulVsTime, count, loadsChange , cooparitive);
			FC.majority(bandOccByPus , SU , BandVector);	//this band do cooperative decision on the empty band 
			FC.changingLoad(loadsChange);
			FC.clearVectors();
			std::vector<int>().swap(bandOccByPus);
		}
		FC.successfulSUTrans(timeSlots);
		std::vector<double> FAvsSUID;
		std::vector<double> MDvsSUID;
		for (int i = 0; i < NumberOfSUs; i++)
		{
			FC.falseAlarm(SU[i].NumFACoop);
			FC.missDetection(SU[i].NumMDCoop);
			FAvsSUID.push_back(SU[i].FaVsSUId);
			MDvsSUID.push_back(SU[i].MdVsSUId);
			//std::cout << SU[i].FaVsSUId << " ";
			SU[i].emptyFAandMD();
		}
		for (int i = 0; i < NumberOfBands; i++)	//PU interference 
		{
			if (ProbPU == 0.0)
			{
				FC.PUInterfere.push_back(0);
				FC.PUInterfereCooparitive.push_back(0);
			}
			else
			{
				FC.PUInterfere.push_back(FC.PUInterfereNum[i] / double(FC.PUInterfereDen[i]));
				FC.PUInterfereCooparitive.push_back(FC.PUInterfereNumCooparitive[i] / double(FC.PUInterfereDen[i]));
			}
		}
		Performance result(timeSlots, ProbPU, succVsTimeSUId, NumberOfSUs);
		result.outputFAFile(FAvsSUID); //this function outputs the file which contain PFA VS SUId
		result.outputMDFile(MDvsSUID);
		result.outputCollision(FC.collisionVsSuN);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		result.outputSuccSUTrans(FC.succSUTrans);
		result.outputPUInterference(FC.PUInterfere);
		result.outputChangingLoad(FC.successfulVsLoads);
		//cooparitive sensing
		if (cooparitive)
		{
			result.outputFAFileCoop(FC.FaVsSUIdCoop);
			result.outputMDFileCoop(FC.MdVsSUIdCoop);
			result.outputCollisionCoop(FC.collisionVsSuNCooparitive);
			result.outputUtilizationCoop(FC.utilizationVsBandCooparitive);
			result.outputThroughputCoop(FC.throughputCooparitive);
			result.outputSuccSUTransCoop(FC.succSUTrans);
			result.outputPUInterferenceCoop(FC.PUInterfereCooparitive);
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
