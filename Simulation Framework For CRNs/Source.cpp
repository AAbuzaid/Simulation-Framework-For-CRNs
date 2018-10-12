#include "Band_Details.h"
#include "SecondaryUser.h"
#include "FusionCenter.h"
#include "Performance.h"
#include <time.h>

int main()
{
	//clock_t start, end, duration;
	//Constant value which may change in the future
	//start = clock();
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
	FusionCenter FC(NumberOfSUs, NumberOfBands, MaxSuBand , PFA , PMD);
	//std::vector<SecondaryUser> tryan(100, SecondaryUser(4, 4, 5, 5));
	//std::vector <SecondaryUser*> SU;		//SU vector with 10 SUs
	std::vector<unsigned int> SuccessfulVsTime(timeSlot , 0); //successful VS time output vector intilization
	for (auto ProbPU : PPU)
	{
		/*for (int i = 0; i < NumberOfBands; i++)				//Initialize a vector with NumberOfBands bands
		{
			Band_Details *NewBand = new Band_Details();
			BandVector.push_back(NewBand);
		}
		for (int i = 0; i < NumberOfSUs; i++)	//Initializes a vector with NumberOfSUs elements
		{
			//SUPushing->scanningBands(BandVector); //Here I should enter the band vector that i should scan it (PU vector)
			//SU.push_back(SUPushing);
			//FC.getSUsIds(i);
			//FC.getEmptyBands(SU[i]->emptyBands);
			//FC.bandsOccupantedBySU(SU[i]->SUsOccupants);
			SecondaryUser *SUPushing = new SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSUs);	//To Push valus to the SU vector
			SU.push_back(SUPushing);
		}**/
		std::vector<Band_Details> BandVector(NumberOfBands, Band_Details(ProbPU));
		std::vector<SecondaryUser> SU(NumberOfSUs, SecondaryUser(PFA, PMD, NumberOfBands, NumberOfBandsReqForEachSUs));

		for (double T = 0; T < timeSlot; T++)
		{
			for (int i = 0; i < NumberOfBands; i++)
			{
				/*if (T > timeVSuccessfulReq)
				{
					if (i < successfulVsTimePUActiveForBandN)
						bandOccByPus.push_back(i);
				}
					FC.successfulVSTime(*SU[succVsTimeSUId], succVsTimeSUId, SuccessfulVsTime[succVsTimeSUId]);*/
				if (T != 0)
					BandVector[i].clearBands();
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
				/*std::cout << "secondary user ID:" << i << "scanning result: ";
				for (int b = 0; b < SU[i].emptyBands.size(); b++)
					std::cout << SU[i].emptyBands[b] << " ";
				std::cout << std::endl;
				std::cout << "secondary user ID: " << i << "Occupaied band: ";
				for (int b = 0; b < SU[i].SUsOccupants.size(); b++)
					std::cout << SU[i].SUsOccupants[b] << " ";
				std::cout << std::endl;*/

				//clear all vector
				SU[i].emptyAllResult();
			}
			FC.collision(bandOccByPus, BandVector);	
			/*std::cout << "collision for SU ID " << ": ";//bands thats contain PUs
			for (int b = 0; b < FC.collisionVsSuN.size(); b++)
				std::cout << FC.collisionVsSuN[b] << " ";
			std::cout << std::endl;*/
			/*std::cout << " utilization Vs Band Number " << ": ";
			for (int b = 0; b < FC.utilizationVsBand.size(); b++)
				std::cout << FC.utilizationVsBand[b] << " ";
			std::cout << std::endl;
			std::cout << "throughput vs band number: ";
			for (int b = 0; b < FC.throughput.size(); b++)
				std::cout << FC.throughput[b] << " ";
			std::cout << std::endl;*/

			FC.majority();
			FC.clearVectors();
			bandOccByPus.clear();
			//FC.successfulVSTime(succVsTimeSUId, timeVSuccessfulReq, T);
			
		}
		
		for (int i = 0; i < NumberOfSUs; i++)
		{
			FC.falseAlarm(SU[i].NumFA);
			FC.misDetection(SU[i].numMD);
			SU[i].emptyFAandMD();
		}
		//deallocate pointer
		
		//Here for preformance calculation
		/*std::cout << "sum of collision for SU ID: ";
		for (int b = 0; b < FC.collisionVsSuN.size(); b++)
			std::cout << FC.collisionVsSuN[b] << " ";
		std::cout << std::endl;
		std::cout << "sum utilization Vs Band Number: ";
		for (int b = 0; b < FC.utilizationVsBand.size(); b++)
			std::cout<< FC.utilizationVsBand[b] << " ";
		std::cout << std::endl;
		std::cout << "sum throughput vs band number: ";
		for (int b = 0; b < FC.throughput.size(); b++)
			std::cout<< FC.throughput[b] << " ";
		std::cout << std::endl;*/

		Performance result(timeSlot, ProbPU, succVsTimeSUId);
		result.outputFAFile(FC.FaVsSUId); //this function output the file which contain PFA VS SUId
		result.outputMDFile(FC.MdVsSUId);
		result.outputCollision(FC.collisionVsSuN);
		result.outputUtilization(FC.utilizationVsBand);
		result.outputThroughput(FC.throughput);
		//result.outputSuccessfulVsTime(SuccessfulVsTime);
		FC.clearPerformanceOut();
	}
/*	for (int i = 0; i < NumberOfBands; i++)
	{
		delete BandVector[i];
	}
	for (int i = 0; i < NumberOfSUs; i++)
	{
		delete SU[i];

	}*/
	//end = clock();
	//duration = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("Decoding time = %d\n", duration);
	system("pause");
	return 0;
}