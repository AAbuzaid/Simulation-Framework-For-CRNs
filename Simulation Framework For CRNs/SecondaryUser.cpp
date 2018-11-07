#include "SecondaryUser.h"


SecondaryUser::SecondaryUser()
{
	NumberOfBand = 100;
	PFA = .1;
	PMD = .1;
	numOfBandsReqForSUs = 10;
}

SecondaryUser::SecondaryUser(double PF_A, double PM_D, int NumberOfBandint,int SUN , bool cooperative)
	://NumFA(NumberOfBandint, 0), NumMD(NumberOfBandint, 0),
	NumFACoop(NumberOfBandint, 0),
	NumMDCoop(NumberOfBandint, 0),currentFA(NumberOfBandint , 0),currentMD(NumberOfBandint , 0 )
{
	PFA = PF_A;
	PMD = PM_D;
	NumberOfBand = NumberOfBandint;
	numOfBandsReqForSUs = SUN;
	coop = cooperative;
}

void SecondaryUser::scanningBands(const std::vector<Band_Details> &Bands, double activePUs , int SUID)
{
	bool falseAlarmPr;
	bool missDetectionPr;
	std::fill(currentFA.begin(), currentFA.end(), 0);
	std::fill(currentMD.begin(), currentMD.end(), 0);
	NumFA = 0;
	NumMD = 0;
	//BandBeingScaned.push_back = Bands.bandNumber();
	for (unsigned int i = 0; i < Bands.size(); i++)
	{
			if (Bands[i].isEmpty()) //H0
		{ 


				falseAlarmPr = (rand() % 100) < (PFA * 100.0);
			//	std::cout << falseAlarmPr;
				if (falseAlarmPr)
				{					//there is false alarm
					//++NumFA[i];		//number of false alarm vs band
					++NumFA;
					++currentFA[i];
				}
				else
					emptyBands.push_back(i);
		}
		else	//H1
		{
				missDetectionPr = (rand() % 100) < (PMD * 100);
				if (missDetectionPr)
				{
					emptyBands.push_back(i);
					{
						//++NumMD[i]; //number of misdetection vs band
						++NumMD;
						++currentMD[i];
					}
				}
		}
	}
	FAVsSU += NumFA / (Bands.size() - activePUs);
	if (activePUs <= 0)
		MdVsSU = 0;
	else
		MdVsSU += NumMD / activePUs;
	/*for (int i = 0; i < Bands.size(); i++)
	{
		NumFA[i] = NumFA[i] / (Bands.size() - activePUs);
		std::cout << NumFA[i] << " ";
		NumMD[i] = NumMD[i] /activePUTimeMD;
		currentFA[i] = currentFA[i] / (Bands.size() - activePUs);
		currentMD[i] = currentMD[i] / activePUTimeMD;
	}*/
}
void SecondaryUser::SUsTransmitting(std::vector<Band_Details> &Bands, int SUID , const std::vector<int> &loadReq)
{
	
		for (int i = 0; i < numOfBandsReqForSUs; i++)
		{
			randomBand = (rand() % Bands.size());
			if (std::find(SUOccupants.begin(),
				SUOccupants.end(), randomBand) == SUOccupants.end())
			{
				SUOccupants.push_back(randomBand);						// Assigning is random
				Bands[randomBand].setOccupants(SUID);
			}
			else
				--i;
		}
		loadIndex = 0;
		for (auto loads : loadReq)
		{
			for (int i = 0; i < loads; i++)
			{
				randomBand = (rand() % Bands.size());
				if (std::find(pick.begin(),
					pick.end(), randomBand) == pick.end())
				{
					pick.push_back(randomBand);
					Bands[randomBand].SUOccupantsForDiffLoads[loadIndex].push_back(SUID);
				}
				else
					--i;
			}
			++loadIndex;
			std::vector<int>().swap(pick);			// Clear pick vector

		}
	//this code do local sensing (extra for project 2)
	/*if (emptyBands.size() != 0) {
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			randomBand = (rand() % emptyBands.size());
			if (std::find(SUOccupants.begin(),
				SUOccupants.end(), emptyBands[randomBand]) == SUOccupants.end())
			{
				SUOccupants.push_back(emptyBands[randomBand]);						// Assigning is random
				//std::cout << SUOccupants[i] << " ";
				Bands[emptyBands[randomBand]].setOccupants(SUID);
			}
			else
				i--;
		}
		// Save which SUs are using a specific band
	}*/
}

void SecondaryUser::emptyAllResult() {
	emptyBands.clear();
	SUOccupants.clear();
	
}
void SecondaryUser::SuDeterministicSensing(std::vector<int> &PU)
{
	
}
void SecondaryUser::emptyFAandMD()
{
	//std::fill(NumFA.begin(), NumFA.end(), 0);
	//std::fill(NumMD.begin(), NumMD.end(), 0);
	FAVsSU = 0;
	MdVsSU = 0;
	std::fill(NumFACoop.begin(), NumFACoop.end(), 0);
	std::fill(NumMDCoop.begin(), NumMDCoop.end(), 0);
}

void SecondaryUser::successfulVSTime(std::vector<DeterministicBand> &Bands, double &succVsTimeN, double T, int SUID)
{
	bool falseAlarmPr;
	bool missDetectionPr;
	for (unsigned int i = 0; i < Bands.size(); i++)
	{
		if (Bands[i].isEmpty(T, i)) //H0
		{
			falseAlarmPr = (rand() % 100) < (PFA * 100.0);
			//	std::cout << falseAlarmPr;
			if (!falseAlarmPr) 				//there is false alarm
				emptyBands.push_back(i);
		}
		else	//H1
		{
			missDetectionPr = (rand() % 100) < (PMD * 100);
			if (missDetectionPr)
			{
				emptyBands.push_back(i);
			}
		}
	}
	if (emptyBands.size() != 0) {
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			int randomBand = (rand() % emptyBands.size());
			if (std::find(SUOccupants.begin(),
				SUOccupants.end(), emptyBands[randomBand]) == SUOccupants.end())
			{
				SUOccupants.push_back(emptyBands[randomBand]);						// Assigning is random
				Bands[emptyBands[randomBand]].setOccupants(SUID);
			}
			else
				--i;
		}


	}
}
void SecondaryUser::SUsTxCooparitive(std::vector<Band_Details> &Bands, int SUID, std::vector<int> &emptyBandsCooparitive)
{
	if (emptyBandsCooparitive.size() != 0) {
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			randomBand = (rand() % emptyBandsCooparitive.size());
			if (std::find(SUsOccupantsCoop.begin(),
				SUsOccupantsCoop.end(), emptyBandsCooparitive[randomBand]) == SUsOccupantsCoop.end())
			{
				SUsOccupantsCoop.push_back(emptyBandsCooparitive[randomBand]);						// Assigning is random
				//std::cout << SUOccupants[i] << " ";
				Bands[emptyBandsCooparitive[randomBand]].setOccupants(SUID);
			}
			else
				--i;
		}
	}
}


