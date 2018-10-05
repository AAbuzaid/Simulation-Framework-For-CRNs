#pragma once
#include <vector>

class Band_Details
{
public:
	Band_Details();
	Band_Details(double ProbON);
	bool isEmpty();


	~Band_Details();
private:
	bool PUState;
	double ProbON;
	std::vector <int> Occupants;
};

