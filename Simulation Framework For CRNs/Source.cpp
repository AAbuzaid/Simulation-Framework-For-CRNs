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
	std::vector<int> loadsChange = {5, 8, 10, 12, 15};
	double timeVSuccessfulReq = timeSlots / 2;
	int successfulVsTimePUActiveForBandN = 50;
	std::vector<int> bandsOccByPU;	
	FusionCenter FC(NumberOfSUs, NumberOfBands, PFA , PMD , NumberOfBandsReqForEachSU,loadsChange.size());

	std::vector<DeterministicBand> BandVectorDeterministic(NumberOfBands,
		DeterministicBand(timeVSuccessfulReq, successfulVsTimePUActiveForBandN));
	std::vector<int> SuccessfulVsTime(timeSlots , 0); //successful VS time output vector intilization
	bool count = true;
	for (auto ProbPU : PPU)
	{
		std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(ProbPU , loadsChange.size()));
		std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSU , cooperative));


		for (int T = 0; T < timeSlots; T++)
		{
			for (int i = 0; i < NumberOfBands; i++)
			{


				if (T != 0)
				{
					BandVector[i].clearBands();
					BandVectorDeterministic[i].clearBands();
				}
				BandVector[i].randomPUState();		//Randomizes PUState each time slot
				if (!BandVector[i].isEmpty())
				{
					bandsOccByPU.push_back(i);
				}
			}
			for (int i = 0; i < NumberOfSUs; i++)
			{
				SU[i].scanningBands(BandVector , bandsOccByPU.size(), i);
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
			FC.performanceCalculation(bandsOccByPU, BandVector, BandVectorDeterministic, succVsTimeSUId
				, timeVSuccessfulReq, T, SuccessfulVsTime, count, loadsChange , cooperative);
			FC.majority(bandsOccByPU , SU , BandVector);	//this band do cooperative decision on the empty band 
			FC.changingLoad(loadsChange);
			FC.clearVectors();
			std::vector<int>().swap(bandsOccByPU);

		}
		FC.successfulSUTrans(timeSlots);
		std::vector<double> FAvsSUID;
		std::vector<double> MDvsSUID;
		for (int i = 0; i < NumberOfSUs; i++)
		{
			FC.falseAlarm(SU[i].NumFACoop);
			FC.missDetection(SU[i].NumMDCoop);
			
			FAvsSUID.push_back(SU[i].FAVsSU);
			MDvsSUID.push_back(SU[i].MdVsSU);
			//std::cout << SU[i].FAVsSU << " ";
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
		Performance result(timeSlots, ProbPU, succVsTimeSUId , NumberOfSUs);
		result.outputFAFile(FAvsSUID); //this function outputs the file which contain PFA VS SUId
		result.outputMDFile(MDvsSUID);
		result.outputCollision(FC.collisionVsSuN);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		result.outputSuccSUTrans(FC.succSUTrans);
		result.outputPUInterference(FC.PUInterfere);	//for taugh
		result.outputChangingLoad(FC.successfulVsLoads);
		//cooperative sensing
		if (cooperative)
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
	printf("Decoding time = %d\n", duration);
	system("pause");
	return 0;
}
