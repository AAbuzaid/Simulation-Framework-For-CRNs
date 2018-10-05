# Simulation-Framework-For-CRNs
Simulation Framework For CRNs
std::vector <SecondaryUser*> SU;		//SU vector which provied 6 SU6
	SecondaryUser *SUPushing = new SecondaryUser;	//To Push valus to the SU vector
	for (int i = 1; i <= NumberOfSUs; i++)
	{
		SUPushing->scanningBands(Band_Details BandVector); //Here I should enter the band vector that i should scan it (PU vector)
		SU.push_back(SUPushing);
	}
