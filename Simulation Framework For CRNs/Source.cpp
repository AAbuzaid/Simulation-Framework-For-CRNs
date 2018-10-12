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
	double timeSlots = 20000;
	int MaxSuBand = 15;
	double PFA = .1;
	double PMD = .1;
	double PPU[3] = { 0 , .15 , .25 };
	int succVsTimeSUId = 4;
	double timeVSuccessfulReq = timeSlots / 2;
	int successfulVsTimePUActiveForBandN = 50;
	std::vector<int> bandOccByPus;	//bands occupied by PUs

	FusionCenter FC(NumberOfSUs, NumberOfBands, MaxSuBand , PFA , PMD , NumberOfBandsReqForEachSUs);

	std::vector<DetermanisticBand> BandVec(NumberOfBands,
		DetermanisticBand(timeVSuccessfulReq, successfulVsTimePUActiveForBandN));
	std::vector<int> SuccessfulVsTime(timeSlots , 0); //successful VS time output vector intilization
	bool count = true;
	for (auto ProbPU : PPU)
	{
		std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(ProbPU));
		std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSUs));

		for (double T = 0; T < timeSlots; T++)
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
					bandOccByPus.push_back(i);		
			}
			for (int i = 0; i < NumberOfSUs; i++)
			{
				SU[i].scanningBands(BandVector);
				FC.getSUsIds(i);
				FC.getEmptyBands(SU[i].emptyBands);
				SU[i].SUsTransmitting(BandVector, i);
				FC.bandsOccupiedBySU(SU[i].SUsOccupants);
				

				//clear all vectors
				SU[i].emptyAllResult();
				if(count)
				SU[i].successfulVSTime(BandVec, timeVSuccessfulReq, T, i);
				SU[i].emptyAllResult();

			}
			FC.collision(bandOccByPus, BandVector, BandVec, succVsTimeSUId, timeVSuccessfulReq, T, SuccessfulVsTime ,count);
			//FC.successfulSUTrans(BandVector);
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
		for (int i = 0; i < NumberOfBands; i++)
		{
			FC.PUInterfere.push_back(FC.PUInterfereNum[i] / double(FC.PUInterfereDen[i]));
		}
		Performance result(timeSlots, ProbPU, succVsTimeSUId);
		result.outputFAFile(FC.FaVsSUId); //this function outputs the file which contain PFA VS SUId
		result.outputMDFile(FC.MdVsSUId);
		result.outputCollision(FC.collisionVsSuN);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		result.outputSuccSUTrans(FC.succSUTrans);
		result.outputPUInterference(FC.PUInterfere);
		FC.clearPerformanceOut();
		count = false;
	}

	Performance result(succVsTimeSUId);
	result.outputSuccessfulVsTime(SuccessfulVsTime);
	end = clock();
	duration =(end - start);
	printf("Decoding time = %d\n", duration);
	system("pause");
	return 0;
}