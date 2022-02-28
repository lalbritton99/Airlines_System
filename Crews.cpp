#include "Crew.h"
#include "Crews.h"
#include "Flight.h"
#include "Flights.h"

extern Flights FC;

Crews::Crews() {
	crewCount = 0;
}

void Crews::addCrew() {
	Crew tempCrew;
	int tempID;
	string tempName, tempCrewType;
	
	cout << "Please input a crew member ID#: ";
	cin  >> tempID;
	if(!(this->searchID(tempID))) {
		cout << "ERROR: ID#" << tempID << " in use" << endl;
		return;
	}
	tempCrew.setID(tempID);
	
	cout << "Please input the crew member's name: ";
	cin  >> tempName;
	tempCrew.setName(tempName);
	
	cout << "1. Pilot" << endl;
	cout << "2. Co-Pilot" << endl;
	cout << "3. Cabin-Crew" << endl;
	cout << "Please input the crew member's type: ";
	int choice;
	cin  >> choice;
	switch(choice) {
		case 1:
			tempCrewType = "Pilot";
			break;
		
		case 2:
			tempCrewType = "Co-Pilot";
			break;
			
		case 3:
			tempCrewType = "Cabin-Crew";
			break;
			
		default:
			cout << "Incorrect input. Please choose from menu." << endl << endl;
			break;
		
	}
	tempCrew.setCrewType(tempCrewType);
	
	crewVec.push_back(tempCrew);
	crewCount++;
}

void Crews::deleteCrew() {
	int tempID;
	cout << "Please input crew member's ID# to delete: ";
	cin  >> tempID;
	
	if(FC.flightVecContainCrew(tempID)) {  //if plane is in flights
		cout << "ERROR: Crew Member is curently booked in a flight/flights";
		return;
	}
	
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) { //find plane and remove
		if (itr->getID() == tempID) {
			crewVec.erase(itr);
			crewCount--;
			return;
		}
	}
	cout << "ERROR: Crew member ID#" << tempID << " does not exist" << endl;
}

void Crews::editCrew() {
	int tempID;
	cout << "Please input crew member's ID to edit: ";
	cin  >> tempID;
	
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) { //find plane and edit
		if (itr->getID() == tempID) {
			int choice1, choice2;
			string tempName, tempCrewType;
			cout << "--------------------  EDIT:  --------------------" << endl;
			cout << "1. Edit name" << endl;
			cout << "2. Edit crew type" << endl;
			cout << "Please enter choice: ";
			cin  >> choice1;
			
			switch(choice1) {
				case 1: 
					cout << "New name: ";
					cin  >> tempName;
					itr->setName(tempName);
					break;
				
				case 2: 
					cout << "1. Pilot" << endl;
					cout << "2. Co-Pilot" << endl;
					cout << "3. Cabin-Crew" << endl;
					cout << "Please input the crew member's type: ";
					cin  >> choice2;
					
					switch(choice2) {
						case 1:
							tempCrewType = "Pilot";
							break;
		
						case 2:
							tempCrewType = "Co-Pilot";
							break;
			
						case 3:
							tempCrewType = "Cabin-Crew";
							break;
			
						default:
							cout << "Incorrect input. Please choose from menu." << endl << endl;
							break;
					
					}
					itr->setCrewType(tempCrewType);
					break;
					
				default:
					cout << "Incorrect input. Please choose from menu." << endl << endl;
					break;
			}
			return;
		}
	}
}

void Crews::printCrews() {
	cout << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "CREW TYPE" << endl;
	
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) {
		itr->print();
	}
	cout << endl;
}

void Crews::printCrewFromVec() {
	int tempID;
	
	cout << "Input crew member's ID#: ";
	cin  >> tempID;
	
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) {
		if((itr->getID()) == tempID) {
			cout << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "CREW TYPE" << endl;
			itr->print();
			cout << endl;
			
			return;
		}
	}
	cout << "ERROR: ID#" << tempID << " not found" << endl << endl;
}

void Crews::loadData() {
	ifstream fin;
	fin.open("Crews.dat");
	
	if(fin) {
		Crew tempCrew;		//temp variables for setting data
		int tempCrewCount, tempID;
		string tempName, tempCrewType;
		
		fin >> tempCrewCount;
		this->setCrewCount(tempCrewCount);
		fin.ignore();
		
		for(int i=0; i<crewCount; i++) {  //inputs crew data: crews delemited by line, data delimited by space
			fin >> tempID >> tempName >> tempCrewType;
			fin.ignore();
			
			tempCrew.setID(tempID);
			tempCrew.setName(tempName);
			tempCrew.setCrewType(tempCrewType);
			
			crewVec.push_back(tempCrew);
		}
	}

	fin.close();
}

void Crews::storeData() {
	ofstream fout;
	fout.open("Crews.dat", ios::out | ios::trunc); //opens and clears file
	
	fout << crewCount << endl;
	
	for (vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) {  //stores Course data: courses delemited by line, data delimited by space
		fout << itr->getID() << " " << itr->getName() << " " << itr->getCrewType() << endl;
	}
	
	fout.close();
}

//helper functions

int Crews::searchID(int inputID) { //print and returns 0 if ID exists, returns 1 if not
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) { //loop through all planes in colection
		if ((*itr).getID() == inputID) { //check for ID
			//cout << "ERROR: ID#" << inputID << " in use" << endl;
			return 0;
		}
	}
	return 1;
}

bool Crews::isPilot(int inputID) { //returns true if ID is pilot, returns false if not
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) { //loop through all planes in colection
		if ((itr->getID() == inputID)&&(itr->getCrewType() == "Pilot")) { //check for ID and crew type
			return true;
		}
	}
	return false;
}

bool Crews::isCoPilot(int inputID) { //returns true if ID is copilot, returns false if not
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) { //loop through all planes in colection
		if ((itr->getID() == inputID)&&(itr->getCrewType() == "Co-Pilot")) { //check for ID and crew type
			return true;
		}
	}
	return false;
}

bool Crews::isCabinCrew(int inputID) { //returns true if ID is cabin-crew, returns false if not
	for(vector<Crew>::iterator itr = crewVec.begin(); itr != crewVec.end(); ++itr) { //loop through all planes in colection
		if ((itr->getID() == inputID)&&(itr->getCrewType() == "Cabin-Crew")) { //check for ID and crew type
			return true;
		}
	}
	return false;
}
