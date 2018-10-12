#include "Band_Details.h"
#include "SecondaryUser.h"
#include "FusionCenter.h"
#include "Performance.h"
#include <time.h>

int main()
{
	clock_t start, end, duration;
	//Constant value which may change in the future
	start = clock();
	int NumberOfBands = 100;
	int NumberOfSUs = 10;
	int NumberOfBandsReqForEachSUs = 10;
	double timeSlot = 20000;
	int MaxSuBand = 15;
	double PFA = .1;
	double PMD = .1;
	double PPU[3] = { 0 , .15 , .25 };
	int succVsTimeSUId = 4;
	double timeVSuccessfulReq = timeSlot / 2;
	int successfulVsTimePUActiveForBandN = 50;
	std::vector<int> bandOccByPus;	//bands occupants by PUs
	//For abdullah to write
	//std::vector<Band_Details*> BandVector;
	//To here
	FusionCenter FC(NumberOfSUs, NumberOfBands, MaxSuBand , PFA , PMD , NumberOfBandsReqForEachSUs);
	

	std::vector<DetermanisticBand> BandVec(NumberOfBands,
		DetermanisticBand(timeVSuccessfulReq, successfulVsTimePUActiveForBandN));
	std::vector<int> SuccessfulVsTime(timeSlot , 0); //successful VS time output vector intilization
	bool count = true;
	for (auto ProbPU : PPU)
	{
		std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(ProbPU));
		std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSUs));

		for (double T = 0; T < timeSlot; T++)
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
					bandOccByPus.push_back(i);		//remove State from constructor
			}
			for (int i = 0; i < NumberOfSUs; i++)
			{
				SU[i].scanningBands(BandVector);
				FC.getSUsIds(i);
				FC.getEmptyBands(SU[i].emptyBands);
				SU[i].SUsTransmitting(BandVector, i);
				FC.bandsOccupiedBySU(SU[i].SUsOccupants);
				

				//clear all vector
				SU[i].emptyAllResult();
				if(count)
				SU[i].successfulVSTime(BandVec, timeVSuccessfulReq, T, i);
				SU[i].emptyAllResult();

			}
			FC.collision(bandOccByPus, BandVector, BandVec, succVsTimeSUId, timeVSuccessfulReq, T, SuccessfulVsTime ,count);

			FC.majority();
			FC.clearVectors();
			bandOccByPus.clear();
			
		}
		
		for (int i = 0; i < NumberOfSUs; i++)
		{
			FC.falseAlarm(SU[i].NumFA);
			FC.misDetection(SU[i].numMD);
			SU[i].emptyFAandMD();
		}
		Performance result(timeSlot, ProbPU, succVsTimeSUId);
		result.outputFAFile(FC.FaVsSUId); //this function output the file which contain PFA VS SUId
		result.outputMDFile(FC.MdVsSUId);
		result.outputCollision(FC.collisionVsSuN);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		//result.outputSuccessfulVsTime(SuccessfulVsTime);
		result.outputSuccSUTrans(FC.succSUTrans);
		FC.clearPerformanceOut();
		count = false;
	}

	Performance result(succVsTimeSUId);
	result.outputSuccessfulVsTime(SuccessfulVsTime);
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Decoding time = %d\n", duration);
	system("pause");
	return 0;
}