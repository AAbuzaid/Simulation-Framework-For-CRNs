//This is a function is used for calculating SU sucessful transmission  Versus the Time 
//each SU will have a cashed value for each time slot 
//dont use anything BUUT unisgend integers while working with vectors parameters as it will give you error 
//the command .push_back will add an element to the vector and expand the size of the vector 
// .size() command will deal with the size of the vector to use it as a parameter in the loops in calcualting 
// .begin () will make the pointer in the compiler begin at the first elemnt in the vector if zero or any postive integer
// .insert ==> is the command to put the information about the bands in it. 
// and it syntax is..... [ .insert(nameofthevector.begin() ,+vector),, where +vector is the data given from the SU


#include <iostream>
#include <vector> 

unsigned int NumberOfBandsNeededforSU = 5;
double NumberOfTimeSlots =2000; // please set the time slots you desire 
vector <int> SUNumber4SucessfullBands; // real time values for bands 1's or 0's 
vector <int> SUSucceNumberofBandsForEachSlot; //// this will tak the recent time slot scan result added to the old ones to help calculations 
unsigned int BandsCapacityForSU4 =5 ;
using namespace std;
unsigned int thevaluefromthesensing;
unsigned int oldvaluefromcash;
unsigned int newcashvalue;
unsigned int BandsPerAllSlots = ((NumberOfTimeSlots) *NumberOfBandsNeededforSU); //As this will give us slots inside each time slot to describe the time slot band reservation 


int main()
{	
		for (unsigned int j = 0; j < BandsPerAllSlots; j++) {

			thevaluefromthesensing = SUNumber4SucessfullBands.at(j);

			newcashvalue = thevaluefromthesensing;
			

			SUSucceNumberofBandsForEachSlot.push_back(newcashvalue)

		};

	

	//printing SU sucessful transmission  Calculations results Vs Time for SU4


	cout << "SU sucessful transmission Vs Time For SU4 " << endl; 
	for (unsigned int f = 0; f < SUSucceNumberofBandsForEachSlot.size(); f++) {
		cout << SUSucceNumberofBandsForEachSlot[f] << "";
	};

	







}



