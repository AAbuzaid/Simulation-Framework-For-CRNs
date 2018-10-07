#include "Band_Details.h"

bool RandomOperation(double);

Band_Details::Band_Details()
{
	ProbON = .1;
	PUState = RandomOperation(ProbON);

}

Band_Details::Band_Details(double ProbOn)
{
	ProbON = ProbOn;
	PUState = RandomOperation(ProbON);

}

Band_Details::~Band_Details()
{
}

bool Band_Details::isEmpty() const
{
	return PUState;
}

bool RandomOperation(double ProbOn)
{
	double RandomNum = double(rand()) / double(RAND_MAX);			//	Uniform random value between [0.0, 1.0]
	return (RandomNum <= ProbOn);		
/*	if (RandomNum <= ProbOn)		^better	
		return true;
	else
		return false;
*/
}
