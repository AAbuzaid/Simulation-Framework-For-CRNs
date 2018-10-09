#include "Band_Details.h"


Band_Details::Band_Details()
{
	ProbON = .1;
	PUState = (double(rand()) / double(RAND_MAX)) <= ProbON;		//Randomly chooses true or false based on ProbON percentage

}

Band_Details::Band_Details(double ProbOn)
{
	ProbON = ProbOn;
	PUState = (double(rand()) / double(RAND_MAX)) <= ProbON;
}

void Band_Details::setOccupants(unsigned int i)
{
	Occupants.push_back(i);
}

Band_Details::~Band_Details()
{
}

bool Band_Details::isEmpty() const
{
	std::cout << PUState;
	return !PUState;
}

void Band_Details::randomPUState()
{
	PUState = (double(rand()) / double(RAND_MAX)) <= ProbON;
}

bool Band_Details::getProbON() const
{
	return ProbON;
}

