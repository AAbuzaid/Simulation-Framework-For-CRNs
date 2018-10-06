#pragma once
#include<vector>
class FusionCenter
{
public:
	FusionCenter(int SUsN, int NBands, int maxSUBand);
	~FusionCenter();
	void getSUsIds(int ID);
	void getEmptyBands(const std::vector<int> &Bands); //band that did't have PUs in it
	void bandsOccupiedBySU(const std::vector<int> &suBand);

private:
	int SuId;
	//int **emptyBands;
	//int **bandOccupanted;
	int NumberOfSUs;
	int NumberOfBands;
	int maxSUsband;
	std::vector<std::vector<int>> emptyBands;
	std::vector<std::vector<int>> bandOccupanted;
};

