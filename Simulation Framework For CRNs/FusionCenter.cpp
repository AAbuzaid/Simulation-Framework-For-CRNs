#include "FusionCenter.h"


FusionCenter::FusionCenter(int SusN , int Nbands , int SUbandMax)
	:emptyBands(SusN, std::vector<int>(0)) , 
	bandOccupanted(SusN, std::vector<int>(0))
{
	NumberOfSUs = SusN;
	NumberOfBands = Nbands;
	maxSUsband = SUbandMax;

	/*emptyBands = new int*[NumberOfSUs];					//creat two Dimentional array to store IDs of SUs and the result 
	for (int raw = 0; raw < NumberOfSUs; raw++)			//of sensing for every one of them
	{
		emptyBands[raw] = new int[NumberOfBands];
		for (int col = 0; col < NumberOfBands; col++)
		{
			emptyBands[raw][col] = 0;
		}
	}

	
	bandOccupanted = new int *[NumberOfSUs];			////creat two Dimentional array to store IDs of SUs and the Occupanted
	for (int raw = 0; raw < NumberOfSUs; raw++)			//band by each one
	{
		bandOccupanted[raw] = new int[maxSUsband];
		for (int col = 0; col < NumberOfBands; col++)
		{
			bandOccupanted[raw][col] = 0;
		}
	}*/

}
FusionCenter::~FusionCenter()
{/**
	delete [] emptyBands;
	delete [] bandOccupanted;*/
} 
void FusionCenter::getSUsIds(int ID)
{
	SuId = ID;
	
}
void FusionCenter::getEmptyBands(const std::vector<int> &Bands)
{
	/*
	for (int col = 0; col < NumberOfBands; col++)
	{
		if (Bands.size() > col)
			emptyBands[SuId][col] = Bands[col];
		else
		{
			break;
		}
	}*/
	
	emptyBands[SuId] = Bands;

}
void FusionCenter::bandsOccupantedBySU(const std::vector<int> &suBand)
{
	/*for (int col = 0; col < maxSUsband; col++)
	{
		if (suBand.size() > col)
			bandOccupanted[SuId][col] = suBand[col];
		else
		{
			break;
		}
	}*/
	bandOccupanted[SuId] = suBand;
}
void FusionCenter::collision(const std::vector<int> &PU)
{
	std::vector<int> temp;
	for (int currentSU = 0; currentSU < NumberOfSUs; currentSU++)
	{
		for (int SUN = 0; SUN < NumberOfSUs; SUN++)
		{
			if (SUN != currentSU)
				std::set_intersection(bandOccupanted[currentSU].begin(), bandOccupanted[currentSU].end(),
					bandOccupanted[SUN].begin(), bandOccupanted[SUN].end(), std::back_inserter(temp));
			collisionVsSuN[currentSU] = temp.size();
			

		}
		
	}
}