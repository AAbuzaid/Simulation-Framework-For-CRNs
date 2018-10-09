#pragma once
#include<vector>
#include"SecondaryUser.h"
#include <fstream>
#include <algorithm>
#include<iterator>
class Performance
{
public:
	Performance(double timeSlot);
	~Performance() {};
	void outputFAFile(const std::vector<int> &PFAvsSU);
	void outputMDFile(const std::vector<int> &MDvsSU);
	void outputCollision(const std::vector<int> &Collision);
	std::vector<int> PFA;
private:
	int timeS;
};

