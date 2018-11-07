#include "SecondaryUser.h"


SecondaryUser::SecondaryUser()
{
	NumberOfBand = 100;
	PFA = .1;
	PMD = .1;
	numOfBandsReqForSUs = 10;
}

SecondaryUser::SecondaryUser(double PF_A, double PM_D, int NumberOfBandint,int SUN , bool cooparitive)
	://NumFA(NumberOfBandint, 0), NumMD(NumberOfBandint, 0),
	NumFACoop(NumberOfBandint, 0),
	NumMDCoop(NumberOfBandint, 0),currentFA(NumberOfBandint , 0),currentMD(NumberOfBandint , 0 )
{
	PFA = PF_A;
	PMD = PM_D;
	NumberOfBand = NumberOfBandint;
	numOfBandsReqForSUs = SUN;
	coop = cooparitive;
}

void SecondaryUser::scanningBands(const std::vector<Band_Details> &Bands, double activePUTime , int SUID)
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
			//	std::cout << falseAlarm;
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
	FaVsSUId += NumFA / (Bands.size() - activePUTime);
//	std::cout << FaVsSUId << " ";
	if (activePUTime <= 0)
		MdVsSUId = 0;
	else
		MdVsSUId += NumMD / activePUTime;
	/*for (int i = 0; i < Bands.size(); i++)
	{
		NumFA[i] = NumFA[i] / (Bands.size() - activePUTime);
		std::cout << NumFA[i] << " ";
		NumMD[i] = NumMD[i] /activePUTimeMD;
		currentFA[i] = currentFA[i] / (Bands.size() - activePUTime);
		currentMD[i] = currentMD[i] / activePUTimeMD;
	}*/
}
void SecondaryUser::SUsTransmitting(std::vector<Band_Details> &Bands, int SUID , const std::vector<int> &loadReq)
{
	
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			randomBand = (rand() % Bands.size());
			if (std::find(SUsOccupants.begin(),
				SUsOccupants.end(), randomBand) == SUsOccupants.end())
			{
				SUsOccupants.push_back(randomBand);						// Assigning is random
				Bands[randomBand].setOccupants(SUID);
			//	std::cout << SUsOccupants[uu] << " ";
			}
			else
				--i;
		}
//	std::cout << std::endl;
		lInc = 0;
		for (auto loads : loadReq)
		{
			//std::vector<int>().swap(occupentsLoads[lInc]);
			for (int i = 0; i < loads; i++)
			{
				randomBand = (rand() % Bands.size());
				if (std::find(pick.begin(),
					pick.end(), randomBand) == pick.end())
				{
					pick.push_back(randomBand);
					Bands[randomBand].SuOccupantsForDiffLoads[lInc].push_back(SUID);
				}
				else
					--i;
			}
			++lInc;
			std::vector<int>().swap(pick);

		}
	//this code do local sensing (extra for project 2)
	/*if (emptyBands.size() != 0) {
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			randomBand = (rand() % emptyBands.size());
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
	}*/
}

void SecondaryUser::emptyAllResult() {
	emptyBands.clear();
	SUsOccupants.clear();
	
}
void SecondaryUser::SuDeterministicSensing(std::vector<int> &PU)
{
	
}
void SecondaryUser::emptyFAandMD()
{
	//std::fill(NumFA.begin(), NumFA.end(), 0);
	//std::fill(NumMD.begin(), NumMD.end(), 0);
	FaVsSUId = 0;
	MdVsSUId = 0;
	std::fill(NumFACoop.begin(), NumFACoop.end(), 0);
	std::fill(NumMDCoop.begin(), NumMDCoop.end(), 0);
}

void SecondaryUser::successfulVSTime(std::vector<DetermanisticBand> &Bands, double &succVsTimeN, double T, int SUID)
{
	bool falseAlarm;
	bool missDetection;
	for (unsigned int i = 0; i < Bands.size(); i++)
	{
		if (Bands[i].isEmpty(T, i)) //H0
		{
			falseAlarm = (rand() % 100) < (PFA * 100.0);
			//	std::cout << falseAlarm;
			if (!falseAlarm) 				//there is false alarm
				emptyBands.push_back(i);
		}
		else	//H1
		{
			missDetection = (rand() % 100) < (PMD * 100);
			if (missDetection)
			{
				emptyBands.push_back(i);
			}
		}
	}
	if (emptyBands.size() != 0) {
		for (int i = 0; i < numOfBandsReqForSUs; i++)				// Su occupants the band
		{
			int randomBand = (rand() % emptyBands.size());
			if (std::find(SUsOccupants.begin(),
				SUsOccupants.end(), emptyBands[randomBand]) == SUsOccupants.end())
			{
				SUsOccupants.push_back(emptyBands[randomBand]);						// Assigning is random
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
				//std::cout << SUsOccupants[i] << " ";
				Bands[emptyBandsCooparitive[randomBand]].setOccupants(SUID);
			}
			else
				--i;
		}
	}
}


