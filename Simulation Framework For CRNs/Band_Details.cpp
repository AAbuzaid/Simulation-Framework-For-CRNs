#include "Band_Details.h"


Band_Details::Band_Details()
{
	ProbON = .5;
	PUOFF = (double(rand()) / double(RAND_MAX)) > ProbON;		//Randomly chooses true or false based on ProbON percentage

}

Band_Details::Band_Details(double ProbOn , int loads):
	SuOccupantsForDiffLoads(loads , std::vector<int>())
{
	ProbON = ProbOn;
	PUOFF = (double(rand()) / double(RAND_MAX)) >= ProbON;
}

void Band_Details::setOccupants(int i)
{
	SuOccupants.push_back(i);
}

Band_Details::~Band_Details()
{
}

bool Band_Details::isEmpty() const
{
	return PUOFF;
}

void Band_Details::randomPUState()
{
	PUOFF = (double(rand()) / double(RAND_MAX)) >= ProbON;
}

bool Band_Details::getProbON() const
{
	return ProbON;
}
void Band_Details::clearBands()
{
	SuOccupants.clear();
}
DetermanisticBand::DetermanisticBand(double T, int B)
{
	timeVSuccessfulReq = T;
	successfulVsTimePUActiveForBandN = B;
}
bool DetermanisticBand::isEmpty(double T, int bandN) const
{
	if (T < timeVSuccessfulReq)
		return true;
	else
	{
		if (bandN > successfulVsTimePUActiveForBandN)
			return true;
		else
		{
			return false;
		}
	}
}

