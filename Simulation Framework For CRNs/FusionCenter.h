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
	FusionCenter(int SUsN, int NBands, double Pfa, double Pmd , int,int );
	~FusionCenter() {};
	void getSUsIds(int ID);
	void getEmptyBands(const std::vector<int> &Bands); //band that did't have PUs in it
	void bandsOccupiedBySU(const std::vector<int> &suBand);
	void performanceCalculation(const std::vector<int> &PU,std::vector<Band_Details> &SUOccupants,
		const std::vector<DetermanisticBand> &bandDetails, int succVsTimeSUId, double &succVsTimeN
		, int T, std::vector<int> &SuccessfulVsTime,bool count ,const std::vector<int> &loadsReq); //return int vector of collision vs su
	void majority(std::vector<int> &puInBand ,std::vector<SecondaryUser> &SU, const std::vector<Band_Details> &Band_D);
	void clearVectors();
	void falseAlarm(const std::vector<double> &FAvsBandCoop);
	void missDetection(const std::vector<double> &MDvsBandCoop);
	void successfulVSTime(const std::vector<DetermanisticBand> &bandDetails,int succVsTimeSUId
		, double &succVsTimeN, double T , std::vector<int> &SuccessfulVsTime ,int bandN);
	void clearPerformanceOut();
	void successfulSUTrans(int timeSlot);
	void changingLoad(const std::vector<int> &loadReq);
	//output
	std::vector<double> FaVsSUId;
	std::vector<double> MdVsSUId;
	std::vector<double> FaVsSUIdCoop;
	std::vector<double> MdVsSUIdCoop;
	std::vector<int> utilizationVsBand;
	std::vector<int> collisionVsSuN; //this vector for su vs collision
	std::vector<int> throughput;
	std::vector<int> succSUTrans;
	std::vector<int> PUInterfereDen;
	std::vector<int> PUInterfereNum;
	std::vector<double> PUInterfere;
	std::vector<std::vector<int>> successfulTxForLoads;
	std::vector<int> successfulVsLoads;
	std::vector<int> majorityBands;


private:
	int SuId;
	int NumberOfSUs;
	int NumberOfBands;
	int maxSUsband;
	std::vector<std::vector<int>> emptyBands;
	std::vector<std::vector<int>> bandOccupied;
	
	bool appearsInVector(const int value , const std::vector<int> &searchIn);
	double PFA, PMD;
	unsigned int count = 0;
	int NumberOfBandsReqForEachSUs;
	int numberOfLoads;
	std::vector<int> falseAlarmCoopBand;
	std::vector<int> missDetectionCoopBand;
	
};

