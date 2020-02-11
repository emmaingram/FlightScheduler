flightSchedule : main.o plane.o planes.o crew.o crews.o flight.o flights.o
	g++ -o flightSchedule main.o plane.o planes.o crew.o crews.o flight.o flights.o

main.o : flights.h
	g++ -c main.cpp

plane.o : plane.h
	g++ -c plane.cpp

planes.o : planes.h
	g++ -c planes.cpp

crew.o : crew.h
	g++ -c crew.cpp

crews.o : crews.h
	g++ -c crews.cpp

flight.o : flight.h
	g++ -c flight.cpp

flights.o : flights.h
	g++ -c flights.cpp

clean :
	rm *.o flightSchedule

run:
	./flightSchedule
