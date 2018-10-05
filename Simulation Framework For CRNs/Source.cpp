#include "Band_Details.h"
#include "SecondaryUser.h"
#include <vector>


int main()
{
	//Constant value which may change in the future
	int NumberOfBands = 100;
	int NumberOfSUs = 6;

	//For abdullah to write
	std::vector<Band_Details> BandVector;
	for (int i = 0; i <= NumberOfBands; i++)				//Initialize a vector with NumberOfBands bands
	{
		Band_Details *NewBand = new Band_Details;
		BandVector[i] = *NewBand;
	}

	//To here

	std::vector <SecondaryUser*> SU;		//SU vector which provied 6 SU6
	SecondaryUser *SUPushing = new SecondaryUser;	//To Push valus to the SU vector
	for (int i = 1; i <= NumberOfSUs; i++)
	{
		SUPushing->scanningBands(BandVector); //Here I should enter the band vector that i should scan it (PU vector)
		SU.push_back(SUPushing);			//Don't we need a dereferencing operator here?
	}
	system("pause");
	return 0;
}