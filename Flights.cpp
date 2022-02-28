#include "Flight.h"
#include "Flights.h"
#include "Crew.h"
#include "Crews.h"
#include "Plane.h"
#include "Planes.h"

extern Crews CC;
extern Planes PC;

Flights::Flights() {
	flightCount = 0;
}

//-------------------------------------------

void Flights::addFlight() {
	Flight tempFlight;
	int tempID, tempNumPassengers, tempCrewID;
	string tempTailNum, tempStartApt, tempEndApt, tempStatus;
	time_t timeDiff;
	tm timeInput;
	
	
	//**************************
	
	
	//set flight ID
	
	cout << endl << "Please input a flight ID#: ";
	cin  >> tempID;
	if(this->IDInUse(tempID)) {
		return;
	}
	tempFlight.setID(tempID);
	
	
	//**************************
	
	
	//set time of flight
	
	cout << endl << "Please input flight start year: ";  //set start time
	cin  >> timeInput.tm_year; timeInput.tm_year -= 1900;
	cout << "Please input flight start month #: ";
	cin  >> timeInput.tm_mon;  timeInput.tm_mon -= 1;
	cout << "Please input flight start day #: ";
	cin  >> timeInput.tm_mday;
	cout << "Please input flight start hour: ";
	cin  >> timeInput.tm_hour;
	cout << "Please input flight start miniute: ";
	cin  >> timeInput.tm_min;
	timeInput.tm_sec = 0;
	
	tempFlight.setStartTime(mktime(&timeInput)); // changes time struct to epoch number for start time
	
	cout << endl << "Please input flight end year: ";  //set end time
	cin  >> timeInput.tm_year; timeInput.tm_year -= 1900;
	cout << "Please input flight end month #: ";
	cin  >> timeInput.tm_mon; timeInput.tm_mon -= 1;
	cout << "Please input flight end day #: ";
	cin  >> timeInput.tm_mday;
	cout << "Please input flight end hour: ";
	cin  >> timeInput.tm_hour;
	cout << "Please input flight end miniute: ";
	cin  >> timeInput.tm_min;
	timeInput.tm_sec = 0;
	cout << endl;
	
	tempFlight.setEndTime(mktime(&timeInput)); // changes time struct to epoch number for end time
	
	timeDiff = difftime(tempFlight.getEndTime(), tempFlight.getStartTime()); //sets flight durration
	
	
	//**************************
	
	
	//add plane to flight
	
	do { //input valid plane
		cout << "Please input a plane tail number: ";
		cin  >> tempTailNum;
	} while(!(PC.tailNumInUse(tempTailNum)));
	
	//check if time conflicts and set plane
	for (vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if(itr->getTailNum() == tempTailNum) {
			if((itr->getStartTime() >= tempFlight.getStartTime())&&(itr->getStartTime() <= tempFlight.getEndTime())) { //if start time overlaps
				cout << "ERROR: Plane is already scheduled during that time" << endl;
				return;
			}
			else if((itr->getEndTime() >= tempFlight.getStartTime())&&(itr->getEndTime() <= tempFlight.getEndTime())) { //if end time overlaps
				cout << "ERROR: Plane is already scheduled during that time" << endl;
				return;
			}
		}
	}
	tempFlight.setTailNum(tempTailNum);
	
	
	//**************************
	
	
	//set minimum crew depending on durration
	
	if(timeDiff >= 28800) { //if flight over 8hrs
		tempFlight.setNumPilots(2);
		tempFlight.setNumCabinCrew(2*(PC.getMinCabinCrewFromCol(tempTailNum)));
	}
	else //if flight under 8 hours
	{
		tempFlight.setNumPilots(1);
		tempFlight.setNumCabinCrew(PC.getMinCabinCrewFromCol(tempTailNum));
	}
	
	
	//**************************
	
	
	//set all crew members
	
	for(int i=0; i<tempFlight.getNumPilots(); i++) { //adds # of pilots
		do {
			cout << endl << "Please enter a Pilot ID# to add to flight: ";
			cin  >> tempCrewID;
			
			if(CC.isPilot(tempCrewID)) { //input is a pilot
				for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
					if((itr->searchPID(tempCrewID) >= 0)) { //pilot is in flight 	
						if((itr->getStartTime() > tempFlight.getStartTime())&&(itr->getEndTime() > tempFlight.getStartTime())) { //if flight is after
							tempFlight.addPID(tempCrewID);
							cout << "Pilot Added." << endl;
							break;
						}
						else if ((itr->getStartTime() < tempFlight.getStartTime())&&(itr->getEndTime() < tempFlight.getStartTime())) { //if flight is before
							tempFlight.addPID(tempCrewID);
							cout << "Pilot Added." << endl;
							break;
						}
						else {
							cout << "ERROR: Pilot has conflicting schedule" << endl;
						}
					}
				}
				
				if(flightVec.size() == 0) { //in no flights to check yet
					if(!(tempFlight.crewInFlight(tempCrewID))) {
						tempFlight.addPID(tempCrewID);
						cout << "Pilot Added." << endl;
					}
					else {
						cout << "ERROR: Pilot has conflicting schedule" << endl;
					}
				}
			}
			else {
				cout << "ERROR: ID#" << tempCrewID << " is not a pilot" << endl;
			}
		} while (!(CC.isPilot(tempCrewID)));
	}
	
	
	for(int i=0; i<tempFlight.getNumPilots(); i++) { //adds # of Copilots
		do {
			cout << endl << "Please enter a CoPilot ID# to add to flight: ";
			cin  >> tempCrewID;
			
			if(CC.isCoPilot(tempCrewID)) { //input is a Copilot
				for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
					if((itr->searchCPID(tempCrewID) >= 0)) { //Copilot is in flight 	
						if((itr->getStartTime() > tempFlight.getStartTime())&&(itr->getEndTime() > tempFlight.getStartTime())) { //if flight is after
							tempFlight.addCPID(tempCrewID);
							cout << "Co-Pilot Added." << endl;
							break;
						}
						else if ((itr->getStartTime() < tempFlight.getStartTime())&&(itr->getEndTime() < tempFlight.getStartTime())) { //if flight is before
							tempFlight.addCPID(tempCrewID);
							cout << "Co-Pilot Added." << endl;
							break;
						}
						else {
							cout << "ERROR: Co-Pilot has conflicting schedule" << endl;
						}
					}
				}
				
				if(flightVec.size() == 0) { //in no flights to check yet
					if(!(tempFlight.crewInFlight(tempCrewID))) {
						tempFlight.addCPID(tempCrewID);
						cout << "Co-Pilot Added." << endl;
					}
					else {
						cout << "ERROR: Co-Pilot has conflicting schedule" << endl;
					}
				}
			}
			else {
				cout << "ERROR: ID#" << tempCrewID << " is not a Co-pilot" << endl;
			}
		} while (!(CC.isCoPilot(tempCrewID)));
	}
	

	for(int i=0; i<tempFlight.getNumCabinCrew(); i++) { //adds # of cabin crew
		do {
			cout << endl << "Please enter a Cabin Crew ID# to add to flight: ";
			cin  >> tempCrewID;
			
			if(CC.isCabinCrew(tempCrewID)) { //input is a pilot
				for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
					if((itr->searchCCID(tempCrewID) >= 0)) { //pilot is in flight 	
						if((itr->getStartTime() > tempFlight.getStartTime())&&(itr->getEndTime() > tempFlight.getStartTime())) { //if flight is after
							tempFlight.addCCID(tempCrewID);
							cout << "Cabin-Crew Added." << endl;
							break;
						}
						else if ((itr->getStartTime() < tempFlight.getStartTime())&&(itr->getEndTime() < tempFlight.getStartTime())) { //if flight is before
							tempFlight.addCCID(tempCrewID);
							cout << "Cabin-Crew Added." << endl;
							break;
						}
						else {
							cout << "ERROR: Cabin-Crew has conflicting schedule" << endl;
						}
					}
				}
				
				if(flightVec.size() == 0) { //in no flights to check yet
					if(!(tempFlight.crewInFlight(tempCrewID))) {
						tempFlight.addCCID(tempCrewID);
						cout << "Cabin-Crew Added." << endl;
					}
					else {
						cout << "ERROR: Cabin-Crew has conflicting schedule" << endl;
					}
				}
			}
			else {
				cout << "ERROR: ID#" << tempCrewID << " is not a Cabin-Crew" << endl;
			}
		} while (!(CC.isCabinCrew(tempCrewID)));
	}
	
	
	//**************************
	
	
	//Add flight start and end locations
	
	cout << endl << "Please enter 3-letter airport code for departure: ";
	cin  >> tempStartApt;
	
	do {
		cout << "Please enter 3-letter airport code for arrival: ";
		cin  >> tempEndApt;
	} while(tempEndApt == tempStartApt);
	
	tempFlight.setStartLoc(tempStartApt);
	tempFlight.setEndLoc(tempEndApt);
	
	
	//**************************
	
	
	//set number of passengers initially on flight
	
	do {
		cout << endl << "Please input number of passengers: ";
		cin  >> tempNumPassengers;
		if(tempNumPassengers > PC.getNumSeats(tempFlight.getTailNum())) {
			cout << "ERROR: Passengers > Seats" << endl;
		}
	} while(tempNumPassengers > PC.getNumSeats(tempFlight.getTailNum()));
	tempFlight.setNumPassengers(tempNumPassengers);
	
	
	//**************************
	
	
	//set flight status
	
	if(time(0) > tempFlight.getEndTime()) { //if flights end time has past 
		tempFlight.setStatus("Completed");
	}
	else {
		tempFlight.setStatus("Active");
	}
	
	
	//**************************
	
	//add flight
	
	flightVec.push_back(tempFlight);
	flightCount++;
	cout << endl << "Flight Added." << endl << endl;
}

