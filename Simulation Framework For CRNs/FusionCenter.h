#pragma once
#include<vector>
#include"Band_Details.h"
#include<algorithm>
#include<iterator>
class FusionCenter
{
public:
	FusionCenter(int SUsN, int NBands, int maxSUBand);
	~FusionCenter();
	void getSUsIds(int ID);
	void getEmptyBands(const std::vector<int> &Bands); //band that did't have PUs in it
	void bandsOccupantedBySU(const std::vector<int> &suBand);
	void collision(const std::vector<int> &PU);	//return int vector of collision vs su

private:
	int SuId;
	//int **emptyBands;
	//int **bandOccupanted;
	int NumberOfSUs;
	int NumberOfBands;
	int maxSUsband;
	std::vector<std::vector<int>> emptyBands;
	std::vector<std::vector<int>> bandOccupanted;
	std::vector<int> collisionVsSuN;
	
};

