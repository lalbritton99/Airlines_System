output: Plane.o Crew.o Flight.o HW4main.o Planes.o Crews.o Flights.o  
	g++ Plane.o Crew.o Flight.o HW4main.o Planes.o Crews.o Flights.o  -o output
	
Plane.o: Plane.h Plane.cpp 
	g++ -Wall -c Plane.cpp
Crew.o: Crew.h Crew.cpp
	g++ -Wall -c Crew.cpp
Flight.o: Flight.h Flight.cpp
	g++ -Wall -c Flight.cpp
Planes.o: Planes.h Planes.cpp
	g++ -Wall -c Planes.cpp
Crews.o: Crews.h Crews.cpp
	g++ -Wall -c Crews.cpp
Flights.o: Flights.h Flights.cpp
	g++ -Wall -c Flights.cpp
HW4main.o: Plane.h Crew.h Flight.h HW4main.cpp Planes.h Crews.h Flights.h  
	g++ -Wall -c HW4main.cpp