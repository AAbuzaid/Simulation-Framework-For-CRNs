#include "FusionCenter.h"

FusionCenter::FusionCenter(int SusN, int Nbands, double Pfa, double Pmd, int numofbandforSu, int numberOfloads)
	:emptyBands(SusN, std::vector<int>(0)),
	bandOccupied(SusN, std::vector<int>(0)),
	collisionVsSuN(SusN, 0),
	utilizationVsBand(Nbands, 0),
	throughput(Nbands, 0),
	succSUTrans(SusN, 0),
	PUInterfereDen(Nbands, 0),
	PUInterfereNum(Nbands, 0),
	successfulTxForLoads(numberOfloads, std::vector<int>(SusN,0)),
	successfulVsLoads(numberOfloads, 0), collisionVsSuNCooparitive(SusN, 0),
	utilizationVsBandCooparitive(Nbands, 0),
	throughputCooparitive(Nbands, 0), PUInterfereNumCooparitive(Nbands, 0)
{
	NumberOfSUs = SusN;
	NumberOfBands = Nbands;
	PFA = Pfa;
	PMD = Pmd;
	NumberOfBandsReqForEachSUs = numofbandforSu;
	numberOfLoads = numberOfloads;
}
void FusionCenter::getSUsIds(int ID)
{
	SuId = ID;
	
}
void FusionCenter::getEmptyBands(const std::vector<int> &Bands)
{
	if(!Bands.empty())
	emptyBands[SuId] = Bands;

}
void FusionCenter::bandsOccupiedBySU(const std::vector<int> &suBand)
{
	bandOccupied[SuId] = suBand;
}
void FusionCenter::performanceCalculation(const std::vector<int> &PUVsBand,std::vector<Band_Details> &bandDetails,
	const std::vector<DetermanisticBand> &bandvec, int succVsTimeSUId, double &succVsTimeN
	, int T, std::vector< int> &SuccessfulVsT , bool count, const std::vector<int> &loadsReq , bool CooperativeOrNot)
{
	for (int bandN = 0; bandN < NumberOfBands; bandN++)	//scan for bands in which there is more than one SU collision
	{
		if (!bandDetails[bandN].SuOccupants.empty())
			++utilizationVsBand[bandN]; //calculate utilization VS band
		if (bandDetails[bandN].SuOccupants.size() > 1 || //this logical expr make sure that there is more than one su in the band
			appearsInVector(bandN, PUVsBand) && !bandDetails[bandN].SuOccupants.empty())//or there is one su and pu
		{
			for (int i = 0; i < bandDetails[bandN].SuOccupants.size(); i++) //for scan the su that in the collision band 
			{
				++collisionVsSuN[bandDetails[bandN].SuOccupants[i]];	//finally store the number of collision is the vector
				//std::cout << collisionVsSuN[bandDetails[bandN].SuOccupants[i]] << " ";
			}
		}
		if (!bandDetails[bandN].isEmpty())
			++PUInterfereDen[bandN];
		if (!bandDetails[bandN].SuOccupants.empty() && !bandDetails[bandN].isEmpty())
			++PUInterfereNum[bandN];
		if (bandDetails[bandN].SuOccupants.size() == 1 && !appearsInVector(bandN , PUVsBand))
			++throughput[bandN];
		//successful VS time 
		if(count)
		successfulVSTime(bandvec, succVsTimeSUId, succVsTimeN, T, SuccessfulVsT, bandN);
		//successful Vs su for different loads
		for (int i = 0; i < loadsReq.size(); i++)
		{
			if (bandDetails[bandN].SuOccupantsForDiffLoads[i].size() == 1 && !appearsInVector(bandN, PUVsBand))
			{
				++successfulTxForLoads[i][bandDetails[bandN].SuOccupantsForDiffLoads[i][0]];

			}
			std::vector<int>().swap(bandDetails[bandN].SuOccupantsForDiffLoads[i]);
		}
		if (CooperativeOrNot)
		{
			if (!bandDetails[bandN].SuOccupants.empty())
				++utilizationVsBandCooparitive[bandN]; //calculate utilization VS band
			if (bandDetails[bandN].SuOccupants.size() > 1 || //this logical expr make sure that there is more than one su in the band
				appearsInVector(bandN, PUVsBand) && !bandDetails[bandN].SuOccupants.empty())//or there is one su and pu
			{
				for (int i = 0; i < bandDetails[bandN].SuOccupants.size(); i++) //for scan the su that in the collision band 
				{
					++collisionVsSuNCooparitive[bandDetails[bandN].SuOccupants[i]];	//finally store the number of collision is the vector
					//std::cout << collisionVsSuN[bandDetails[bandN].SuOccupants[i]] << " ";
				}
			}
			if (!bandDetails[bandN].SuOccupants.empty() && !bandDetails[bandN].isEmpty())
				++PUInterfereNumCooparitive[bandN];
			if (bandDetails[bandN].SuOccupants.size() == 1 && !appearsInVector(bandN, PUVsBand))
				++throughputCooparitive[bandN];
		}
		
	}
}
bool FusionCenter::appearsInVector(const int value, const std::vector<int> &searchIn) //to find if the value in the vector
{
	
		for (unsigned int i = 0; i < searchIn.size(); i++)
		{
			if (value == searchIn[i])
				return true;
		}
		return false; // no matches found
	
}
void FusionCenter::majority(std::vector<int> &puInBand, std::vector<SecondaryUser> &SU ,std::vector<Band_Details> &Band_D)	
//this class find what band is empty by majority rule which(num of SU who says yes > who says no)
{
	int counter = 0;
	int counter1 = 0;
	for (int bandN = 0; bandN < NumberOfBands; bandN++)
	{
		for (int suN = 0; suN < NumberOfSUs; suN++)
		{
			//std::cout << SU[suN].currentFA[bandN] << " ";
			if (SU[suN].currentFA[bandN] > 0)
				++counter;
			else
				--counter;
			if(SU[suN].currentMD[bandN] > 0)
				++counter1;
			else
				--counter1;
			//std::cout << counter << " " << counter1;
		}
		//std::cout << std::endl;
		if (counter > 0)
			falseAlarmCoopBand.push_back(bandN);
		if (counter1 > 0)
			missDetectionCoopBand.push_back(bandN);
	}
	for (int bandC : falseAlarmCoopBand)
	{
		for (int su = 0; su < NumberOfSUs; su++)
			SU[su].NumFACoop[bandC] = SU[su].NumFACoop[bandC] + SU[su].currentFA[bandC];
	}
	for (int bandC : missDetectionCoopBand)
	{
		for(int su = 0; su < NumberOfSUs; su++)
			SU[su].NumMDCoop[bandC] = SU[su].NumMDCoop[bandC] + SU[su].currentMD[bandC];
	}

	//this code for majority decision for PU active in the band
	std::vector<int> vectora(NumberOfBands , 0);	//temporary vector
	//std::vector<int> SUIdMajority;
	//SUIdMajority.reserve(NumberOfBands);
	for (int bandN = 0; bandN < NumberOfBands; bandN++)	//scan all bands
	{
		for (int SUN = 0; SUN < emptyBands.size(); SUN++)	//to enter the 2D vector empty class
		{
			if (std::find(emptyBands[SUN].begin(), emptyBands[SUN].end(), bandN) != emptyBands[SUN].end())
			{	//inter in here if the band is says empty by SUN
				++vectora[bandN]; //how much SU says the band is empty
				//SUIdMajority.push_back(SUN);
			}
			else
				--vectora[bandN]; //how much one says it is not empty
		}

		if (vectora[bandN] > 0) //now if the band decision is positive (most SUs say yes) then:
		{
			majorityBands.push_back(bandN); //this band is empty by majority rule
			//std::copy(SUIdMajority.begin(), SUIdMajority.end(), std::back_inserter(Band_D[bandN].SuOccupantsCooparitive));
		}
		//std::vector<int>().swap(SUIdMajority);
	}
}


