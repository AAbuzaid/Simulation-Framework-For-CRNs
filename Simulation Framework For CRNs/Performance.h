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
	void outputFAFile(const std::vector<int> &PFAvsSU) const;
	void outputMDFile(const std::vector<int> &MDvsSU) const;
	void outputCollision(const std::vector<int> &Collision)	const;
	void outputUtilization(const std::vector<int> &Utilization) const;
	void outputThroughput(const std::vector<int> &throughput) const;
	void outputSuccessfulVsTime(const std::vector<int> &successfulVsTime) const;
	void outputSuccSUTrans(const std::vector<int> &succSUTrans)	const;
	void outputPUInterference(const std::vector<double> &PUInterfere) const;
	void outputChangingLoad(const std::vector<int> &loadsVsSucc) const;
	//cooperative sensing result
	void outputFAFileCoop(const std::vector<int> &PFAvsSUCoop) const;
	void outputMDFileCoop(const std::vector<int> &MDvsSUCoop) const;
	void outputCollisionCoop(const std::vector<int> &Collision) const;
	void outputUtilizationCoop(const std::vector<int> &Utilization) const;
	void outputThroughputCoop(const std::vector<int> &throughput) const;
	void outputSuccessfulVsTimeCoop(const std::vector<int> &successfulVsTime) const;
	void outputSuccSUTransCoop(const std::vector<int> &succSUTrans)	const;
	void outputPUInterferenceCoop(const std::vector<double> &PUInterfere) const;
	void outputChangingLoadCoop(const std::vector<int> &loadsVsSucc) const;
private:
	double timeS;
	int PuProb;
	int succTxSuId;
	double numberOfSUs;
};

