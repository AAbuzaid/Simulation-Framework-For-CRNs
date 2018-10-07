#pragma once
#include<vector>
#include"SecondaryUser.h"
class Performance
{
public:
	Performance();
	~Performance() {};
	void calculatePFA(const std::vector<int> &PFAvsSU);

	std::vector<int> PFA;
};

