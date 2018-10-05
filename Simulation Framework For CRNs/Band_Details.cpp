#include "Band_Details.h"

bool ONorOFF(double);

Band_Details::Band_Details()
{
	ProbON = .1;
	PUState = ONorOFF(ProbON);

}

Band_Details::Band_Details(double ProbOn)
{
	ProbON = ProbOn;
	PUState = ONorOFF(ProbON);

}

Band_Details::~Band_Details()
{
}

bool Band_Details::isEmpty()
{
	return PUState;
}

bool ONorOFF(double ProbON)
{
	double RandomNum = double(rand()) / double(RAND_MAX);			//	Uniform random value between [0.0, 1.0]

	if (RandomNum <= ProbON)
		return true;
	else
		return false;

}
