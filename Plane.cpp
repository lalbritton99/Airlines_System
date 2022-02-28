#include "Plane.h"
#include "Planes.h"
	
extern Planes PC;
	
Plane::Plane() {
	string make = "NO_MAKE";
	int model = -1;
	string tailNum = "NO_TAILNUM";
	int numSeats = -1;
	int range = -1;
	int minCabinCrew = -1;
}

//--------------------------------------------------

void Plane::setTailNum(string input) { //set tailNum if input not already used
	if(PC.searchTailNum(input)) {
		tailNum = input;
	}
}

//--------------------------------------------------

void Plane::print() {
	cout << setw(20) << tailNum << setw(20) << make << setw(20) << model << setw(20) << numSeats << setw(20) << range << setw(20) << minCabinCrew << endl;
}
