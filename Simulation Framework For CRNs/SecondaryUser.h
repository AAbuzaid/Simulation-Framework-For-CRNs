#pragma once
#include <vector>
#include "Band_Details.h"
#include <iostream>
#include <algorithm>
#include <iterator>
class SecondaryUser
{
public:
	SecondaryUser();
	SecondaryUser(double PFA, double PMD, int NumberOfBand , int SUN , bool );	//Allow you to change the variable 
	~SecondaryUser() {};
	//void getBandNumber(int BN);							//get the number of bandwidth
	void scanningBands(const std::vector<Band_Details> &Bands, double activePUTime ,int SUID);	//this function scan for empty bands and store them 
															//in vector BandBeingScanned
	void SUsTransmitting(std::vector<Band_Details> &Bands,int SUID, const std::vector<int> &loadReq);		//All is well let's Tx		
	void SuDeterministicSensing(std::vector<int> &band);
	void emptyAllResult();
	void emptyFAandMD();
	void successfulVSTime(std::vector<DeterministicBand> &Bands, double &succVsTimeN, double T , int SUID);
	void SUsTxCooparitive(std::vector<Band_Details> &Bands, int SUID, std::vector<int> &emptyBandsCooparitive);
	//To output result
	std::vector<int> emptyBands;	// empty bands after sensing
	std::vector<int> SUsOccupants;		//bands occupented by SU
	std::vector<int> SUsOccupantsCoop;		//bands occupented by SU
	std::vector<int> changeLoads;
	//std::vector<std::vector<int>> occupentsLoads;
	std::vector<double> NumFACoop;
	std::vector<double> NumMDCoop;
	std::vector<double> currentFA;
	std::vector<double> currentMD;
	double FaVsSUId = 0;
	double MdVsSUId = 0;




private:
	int NumberOfBand;									
	double PFA, PMD;													//probability of false alarm and missdetection
	//std::vector<int> BandBeingScaned;									//Band Being scanned for SUs and PUs
	unsigned int count = 0;
	 int numOfBandsReqForSUs; //Number of bands for SUs 5-15
	 int randomBand;
	 int lInc;
	 std::vector<int> pick;
	 bool coop;
	 double NumFA = 0;
	 double NumMD = 0;
};

