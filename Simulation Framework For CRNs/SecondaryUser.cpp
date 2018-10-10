#include "SecondaryUser.h"



SecondaryUser::SecondaryUser()
	:NumFA(100 ,0) ,numMD(100 , 0)
{
	NumberOfBand = 100;
	PFA = .1;
	PMD = .1;
	numOfBandsReqForSUs = 10;
}

SecondaryUser::SecondaryUser(double PF_A, double PM_D, int NumberOfBandint,int SUN)
	:NumFA(NumberOfBandint, 0), numMD(NumberOfBandint, 0)
{
	PFA = PF_A;
	PMD = PM_D;
	NumberOfBand = NumberOfBandint;
	numOfBandsReqForSUs = SUN;
}

void SecondaryUser::scanningBands(const std::vector<Band_Details> &Bands)
{
	bool falseAlarm;
	bool missDetection;
	//BandBeingScaned.push_back = Bands.bandNumber();
	for (unsigned int i = 0; i < Bands.size(); i++)
	{
			if (Bands[i].isEmpty()) //H0
		{ 
				falseAlarm = (rand() % 100) <= (PFA * 100.0);
			//	std::cout << falseAlarm;
			if (falseAlarm) 				//there is false alarm
				NumFA[i]++;		//number of false alarm vs band
			else
				emptyBands.push_back(i); 
		}
		else	//H1
		{
				missDetection = (rand() % 100) < (PMD * 100);
			if (missDetection)
			{
				emptyBands.push_back(i);
				numMD[i]++; //number of misdetection vs band
			}
		}
	}
}
void SecondaryUser::SUsTransmitting(std::vector<Band_Details> &Bands, int SUID)
{
	// Number of su bands needed 5-15
	if (emptyBands.size() != 0){
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			int randomBand = (rand() % emptyBands.size());
			if (std::find(SUsOccupants.begin(),
				SUsOccupants.end(), emptyBands[randomBand]) == SUsOccupants.end())
			{
				SUsOccupants.push_back(emptyBands[randomBand]);						// Assigning is random
				//std::cout << SUsOccupants[i] << " ";
				Bands[emptyBands[randomBand]].setOccupants(SUID);
			}
			else
				i--;
		}

		// Save which SUs are using a specific band
	}
}
void SecondaryUser::emptyAllResult() {
	emptyBands.clear();
	SUsOccupants.clear();
	
}