/******************************************
NAME: Logan Albritton
COURSE: CSCE 1040
PROJECT: Homework 4
EMAIL: loganalbritton@my.unt.edu
DESCRIPTION: Program runs a menu based scheduling program to manage planes, crew members, and flights
******************************************/

#include "Plane.h" 
#include "Planes.h"
#include "Crew.h"
#include "Crews.h" 
#include "Flight.h"
#include "Flights.h"

#include <iostream>
 
using namespace std;


void storeData(Planes PC, Crews CC, Flights FC);
void loadData(Planes &PC, Crews &CC, Flights &FC);
int load = 0;	//truth val for load function

//global collection objects for planes, crew members, and flights
Planes PC;
Crews CC;
Flights FC;



int main() {
	
	cout << "*****************************" << endl;
	cout << "*       Logan Albritton     *" << endl;
	cout << "*          CSCE 1040        *" << endl;
	cout << "*          Homework 4       *" << endl;
	cout << "* loganalbritton@mt.unt.edu *" << endl;
	cout << "*****************************" << endl << endl;

	loadData(PC, CC, FC); //load in stored data

	int menuChoice1 = -1;
	int menuChoice2;
	
	cout << "Welcome to the Mean Green Airlines Scheduler." << endl << endl;
	
	while (menuChoice1) {
		cout << "--------------------  MENU OPTIONS:  --------------------" << endl;
		cout << "1. Add" << endl;
		cout << "2. Edit" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Find" << endl;
		cout << "5. Print" << endl;
		cout << "6. Print Assignment Schedule" << endl;
		cout << "7. Print Flights of a Status" << endl;
		cout << "8. Delete Past/Canceled Flights" << endl;
		cout << "9. Update Flight Statuses" << endl;
		cout << "0. Exit Scheduler" << endl;
		
		cout << endl << "Please enter choice: ";
		cin  >> menuChoice1;
		
		
		switch(menuChoice1) {
			case 0: //EXIT --------------------------------------------------------------------------------------------
				cout << "Thanks for using the scheduler. Goodbye." << endl;
				break;
				
			case 1: // ADDING AN OBJECT --------------------------------------------------------------------------------------------
				cout << "--------------------  ADD:  --------------------" << endl;
				cout << "1. Add a new plane" << endl;
				cout << "2. Add a new crew member" << endl;
				cout << "3. Add a new flight" << endl;
				
				cout << endl << "Please enter choice: ";
				cin  >> menuChoice2;
				
				switch(menuChoice2) {
					case 1: //ADDING PLANE
						PC.addPlane();
						storeData(PC, CC, FC); //store data
						break;
						
					case 2: //ADDING CREW
						CC.addCrew();
						storeData(PC, CC, FC); //store data
						break;
						
					case 3: //ADDING FLIGHT
						FC.addFlight();
						storeData(PC, CC, FC); //store data
						break;
						
					default: //INCORRECT INPUT
						cout << "Incorrect input. Please choose from menu." << endl << endl;
						break;	
				}
				break;
			
			case 2: //EDIT AN OBJECT --------------------------------------------------------------------------------------------
				cout << "--------------------  EDIT:  --------------------" << endl;
				cout << "1. Edit a plane" << endl;
				cout << "2. Edit a crew member" << endl;
				cout << "3. Edit a flight" << endl;
				
				cout << endl << "Please enter choice: ";
				cin  >> menuChoice2;
				
				switch(menuChoice2) {
					case 1: //EDITING PLANE
						PC.editPlane();
						storeData(PC, CC, FC); //store data
						break;
						
					case 2: //EDITING CREW
						CC.editCrew();
						storeData(PC, CC, FC); //store data
						break;
						
					case 3: //EDITING FLIGHT
						FC.editFlight();
						storeData(PC, CC, FC); //store data
						break;
						
					default: //INCORRECT INPUT
						cout << "Incorrect input. Please choose from menu." << endl << endl;
						break;	
				}
				break;
				
			case 3: //DELETING AN OBJECT --------------------------------------------------------------------------------------------
				cout << "--------------------  DELETE:  --------------------" << endl;
				cout << "1. Delete a plane" << endl;
				cout << "2. Delete a crew member" << endl;
				cout << "3. Delete a flight" << endl;
				
				cout << endl << "Please enter choice: ";
				cin  >> menuChoice2;
				
				switch(menuChoice2) {
					case 1: //DELETING PLANE
						PC.deletePlane();
						storeData(PC, CC, FC); //store data
						break;
						
					case 2: //DELETING CREW
						CC.deleteCrew();
						storeData(PC, CC, FC); //store data
						break;
						
					case 3: //DELETING FLIGHT
						FC.deleteFlight();
						storeData(PC, CC, FC); //store data
						break;
						
					default: //INCORRECT INPUT
						cout << "Incorrect input. Please choose from menu." << endl << endl;
						break;	
				}
				break;
			
			case 4: //FIND AN OBJECT --------------------------------------------------------------------------------------------
				cout << "--------------------  FIND:  --------------------" << endl;
				cout << "1. Find a plane" << endl;
				cout << "2. Find a crew member" << endl;
				cout << "3. Find a flight" << endl;
				
				cout << endl << "Please enter choice: ";
				cin  >> menuChoice2;
				
				switch(menuChoice2) {
					case 1: //FIND PLANE
						//PC.findPlane();
						break;
						
					case 2: //FIND CREW
						//CC.findCrew();
						break;
						
					case 3: //FIND FLIGHT
						//FC.findFlight();
						break;
						
					default: //INCORRECT INPUT
						cout << "Incorrect input. Please choose from menu." << endl << endl;
						break;	
				}
				break;
			
			case 5: //PRINT AN OBJECT --------------------------------------------------------------------------------------------
				cout << "--------------------  PRINT:  --------------------" << endl;
				cout << "1. Print all planes" << endl;
				cout << "2. Print all crew members" << endl;
				cout << "3. Print all flights" << endl << "*" << endl;
				cout << "4. Print single plane" << endl;
				cout << "5. Print single crew member" << endl;
				cout << "6. Print single flight" << endl;
				
				cout << endl << "Please enter choice: ";
				cin  >> menuChoice2;
				
				switch(menuChoice2) {
					case 1: //PRINT ALL PLANES
						PC.printPlanes();
						break;
						
					case 2: //PRINT ALL CREW MEMBERS
						CC.printCrews();
						break;
						
					case 3: //PRINT ALL FLIGHTS
						FC.printFlights();
						break;
						
					case 4: //PRINT A PLANE
						PC.printPlaneFromVec();
						break;
						
					case 5: //PRINT A CREW MEMBER
						CC.printCrewFromVec();
						break;
					
					case 6: //PRINT A FLIGHT
						FC.printFlightFromVec();
						break;
						
					default: //INCORRECT INPUT
						cout << "Incorrect input. Please choose from menu." << endl << endl;
						break;	
				}
				break;
			
			
			case 6: //PRINT ASSIGNMENT SCHEDULE --------------------------------------------------------------------------------------------
			
				break;
				
			case 7: //PRINT FLIGHTS OF A STATUS --------------------------------------------------------------------------------------------
			
				break;
				
			case 8: //DELETE PAST/CANCELED FLIGHTS --------------------------------------------------------------------------------------------
			
			
				storeData(PC, CC, FC); //store data
				break;
				
			case 9: //UPDATE FLIGHT STATUSES --------------------------------------------------------------------------------------------
				
				storeData(PC, CC, FC); //store data
				break;
			
			
			default: //INCORRECT INPUT --------------------------------------------------------------------------------------------
				cout << "Incorrect input. Please choose from menu." << endl << endl;
				break;
				
		}
	}
	
return 0;
}


//---------------------------------------------------------------------------------------------------------------


void storeData(Planes PC, Crews CC, Flights FC) { //stores all program data
	PC.storeData();
	CC.storeData();
	FC.storeData();
}

void loadData(Planes &PC, Crews &CC, Flights &FC) { //loads all program data
	if(!load) {
		PC.loadData();
		CC.loadData();
		FC.loadData();
	}
	load = 1;
}