/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the main function for the flight plan program
*/

#include "flights.h"

Planes planes;
CrewMembers crew;
Flights flights;

void loaddata(); //function to load data
void storedata();//function to store data

int main()
{
    cout << "+------------------------------------------------+ \n";
    cout << "|        Computer Science and Engineering        | \n";
    cout << "|         CSCE 1040 - Computer Science II        | \n";
    cout << "|  Emma Ingram   eci0011   emmaingram@my.unt.edu | \n";
    cout << "+------------------------------------------------+ \n";	
	
	cout << "\nMEAN GREEN AIRLINES\n\n";
	
	int input, planeInput, flightInput, crewInput;
	do{
		//print menu
		cout << "MENU\n";
		cout << "\t1 - PLANES\n"
			 << "\t2 - FLIGHTS\n"
			 << "\t3 - CREW\n"
			 << "\t4 - LOAD DATA\n"
			 << "\t5 - STORE DATA\n"
			 << "\t6 - QUIT\n";

		cout << "\nChoose an option from the menu:\n";
		cin >> input;
		
		if(input == 1)
		{
			//print plane menu
			cout << "\nPLANE MENU\n";
			cout << "\t1 - ADD PLANE\n"
				 << "\t2 - EDIT PLANE\n"
				 << "\t3 - DELETE PLANE\n"
				 << "\t4 - PRINT LIST OF ALL PLANES\n"
				 << "\t5 - PRINT DETAILS OF SINGLE PLANE\n"
				 << "\t6 - EXIT PLANE MENU\n";
			
			cout << "\nChoose an option from the plane menu:\n";
			cin >> planeInput;
			cin.ignore();
			
			if(planeInput == 1)
				planes.AddPlane();
			else if(planeInput == 2)
				planes.EditPlane();
			else if(planeInput == 3)
				planes.DeletePlane();
			else if(planeInput == 4)
				planes.PrintPlanes();
			else if(planeInput == 5)
				planes.PrintDetailsForPlane();
		}
		else if(input == 2)
		{
			//print flight menu
			cout << "\nFLIGHT MENU\n";
			cout << "\t1 - ADD FLIGHT\n"
				 << "\t2 - EDIT FLIGHT\n"
				 << "\t3 - DELETE FLIGHT\n"
				 << "\t4 - PRINT LIST OF ALL FLIGHTS\n"
				 << "\t5 - PRINT DETAILS OF SINGLE FLIGHT\n"
				 << "\t6 - PRINT DETAILS FOR SPECIFIC AIRCRAFT\n"
				 << "\t7 - PRINT DETAILS FOR SPECIFIC CREW MEMBER\n"
				 << "\t8 - PRINT FLIGHTS BASED ON STATUS\n"
				 << "\t9 - DELETE COMPLETED/CANCELLED FLIGHTS\n"
				 << "\t10 - EXIT FLIGHT MENU\n";
			
			cout << "\nChoose an option from the flight menu:\n";
			cin >> flightInput;
			cin.ignore();
			
			if(flightInput == 1)
				flights.AddFlight(planes, crew);
			else if(flightInput == 2)
				flights.EditFlight(planes, crew);
			else if(flightInput == 3)
				flights.DeleteFlight();
			else if(flightInput == 4)
				flights.PrintFlights(crew);
			else if(flightInput == 5)
				flights.PrintDetailsForFlight(crew);
			else if(flightInput == 6)
				flights.PrintDetailsForAircraft(crew);
			else if(flightInput == 7)
				flights.PrintDetailsForCrewMember(crew);
			else if(flightInput == 8)
				flights.PrintFlightsByStatus(crew);
			else if(flightInput == 9)
				flights.DeleteOldFlights();
		}
		else if(input == 3)
		{
			//print crew menu
			cout << "\nCREW MENU\n";
			cout << "\t1 - ADD CREW MEMBER\n"
				 << "\t2 - EDIT CREW MEMBER\n"
				 << "\t3 - DELETE CREW MEMBER\n"
				 << "\t4 - PRINT LIST OF ALL CREW MEMBERS\n"
				 << "\t5 - PRINT DETAILS OF SINGLE CREW MEMBER\n"
				 << "\t6 - EXIT CREW MENU\n";
				 
			cout << "\nChoose an option from the crew menu:\n";
			cin >> crewInput;
			cin.ignore();
			
			if(crewInput == 1)
				crew.AddCrewMember();
			else if(crewInput == 2)
				crew.EditCrewMember();
			else if(crewInput == 3)
				crew.DeleteCrewMember();
			else if(crewInput == 4)
				crew.PrintCrewMembers();
			else if(crewInput == 5)
				crew.PrintDetailsForCrew();
		}
		else if(input == 4)
		{
			//load data
			cout << endl;
			loaddata();
			cout << endl;
		}
		else if(input == 5)
		{
			//store data
			cout << endl;
			storedata();
			cout << endl;
		}
		else if(input == 6)
		{
			return -1;
		}
		
		//update status based on time
		flights.UpdateStatus();
	}while(input != 6);
	
	return 0;
}

void loaddata()
{
	planes.loaddata(); //load planes
	crew.loaddata(); //load crew members
	flights.loaddata(); //load flights
}

void storedata()
{
	planes.storedata(); //store planes
	crew.storedata(); //store crew members
	flights.storedata(); //store flights
}