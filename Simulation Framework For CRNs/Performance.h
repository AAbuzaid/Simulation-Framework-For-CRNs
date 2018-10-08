#pragma once
#include<vector>
#include"SecondaryUser.h"
#include <fstream>
#include <algorithm>
#include<iterator>
class Performance
{
public:
	Performance(int timeSlot);
	~Performance() {};
	void outputFAFile(const std::vector<int> &PFAvsSU);

	std::vector<int> PFA;
private:
	int timeS;
};

