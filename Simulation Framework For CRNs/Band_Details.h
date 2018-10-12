#pragma once
#include <vector>
#include <iostream>
class Band_Details
{
public:
	Band_Details();
	Band_Details(double ProbON);
	bool isEmpty() const;
	void randomPUState();
	bool getProbON() const;
	std::vector<int> SuOccupants;
	void setOccupants(unsigned int i);
	~Band_Details();
	void clearBands();

private:
	bool PUState;
	double ProbON;
	//std::vector<unsigned int> Occupants;
};
class DetermanisticBand : public Band_Details
{
public:
	DetermanisticBand(double , int);
	bool isEmpty(double T ,int bandN) const;
private:
	int successfulVsTimePUActiveForBandN;
	double timeVSuccessfulReq;
};




