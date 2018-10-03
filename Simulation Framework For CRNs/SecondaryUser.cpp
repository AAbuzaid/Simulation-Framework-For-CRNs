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
	BandBeingScaned.push_back = Bands.bandNumber();
	if (Bands.isEmpty()) //H0
	{
		bool falseAlarmSimulation = true && falseAlarm;

		if (!falseAlarmSimulation) {
			Bands.Occupying();
		}
		else
		{
			NumFA++;
		}
	}
	else	//H1
	{
		bool missDetectionSimulation = true && missDetection;
		if (missDetectionSimulation)
		{
			numMD++;
			Bands.Occupying();
		}
	}
}