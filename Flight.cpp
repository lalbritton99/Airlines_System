#include "Flight.h"
#include "Plane.h"
#include "Planes.h"

Flight::Flight() {
	int ID = -1; 
	string tailNum = "NO_TAILNUM";
	int numPilots = -1;
	int numCabinCrew = -1;
	time_t startTime = -1;
	time_t endTime = -1 ;
	string startLoc = "NO_STARTLOC";
	string endLoc = "NO_ENDLOC";
	int numPassengers = -1;
	string status = "NO_STATUS";
}

//---------------------------------------

int Flight::searchPID(int PID) { //return index if found, return -1 if not found
	int index = 0;
	for(vector<int>::iterator itr = pilotIDs.begin(); itr != pilotIDs.end(); ++itr) {
		if(*itr == PID) {
			return index;
		}
		index++;
	}
	return -1;
}	

//---------------------------------------

int Flight::searchPIDByIndex(int index) { //return PID if found, return -1 if not found
	return (pilotIDs.at(index));
}	

//---------------------------------------
	
void Flight::addPID(int PID) { //adds ID to list of pilots 
	if(this->searchPID(PID) < 0) {
		pilotIDs.push_back(PID);
	}
	else {
		cout << "ERROR: Pilot ID#:" << PID << " in use" << endl;
	}
}

//---------------------------------------

void Flight::removePID(int PID) { //finds pilot ID and removes from list if exists
	int index = this->searchPID(PID);
	
	if(index >= 0) {
		vector<int>::iterator itr = pilotIDs.begin(); //set iterator to correct index
		for(int i=0; i < index; i++) {
			itr++;
		}
		
		pilotIDs.erase(itr);
	}
	else {
		cout << "ERROR: Pilot ID#:" << PID << " does not exist" << endl;
	}
}

//---------------------------------------

int Flight::searchCPID(int CPID) { //return index if found, return -1 if not found
	int index = 0;
	for(vector<int>::iterator itr = coPilotIDs.begin(); itr != coPilotIDs.end(); ++itr) {
		if(*itr == CPID) {
			return index;
		}
		index++;
	}
	return -1;
}

//---------------------------------------

int Flight::searchCPIDByIndex(int index) { //return CPID if found, return -1 if not found
	return (coPilotIDs.at(index));
}

//---------------------------------------
	
void Flight::addCPID(int CPID) { //adds ID to list of copilots 
	if(this->searchCPID(CPID) < 0) {
		coPilotIDs.push_back(CPID);
	}
	else {
		cout << "ERROR: Co-Pilot ID#:" << CPID << " in use" << endl;
	}
}

//---------------------------------------

void Flight::removeCPID(int CPID) { //finds pilot ID and removes from list if exists
	int index = this->searchCPID(CPID);
	
	if(index >= 0) {
		vector<int>::iterator itr = coPilotIDs.begin(); //set iterator to correct index
		for(int i=0; i < index; i++) {
			itr++;
		}
		
		coPilotIDs.erase(itr);
	}
	else {
		cout << "ERROR: Co-Pilot ID#:" << CPID << " does not exist" << endl;
	}
}

//---------------------------------------

int Flight::searchCCID(int CCID) { //return index if found, return -1 if not found
	int index = 0;
	for(vector<int>::iterator itr = cabinCrewIDs.begin(); itr != cabinCrewIDs.end(); ++itr) {
		if(*itr == CCID) {
			return index;
		}
		index++;
	}
	return -1;
}

//---------------------------------------

int Flight::searchCCIDByIndex(int index) { //return CCID if found, return -1 if not found
	return (cabinCrewIDs.at(index));
}

//---------------------------------------

void Flight::addCCID(int CCID) { //adds ID to list of cabin crew  
	if(this->searchCCID(CCID) < 0) {
		cabinCrewIDs.push_back(CCID);
	}
	else {
		cout << "ERROR: Cabin crew ID#:" << CCID << " in use" << endl;
	}
}

//---------------------------------------

void Flight::removeCCID(int CCID) { //finds pilot ID and removes from list if exists
	int index = this->searchCCID(CCID);
	
	if(index >= 0) {
		vector<int>::iterator itr = cabinCrewIDs.begin(); //set iterator to correct index
		for(int i=0; i < index; i++) {
			itr++;
		}
		
		cabinCrewIDs.erase(itr);
	}
	else {
		cout << "ERROR: Cabin crew ID#:" << CCID << " does not exist" << endl;
	}
}

//---------------------------------------



//---------------------------------------



//---------------------------------------

void Flight::print() {
	string startTimeStr = ctime(&startTime); //usable string for start time
	startTimeStr.erase(startTimeStr.end() - 1);
	string endTimeStr = ctime(&endTime); //usable string for end time
	endTimeStr.erase(endTimeStr.end() - 1);
	
	cout << setw(20) << ID << setw(20) << tailNum << setw(20) << 2*numPilots << setw(20) << numCabinCrew << setw(30) << startTimeStr << setw(30) << endTimeStr << setw(20) << startLoc << setw(20) << endLoc << setw(20) << numPassengers << setw(20) << status << endl;
}

//helper functions

bool Flight::crewInFlight(int ID) { //returns true if ID is in a crew vector, false in not
	for(vector<int>::iterator itr = pilotIDs.begin(); itr != pilotIDs.end(); ++itr) {
		if(*itr == ID) {
			return true;
		}
	}
	for(vector<int>::iterator itr = coPilotIDs.begin(); itr != coPilotIDs.end(); ++itr) {
		if(*itr == ID) {
			return true;
		}
	}
	for(vector<int>::iterator itr = cabinCrewIDs.begin(); itr != cabinCrewIDs.end(); ++itr) {
		if(*itr == ID) {
			return true;
		}
	}
	return false;
}

