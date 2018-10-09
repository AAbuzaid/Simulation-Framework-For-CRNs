#include "Performance.h"



Performance::Performance(double timeSlot)
{
	timeS = timeSlot;
}


void Performance::outputFAFile(const std::vector<int> &PFAvsSU)
{	
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(PFAvsSU.begin(), PFAvsSU.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS;}); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("PFA_VS_SUID_FOR_ALLBANDs.csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
}
