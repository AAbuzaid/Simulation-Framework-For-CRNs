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
	Performance(double timeSlot ,double PUprob,int SuccessfulSUID);
	~Performance() {};
	void outputFAFile(const std::vector<int> &PFAvsSU);
	void outputMDFile(const std::vector<int> &MDvsSU);
	void outputCollision(const std::vector<int> &Collision);
	void outputUtilization(const std::vector<int> &Utilization);
	void outputThroughput(const std::vector<int> &throughput);
	void outputSuccessfulVsTime(const std::vector<unsigned int> &successfulVsTime);
	void outputSuccSUTrans(const std::vector<int> &succSUTrans);
	//std::vector<int> PFA;
private:
	double timeS;
	int PuProb;
	int succTxSuId;
};

