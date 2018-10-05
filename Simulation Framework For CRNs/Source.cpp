#include "Band_Details.h"
#include "SecondaryUser.h"


int main()
{
	//Constant value which may change in the future
	int NumberOfBand = 100;
	int NumberOfSUs = 6;
	//For abdullah to write

	//To here
	std::vector <SecondaryUser*> SU;		//SU vector which provied 6 SU6
	SecondaryUser *SUPushing = new SecondaryUser;	//To Push valus to the SU vector
	for (int i = 1; i <= NumberOfSUs; i++)
	{
		SUPushing->scanningBands(Band_Details BandVector); //Here I should enter the band vector that i should scan it (PU vector)
		SU.push_back(SUPushing);
	}
	system("pause");
	return 0;
}