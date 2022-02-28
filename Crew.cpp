#include "Crew.h"

Crew::Crew() {
	string name = "NO_NAME";
	int ID = -1;
	string crewType = "NO_TYPE";
}

void Crew::print() {
	cout << setw(20) << ID << setw(20) << name << setw(20) << crewType << endl;
}