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
	double PPU = 0; //prob of PU
	int succVsTimeSUId = 4;
	int timeVSuccessfulReq = timeSlot / 2;
	int successfulVsTimePUActiveForBandN = 50;
	std::vector<int> bandOccByPus;	//bands occupants by PUs
	//For abdullah to write
	std::vector<Band_Details*> BandVector;
	for (int i = 0; i < NumberOfBands; i++)				//Initialize a vector with NumberOfBands bands
	{
		Band_Details *NewBand = new Band_Details(PPU);
		BandVector.push_back(NewBand);
	}

	//To here
	FusionCenter FC(NumberOfSUs, NumberOfBands, MaxSuBand);
	//std::vector<SecondaryUser> tryan(100, SecondaryUser(4, 4, 5, 5));
	std::vector <SecondaryUser*> SU;		//SU vector with 10 SUs
	for (int i = 0; i < NumberOfSUs; i++)	//Initializes a vector with NumberOfSUs elements
	{
		//SUPushing->scanningBands(BandVector); //Here I should enter the band vector that i should scan it (PU vector)
		//SU.push_back(SUPushing);
		//FC.getSUsIds(i);
		//FC.getEmptyBands(SU[i]->emptyBands);
		//FC.bandsOccupantedBySU(SU[i]->SUsOccupants);
		SecondaryUser *SUPushing = new SecondaryUser(PFA,PMD,NumberOfBands,NumberOfBandsReqForEachSUs);	//To Push valus to the SU vector
		SU.push_back(SUPushing);
	}
	std::vector<unsigned int> SuccessfulVsTime(timeSlot , 0); //successful VS time output vector intilization
	for (unsigned int T = 0; T < timeSlot; T++)
	{
		for (int i = 0; i < NumberOfBands; i++)
		{
			/*if (T > timeVSuccessfulReq)
			{
				if (i < successfulVsTimePUActiveForBandN)
					bandOccByPus.push_back(i);
			}
				FC.successfulVSTime(*SU[succVsTimeSUId], succVsTimeSUId, SuccessfulVsTime[succVsTimeSUId]);*/
			if(i != 0)
			BandVector[i - 1]->clearBands();
			BandVector[i]->randomPUState();		//Randomizes PUState each timeSlot
			if (!BandVector[i]->isEmpty())
				bandOccByPus.push_back(i);		//remove State from constructor
		}
		for (int i = 0; i < NumberOfSUs; i++)
		{
			SU[i]->scanningBands(BandVector);
			FC.getSUsIds(i);
			FC.getEmptyBands(SU[i]->emptyBands);
			SU[i]->SUsTransmitting(BandVector);
			FC.bandsOccupiedBySU(SU[i]->SUsOccupants);
			//clear all vector

			SU[i]->emptyAllResult();
		}
		FC.collision(bandOccByPus ,BandVector , succVsTimeSUId , SuccessfulVsTime[T]);					//bands thats contain PUs
		FC.majority();
		FC.clearVectors();
		bandOccByPus.clear();
	}
	for (int i = 0; i < NumberOfSUs; i++)
	{
		FC.falseAlarm(SU[i]->NumFA);
		FC.misDetection(SU[i]->numMD);
	}
	//Here for preformance calculation
	Performance result(timeSlot , PPU , succVsTimeSUId);
	/*result.outputFAFile(FC.FaVsSUId); //this function output the file which contain PFA VS SUId
	result.outputMDFile(FC.MdVsSUId);
	result.outputCollision(FC.collisionVsSuN);
	result.outputUtilization(FC.utilizationVsBand);
	result.outputThroughput(FC.throughput);
	result.outputSuccessfulVsTime(SuccessfulVsTime);*/
	end = clock();
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Decoding time = %d\n", duration);
	system("pause");
	return 0;
}