void FusionCenter::clearVectors()
{
	//for (int i = 0; i < emptyBands.size(); i++)
	//std::vector<int>().swap(emptyBands[i]);
	//for (int i = 0; i < bandOccupied.size(); i++)
	//std::vector<int>().swap(bandOccupied[i]);
	std::vector<int>().swap(majorityBands);
	std::vector<int>().swap(falseAlarmCoopBand);
	std::vector<int>().swap(missDetectionCoopBand);

}
void FusionCenter::falseAlarm(const std::vector<double> &FAvsBandCoop)
{
	//double sumOfElement = 0;
	double sumOfElementCoop = 0;
	//sumOfElement = std::accumulate(FAvsBand.begin(), FAvsBand.end(), 0);
	sumOfElementCoop = std::accumulate(FAvsBandCoop.begin(), FAvsBandCoop.end(), 0);
	//FaVsSUId.push_back(sumOfElement);
	FaVsSUIdCoop.push_back(sumOfElementCoop);
	
}
void FusionCenter::missDetection(const std::vector<double> &MDvsBandCoop)
{
	//int sumOfElement = 0;
	int sumOfElementCoop = 0;
	//sumOfElement = std::accumulate(MDvsBand.begin(), MDvsBand.end(), 0);
	sumOfElementCoop = std::accumulate(MDvsBandCoop.begin(), MDvsBandCoop.end(), 0);
	//MdVsSUId.push_back(sumOfElement);
	MdVsSUIdCoop.push_back(sumOfElementCoop);

}
void FusionCenter::successfulVSTime(const std::vector<DetermanisticBand> &bandDetails,int succVsTimeSUId, double &succVsTimeN
	, double T, std::vector< int> &SuccessfulVsTime , int bandN)
{
	if ((bandN > 50 || bandN < 50 && T < succVsTimeN) && !bandDetails[bandN].SuOccupants.empty()) //no PU
	{
		if (bandDetails[bandN].SuOccupants.size() == 1 && bandDetails[bandN].SuOccupants[0] == succVsTimeSUId) //there is one su (4)
			++SuccessfulVsTime[T];
	}
}
void FusionCenter::clearPerformanceOut()
{
	std::fill(collisionVsSuN.begin(), collisionVsSuN.end(), 0);
	std::fill(utilizationVsBand.begin(), utilizationVsBand.end(), 0);
	std::fill(throughput.begin(), throughput.end(), 0);
	std::fill(collisionVsSuNCooparitive.begin(), collisionVsSuNCooparitive.end(), 0);
	std::fill(utilizationVsBandCooparitive.begin(), utilizationVsBandCooparitive.end(), 0);
	std::fill(throughputCooparitive.begin(), throughputCooparitive.end(), 0);
	std::vector<double>().swap(FaVsSUId);
	std::vector<double>().swap(MdVsSUId);
	std::fill(succSUTrans.begin(), succSUTrans.end(), 0);
	std::vector<double>().swap(PUInterfere);
	std::vector<double>().swap(PUInterfereCooparitive);
	std::fill(successfulVsLoads.begin(), successfulVsLoads.end(), 0);
	std::vector<double>().swap(FaVsSUIdCoop);
	std::vector<double>().swap(MdVsSUIdCoop);

}

void FusionCenter::successfulSUTrans(int timeSlot)
{
	for (int i = 0; i < NumberOfSUs; i++)
		succSUTrans[i] =timeSlot * NumberOfBandsReqForEachSUs - collisionVsSuN[i];
}
void FusionCenter::changingLoad(const std::vector<int> &loadReq)
{
	for (int i = 0; i < loadReq.size(); i++)
	{
		successfulVsLoads[i] = successfulVsLoads[i] + std::accumulate(successfulTxForLoads[i].begin(), successfulTxForLoads[i].end(), 0);
		std::fill(successfulTxForLoads[i].begin(), successfulTxForLoads[i].end(), 0);

	}
}
