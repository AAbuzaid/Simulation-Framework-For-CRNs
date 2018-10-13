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
	Performance(double timeSlot ,double PUprob,int SuccessfulSUID, int numberOfSus);
	~Performance() {};
	void outputFAFile(const std::vector<int> &PFAvsSU);
	void outputMDFile(const std::vector<int> &MDvsSU);
	void outputCollision(const std::vector<int> &Collision);
	void outputUtilization(const std::vector<int> &Utilization);
	void outputThroughput(const std::vector<int> &throughput);
	void outputSuccessfulVsTime(const std::vector<int> &successfulVsTime);
	void outputSuccSUTrans(const std::vector<int> &succSUTrans);
	void outputPUInterference(const std::vector<double> &PUInterfere);
	void outputMDCooperative(const std::vector<int> &MDvsSU);
	void outputFACooperative(const std::vector<int> &PFAvsSU);

	//std::vector<int> PFA;
private:
	double timeS;
	int PuProb;
	int succTxSuId;
	double numberOfSUs;
};

