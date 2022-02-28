#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Planes {
	private:
		vector<Plane> planeVec;
		int planeCount;
	public:
		Planes();
		void setPlaneCount(int input) {planeCount = input;}
		int getPlaneCount() {return planeCount;}
		void addPlane();
		void deletePlane();
		void editPlane();
		void printPlanes();
		void printPlaneFromVec();
		void loadData();
		void storeData();
		
		//helper functions:
		int searchTailNum(string inputTailNum);
		bool tailNumInUse(string tailNum);
		int getMinCabinCrewFromCol(string tailNum); 
		int getNumSeats(string tailNum);
		
};
