#include "FusionCenter.h"

FusionCenter::FusionCenter(int SUsN, int Nbands, double Pfa, double Pmd, int numOfBandForSu, int numberOfloads)
	:emptyBands(SUsN, std::vector<int>(0)),
	bandOccupied(SUsN, std::vector<int>(0)),
	collisionVsSU(SUsN, 0),
	utilizationVsBand(Nbands, 0),
	throughput(Nbands, 0),
	succSUTrans(SUsN, 0),
	PUInterfereDen(Nbands, 0),
	PUInterfereNum(Nbands, 0),
	successfulTxForLoads(numberOfloads, std::vector<int>(SUsN,0)),
	successfulVsLoads(numberOfloads, 0), collisionVsSUCooperative(SUsN, 0),
	utilizationVsBandCooperative(Nbands, 0),
	throughputCooperative(Nbands, 0), PUInterfereNumCooperative(Nbands, 0)
{
	NumberOfSUs = SUsN;
	NumberOfBands = Nbands;
	PFA = Pfa;
	PMD = Pmd;
	NumberOfBandsReqForEachSUs = numOfBandForSu;
	numberOfLoads = numberOfloads;
	/*emptyBands.reserve(NumberOfSUs + 1);
	bandOccupied.reserve(SUsN + 1);
	collisionVsSU.reserve(NumberOfSUs + 1);
	utilizationVsBand.reserve(NumberOfBands + 1);
	throughput.reserve(NumberOfBands + 1);
	succSUTrans.reserve(NumberOfSUs + 1);
	PUInterfereDen.reserve(NumberOfBands + 1);
	PUInterfereNum.reserve(NumberOfBands + 1);
	successfulTxForLoads.reserve(numberOfloads + 1);
	successfulVsLoads.reserve(NumberOfBands+1);*/
}
void FusionCenter::getSUID(int ID)
{
	SUID = ID;
	
}
void FusionCenter::getEmptyBands(const std::vector<int> &Bands)
{
	if(!Bands.empty())
	emptyBands[SUID] = Bands;

}
void FusionCenter::bandsOccupiedBySU(const std::vector<int> &SUBand)
{
	bandOccupied[SUID] = SUBand;
}
void FusionCenter::performanceCalculation(const std::vector<int> &PUVsBand,std::vector<Band_Details> &bandDetails,
	const std::vector<DeterministicBand> &bandVecDeterministic, int succVsTimeSUId, double &succVsTimeN
	, int T, std::vector< int> &SuccessfulVsT , bool count, const std::vector<int> &loadsReq , bool CooperativeOrNot)
{
	for (int bandN = 0; bandN < NumberOfBands; bandN++)
	{
		if (!bandDetails[bandN].SUOccupants.empty())
			++utilizationVsBand[bandN]; //calculate utilization VS band
		if (bandDetails[bandN].SUOccupants.size() > 1 ||										//this logical expression tests if there is more than one SU in the band
			appearsInVector(bandN, PUVsBand) && !bandDetails[bandN].SUOccupants.empty())		//or there is one SU and PU
		{
			for (int i = 0; i < bandDetails[bandN].SUOccupants.size(); i++) // scan the SU thats in the collision band 
			{
				++collisionVsSU[bandDetails[bandN].SUOccupants[i]];	//finally store the number of collision in the vector
			}
		}
		if (!bandDetails[bandN].isEmpty())
			++PUInterfereDen[bandN];
		if (!bandDetails[bandN].SUOccupants.empty() && !bandDetails[bandN].isEmpty())
			++PUInterfereNum[bandN];
		if (bandDetails[bandN].SUOccupants.size() == 1 && !appearsInVector(bandN , PUVsBand))
			++throughput[bandN];
		//successful VS time 
		if(count)
			successfulVSTime(bandVecDeterministic, succVsTimeSUId, succVsTimeN, T, SuccessfulVsT, bandN);
		//successful Vs SU for different loads
		for (int i = 0; i < loadsReq.size(); i++)
		{
			if (bandDetails[bandN].SUOccupantsForDiffLoads[i].size() == 1 && !appearsInVector(bandN, PUVsBand))
			{
				++successfulTxForLoads[i][bandDetails[bandN].SUOccupantsForDiffLoads[i][0]];

			}
			std::vector<int>().swap(bandDetails[bandN].SUOccupantsForDiffLoads[i]);
		}
		if (CooperativeOrNot)
		{
			if (!bandDetails[bandN].SUOccupants.empty())
				++utilizationVsBandCooperative[bandN]; //calculate utilization VS band
			if (bandDetails[bandN].SUOccupants.size() > 1 || //this logical expr make sure that there is more than one SUN in the band
				appearsInVector(bandN, PUVsBand) && !bandDetails[bandN].SUOccupants.empty())//or there is one SUN and pu
			{
				for (int i = 0; i < bandDetails[bandN].SUOccupants.size(); i++) //for scan the SUN that in the collision band 
				{
					++collisionVsSUCooperative[bandDetails[bandN].SUOccupants[i]];	//finally store the number of collision is the vector
					//std::cout << collisionVsSU[bandDetails[bandN].SUOccupants[i]] << " ";
				}
			}
			if (!bandDetails[bandN].SUOccupants.empty() && !bandDetails[bandN].isEmpty())
				++PUInterfereNumCooperative[bandN];
			if (bandDetails[bandN].SUOccupants.size() == 1 && !appearsInVector(bandN, PUVsBand))
				++throughputCooperative[bandN];
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
	int counterFA = 0;
	int counterMD = 0;
	for (int bandN = 0; bandN < NumberOfBands; bandN++)
	{
		for (int SUN = 0; SUN < NumberOfSUs; SUN++)
		{
			if (SU[SUN].currentFA[bandN] > 0)
				++counterFA;
			else
				--counterFA;
			if(SU[SUN].currentMD[bandN] > 0)
				++counterMD;
			else
				--counterMD;
		}
		if (counterFA > 0)
			falseAlarmCoopBand.push_back(bandN);
		if (counterMD > 0)
			missDetectionCoopBand.push_back(bandN);
	}
	for (int bandC : falseAlarmCoopBand)
	{
		for (int SUN = 0; SUN < NumberOfSUs; SUN++)
			SU[SUN].NumFACoop[bandC] = SU[SUN].NumFACoop[bandC] + SU[SUN].currentFA[bandC];
	}
	for (int bandC : missDetectionCoopBand)
	{
		for(int SUN = 0; SUN < NumberOfSUs; SUN++)
			SU[SUN].NumMDCoop[bandC] = SU[SUN].NumMDCoop[bandC] + SU[SUN].currentMD[bandC];
	}

	//this code for majority decision for PU active in the band
	std::vector<int> tempVector(NumberOfBands , 0);	//temporary vector
	//std::vector<int> SUIdMajority;
	//SUIdMajority.reserve(NumberOfBands);
	for (int bandN = 0; bandN < NumberOfBands; bandN++)	//scan all bands
	{
		for (int SUN = 0; SUN < emptyBands.size(); SUN++)	//to enter the 2D vector empty class
		{
			if (std::find(emptyBands[SUN].begin(), emptyBands[SUN].end(), bandN) != emptyBands[SUN].end())
			{	//enter in here if the band is says empty by SUN
				++tempVector[bandN]; //how many SUs say the band is empty
				//SUIdMajority.push_back(SUN);
			}
			else
				--tempVector[bandN]; //how many say it is not empty
		}

		if (tempVector[bandN] > 0) //now if the band decision is positive (most SUs say yes) then:
		{
			majorityBands.push_back(bandN); //this band is empty by majority rule
			//std::copy(SUIdMajority.begin(), SUIdMajority.end(), std::back_inserter(Band_D[bandN].SUOccupantsCooperative));
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
	//FAVsSU.push_back(sumOfElement);
	FaVsSUIdCoop.push_back(sumOfElementCoop);
	
}
void FusionCenter::missDetection(const std::vector<double> &MDvsBandCoop)
{
	//int sumOfElement = 0;
	int sumOfElementCoop = 0;
	//sumOfElement = std::accumulate(MDvsBand.begin(), MDvsBand.end(), 0);
	sumOfElementCoop = std::accumulate(MDvsBandCoop.begin(), MDvsBandCoop.end(), 0);
	//MDVsSU.push_back(sumOfElement);
	MdVsSUIdCoop.push_back(sumOfElementCoop);

}
void FusionCenter::successfulVSTime(const std::vector<DeterministicBand> &bandDetails,int succVsTimeSUId, double &succVsTimeN
	, double T, std::vector< int> &SuccessfulVsTime , int bandN)
{
	if ((bandN > 50 || bandN < 50 && T < succVsTimeN) && !bandDetails[bandN].SUOccupants.empty()) //no PU
	{
		if (bandDetails[bandN].SUOccupants.size() == 1 && bandDetails[bandN].SUOccupants[0] == succVsTimeSUId) //there is one SUN (4)
			++SuccessfulVsTime[T];
	}
}
void FusionCenter::clearPerformanceOut()
{
	std::fill(collisionVsSU.begin(), collisionVsSU.end(), 0);
	std::fill(utilizationVsBand.begin(), utilizationVsBand.end(), 0);
	std::fill(throughput.begin(), throughput.end(), 0);
	std::fill(collisionVsSUCooperative.begin(), collisionVsSUCooperative.end(), 0);
	std::fill(utilizationVsBandCooperative.begin(), utilizationVsBandCooperative.end(), 0);
	std::fill(throughputCooperative.begin(), throughputCooperative.end(), 0);
	std::vector<double>().swap(FAVsSU);
	std::vector<double>().swap(MDVsSU);
	std::fill(succSUTrans.begin(), succSUTrans.end(), 0);
	std::vector<double>().swap(PUInterfere);
	std::vector<double>().swap(PUInterfereCooperative);
	std::fill(successfulVsLoads.begin(), successfulVsLoads.end(), 0);
	std::vector<double>().swap(FaVsSUIdCoop);
	std::vector<double>().swap(MdVsSUIdCoop);

}

void FusionCenter::successfulSUTrans(int timeSlot)
{
	for (int i = 0; i < NumberOfSUs; i++)
		succSUTrans[i] =timeSlot * NumberOfBandsReqForEachSUs - collisionVsSU[i];
}
void FusionCenter::changingLoad(const std::vector<int> &loadReq)
{
	for (int i = 0; i < loadReq.size(); i++)
	{
		successfulVsLoads[i] = successfulVsLoads[i] + std::accumulate(successfulTxForLoads[i].begin(), successfulTxForLoads[i].end(), 0);
		std::fill(successfulTxForLoads[i].begin(), successfulTxForLoads[i].end(), 0);

	}
}
