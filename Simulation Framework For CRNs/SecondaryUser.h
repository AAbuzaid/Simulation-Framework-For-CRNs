#pragma once
#include <vector>
#include "Band_Details.h"
#include <iostream>
#include <algorithm>


class SecondaryUser
{
public:
	SecondaryUser();
	SecondaryUser(double PFA, double PMD, int NumberOfBand , int SUN);	//Allow you to change the variable 
	~SecondaryUser() {};
	//void getBandNumber(int BN);							//get the number of bandwidth
	void scanningBands(const std::vector<Band_Details*> &Bands);	//this function scan for empty bands and store them 
															//in vector BandBeingScanned
	void SUsTransmitting(std::vector<Band_Details*> &Bands);		//All is well let's Tx		
	void emptyAllResult();
	//To output result
	std::vector<int> emptyBands;	// empty bands after sensing
	std::vector<int> SUsOccupants;		//bands occupented by SU
	std::vector<int> NumFA;
	std::vector<int> numMD;
	
private:
	int NumberOfBand;									
	double PFA, PMD;													//probability of false alarm and missdetection
	//std::vector<int> BandBeingScaned;									//Band Being scanned for SUs and PUs
	
	unsigned int numOfBandsReqForSUs; //Number of bands for SUs 5-15
};

