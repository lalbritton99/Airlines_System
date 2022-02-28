#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Crews {
	private:
		vector<Crew> crewVec;
		int crewCount;
	public:
		Crews();
		void setCrewCount(int input) {crewCount = input;}
		int getCrewCount() {return crewCount;}
		void addCrew();
		void deleteCrew();
		void editCrew();
		void printCrews();
		void printCrewFromVec();
		void loadData();
		void storeData();
		
		//helper functions
		int searchID(int inputID);
		bool isPilot(int inputID);
		bool isCoPilot(int inputID);
		bool isCabinCrew(int inputID);
};
