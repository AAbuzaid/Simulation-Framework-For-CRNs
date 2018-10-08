#include "SecondaryUser.h"



SecondaryUser::SecondaryUser()
	:NumFA(100 ,0) ,numMD(100 , 0)
{
	NumberOfBand = 100;
	PFA = .1;
	PMD = .1;
}

SecondaryUser::SecondaryUser(int PF_A, int PM_D, int NumberOfBandint)
	:NumFA(NumberOfBandint, 0), numMD(NumberOfBandint, 0)
{
	PFA = PF_A;
	PMD = PM_D;
	NumberOfBand = NumberOfBandint;
}

void SecondaryUser::scanningBands(const std::vector<Band_Details*> &Bands)
{
	bool falseAlarm = (rand() % 100) < (PFA * 100);
	std::cout <<""
	bool missDetection = (rand() % 100) < (PMD * 100);
	//BandBeingScaned.push_back = Bands.bandNumber();
	for (unsigned int i = 0; i < Bands.size(); i++)
	{
			if (Bands[i]->isEmpty()) //H0
		{ 
			if (falseAlarm) 				//there is false alarm
				NumFA[i]++;		//number of false alarm vs band
			else
				emptyBands.push_back(i); 
		}
		else	//H1
		{

			if (missDetection)
			{
				emptyBands.push_back(i);
				numMD[i]++; //number of misdetection vs band
			}
		}
	}
}
void SecondaryUser::SUsTransmitting(std::vector<Band_Details*> &Bands)
{
	numOfBandsReqForSUs = 5 + (rand() % 10);							// Number of su bands needed 5-15
	for (unsigned int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
	{
		int randomBand = (rand() % emptyBands.size());
		SUsOccupants[i] = emptyBands[randomBand];						// Assigning is random
		Bands[randomBand]->setOccupants(i);								// Save which SUs are using a specific band
	}
}
void SecondaryUser::emptyAllResult() {
	emptyBands.clear();
	SUsOccupants.clear();
	
}