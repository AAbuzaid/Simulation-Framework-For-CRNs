#pragma once
#include<vector>
#include"Band_Details.h"
#include<algorithm>
#include<iterator>
#include<numeric>
#include "SecondaryUser.h"
class FusionCenter
{
public:
	FusionCenter(int SUsN, int NBands, int maxSUBand, double Pfa, double Pmd , int,int );
	~FusionCenter();
	void getSUsIds(int ID);
	void getEmptyBands(const std::vector<int> &Bands); //band that did't have PUs in it
	void bandsOccupiedBySU(const std::vector<int> &suBand);
	void performanceCalculation(const std::vector<int> &PU,std::vector<Band_Details> &SUOccupants,
		const std::vector<DetermanisticBand> &bandDetails, int succVsTimeSUId, double &succVsTimeN
		, int T, std::vector<int> &SuccessfulVsTime,bool count ,const std::vector<int> &loadsReq); //return int vector of collision vs su
	void majority(std::vector<int> &puInBand ,std::vector<SecondaryUser> &SU);
	void clearVectors();
	void falseAlarm(const std::vector<int> &FAvsBand, const std::vector<int> &FAvsBandCoop);
	void missDetection(const std::vector<int> &MDvsBand, const std::vector<int> &MDvsBandCoop);
	void successfulVSTime(const std::vector<DetermanisticBand> &bandDetails,int succVsTimeSUId
		, double &succVsTimeN, double T , std::vector<int> &SuccessfulVsTime ,int bandN);
	void clearPerformanceOut();
	void successfulSUTrans(int timeSlot);
	void changingLoad(const std::vector<int> &loadReq);
	//output
	std::vector<int> FaVsSUId;
	std::vector<int> MdVsSUId;
	std::vector<int> FaVsSUIdCoop;
	std::vector<int> MdVsSUIdCoop;
	std::vector<int> utilizationVsBand;
	std::vector<int> collisionVsSuN; //this vector for su vs collision
	std::vector<int> throughput;
	std::vector<int> succSUTrans;
	std::vector<int> PUInterfereDen;
	std::vector<int> PUInterfereNum;
	std::vector<double> PUInterfere;
	std::vector<int> cooperateFA;
	std::vector<int> cooperateMD;
	std::vector<int> resultFacoop;
	std::vector<int> resultMdcoop;
	std::vector<std::vector<int>> successfulTxForLoads;
	std::vector<int> successfulVsLoads;

private:
	int SuId;
	//int **emptyBands;
	//int **bandOccupied;
	int NumberOfSUs;
	int NumberOfBands;
	int maxSUsband;
	std::vector<std::vector<int>> emptyBands;
	std::vector<std::vector<int>> bandOccupied;
	
	bool appearsInVector(const int value , const std::vector<int> &searchIn);
	std::vector<int> majorityBands;
	double PFA, PMD;
	unsigned int count = 0;
	int NumberOfBandsReqForEachSUs;
	std::vector<std::vector <int>> FA_Temp;	//temp vector
	std::vector<std::vector <int>> MD_Temp;	//temp vector
	int numberOfLoads;
	std::vector<int> falseAlarmCoopBand;
	std::vector<int> missDetectionCoopBand;
	
};

