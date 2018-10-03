#include "SecondaryUser.h"



SecondaryUser::SecondaryUser()
{
	NumberOfBand = 100;
	PFA = .1;
	PMD = .1;
}

SecondaryUser::SecondaryUser(int PFA, int PMD, int NumberOfBandint)
{

}


SecondaryUser::~SecondaryUser()
{
}

void SecondaryUser::scanningBands(Band_Details &Bands)
{
	bool falseAlarm = (rand() % 100) < (PFA *100);
	bool missDetection = (rand() % 100) < (PMD * 100);
	
	if (Bands.isEmpty()) //H0
	{
		BandBeingScaned.push_back = Bands.bandNumber();
		bool falseAlarmSimulation = true && falseAlarm;
		if (!falseAlarmSimulation) {
			Bands.Occupants();
		}
	}
}