#include "FusionCenter.h"

FusionCenter::FusionCenter(int SusN, int Nbands, int SUbandMax )
	:emptyBands(SusN, std::vector<int>(0)),
	bandOccupied(SusN, std::vector<int>(0)),
	collisionVsSuN(SusN, 0),
	utilizationVsBand(Nbands , 0),
	throughput(Nbands , 0)
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
void FusionCenter::bandsOccupiedBySU(const std::vector<int> &suBand)
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
	bandOccupied[SuId] = suBand;
}
void FusionCenter::collision(const std::vector<int> &PUVsBand, const std::vector<Band_Details*> &bandDetails
	, int succVsTimeSUId, unsigned int &succVsTimeN)
{
	std::vector<int> temp;
	/*for (int currentSU = 0; currentSU < NumberOfSUs; currentSU++)
	{
		for (int BandN = 0; BandN < NumberOfBands; BandN++)
		{ 
			if (SUN != currentSU)
				std::set_intersection(SuOccupants[BandN].SuOccupants.begin(), SuOccupants[BandN].SuOccupants.begin(),
					SuOccupants[BandN].SuOccupants.begin(), SuOccupants[BandN].SuOccupants.begin(), std::back_inserter(temp));
			collisionVsSuN[currentSU] = temp.size();
			To be cont...

		}
		
	}*/
	for (int bandN = 0; bandN < NumberOfBands; bandN++)	//scan for bands in which there is more than one SU collision
	{
		//if (std::find(bandDetails[bandN].SuOccupants.begin(), //scan the band if there is any SU 
			//bandDetails[bandN].SuOccupants.end(), bandN) != bandDetails[bandN].SuOccupants.end())
		if(!bandDetails[bandN]->SuOccupants.empty())
			utilizationVsBand[bandN]++; //calculate utilization VS band
		if (bandDetails[bandN]->SuOccupants.size() > 1 || //this logical expr make sure that there is more than one su in the band
			appearsInVector(bandN, PUVsBand) && !bandDetails[bandN]->SuOccupants.empty())//or there is one su and pu
		{
			for (int i = 0; i < bandDetails[bandN]->SuOccupants.size(); i++) //for scan the su that in the collision band 
			{
				collisionVsSuN[bandDetails[bandN]->SuOccupants[i]]++;	//finally store the number of collision is the vector
			}
		}
		else
		{
			if (SuId = succVsTimeSUId)
				succVsTimeN++;
		}
		if (bandDetails[bandN]->SuOccupants.size() == 1 && !appearsInVector(bandN, PUVsBand))
			throughput[bandN]++;
	}
}
bool FusionCenter::appearsInVector(const int value, const std::vector<int> &searchIn) //to find if the value in the vector
{
	
		for (int i = 0; i < searchIn.size(); i++)
		{
			if (value == searchIn[i])
				return true;
		}
		return false; // no matches found
	
}
void FusionCenter::majority()	//this class find what band is empty by majority rule which(num of SU who says yes > who says no)
{
	std::vector<int> vectoria(NumberOfBands , 0);	//temp vector
	for (int bandN = 0; bandN < NumberOfBands; bandN++)	//scan all bands 
	{
		for (int SUN = 0; SUN < emptyBands.size(); SUN++)	//to enter the 2D vector empty class
		{
			if (std::find(emptyBands[SUN].begin(), emptyBands[SUN].end(), bandN) != emptyBands[SUN].end())
			{	//inter in here if the band is says empty by SUN
				vectoria[bandN]++; //how much SU says the band is empty 

			}
			else
				vectoria[bandN]--; //how much one says it is not empty 
		}
		if (vectoria[bandN] > 0) //now if the band decision is positive (most SUs say yes) then:
			majorityBands.push_back(bandN); //this band is empty by majority rule
	}

}

void FusionCenter::clearVectors()
{
	for (int i = 0; i < emptyBands.size(); i++)
		emptyBands[i].clear();
	for (int i = 0; i < bandOccupied.size(); i++)
		bandOccupied[i].clear();
	majorityBands.clear();
}
void FusionCenter::falseAlarm(const std::vector<int> &FAvsBand)
{
	int sumOfElement = 0;
	sumOfElement = std::accumulate(FAvsBand.begin(), FAvsBand.end(), 0);
	FaVsSUId.push_back(sumOfElement);
}
void FusionCenter::misDetection(const std::vector<int> &MDvsBand) 
{
	int sumOfElement = 0;
	sumOfElement = std::accumulate(MDvsBand.begin(), MDvsBand.end(), 0);
	MdVsSUId.push_back(sumOfElement);
}