//-------------------------------------------

void Flights::deleteFlight() { //deletes flight
	int tempID;
	cout << "Please input Flight ID# to delete: ";
	cin  >> tempID;

	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if(itr->getID() == tempID) {
			flightVec.erase(itr);
			flightCount--;
			return;
		}
	}
	cout << "ERROR: Flight ID#" << tempID << " does not exist" << endl;
}

//-------------------------------------------

void Flights::editFlight() {
	
}

//-------------------------------------------

void Flights::printFlights() {
	cout << setw(20) << "ID" << setw(20) << "TAIL NUMBER" << setw(20) << "PILOTS" << setw(20) << "CABIN CREW" << setw(30) << "DEPARTURE TIME" << setw(30) << "ARIVAL TIME" << setw(20) << "FROM" << setw(20) << "TO" << setw(20) << "PASSENGERS" << setw(20) << "STATUS" << endl;
	
	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		itr->print();
	}
	cout << endl;
}

//-------------------------------------------

void Flights::printFlightFromVec() {
	int tempID;
	
	cout << "Input flight's ID#: ";
	cin  >> tempID;
	
	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if((*itr).getID() == tempID) {
			cout << setw(20) << "ID" << setw(20) << "TAIL NUMBER" << setw(20) << "PILOTS" << setw(20) << "CABIN CREW" << setw(30) << "DEPARTURE TIME" << setw(30) << "ARIVAL TIME" << setw(20) << "FROM" << setw(20) << "TO" << setw(20) << "PASSENGERS" << setw(20) << "STATUS" << endl;
			itr->print();
			cout << endl;
			
			return;
		}
	}
	cout << "ERROR: ID#" << tempID << " not found" << endl << endl;
}

