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

void SecondaryUser::scanningBands() //Band_Details &Bands
{
	for (int i = 0; i < 10; i++) {
		bool falseAlarm = (rand() % 100) < 10;
		std::cout << falseAlarm;
	}
	/*if (Bands.isEmpty)
	{
		
	}*/
}