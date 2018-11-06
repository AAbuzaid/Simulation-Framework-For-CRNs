#include "Band_Details.h"
#include "SecondaryUser.h"
#include "FusionCenter.h"
#include "Performance.h"
#include <time.h>
bool cooparitive = false;

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
	unsigned int activePUTimes = 0;
	unsigned int inactivePUTimes = 0;
	FusionCenter FC(NumberOfSUs, NumberOfBands, PFA , PMD , NumberOfBandsReqForEachSUs,loadsChange.size());

	std::vector<DetermanisticBand> BandVec(NumberOfBands,
		DetermanisticBand(timeVSuccessfulReq, successfulVsTimePUActiveForBandN));
	std::vector<int> SuccessfulVsTime(timeSlots , 0); //successful VS time output vector intilization
	bool count = true;
	for (auto ProbPU : PPU)
	{
		std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(ProbPU , loadsChange.size()));
		std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSUs , cooparitive));


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
					++activePUTimes;
				}
				else
				{
					++inactivePUTimes;
				}
			}
			for (int i = 0; i < NumberOfSUs; i++)
			{
				SU[i].scanningBands(BandVector);
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
				, timeVSuccessfulReq, T, SuccessfulVsTime, count, loadsChange);
			FC.majority(bandOccByPus , SU);	//this band do cooperative decision on the empty band 
			/*if(cooparitive)
				{
					for(int i =0; i < NumberOfSUs ; i++)
						SU[i].SUsTransmitting(BandVector, i, FC.majorityBands);

				FC.performanceCalculation(bandOccByPus, BandVector, BandVec, succVsTimeSUId
					, timeVSuccessfulReq, T, SuccessfulVsTime, count, loadsChange);
				}*/
			FC.changingLoad(loadsChange);
			FC.clearVectors();
			std::vector<int>().swap(bandOccByPus);

		}
		FC.successfulSUTrans(timeSlots);
		for (int i = 0; i < NumberOfSUs; i++)
		{
			FC.falseAlarm(SU[i].NumFA , SU[i].NumFACoop);
			FC.missDetection(SU[i].NumMD , SU[i].NumMDCoop);
			SU[i].emptyFAandMD();
		}
		for (int i = 0; i < NumberOfBands; i++)	//PU interference 
		{
			if (ProbPU == 0.0)
				FC.PUInterfere.push_back(0);
			else
				FC.PUInterfere.push_back(FC.PUInterfereNum[i] / double(FC.PUInterfereDen[i]));
		}
		activePUTimes = activePUTimes / double(timeSlots);
		inactivePUTimes = inactivePUTimes / double(timeSlots);
		Performance result(timeSlots, ProbPU, succVsTimeSUId , NumberOfSUs);
		result.outputFAFile(FC.FaVsSUId); //this function outputs the file which contain PFA VS SUId
		result.outputMDFile(FC.MdVsSUId);
		result.outputCollision(FC.collisionVsSuN);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		result.outputSuccSUTrans(FC.succSUTrans);
		result.outputPUInterference(FC.PUInterfere);	//for taugh
		result.outputChangingLoad(FC.successfulVsLoads);
		//cooparitive sensing
		result.outputFAFileCoop(FC.FaVsSUIdCoop);
		result.outputMDFileCoop(FC.MdVsSUIdCoop);
		result.outputCollisionCoop(FC.collisionVsSuN);
		result.outputUtilizationCoop(FC.utilizationVsBand);
		result.outputThroughputCoop(FC.throughput);
		result.outputSuccSUTransCoop(FC.succSUTrans);
		result.outputPUInterferenceCoop(FC.PUInterfere);	
		result.outputChangingLoadCoop(FC.successfulVsLoads);
		FC.clearPerformanceOut();
		count = false;
		activePUTimes = 0;
		inactivePUTimes = 0;
	}

	Performance result(succVsTimeSUId);
	result.outputSuccessfulVsTime(SuccessfulVsTime);
	end = clock();
	duration =(end - start);
	printf("Decoding time = %d\n", duration);
	system("pause");
	return 0;
}
