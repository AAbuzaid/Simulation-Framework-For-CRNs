#include "FusionCenter.h"


FusionCenter::FusionCenter(int SusN , int Nbands , int SUbandMax)
{
	NumberOfSUs = SusN;
	NumberOfBands = Nbands;
	maxSUsband = SUbandMax;
}
FusionCenter::~FusionCenter()
{
	delete [] emptyBands;
	delete [] bandOccupanted;
} 
void FusionCenter::getSUsIds(int ID)
{
	SuId = ID;
	
}
void FusionCenter::getEmptyBands(const std::vector<int> &Bands)
{
	emptyBands = new int*[NumberOfSUs];					//creat two Dimentional array to store IDs of SUs and the result 
	for (int raw = 0; raw < NumberOfSUs; raw++)			//of sensing for every one of them
	{
		emptyBands[raw] = new int[NumberOfBands];		
	}

	for (int raw = 0; raw < NumberOfSUs; raw++)			//input empty bands and su id
	{
		for (int col = 0; col < NumberOfBands; col++)
		{
			if(Bands.size() > col)
			emptyBands[raw][col] = Bands[col];
			else
			{
				break;
			}
		}
	}
}
void FusionCenter::bandsOccupantedBySU(const std::vector<int> &suBand)
{
	bandOccupanted = new int *[NumberOfSUs];			////creat two Dimentional array to store IDs of SUs and the Occupanted
	for (int raw = 0; raw < NumberOfSUs; raw++)			//band by each one
	{
		bandOccupanted[raw] = new int[maxSUsband];
	}

	for (int raw = 0; raw < NumberOfSUs; raw++)			//input band occ by su and su id
	{
		for (int col = 0; col < maxSUsband; col++)
		{
			if (suBand.size() > col)
				bandOccupanted[raw][col] = suBand[col];
			else
			{
				break;
			}
		}
	}
	
}