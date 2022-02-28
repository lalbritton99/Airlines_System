#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Plane {
	private:
		string tailNum; //serves as ID
		string make;
		int model;
		int numSeats;
		int range;
		int minCabinCrew;
		
	public:
		Plane();
	
		void setTailNum(string input); //declared in .cpp
		string getTailNum() {return tailNum;}
		
		void setMake(string input) {make = input;}
		string getMake() {return make;}
		
		void setModel(int input) {model = input;}
		int getModel() {return model;}
		
		void setNumSeats(int input) {numSeats = input;}
		int getNumSeats() {return numSeats;}
		
		void setRange(int input) {range = input;}
		int getRange() {return range;}
		
		void setMinCabinCrew(int input) {minCabinCrew = input;}
		int getMinCabinCrew() {return minCabinCrew;}
		 
		void print();
};

