#pragma once
#include<vector>
#include"SecondaryUser.h"
#include <fstream>
#include <algorithm>
#include<iterator>
#include <string>
class Performance
{
public:
	Performance(int SuccessfulSUID) { succTxSuId = SuccessfulSUID; };
	Performance(int timeSlot ,double PUprob,int SuccessfulSUID, int numberOfSus);
	~Performance() {};
	void outputFAFile(const std::vector<int> &PFAvsSU);
	void outputMDFile(const std::vector<int> &MDvsSU);
	void outputCollision(const std::vector<int> &Collision);
	void outputUtilization(const std::vector<int> &Utilization);
	void outputThroughput(const std::vector<int> &throughput);
	void outputSuccessfulVsTime(const std::vector<int> &successfulVsTime);
	void outputSuccSUTrans(const std::vector<int> &succSUTrans);
	void outputPUInterference(const std::vector<double> &PUInterfere);
	void outputChangingLoad(const std::vector<int> &loadsVsSucc);
	//cooparitive sensing result
	void outputFAFileCoop(const std::vector<int> &PFAvsSUCoop);
	void outputMDFileCoop(const std::vector<int> &MDvsSUCoop);
	void outputCollisionCoop(const std::vector<int> &Collision);
	void outputUtilizationCoop(const std::vector<int> &Utilization);
	void outputThroughputCoop(const std::vector<int> &throughput);
	void outputSuccessfulVsTimeCoop(const std::vector<int> &successfulVsTime);
	void outputSuccSUTransCoop(const std::vector<int> &succSUTrans);
	void outputPUInterferenceCoop(const std::vector<double> &PUInterfere);
	void outputChangingLoadCoop(const std::vector<int> &loadsVsSucc);
private:
	double timeS;
	int PuProb;
	int succTxSuId;
	double numberOfSUs;
};