//-------------------------------------------

void Flights::printActivePlaneAsignments() {
	
}

//-------------------------------------------

void Flights::printActiveCrewAssignments() {
	
}

//-------------------------------------------

void Flights::printFlightsOfASatus() {
	string tempStatus;
	
	cout << "1. Active" << endl;
	cout << "2. Canceled" << endl;
	cout << "3. Completed" << endl;
	cout << "Please input a status to print flights of (#):";
	int choice;
	cin  >> choice;
	switch(choice) {
		case 1:
			tempStatus = "Active";
			break;
			
		case 2:
			tempStatus = "Canceled";
			break;
			
		case 3:
			tempStatus = "Completed";
			break;
			
		default:
			cout << "Incorrect input. Please choose from menu." << endl << endl;
			return;
	}
	
	cout << endl << setw(20) << "ID" << setw(20) << "TAIL NUMBER" << setw(20) << "PILOTS" << setw(20) << "CABIN CREW" << setw(30) << "DEPARTURE TIME" << setw(30) << "ARIVAL TIME" << setw(20) << "FROM" << setw(20) << "TO" << setw(20) << "PASSENGERS" << setw(20) << "STATUS" << endl;
	
	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if (itr->getStatus() == tempStatus) {
			itr->print();
		}
	}
	cout << endl;
}

//-------------------------------------------

void Flights::deletePastFlights() {
	
}

//-------------------------------------------

void Flights::updateFlightStatuses() {
	
}

//-------------------------------------------

void Flights::loadData() {
	
}

//-------------------------------------------

void Flights::storeData() {
	
}

//helper functions

bool Flights::flightVecContainPlane(string tailNum) { //if plane used in any flights
	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if(itr->getTailNum() == tailNum) {
			return true;
		}
	}
	return false;
}

//-------------------------------------------

bool Flights::flightVecContainCrew(int ID) { //if crew member booked in any flights
	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if(itr->getID() == ID) {
			return true;
		}
	}
	return false;
}

//-------------------------------------------

bool Flights::IDInUse(int ID) {
	for(vector<Flight>::iterator itr = flightVec.begin(); itr != flightVec.end(); ++itr) {
		if(itr->getID() == ID) {
			cout << "ERROR: ID#" << ID << " is in use" << endl;
			return true;
		}
	}
	return false;
}
