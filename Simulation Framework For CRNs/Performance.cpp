#include "Performance.h"



Performance::Performance(double timeSlot , double PUprob, int SuccessfulSUID)
{
	timeS = timeSlot;
	succTxSuId = SuccessfulSUID;
	PuProb = PUprob *100;
}


void Performance::outputFAFile(const std::vector<int> &PFAvsSU)
{	
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(PFAvsSU.begin(), PFAvsSU.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS;}); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("PFA_VS_SUID_FOR_ALLBANDs_PPU(."+std::to_string(PuProb)+").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputMDFile(const std::vector<int> &MDvsSU)
{
	
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(MDvsSU.begin(), MDvsSU.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("PMD_VS_SUID_FOR_ALLBANDs_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputCollision(const std::vector<int> &Collision)
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(Collision.begin(), Collision.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Collision_VS_SUID_FOR_ALLBANDs_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputUtilization(const std::vector<int> &utilization)
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(utilization.begin(), utilization.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Utilization_VS_BAND_FOR_ALLSUs_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputThroughput(const std::vector<int> &throughput)
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(throughput.begin(), throughput.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("THROUGHPUT_VS_BAND_FOR_ALLSUs_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputSuccessfulVsTime(const std::vector<unsigned int> &SuccessfulVsTime)
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(SuccessfulVsTime.begin(), SuccessfulVsTime.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Successful_VS_Time_FOR_SU(" + std::to_string(succTxSuId)
		+")_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}

void Performance::outputSuccSUTrans(const std::vector<int> &succSUTrans)
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(succSUTrans.begin(), succSUTrans.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("SuccessfulTransmission_VS_BAND_FOR_ALLSUs_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
