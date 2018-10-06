#pragma once
#include<vector>
#include"SecondaryUser.h"
class Preformance
{
public:
	Preformance(const std::vector<SecondaryUser> &SUs);
	~Preformance();
	void CalculatePfa();

	std::vector<int> PFA;
};

