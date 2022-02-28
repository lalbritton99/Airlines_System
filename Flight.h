#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

class Flight {
	private:
		int ID; 
		string tailNum;
		int numPilots;
		int numCabinCrew;
		vector<int> pilotIDs;
		vector<int> cabinCrewIDs;
		vector<int> coPilotIDs;
		time_t startTime;
		time_t endTime;
		string startLoc;
		string endLoc;
		int numPassengers;
		string status;
		
	public:
		Flight();
	
		void setID(int input) {ID = input;} //checking in main
		int getID() {return ID;}
		
		void setTailNum(string input) {tailNum = input;} //checking in main
		string getTailNum() {return tailNum;}
		
		void setNumPilots(int input) {numPilots = input;} //checking in main
		int getNumPilots() {return numPilots;}
		
		void setNumCabinCrew(int input) {numCabinCrew = input;} //checking in main
		int getNumCabinCrew() {return numCabinCrew;}
		
		int searchPID(int PID);	
		int searchPIDByIndex(int index);		
		void addPID(int PID);
		void removePID(int PID);
		
		int searchCPID(int CPID);
		int searchCPIDByIndex(int index);		
		void addCPID(int CPID);
		void removeCPID(int CPID);
		
		int searchCCID(int CCID);
		int searchCCIDByIndex(int index);
		void addCCID(int CCID);
		void removeCCID(int CCID);
		
		void setStartTime(time_t time) {startTime = time;} //checking in main
		time_t getStartTime() {return startTime;}
		
		void setEndTime(time_t time) {endTime = time;} //checking in main
		time_t getEndTime() {return endTime;}
		
		void setStartLoc(string input) {startLoc = input;}
		string getStartLoc() {return startLoc;}
		
		void setEndLoc(string input) {endLoc = input;}
		string getEndLoc() {return endLoc;}
		
		void setNumPassengers(int input) {numPassengers = input;} //checking in main
		int getNumPassengers() {return numPassengers;}
		
		void setStatus(string input) {status = input;}
		string getStatus() {return status;}
		
		void print();
		
		//helper function
	
		bool crewInFlight(int ID); //returns true if ID is in a crew vector, false in not
};

