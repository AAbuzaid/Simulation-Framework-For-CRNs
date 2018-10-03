#pragma once
#include <vector>
#include "Band_Details.h"
#include <iostream>
class SecondaryUser
{
public:
	SecondaryUser();
	SecondaryUser(int PFA, int PMD, int NumberOfBand);	//Allow you to change the variable 
	~SecondaryUser();
	//void getBandNumber(int BN);							//get the number of bandwidth
	void scanningBands(Band_Details &Bands);				//this function scan for empty bands and store them in vector BandBeingScanned


private:
	int NumberOfBand;									
	double PFA, PMD;									//probability of false alarm and missdetection
	std::vector<int> BandBeingScaned;					//Band Being scanned for SUs and PUs

};

