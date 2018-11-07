#include "Band_Details.h"


Band_Details::Band_Details()
{
	ProbON = .5;
	PUOFF = (double(rand()) / double(RAND_MAX)) > ProbON;		// Randomly chooses true or false based on ProbON percentage

}

Band_Details::Band_Details(double ProbOn , int loads):
	SUOccupantsForDiffLoads(loads , std::vector<int>())
{
	ProbON = ProbOn;
	PUOFF = (double(rand()) / double(RAND_MAX)) >= ProbON;
	if (ProbON == 1)											// This solves the problem with extreme values 
		PUOFF = false;
}

void Band_Details::setOccupants(int i)
{
	SUOccupants.push_back(i);
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
	if (ProbON == 1)
		PUOFF = false;
}

bool Band_Details::getProbON() const
{
	return ProbON;
}
void Band_Details::clearBands()
{
	std::vector<int>().swap(SUOccupants);
	std::vector<int>().swap(SUOccupantsCooperative);
}
DeterministicBand::DeterministicBand(double T, int B)
{
	timeVSuccessfulReq = T;
	successfulVsTimePUActiveForBandN = B;
}
bool DeterministicBand::isEmpty(double T, int bandN) const
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

