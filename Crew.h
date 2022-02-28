#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Crew {
	private:
		int ID;
		string name;
		string crewType;
		
	public:
		Crew();
	
		void setID(int input) {ID = input;}
		int getID() {return ID;}
		
		void setName(string input) {name = input;}
		string getName() {return name;}
		
		void setCrewType(string input) {crewType = input;}
		string getCrewType() {return crewType;}
		
		void print();
};

