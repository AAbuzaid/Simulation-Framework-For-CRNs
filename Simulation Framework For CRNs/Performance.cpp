#include "Performance.h"



Performance::Performance(int timeSlot , double PUprob, int SuccessfulSUID , int numberOfSus)
{
	timeS = double(timeSlot);
	succTxSuId = SuccessfulSUID;
	PuProb = PUprob *100;
	numberOfSUs = double(numberOfSus);
}


void Performance::outputFAFile(const std::vector<double> &PFAvsSU) const
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
void Performance::outputMDFile(const std::vector<double> &MDvsSU) const
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
void Performance::outputCollision(const std::vector<int> &Collision) const
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
void Performance::outputUtilization(const std::vector<int> &utilization) const
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
void Performance::outputThroughput(const std::vector<int> &throughput) const
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
void Performance::outputSuccessfulVsTime(const std::vector<int> &SuccessfulVsTime) const
{
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Successful_VS_Time_FOR_SU(" + std::to_string(succTxSuId)
		+")_Deterministic.csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(SuccessfulVsTime.begin(), SuccessfulVsTime.end(), outputIterator);
	outputFileFAvsSUid.close();
}

void Performance::outputSuccSUTrans(const std::vector<int> &succSUTrans) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(succSUTrans.begin(), succSUTrans.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileSuccessfulvsSUid;
	outputFileSuccessfulvsSUid.open("SuccessfulTransmission_VS_BAND_FOR_ALLSUs_PPU(." + std::to_string(PuProb) +").csv");
	std::ostream_iterator<double> outputIterator(outputFileSuccessfulvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileSuccessfulvsSUid.close();
}
void Performance::outputPUInterference(const std::vector<double> &PUInterfere) const
{
	std::ofstream outputFilePUInterfere;
	outputFilePUInterfere.open("PU_Interference_ratio_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFilePUInterfere, "\n");
	std::copy(PUInterfere.begin(), PUInterfere.end(), outputIterator);
	outputFilePUInterfere.close();
}
void Performance::outputChangingLoad(const std::vector<int> &loadsVsSucc) const
{
	double tS = timeS * numberOfSUs;
	std::vector<double> oFile;
	std::transform(loadsVsSucc.begin(), loadsVsSucc.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileSuccessfulvsSUid;
	outputFileSuccessfulvsSUid.open("SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileSuccessfulvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileSuccessfulvsSUid.close();
}
void Performance::outputFAFileCoop(const std::vector<double> &PFAvsSUCoop) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(PFAvsSUCoop.begin(), PFAvsSUCoop.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("PFA_VS_SUID_FOR_ALLBANDs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputMDFileCoop(const std::vector<double> &MDAvsSUCoop) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(MDAvsSUCoop.begin(), MDAvsSUCoop.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("PMD_VS_SUID_FOR_ALLBANDs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputCollisionCoop(const std::vector<int> &Collision) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(Collision.begin(), Collision.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Collision_VS_SUID_FOR_ALLBANDs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputUtilizationCoop(const std::vector<int> &utilization) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(utilization.begin(), utilization.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Utilization_VS_BAND_FOR_ALLSUs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputThroughputCoop(const std::vector<int> &throughput) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(throughput.begin(), throughput.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("THROUGHPUT_VS_BAND_FOR_ALLSUs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileFAvsSUid.close();
}
void Performance::outputSuccessfulVsTimeCoop(const std::vector<int> &SuccessfulVsTime) const
{
	std::ofstream outputFileFAvsSUid;
	outputFileFAvsSUid.open("Successful_VS_Time_FOR_SU(" + std::to_string(succTxSuId)
		+ ")_Deterministic_Coop.csv");
	std::ostream_iterator<double> outputIterator(outputFileFAvsSUid, "\n");
	std::copy(SuccessfulVsTime.begin(), SuccessfulVsTime.end(), outputIterator);
	outputFileFAvsSUid.close();
}

void Performance::outputSuccSUTransCoop(const std::vector<int> &succSUTrans) const
{
	double tS = timeS;
	std::vector<double> oFile;
	std::transform(succSUTrans.begin(), succSUTrans.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileSuccessfulvsSUid;
	outputFileSuccessfulvsSUid.open("SuccessfulTransmission_VS_BAND_FOR_ALLSUs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileSuccessfulvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileSuccessfulvsSUid.close();
}
void Performance::outputPUInterferenceCoop(const std::vector<double> &PUInterfere) const
{
	std::ofstream outputFilePUInterfere;
	outputFilePUInterfere.open("PU_Interference_ratio_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFilePUInterfere, "\n");
	std::copy(PUInterfere.begin(), PUInterfere.end(), outputIterator);
	outputFilePUInterfere.close();
}
void Performance::outputChangingLoadCoop(const std::vector<int> &loadsVsSucc) const
{
	double tS = timeS * numberOfSUs;
	std::vector<double> oFile;
	std::transform(loadsVsSucc.begin(), loadsVsSucc.end(), std::back_inserter(oFile),
		[tS](int num) {return num / tS; }); //this function divide all element in vector
	std::ofstream outputFileSuccessfulvsSUid;
	outputFileSuccessfulvsSUid.open("SuccessfulTransmission_VS_CHNANGING_LOADS_FOR_ALLSUs_Coop_PPU(." + std::to_string(PuProb) + ").csv");
	std::ostream_iterator<double> outputIterator(outputFileSuccessfulvsSUid, "\n");
	std::copy(oFile.begin(), oFile.end(), outputIterator);
	outputFileSuccessfulvsSUid.close();
}