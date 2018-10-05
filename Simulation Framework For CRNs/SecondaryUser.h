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
	void scanningBands(std::vector<Band_Details> &Bands);				//this function scan for empty bands and store them in vector BandBeingScanned
	void SUsTransmitting();		//All is well let's Tx
	//To output result
	std::vector<int> emptyBands;	// empty bands after sensing
	std::vector<int> SUsOccupantes;		//bands occupented by SU
private:
	int NumberOfBand;									
	double PFA, PMD;													//probability of false alarm and missdetection
	//std::vector<int> BandBeingScaned;									//Band Being scanned for SUs and PUs
	int NumFA;
	int numMD;
	std::vector<int> emptyBands;	// empty bands after sensing
	unsigned int numOfBandsReqForSUs; //Number of bands for SUs 5-15
	std::vector<int> SUsOccupantes;
};

