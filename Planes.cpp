#include "Plane.h"
#include "Planes.h"
#include "Flight.h"
#include "Flights.h"

extern Flights FC;

Planes::Planes() {
	planeCount = 0;
}

void Planes::addPlane() {
	Plane tempPlane;
	string tempMake, tempTailNum;
	int tempModel, tempNumSeats, tempRange, tempMinCabinCrew;
	
	cout << "Please input a plane tail number: ";
	cin  >> tempTailNum;
	if(!(this->searchTailNum(tempTailNum))) {
		return;
	}
	tempPlane.setTailNum(tempTailNum);
	
	cout << "Please input the plane's make: ";
	cin  >> tempMake;
	tempPlane.setMake(tempMake);
	
	cout << "Please input the plane's model: ";
	cin  >> tempModel;
	tempPlane.setModel(tempModel);
	
	cout << "Please input the plane's number of seats: ";
	cin  >> tempNumSeats;
	tempPlane.setNumSeats(tempNumSeats);
	
	cout << "Please input the plane's range (mi.): ";
	cin  >> tempRange;
	tempPlane.setRange(tempRange);
	
	cout << "Please input the plane's minimum crew: ";
	cin  >> tempMinCabinCrew;
	tempPlane.setMinCabinCrew(tempMinCabinCrew);
	
	planeVec.push_back(tempPlane);
	planeCount++;
}

//-------------------------------------------

void Planes::deletePlane() { //remove plane from vector
	string tempTailNum;
	cout << "Please input plane's tail number to delete: ";
	cin  >> tempTailNum;
	
	if(FC.flightVecContainPlane(tempTailNum)) {  //if plane is in no flights
		cout << "ERROR: Plane is curently used in a flight/flights";
		return;
	}
	
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) { //find plane and remove
		if (itr->getTailNum() == tempTailNum) {
			planeVec.erase(itr);
			planeCount--;
			return;
		}
	}
	cout << "ERROR: Plane ID#" << tempTailNum << " does not exist" << endl;
}

//-------------------------------------------

void Planes::editPlane() {
	string tempTailNum;
	cout << "Please input plane's tail number to edit: ";
	cin  >> tempTailNum;
	
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) { //find plane and edit
		if (itr->getTailNum() == tempTailNum) {
			int choice;
			cout << "--------------------  EDIT:  --------------------" << endl;
			cout << "1. Edit number of seats" << endl;
			cout << "2. Edit range" << endl;
			cout << "3. Edit minimum cabin crew" << endl << endl;
			cout << "Please enter choice: ";
			cin  >> choice;
			
			switch(choice) {
				case 1:
					int tempNumSeats;
					cout << "New number of seats: ";
					cin  >> tempNumSeats;
					itr->setNumSeats(tempNumSeats);
					break;
					
				case 2:
					int tempRange;
					cout << "New range: ";
					cin  >> tempRange;
					itr->setRange(tempRange);
					break;
					
				case 3:
					int tempMinCabinCrew;
					cout << "New minimum cabin crew: ";
					cin  >> tempMinCabinCrew;
					itr->setMinCabinCrew(tempMinCabinCrew);
					break;
					
				default:
					cout << "Incorrect input. Please choose from menu." << endl << endl;
					break;
			}
			return;
		}
	}
}

//-------------------------------------------

void Planes::printPlanes() {
	cout << setw(20) << "TAIL NUMBER" << setw(20) << "MAKE" << setw(20) << "MODEL" << setw(20) << "NUMBER OF SEATS" << setw(20) << "RANGE" << setw(20) << "MINIMUM CABIN CREW" << endl;
	
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) {
		itr->print();
	}
	cout << endl;
}

//-------------------------------------------

void Planes::printPlaneFromVec() {
	string tempTailNum;
	
	cout << "Input plane's tail number: ";
	cin  >> tempTailNum;
	
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) {
		if((*itr).getTailNum() == tempTailNum) {
			cout << setw(20) << "TAIL NUMBER" << setw(20) << "MAKE" << setw(20) << "MODEL" << setw(20) << "NUMBER OF SEATS" << setw(20) << "RANGE" << setw(20) << "MINIMUM CABIN CREW" << endl;
			itr->print();
			cout << endl;
			
			return;
		}
	}
	cout << "ERROR: Tail number not found" << endl << endl;
}

//-------------------------------------------

void Planes::loadData() {
	ifstream fin;
	fin.open("Planes.dat");
	
	if(fin) {
		Plane tempPlane;		//temp variables for setting data
		int tempPlaneCount, tempModel, tempNumSeats, tempRange, tempMinCabinCrew;
		string tempTailNum, tempMake;
		
		fin >> tempPlaneCount;
		this->setPlaneCount(tempPlaneCount);
		fin.ignore();
		
		for(int i=0; i<planeCount; i++) {  //inputs plane data: planes delemited by line, data delimited by space
			fin >> tempTailNum >> tempMake >> tempModel >> tempNumSeats >> tempRange >> tempMinCabinCrew;
			fin.ignore();
			
			tempPlane.setTailNum(tempTailNum);
			tempPlane.setMake(tempMake);
			tempPlane.setModel(tempModel);
			tempPlane.setNumSeats(tempNumSeats);
			tempPlane.setRange(tempRange);
			tempPlane.setMinCabinCrew(tempMinCabinCrew);
		
			planeVec.push_back(tempPlane);
		}
	}

	fin.close();
}

//-------------------------------------------

void Planes::storeData() {
	ofstream fout;
	fout.open("Planes.dat", ios::out | ios::trunc); //opens and clears file
	
	fout << planeCount << endl;
	
	for (vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) {  //stores Course data: courses delemited by line, data delimited by space
		fout << itr->getTailNum() << " " << itr->getMake() << " " << itr->getModel() << " " << itr->getNumSeats() << " " << itr->getRange() << " " << itr->getMinCabinCrew() << endl;
	}
	
	fout.close();
}


//HELPER FUNCTIONS --------------------------------------------------------------------------------------------


int Planes::searchTailNum(string inputTailNum) { //print and returns 0 if ID exists, returns 1 if not

	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) { //loop through all planes in colection
		if ((*itr).getTailNum() == inputTailNum) { //check for ID
			cout << "ERROR: ID#" << inputTailNum << " in use" << endl;
			return 0;
		}
	}
	return 1;
}

//-------------------------------------------

bool Planes::tailNumInUse(string tailNum) {
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) { //loop through all planes in colection
		if ((*itr).getTailNum() == tailNum) { //check for ID
			return true;
		}
	}
	cout << "ERROR: ID#" << tailNum << " not found" << endl;
	return false;
}

//-------------------------------------------

int Planes::getMinCabinCrewFromCol(string tailNum) {
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); ++itr) {
		if ((itr->getTailNum()) == tailNum) {
			return (itr->getMinCabinCrew());
		}
	}
	return -1;
}

//-------------------------------------------

int Planes::getNumSeats(string tailNum) {
	for(vector<Plane>::iterator itr = planeVec.begin(); itr != planeVec.end(); itr++) {
		if(itr->getTailNum() == tailNum) {
			return (itr->getNumSeats());
		}
	}
	return -1;
}

//-------------------------------------------



//-------------------------------------------


