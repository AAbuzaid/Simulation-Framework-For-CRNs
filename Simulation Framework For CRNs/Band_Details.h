#pragma once
#include <vector>

class Band_Details
{
public:
	Band_Details();
	Band_Details(double ProbON);
	bool isEmpty() const;
	bool getProbON() const;
	std::vector<int> SuOccupants;
	
	~Band_Details();
private:
	bool PUState;
	double ProbON;
	std::vector <int> Occupants;
};

