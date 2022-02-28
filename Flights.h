#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

class Flights {
	private:
		vector<Flight> flightVec;
		int flightCount;
	public:
		Flights();
		void setFlightCount(int input) {flightCount = input;}
		int getFlightCount() {return flightCount;}
		void addFlight();
		void deleteFlight();
		void editFlight();
		void printFlights();
		void printFlightFromVec();
		void printActivePlaneAsignments();
		void printActiveCrewAssignments();
		void printFlightsOfASatus();
		void deletePastFlights();
		void updateFlightStatuses();
		void loadData();
		void storeData();
		
		//helper functions
		bool flightVecContainPlane(string tailNum);
		bool flightVecContainCrew(int ID);
		bool IDInUse(int ID);
};
