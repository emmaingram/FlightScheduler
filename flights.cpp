/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the function definitions for Flights class
*/

#include "flights.h"

void Flights::AddFlight(Planes &plane, CrewMembers &crew) //function to add a flight
{
	flightCount = FlightList.size();
	
	Flight tempFlight;
	
	int tempFlightNum, tempStatus;
	string tempPilotID, tempCoPilotID, tempC1ID, tempC2ID, tempC3ID;
	int tempStartDate, tempStartYear, tempEndDate, tempEndYear, tempNumPass, tempStartMonth, tempEndMonth;
	string tempPlaneID, tempStartAir, tempEndAir;
	int tempStartHour, tempStartMin, tempEndHour, tempEndMin;
	string sMon, eMon;
	
	cout << "\nADD FLIGHT\n";
	
	//prompt user for flight number (ID)
	cout << "Enter flight number:\n";
	cin >> tempFlightNum;
	
	int test=-1;
	//check if tail number is already used
	do{
		for(int i=0; i<flightCount; i++)
		{
			test = -1;
			if((FlightList.at(i)).GetFlightNum() == tempFlightNum)
			{
				cout << "ERROR - Flight Number already taken.\n";
				cout << "Try again:\n";
				cin >> tempFlightNum;
				test++;
			}
		}
	}while(test != -1);//if tail number is used, test will not be -1
	//if tail number is not used, test will still be -1
	
	tempFlight.SetFlightNum(tempFlightNum);
	
	//prompt user for start time
	do{
		cout << "Enter start date for flight.\n";
		cout << "\tMonth:\n";
		cout << "\t\t1 - January\n\t\t2 - February\n\t\t3 - March\n\t\t4 - April\n\t\t5 - May\n"
			 << "\t\t6 - June\n\t\t7 - July\n\t\t8 - August\n\t\t9 - September\n\t\t10 - October\n"
			 << "\t\t11 - November\n\t\t12 - December\n";
		cin >> tempStartMonth;
		
		if(tempStartMonth < 1 || tempStartMonth > 12)
			cout << "ERROR - Invalid Month. Try again.\n";		
	}while(tempStartMonth < 1 || tempStartMonth > 12);
	
	//set month according to input
	if(tempStartMonth == 1)
	{
		tempFlight.SetStartMonth("January");
		sMon = "January";
	}
	else if(tempStartMonth == 2)
	{
		tempFlight.SetStartMonth("February");
		sMon = "February";
	}
	else if(tempStartMonth == 3)
	{
		tempFlight.SetStartMonth("March");	
		sMon = "March";
	}
	else if(tempStartMonth == 4)
	{
		tempFlight.SetStartMonth("April");
		sMon = "April";
	}
	else if(tempStartMonth == 5)
	{
		tempFlight.SetStartMonth("May");
		sMon = "May";
	}
	else if(tempStartMonth == 6)
	{
		tempFlight.SetStartMonth("June");
		sMon = "June";
	}
	else if(tempStartMonth == 7)
	{
		tempFlight.SetStartMonth("July");
		sMon = "July";
	}
	else if(tempStartMonth == 8)
	{
		tempFlight.SetStartMonth("August");
		sMon = "August";
	}
	else if(tempStartMonth == 9)
	{
		tempFlight.SetStartMonth("September");
		sMon = "September";
	}
	else if(tempStartMonth == 10)
	{
		tempFlight.SetStartMonth("October");
		sMon = "October";
	}
	else if(tempStartMonth == 11)
	{
		tempFlight.SetStartMonth("November");
		sMon = "November";
	}
	else if(tempStartMonth == 12)
	{
		tempFlight.SetStartMonth("December");
		sMon = "December";
	}
	
	//prompt for start date
	do{
		cout << "\tDay:\n";
		cin >> tempStartDate;
		
		if(tempStartDate < 1 || tempStartDate > 31)
			cout << "ERROR - Invalid Date. Try again.\n";
	}while(tempStartDate < 1 || tempStartDate > 31);
	
	tempFlight.SetStartDate(tempStartDate);
	
	//prompt user for start year
	do{
		cout << "\tYear:\n";
		cin >> tempStartYear;
		
		if(tempStartYear < 2018)
			cout << "ERROR - Cannot add flights in past. Try again.\n";
	}while(tempStartYear < 2018);
	
	tempFlight.SetStartYear(tempStartYear);
	
	//prompt for start hour and minute
	cout << "Enter start time (GMT)\n";
	do{
		cout << "\tHour: ";
		cin >> tempStartHour;
		
		if(tempStartHour > 24 || tempStartHour < 0)
		{
			cout << "ERROR - Invalid entry. Start hour must be between 0 and 24. Try again.\n";
		}
		else
		{
			tempFlight.SetStartHour(tempStartHour);
		}
	}while(tempStartHour > 24 || tempStartHour < 0);
	
	do{
		cout << "\tMin: ";
		cin >> tempStartMin;
		
		if(tempStartMin > 59 || tempStartMin < 0)
		{
			cout << "ERROR - Invalid entry. Start minute must be between 0 and 59. Try again.\n";
		}
		else
		{
			tempFlight.SetStartMin(tempStartMin);
		}
	}while(tempStartMin > 59 || tempStartMin < 0);
	
	//prompt uer for end time
	do{
		cout << "Enter end date for flight.\n";
		cout << "\tMonth:\n";
		cout << "\t\t1 - January\n\t\t2 - February\n\t\t3 - March\n\t\t4 - April\n\t\t5 - May\n"
			 << "\t\t6 - June\n\t\t7 - July\n\t\t8 - August\n\t\t9 - September\n\t\t10 - October\n"
			 << "\t\t11 - November\n\t\t12 - December\n";
		cin >> tempEndMonth;
		
		if(tempEndMonth < 1 || tempEndMonth > 12)
			cout << "ERROR - Invalid Month. Try again.\n";	
		else if((tempEndMonth < tempStartMonth) && tempEndMonth != 1)
			cout << "ERROR - End month must be same month or after start month. Try again.\n";
	}while((tempEndMonth < 1 || tempEndMonth > 12) || ((tempEndMonth < tempStartMonth) && tempEndMonth != 1));
	
	//set month according to user input
	if(tempEndMonth == 1)
	{
		tempFlight.SetEndMonth("January");
		eMon = "January";
	}
	else if(tempEndMonth == 2)
	{
		tempFlight.SetEndMonth("February");
		eMon = "February";
	}
	else if(tempEndMonth == 3)
	{
		tempFlight.SetEndMonth("March");	
		eMon = "March";
	}
	else if(tempEndMonth == 4)
	{
		tempFlight.SetEndMonth("April");
		eMon = "April";
	}
	else if(tempEndMonth == 5)
	{
		tempFlight.SetEndMonth("May");
		eMon = "May";
	}
	else if(tempEndMonth == 6)
	{
		tempFlight.SetEndMonth("June");
		eMon = "June";
	}
	else if(tempEndMonth == 7)
	{
		tempFlight.SetEndMonth("July");
		eMon = "July";
	}
	else if(tempEndMonth == 8)
	{
		tempFlight.SetEndMonth("August");
		eMon = "August";
	}
	else if(tempEndMonth == 9)
	{
		tempFlight.SetEndMonth("September");
		eMon = "September";
	}
	else if(tempEndMonth == 10)
	{
		tempFlight.SetEndMonth("October");
		eMon = "October";
	}
	else if(tempEndMonth == 11)
	{
		tempFlight.SetEndMonth("November");
		eMon = "November";
	}
	else if(tempEndMonth == 12)
	{
		tempFlight.SetEndMonth("December");
		eMon = "December";
	}
	
	//prompt for date
	do{
		cout << "\tDay:\n";
		cin >> tempEndDate;
		
		if(tempEndDate < 1 || tempEndDate > 31)
			cout << "ERROR - Invalid Date. Try again.\n";
		else if((tempEndDate < tempStartDate) && tempEndDate != 1)
			cout << "ERROR - End date must be same day or after start date. Try again.\n";
	}while((tempEndDate < 1 || tempEndDate > 31) || ((tempEndDate < tempStartDate) && tempStartDate != 1));
	
	tempFlight.SetEndDate(tempEndDate);
	
	do{
		cout << "\tYear:\n";
		cin >> tempEndYear;
		
		if(tempEndYear < 2018)
			cout << "ERROR - Cannot add flights in past. Try again.\n";
	}while(tempEndYear < 2018);	
	
	tempFlight.SetEndYear(tempEndYear);
	
	cout << "Enter end time (GMT)\n";
	do{
		cout << "\tHour: ";
		cin >> tempEndHour;
		
		if(tempEndHour > 24 || tempEndHour < 0)
		{
			cout << "ERROR - Invalid entry. End hour must be between 0 and 24. Try again.\n";
		}
		else if((tempEndHour < tempStartHour) && tempEndDate == tempStartDate)
		{
			cout << "ERROR - Invalid entry. End hour must come after start hour. Try again.\n";
		}
		else
		{
			tempFlight.SetEndHour(tempEndHour);
		}		
	}while((tempEndHour > 24 || tempEndHour < 0) || ((tempEndHour < tempStartHour) && tempEndDate == tempStartDate));
	
	do{	
		cout << "\tMin: ";
		cin >> tempEndMin;
		
		if(tempEndMin > 59 || tempEndMin < 0)
		{
			cout << "ERROR - Invalid entry. End minute must be between 0 and 59. Try again.\n";
		}
		else if((tempStartHour == tempEndHour) && (tempEndMin < tempStartMin))
		{
			cout << "ERROR - Invalid entry. End time must come after start time. Try again.\n";
		}
		else
		{
			tempFlight.SetEndMin(tempEndMin);
		}
	}while((tempEndMin > 59 || tempEndMin < 0) || ((tempStartHour == tempEndHour) && (tempEndMin < tempStartMin)));
		
	//prompt user for plane id
	bool planeExist;
	bool planeAvailable;
	bool planeBusy;
	do{
		cout << "Enter plane ID (tail number):\n";
		cin >> tempPlaneID;
		
		planeExist = plane.SearchForPlane(tempPlaneID);
		planeAvailable = plane.PlaneAvailable(tempPlaneID);
		
		if(planeExist == true)
			planeBusy = isPlaneBusy(tempPlaneID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
		
		if(planeExist == false)
			cout << "ERROR - Plane not found. Try again.\n";
		else if(planeAvailable == false)
			cout << "ERROR - Plane is unavailable. Try again.\n";
		else if(planeBusy == false)
			cout << "ERROR - Plane is busy at scheduled time. Try again.\n";
	}while(planeExist != true || planeAvailable != true || planeBusy != true);
	
	tempFlight.SetPlaneID(tempPlaneID);
	
	//prompt user for pilot id
	bool pilotExist;
	bool isPilotAvailable;
	bool pilotBusy;
	do{
		cout << "Enter pilot ID:\n";
		cin >> tempPilotID;
		
		pilotExist = crew.SearchForCrew(tempPilotID);
		
		if(pilotExist == true)
		{
			bool isPilot;
			
			isPilot = crew.IsPilot(tempPilotID);
			isPilotAvailable = crew.IsAvailable(tempPilotID);
			pilotBusy = isCrewMemberBusy(tempPilotID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
			
			if(isPilot == false)
			{
				cout << "ERROR - Crew member is not a pilot. Try again.\n";
				pilotExist = false;
			}
			else if(isPilotAvailable == false)
			{
				cout << "ERROR - Crew member is not available. Try again.\n";
				isPilotAvailable = false;
			}
			else if(pilotBusy == false)
			{
				cout << "ERROR - Crew member is busy at scheduled time. Try again.\n";
				pilotBusy = false;
			}
			else
				tempFlight.SetPilotID(tempPilotID);
		}
		else
			cout << "Crew member not found. Try again:\n";		
	}while(pilotExist != true || isPilotAvailable != true || pilotBusy != true);
	
	//prompt user for copilot id
	bool copilotExist;
	bool isCoPilotAvailable;
	bool copilotBusy;
	do{
		cout << "Enter copilot ID:\n";
		cin >> tempCoPilotID;
		
		copilotExist = crew.SearchForCrew(tempCoPilotID);
		
		if(copilotExist == true)
		{
			bool isCoPilot;
			
			isCoPilot = crew.IsCopilot(tempCoPilotID);
			isCoPilotAvailable = crew.IsAvailable(tempCoPilotID);
			copilotBusy = isCrewMemberBusy(tempCoPilotID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);

			if(isCoPilot == false)
			{
				cout << "ERROR - Crew member is not a copilot. Try again.\n";
				copilotExist = false;
			}
			else if(isCoPilotAvailable == false)
			{
				cout << "ERROR - Crew member is not available. Try again.\n";
				isCoPilotAvailable = false;
			}
			else if(copilotBusy == false)
			{
				cout << "ERROR - Crew member is busy at scheduled time. Try again.\n";
				copilotBusy = false;
			}
			else
				tempFlight.SetCoPilotID(tempCoPilotID);
		}
		else
			cout << "Crew member not found. Try again:\n";		
	}while(copilotExist != true || isCoPilotAvailable != true || copilotBusy != true);	
	
	//prompt user for cabin 1 id
	bool cabin1Exist;
	bool isCabin1Available;
	bool cabin1Busy;
	do{
		cout << "Enter first cabin crew ID:\n";
		cin >> tempC1ID;
		
		cabin1Exist = crew.SearchForCrew(tempC1ID);
		
		if(cabin1Exist == true)
		{
			bool isCabin;
			
			isCabin = crew.IsCabin(tempC1ID);
			isCabin1Available = crew.IsAvailable(tempC1ID);
			cabin1Busy = isCrewMemberBusy(tempC1ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin); 
			
			if(isCabin == false)
			{
				cout << "ERROR - Crew member does not work in cabin. Try again.\n";
				cabin1Exist = false;
			}
			else if(isCabin1Available == false)
			{
				cout << "ERROR - Crew member is not available. Try again.\n";
				isCabin1Available = false;
			}
			else if(cabin1Busy == false)
			{
				cout << "ERROR - Crew member is busy at scheduled time. Try again.\n";
				cabin1Busy = false;
			}
			else
				tempFlight.Set1CabinID(tempC1ID);
		}
		else
			cout << "Crew member not found. Try again:\n";		
	}while(cabin1Exist != true || isCabin1Available != true || cabin1Busy != true);		
	
	//prompt user for cabin 2 id
	bool cabin2Exist;
	bool isCabin2Available;
	bool cabin2Busy;
	do{
		cout << "Enter second cabin crew ID:\n";
		cin >> tempC2ID;
		
		while(tempC1ID == tempC2ID)
		{
			cout << "ERROR - Crew member already working flight. Try again.\n";
			
			cout << "Enter first cabin crew ID:\n";
			cin >> tempC2ID;
		}
		
		cabin2Exist = crew.SearchForCrew(tempC2ID);
		
		if(cabin2Exist == true)
		{
			bool isCabin;
			
			isCabin = crew.IsCabin(tempC2ID);
			isCabin2Available = crew.IsAvailable(tempC2ID);
			cabin2Busy = isCrewMemberBusy(tempC2ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin); 

			if(isCabin == false)
			{
				cout << "ERROR - Crew member does not work in cabin. Try again.\n";
				cabin2Exist = false;
			}
			else if(isCabin2Available == false)
			{
				cout << "ERROR - Crew member is not available. Try again.\n";
				isCabin2Available = false;
			}
			else if(cabin2Busy == false)
			{
				cout << "ERROR - Crew member is busy at scheduled time. Try again.\n";
				cabin2Busy = false;
			}
			else
				tempFlight.Set2CabinID(tempC2ID);
		}
		else
			cout << "Crew member not found. Try again:\n";		
	}while(cabin2Exist != true || isCabin2Available != true || cabin2Busy != true);	
	
	//prompt user for third cabin crew member id
	bool cabin3Exist;
	bool isCabin3Available;
	bool cabin3Busy;
	do{
		cout << "Enter third cabin crew ID:\n";
		cin >> tempC3ID;
		
		while((tempC1ID == tempC3ID) || (tempC2ID == tempC3ID))
		{
			cout << "ERROR - Crew member already working flight. Try again.\n";
			
			cout << "Enter first cabin crew ID:\n";
			cin >> tempC3ID;
		}
		
		cabin3Exist = crew.SearchForCrew(tempC3ID);
		
		if(cabin3Exist == true)
		{
			bool isCabin;
			
			isCabin = crew.IsCabin(tempC3ID);
			isCabin3Available = crew.IsAvailable(tempC3ID);
			cabin3Busy = isCrewMemberBusy(tempC3ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin); 

			if(isCabin == false)
			{
				cout << "ERROR - Crew member is not a copilot. Try again.\n";
				cabin3Exist = false;
			}
			else if(isCabin3Available == false)
			{
				cout << "ERROR - Crew member is not available. Try again.\n";
				isCabin3Available = false;
			}
			else if(cabin3Busy == false)
			{
				cout << "ERROR - Crew member is busy at scheduled time. Try again.\n";
				cabin3Busy = false;
			}
			else
				tempFlight.Set3CabinID(tempC3ID);
		}
		else
			cout << "Crew member not found. Try again:\n";		
	}while(cabin3Exist != true || isCabin3Available != true || cabin3Busy != true);	
	
	//prompt for starting airport code
	cout << "Enter starting airport code:\n";
	cin >> tempStartAir;
	
	tempFlight.SetStartAirport(tempStartAir);
	
	//prompt for ending airport code
	do{
		cout << "Enter ending airport code:\n";
		cin >> tempEndAir;
		
		if(tempEndAir == tempStartAir)
			cout << "ERROR - Airport codes must be different. Try again.\n";
	}while(tempEndAir == tempStartAir);
	
	tempFlight.SetEndAirport(tempEndAir);
	
	//prompt for number of passengers
	int numberPass = plane.GetNumSeats(tempPlaneID);
	do{
		cout << "Enter number of passengers:\n";
		cin >> tempNumPass;
	
		if(tempNumPass > numberPass)
			cout << "ERROR - Not enough room in plane. Try again.\n";	
	}while(tempNumPass > numberPass);
	
	tempFlight.SetNumPassengers(tempNumPass);
	
	//prompt user for status
	do{
		cout << "Enter flight status.\n";
		cout << "\t1 - Active\n\t2 - Cancelled\n\t3 - Completed\n";
		
		cin >> tempStatus;
		
		if(tempStatus < 1 || tempStatus > 3)
			cout << "ERROR - Invalid entry. Try again.\n";	
	}while(tempStatus < 1 || tempStatus > 3);
	
	if(tempStatus == 1)
		tempFlight.SetStatus("Active");
	else if(tempStatus == 2)
		tempFlight.SetStatus("Cancelled");
	else if(tempStatus == 3)
		tempFlight.SetStatus("Completed");
	
	FlightList.push_back(tempFlight);
	
	tempFlight.clear();
	
	return;
}

void Flights::EditFlight(Planes &plane, CrewMembers &crew) //function to edit a flight
{
	int tempFlightNum, tempStatus;
	string tempPilotID, tempCoPilotID, tempC1ID, tempC2ID, tempC3ID;
	int tempStartDate, tempStartYear, tempEndDate, tempEndYear, tempNumPass, tempStartMonth, tempEndMonth;
	string tempPlaneID, tempStartAir, tempEndAir;
	int tempStartHour, tempStartMin, tempEndHour, tempEndMin;
	string sMon, eMon;
	
	cout << "\nEDIT FLIGHT\n";

	flightCount = FlightList.size();
	
	int choice, flightNum;
	
	//prompt for flight number
	cout << "Enter the flight number of the flight you want to edit:\n";
	cin >> flightNum;
	
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetFlightNum() == flightNum)
		{
			index = i;
		}
	}
	
	if(index == -1)
	{
		cout << "ERROR - Flight not found. Nothing edited.\n";
		return;
	}
	
	char again = ' ';
	do{
		//print menu
		cout << "What would you like to edit?\n";
		cout << "\t1 - Flight number\n"
			 << "\t2 - Plane\n"
			 << "\t3 - Pilot\n"
			 << "\t4 - CoPilot\n"
			 << "\t5 - Cabin Crew 1\n"
			 << "\t6 - Cabin Crew 2\n"
			 << "\t7 - Cabin Crew 3\n"
			 << "\t8 - Flight Date/Time\n"
			 << "\t9 - Starting Airport\n"
			 << "\t10 - Ending Airport\n"
			 << "\t11 - Number of Passengers\n"
			 << "\t12 - Status\n";
			 
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "EDIT FLIGHT NUMBER\n";
			//prompt user for flight number (ID)
			cout << "Enter new flight number:\n";
			cin >> tempFlightNum;
			
			int test=-1;
			//check if tail number is already used
			do{
				for(int i=0; i<flightCount; i++)
				{
					test = -1;
					if((FlightList.at(i)).GetFlightNum() == tempFlightNum)
					{
						cout << "ERROR - Flight Number already taken.\n";
						cout << "Try again:\n";
						cin >> tempFlightNum;
						test++;
					}
				}
			}while(test != -1);//if tail number is used, test will not be -1
			//if tail number is not used, test will still be -1
			
			(FlightList.at(index)).SetFlightNum(tempFlightNum);		
		}
		else if(choice == 2)
		{
			cout << "EDIT PLANE\n";
			//prompt user for new plane id
			bool planeExist;
			bool planeAvailable;
			bool planeBusy;
			do{
				if((FlightList.at(index)).GetStartMonth() == "January")
					sMon = 1;
				else if((FlightList.at(index)).GetStartMonth() == "February")
					sMon = 2;
				else if((FlightList.at(index)).GetStartMonth() == "March")
					sMon = 3;
				else if((FlightList.at(index)).GetStartMonth() == "April")
					sMon = 4;
				else if((FlightList.at(index)).GetStartMonth() == "May")
					sMon = 5;
				else if((FlightList.at(index)).GetStartMonth() == "June")
					sMon = 6;
				else if((FlightList.at(index)).GetStartMonth() == "July")
					sMon = 7;
				else if((FlightList.at(index)).GetStartMonth() == "August")
					sMon = 8;
				else if((FlightList.at(index)).GetStartMonth() == "September")
					sMon = 9;
				else if((FlightList.at(index)).GetStartMonth() == "October")
					sMon = 10;
				else if((FlightList.at(index)).GetStartMonth() == "November")
					sMon = 11;
				else if((FlightList.at(index)).GetStartMonth() == "December")
					sMon = 12;
				
				tempStartDate = (FlightList.at(index)).GetStartDate();
				tempStartYear = (FlightList.at(index)).GetStartYear();
				tempStartHour = (FlightList.at(index)).GetStartHour();
				tempStartMin = (FlightList.at(index)).GetStartMin();
				
				if((FlightList.at(index)).GetEndMonth() == "January")
					eMon = 1;
				else if((FlightList.at(index)).GetEndMonth() == "February")
					eMon = 2;
				else if((FlightList.at(index)).GetEndMonth() == "March")
					eMon = 3;
				else if((FlightList.at(index)).GetEndMonth() == "April")
					eMon = 4;
				else if((FlightList.at(index)).GetEndMonth() == "May")
					eMon = 5;
				else if((FlightList.at(index)).GetEndMonth() == "June")
					eMon = 6;
				else if((FlightList.at(index)).GetEndMonth() == "July")
					eMon = 7;
				else if((FlightList.at(index)).GetEndMonth() == "August")
					eMon = 8;
				else if((FlightList.at(index)).GetEndMonth() == "September")
					eMon = 9;
				else if((FlightList.at(index)).GetEndMonth() == "October")
					eMon = 10;
				else if((FlightList.at(index)).GetEndMonth() == "November")
					eMon = 11;
				else if((FlightList.at(index)).GetEndMonth() == "December")
					eMon = 12;
				
				tempEndDate = (FlightList.at(index)).GetEndDate();
				tempEndYear = (FlightList.at(index)).GetEndYear();
				tempEndHour = (FlightList.at(index)).GetEndHour();
				tempEndMin = (FlightList.at(index)).GetEndMin();
				
				cout << "Enter new plane ID (tail number):\n";
				cin >> tempPlaneID;
				
				planeExist = plane.SearchForPlane(tempPlaneID);
				planeAvailable = plane.PlaneAvailable(tempPlaneID);
				planeBusy = isPlaneBusy(tempPlaneID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				if(planeExist == false)
					cout << "ERROR - Plane not found. Try again.\n";
				else if(planeAvailable == false)
					cout << "ERROR - Plane is unavailable. Try again.\n";
				else if(planeBusy == false)
					cout <<  "ERROR - Plane is busy at scheduled time. Try again.\n";
			}while(planeExist != true || planeAvailable != true || planeBusy != true);
			
			(FlightList.at(index)).SetPlaneID(tempPlaneID);		
		}
		else if(choice == 3)
		{
			cout << "EDIT PILOT\n";
			//prompt user for new pilot id
			bool pilotExist;
			bool isPilotAvailable;
			bool pilotBusy;
			do{
				//set month
				if((FlightList.at(index)).GetStartMonth() == "January")
					sMon = 1;
				else if((FlightList.at(index)).GetStartMonth() == "February")
					sMon = 2;
				else if((FlightList.at(index)).GetStartMonth() == "March")
					sMon = 3;
				else if((FlightList.at(index)).GetStartMonth() == "April")
					sMon = 4;
				else if((FlightList.at(index)).GetStartMonth() == "May")
					sMon = 5;
				else if((FlightList.at(index)).GetStartMonth() == "June")
					sMon = 6;
				else if((FlightList.at(index)).GetStartMonth() == "July")
					sMon = 7;
				else if((FlightList.at(index)).GetStartMonth() == "August")
					sMon = 8;
				else if((FlightList.at(index)).GetStartMonth() == "September")
					sMon = 9;
				else if((FlightList.at(index)).GetStartMonth() == "October")
					sMon = 10;
				else if((FlightList.at(index)).GetStartMonth() == "November")
					sMon = 11;
				else if((FlightList.at(index)).GetStartMonth() == "December")
					sMon = 12;
				
				tempStartDate = (FlightList.at(index)).GetStartDate();
				tempStartYear = (FlightList.at(index)).GetStartYear();
				tempStartHour = (FlightList.at(index)).GetStartHour();
				tempStartMin = (FlightList.at(index)).GetStartMin();
				
				if((FlightList.at(index)).GetEndMonth() == "January")
					eMon = 1;
				else if((FlightList.at(index)).GetEndMonth() == "February")
					eMon = 2;
				else if((FlightList.at(index)).GetEndMonth() == "March")
					eMon = 3;
				else if((FlightList.at(index)).GetEndMonth() == "April")
					eMon = 4;
				else if((FlightList.at(index)).GetEndMonth() == "May")
					eMon = 5;
				else if((FlightList.at(index)).GetEndMonth() == "June")
					eMon = 6;
				else if((FlightList.at(index)).GetEndMonth() == "July")
					eMon = 7;
				else if((FlightList.at(index)).GetEndMonth() == "August")
					eMon = 8;
				else if((FlightList.at(index)).GetEndMonth() == "September")
					eMon = 9;
				else if((FlightList.at(index)).GetEndMonth() == "October")
					eMon = 10;
				else if((FlightList.at(index)).GetEndMonth() == "November")
					eMon = 11;
				else if((FlightList.at(index)).GetEndMonth() == "December")
					eMon = 12;
				
				tempEndDate = (FlightList.at(index)).GetEndDate();
				tempEndYear = (FlightList.at(index)).GetEndYear();
				tempEndHour = (FlightList.at(index)).GetEndHour();
				tempEndMin = (FlightList.at(index)).GetEndMin();				
				
				cout << "Enter new pilot ID:\n";
				cin >> tempPilotID;
				
				pilotExist = crew.SearchForCrew(tempPilotID);
				
				if(pilotExist == true)
				{
					bool isPilot;
					//check if crew member is busy, available, and a pilot
					isPilot = crew.IsPilot(tempPilotID);
					isPilotAvailable = crew.IsAvailable(tempPilotID);
					pilotBusy = isCrewMemberBusy(tempPilotID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
					
					if(isPilot == false)
					{
						cout << "ERROR - Crew member is not a pilot. Try again.\n";
						pilotExist = false;
					}
					else if(isPilotAvailable == false)
					{
						cout << "ERROR - Crew member is not available. Try again.\n";
						isPilotAvailable = false;
					}
					else if(pilotBusy == false)
					{
						cout << "ERROR - Pilot is busy during scheduled time. Try again.\n";
						pilotBusy = false;
					}
					else
						(FlightList.at(index)).SetPilotID(tempPilotID);
				}
				else
					cout << "Crew member not found. Try again:\n";		
			}while(pilotExist != true || isPilotAvailable != true || pilotBusy != true);		
		}
		else if(choice == 4)
		{
			cout << "EDIT COPILOT\n";
			//prompt user for new copilot id
			bool copilotExist;
			bool isCoPilotAvailable;
			bool copilotBusy;
			do{
				//set month
				if((FlightList.at(index)).GetStartMonth() == "January")
					sMon = 1;
				else if((FlightList.at(index)).GetStartMonth() == "February")
					sMon = 2;
				else if((FlightList.at(index)).GetStartMonth() == "March")
					sMon = 3;
				else if((FlightList.at(index)).GetStartMonth() == "April")
					sMon = 4;
				else if((FlightList.at(index)).GetStartMonth() == "May")
					sMon = 5;
				else if((FlightList.at(index)).GetStartMonth() == "June")
					sMon = 6;
				else if((FlightList.at(index)).GetStartMonth() == "July")
					sMon = 7;
				else if((FlightList.at(index)).GetStartMonth() == "August")
					sMon = 8;
				else if((FlightList.at(index)).GetStartMonth() == "September")
					sMon = 9;
				else if((FlightList.at(index)).GetStartMonth() == "October")
					sMon = 10;
				else if((FlightList.at(index)).GetStartMonth() == "November")
					sMon = 11;
				else if((FlightList.at(index)).GetStartMonth() == "December")
					sMon = 12;
				
				tempStartDate = (FlightList.at(index)).GetStartDate();
				tempStartYear = (FlightList.at(index)).GetStartYear();
				tempStartHour = (FlightList.at(index)).GetStartHour();
				tempStartMin = (FlightList.at(index)).GetStartMin();
				
				if((FlightList.at(index)).GetEndMonth() == "January")
					eMon = 1;
				else if((FlightList.at(index)).GetEndMonth() == "February")
					eMon = 2;
				else if((FlightList.at(index)).GetEndMonth() == "March")
					eMon = 3;
				else if((FlightList.at(index)).GetEndMonth() == "April")
					eMon = 4;
				else if((FlightList.at(index)).GetEndMonth() == "May")
					eMon = 5;
				else if((FlightList.at(index)).GetEndMonth() == "June")
					eMon = 6;
				else if((FlightList.at(index)).GetEndMonth() == "July")
					eMon = 7;
				else if((FlightList.at(index)).GetEndMonth() == "August")
					eMon = 8;
				else if((FlightList.at(index)).GetEndMonth() == "September")
					eMon = 9;
				else if((FlightList.at(index)).GetEndMonth() == "October")
					eMon = 10;
				else if((FlightList.at(index)).GetEndMonth() == "November")
					eMon = 11;
				else if((FlightList.at(index)).GetEndMonth() == "December")
					eMon = 12;
				
				tempEndDate = (FlightList.at(index)).GetEndDate();
				tempEndYear = (FlightList.at(index)).GetEndYear();
				tempEndHour = (FlightList.at(index)).GetEndHour();
				tempEndMin = (FlightList.at(index)).GetEndMin();
				
				cout << "Enter new copilot ID:\n";
				cin >> tempCoPilotID;
				
				copilotExist = crew.SearchForCrew(tempCoPilotID);
				
				if(copilotExist == true)
				{
					bool isCoPilot;
					
					//check if crew member is busy, available, and a copilot
					isCoPilot = crew.IsCopilot(tempCoPilotID);
					isCoPilotAvailable = crew.IsAvailable(tempCoPilotID);
					copilotBusy = isCrewMemberBusy(tempCoPilotID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);

					if(isCoPilot == false)
					{
						cout << "ERROR - Crew member is not a copilot. Try again.\n";
						copilotExist = false;
					}
					else if(isCoPilotAvailable == false)
					{
						cout << "ERROR - Crew member is not available. Try again.\n";
						isCoPilotAvailable = false;
					}
					else if(copilotBusy == false)
					{
						cout << "ERROR - CoPilot is busy during scheduled time. Try again.\n";
						copilotBusy = false;
					}
					else
						(FlightList.at(index)).SetCoPilotID(tempCoPilotID);
				}
				else
					cout << "Crew member not found. Try again:\n";		
			}while(copilotExist != true || isCoPilotAvailable != true || copilotBusy != true);		
		}
		else if(choice == 5)
		{
			cout << "EDIT CABIN CREW 1\n";
			//prompt user for cabin 1 id
			bool cabin1Exist;
			bool isCabin1Available;
			bool cabin1Busy;
			do{
				//set month
				if((FlightList.at(index)).GetStartMonth() == "January")
					sMon = 1;
				else if((FlightList.at(index)).GetStartMonth() == "February")
					sMon = 2;
				else if((FlightList.at(index)).GetStartMonth() == "March")
					sMon = 3;
				else if((FlightList.at(index)).GetStartMonth() == "April")
					sMon = 4;
				else if((FlightList.at(index)).GetStartMonth() == "May")
					sMon = 5;
				else if((FlightList.at(index)).GetStartMonth() == "June")
					sMon = 6;
				else if((FlightList.at(index)).GetStartMonth() == "July")
					sMon = 7;
				else if((FlightList.at(index)).GetStartMonth() == "August")
					sMon = 8;
				else if((FlightList.at(index)).GetStartMonth() == "September")
					sMon = 9;
				else if((FlightList.at(index)).GetStartMonth() == "October")
					sMon = 10;
				else if((FlightList.at(index)).GetStartMonth() == "November")
					sMon = 11;
				else if((FlightList.at(index)).GetStartMonth() == "December")
					sMon = 12;
				
				tempStartDate = (FlightList.at(index)).GetStartDate();
				tempStartYear = (FlightList.at(index)).GetStartYear();
				tempStartHour = (FlightList.at(index)).GetStartHour();
				tempStartMin = (FlightList.at(index)).GetStartMin();
				
				if((FlightList.at(index)).GetEndMonth() == "January")
					eMon = 1;
				else if((FlightList.at(index)).GetEndMonth() == "February")
					eMon = 2;
				else if((FlightList.at(index)).GetEndMonth() == "March")
					eMon = 3;
				else if((FlightList.at(index)).GetEndMonth() == "April")
					eMon = 4;
				else if((FlightList.at(index)).GetEndMonth() == "May")
					eMon = 5;
				else if((FlightList.at(index)).GetEndMonth() == "June")
					eMon = 6;
				else if((FlightList.at(index)).GetEndMonth() == "July")
					eMon = 7;
				else if((FlightList.at(index)).GetEndMonth() == "August")
					eMon = 8;
				else if((FlightList.at(index)).GetEndMonth() == "September")
					eMon = 9;
				else if((FlightList.at(index)).GetEndMonth() == "October")
					eMon = 10;
				else if((FlightList.at(index)).GetEndMonth() == "November")
					eMon = 11;
				else if((FlightList.at(index)).GetEndMonth() == "December")
					eMon = 12;
				
				tempEndDate = (FlightList.at(index)).GetEndDate();
				tempEndYear = (FlightList.at(index)).GetEndYear();
				tempEndHour = (FlightList.at(index)).GetEndHour();
				tempEndMin = (FlightList.at(index)).GetEndMin();
				
				cout << "Enter frist cabin crew ID:\n";
				cin >> tempC1ID;
				
				cabin1Exist = crew.SearchForCrew(tempC1ID);
				
				if(cabin1Exist == true)
				{
					bool isCabin;
					
					//check if crew member is busy, available, and a cabin
					isCabin = crew.IsCabin(tempC1ID);
					isCabin1Available = crew.IsAvailable(tempC1ID);
					cabin1Busy = isCrewMemberBusy(tempC1ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
					
					if(isCabin == false)
					{
						cout << "ERROR - Crew member does not work in cabin. Try again.\n";
						cabin1Exist = false;
					}
					else if(isCabin1Available == false)
					{
						cout << "ERROR - Crew member is not available. Try again.\n";
						isCabin1Available = false;
					}
					else if(cabin1Busy == false)
					{
						cout << "ERROR - Cabin member is busy during scheduled time. Try again.\n";
						cabin1Busy = false;
					}
					else
						(FlightList.at(index)).Set1CabinID(tempC1ID);
				}
				else
					cout << "Crew member not found. Try again:\n";		
			}while(cabin1Exist != true || isCabin1Available != true || cabin1Busy != true);		
		}
		else if(choice == 6)
		{
			cout << "EDIT CABIN CREW 2\n";
			//prompt user for cabin 2 id
			bool cabin2Exist;
			bool isCabin2Available;
			bool cabin2Busy;
			do{
				//set month
				if((FlightList.at(index)).GetStartMonth() == "January")
					sMon = 1;
				else if((FlightList.at(index)).GetStartMonth() == "February")
					sMon = 2;
				else if((FlightList.at(index)).GetStartMonth() == "March")
					sMon = 3;
				else if((FlightList.at(index)).GetStartMonth() == "April")
					sMon = 4;
				else if((FlightList.at(index)).GetStartMonth() == "May")
					sMon = 5;
				else if((FlightList.at(index)).GetStartMonth() == "June")
					sMon = 6;
				else if((FlightList.at(index)).GetStartMonth() == "July")
					sMon = 7;
				else if((FlightList.at(index)).GetStartMonth() == "August")
					sMon = 8;
				else if((FlightList.at(index)).GetStartMonth() == "September")
					sMon = 9;
				else if((FlightList.at(index)).GetStartMonth() == "October")
					sMon = 10;
				else if((FlightList.at(index)).GetStartMonth() == "November")
					sMon = 11;
				else if((FlightList.at(index)).GetStartMonth() == "December")
					sMon = 12;
				
				tempStartDate = (FlightList.at(index)).GetStartDate();
				tempStartYear = (FlightList.at(index)).GetStartYear();
				tempStartHour = (FlightList.at(index)).GetStartHour();
				tempStartMin = (FlightList.at(index)).GetStartMin();
				
				if((FlightList.at(index)).GetEndMonth() == "January")
					eMon = 1;
				else if((FlightList.at(index)).GetEndMonth() == "February")
					eMon = 2;
				else if((FlightList.at(index)).GetEndMonth() == "March")
					eMon = 3;
				else if((FlightList.at(index)).GetEndMonth() == "April")
					eMon = 4;
				else if((FlightList.at(index)).GetEndMonth() == "May")
					eMon = 5;
				else if((FlightList.at(index)).GetEndMonth() == "June")
					eMon = 6;
				else if((FlightList.at(index)).GetEndMonth() == "July")
					eMon = 7;
				else if((FlightList.at(index)).GetEndMonth() == "August")
					eMon = 8;
				else if((FlightList.at(index)).GetEndMonth() == "September")
					eMon = 9;
				else if((FlightList.at(index)).GetEndMonth() == "October")
					eMon = 10;
				else if((FlightList.at(index)).GetEndMonth() == "November")
					eMon = 11;
				else if((FlightList.at(index)).GetEndMonth() == "December")
					eMon = 12;
				
				tempEndDate = (FlightList.at(index)).GetEndDate();
				tempEndYear = (FlightList.at(index)).GetEndYear();
				tempEndHour = (FlightList.at(index)).GetEndHour();
				tempEndMin = (FlightList.at(index)).GetEndMin();
				
				cout << "Enter second cabin crew ID:\n";
				cin >> tempC2ID;
				
				while(tempC1ID == tempC2ID)
				{
					cout << "ERROR - Crew member already working flight. Try again.\n";
					
					cout << "Enter first cabin crew ID:\n";
					cin >> tempC2ID;
				}
				
				cabin2Exist = crew.SearchForCrew(tempC2ID);
				
				if(cabin2Exist == true)
				{
					bool isCabin;
					
					//check if crew member is busy, available, and a cabin
					isCabin = crew.IsCabin(tempC2ID);
					isCabin2Available = crew.IsAvailable(tempC2ID);
					cabin2Busy = isCrewMemberBusy(tempC2ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
					
					if(isCabin == false)
					{
						cout << "ERROR - Crew member does not work in cabin. Try again.\n";
						cabin2Exist = false;
					}
					else if(isCabin2Available == false)
					{
						cout << "ERROR - Crew member is not available. Try again.\n";
						isCabin2Available = false;
					}
					else if(cabin2Busy == false)
					{
						cout << "ERROR - Cabin member is busy during scheduled time. Try again.\n";
						cabin2Busy = false;
					}
					else
						(FlightList.at(index)).Set2CabinID(tempC2ID);
				}
				else
					cout << "Crew member not found. Try again:\n";		
			}while(cabin2Exist != true || isCabin2Available != true || cabin2Busy != true);	
		}
		else if(choice == 7)
		{
			cout << "EDIT CABIN CREW 3\n";
			//prompt user for third cabin crew member id
			bool cabin3Exist;
			bool isCabin3Available;
			bool cabin3Busy;
			do{
				//set month
				if((FlightList.at(index)).GetStartMonth() == "January")
					sMon = 1;
				else if((FlightList.at(index)).GetStartMonth() == "February")
					sMon = 2;
				else if((FlightList.at(index)).GetStartMonth() == "March")
					sMon = 3;
				else if((FlightList.at(index)).GetStartMonth() == "April")
					sMon = 4;
				else if((FlightList.at(index)).GetStartMonth() == "May")
					sMon = 5;
				else if((FlightList.at(index)).GetStartMonth() == "June")
					sMon = 6;
				else if((FlightList.at(index)).GetStartMonth() == "July")
					sMon = 7;
				else if((FlightList.at(index)).GetStartMonth() == "August")
					sMon = 8;
				else if((FlightList.at(index)).GetStartMonth() == "September")
					sMon = 9;
				else if((FlightList.at(index)).GetStartMonth() == "October")
					sMon = 10;
				else if((FlightList.at(index)).GetStartMonth() == "November")
					sMon = 11;
				else if((FlightList.at(index)).GetStartMonth() == "December")
					sMon = 12;
				
				tempStartDate = (FlightList.at(index)).GetStartDate();
				tempStartYear = (FlightList.at(index)).GetStartYear();
				tempStartHour = (FlightList.at(index)).GetStartHour();
				tempStartMin = (FlightList.at(index)).GetStartMin();
				
				if((FlightList.at(index)).GetEndMonth() == "January")
					eMon = 1;
				else if((FlightList.at(index)).GetEndMonth() == "February")
					eMon = 2;
				else if((FlightList.at(index)).GetEndMonth() == "March")
					eMon = 3;
				else if((FlightList.at(index)).GetEndMonth() == "April")
					eMon = 4;
				else if((FlightList.at(index)).GetEndMonth() == "May")
					eMon = 5;
				else if((FlightList.at(index)).GetEndMonth() == "June")
					eMon = 6;
				else if((FlightList.at(index)).GetEndMonth() == "July")
					eMon = 7;
				else if((FlightList.at(index)).GetEndMonth() == "August")
					eMon = 8;
				else if((FlightList.at(index)).GetEndMonth() == "September")
					eMon = 9;
				else if((FlightList.at(index)).GetEndMonth() == "October")
					eMon = 10;
				else if((FlightList.at(index)).GetEndMonth() == "November")
					eMon = 11;
				else if((FlightList.at(index)).GetEndMonth() == "December")
					eMon = 12;
				
				tempEndDate = (FlightList.at(index)).GetEndDate();
				tempEndYear = (FlightList.at(index)).GetEndYear();
				tempEndHour = (FlightList.at(index)).GetEndHour();
				tempEndMin = (FlightList.at(index)).GetEndMin();
				
				cout << "Enter third cabin crew ID:\n";
				cin >> tempC3ID;
				
				while((tempC1ID == tempC3ID) || (tempC2ID == tempC3ID))
				{
					cout << "ERROR - Crew member already working flight. Try again.\n";
					
					cout << "Enter first cabin crew ID:\n";
					cin >> tempC3ID;
				}
				
				cabin3Exist = crew.SearchForCrew(tempC3ID);
				
				if(cabin3Exist == true)
				{
					bool isCabin;
					
					//check if crew member is busy, available, and a cabin
					isCabin = crew.IsCabin(tempC3ID);
					isCabin3Available = crew.IsAvailable(tempC3ID);
					cabin3Busy = isCrewMemberBusy(tempC3ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);

					if(isCabin == false)
					{
						cout << "ERROR - Crew member is not a copilot. Try again.\n";
						cabin3Exist = false;
					}
					else if(isCabin3Available == false)
					{
						cout << "ERROR - Crew member is not available. Try again.\n";
						isCabin3Available = false;
					}
					else if(cabin3Busy == false)
					{
						cout << "ERROR - Cabin member is busy during scheduled time. Try again.\n";
						cabin3Busy = false;
					}
					else
						(FlightList.at(index)).Set3CabinID(tempC3ID);
				}
				else
					cout << "Crew member not found. Try again:\n";		
			}while(cabin3Exist != true || isCabin3Available != true || cabin3Busy != true);
		}
		else if(choice == 8)
		{
			int option;
			cout << "EDIT START AND END DATE/TIME\n";

			//prompt user for start time
			bool plBusy, piBusy, coBusy, c1Busy, c2Busy, c3Busy;
			do{
				do{
					cout << "Enter new start date for flight.\n";
					cout << "\tMonth:\n";
					cout << "\t\t1 - January\n\t\t2 - February\n\t\t3 - March\n\t\t4 - April\n\t\t5 - May\n"
						 << "\t\t6 - June\n\t\t7 - July\n\t\t8 - August\n\t\t9 - September\n\t\t10 - October\n"
						 << "\t\t11 - November\n\t\t12 - December\n";
					cin >> tempStartMonth;
					
					if(tempStartMonth < 1 || tempStartMonth > 12)
						cout << "ERROR - Invalid Month. Try again.\n";		
				}while(tempStartMonth < 1 || tempStartMonth > 12);
				
				if(tempStartMonth == 1)
				{
					sMon = "January";
				}
				else if(tempStartMonth == 2)
				{
					sMon = "February";
				}
				else if(tempStartMonth == 3)
				{
					sMon = "March";
				}
				else if(tempStartMonth == 4)
				{
					sMon = "April";
				}
				else if(tempStartMonth == 5)
				{
					sMon = "May";
				}
				else if(tempStartMonth == 6)
				{
					sMon = "June";
				}
				else if(tempStartMonth == 7)
				{
					sMon = "July";
				}
				else if(tempStartMonth == 8)
				{
					sMon = "August";
				}
				else if(tempStartMonth == 9)
				{
					sMon = "September";
				}
				else if(tempStartMonth == 10)
				{
					sMon = "October";
				}
				else if(tempStartMonth == 11)
				{
					sMon = "November";
				}
				else if(tempStartMonth == 12)
				{
					sMon = "December";
				}
				
				do{
					cout << "\tDay:\n";
					cin >> tempStartDate;
					
					if(tempStartDate < 1 || tempStartDate > 31)
						cout << "ERROR - Invalid Date. Try again.\n";
				}while(tempStartDate < 1 || tempStartDate > 31);
				
				do{
					cout << "\tYear:\n";
					cin >> tempStartYear;
					
					if(tempStartYear < 2018)
						cout << "ERROR - Cannot add flights in past. Try again.\n";
				}while(tempStartYear < 2018);
				
				do{
					cout << "Enter new start time (GMT)\n";
					cout << "\tHour: ";
					cin >> tempStartHour;
					cout << "\tMin: ";
					cin >> tempStartMin;
					
					if(tempStartHour > 24 || tempStartHour < 0)
					{
						cout << "ERROR - Invalid entry. Start hour must be between 0 and 24. Try again.\n";
					}
					else if(tempStartMin > 59 || tempStartMin < 0)
					{
						cout << "ERROR - Invalid entry. Start minute must be between 0 and 59. Try again.\n";
					}
				}while((tempStartHour > 24 || tempStartHour < 0) || (tempStartMin > 59 || tempStartMin < 0));

				//prompt uer for end time
				do{
					cout << "Enter end date for flight.\n";
					cout << "\tMonth:\n";
					cout << "\t\t1 - January\n\t\t2 - February\n\t\t3 - March\n\t\t4 - April\n\t\t5 - May\n"
						 << "\t\t6 - June\n\t\t7 - July\n\t\t8 - August\n\t\t9 - September\n\t\t10 - October\n"
						 << "\t\t11 - November\n\t\t12 - December\n";
					cin >> tempEndMonth;
					
					if(tempEndMonth < 1 || tempEndMonth > 12)
						cout << "ERROR - Invalid Month. Try again.\n";	
					else if((tempEndMonth < tempStartMonth) && tempEndMonth != 1)
						cout << "ERROR - End month must be same month or after start month. Try again.\n";
				}while((tempEndMonth < 1 || tempEndMonth > 12) || ((tempEndMonth < tempStartMonth) && tempEndMonth != 1));
				
				if(tempEndMonth == 1)
				{
					eMon = "January";
				}
				else if(tempEndMonth == 2)
				{
					eMon = "February";
				}
				else if(tempEndMonth == 3)
				{
					eMon = "March";
				}
				else if(tempEndMonth == 4)
				{
					eMon = "April";
				}
				else if(tempEndMonth == 5)
				{
					eMon = "May";
				}
				else if(tempEndMonth == 6)
				{
					eMon = "June";
				}
				else if(tempEndMonth == 7)
				{
					eMon = "July";
				}
				else if(tempEndMonth == 8)
				{
					eMon = "August";
				}
				else if(tempEndMonth == 9)
				{
					eMon = "September";
				}
				else if(tempEndMonth == 10)
				{
					eMon = "October";
				}
				else if(tempEndMonth == 11)
				{
					eMon = "November";
				}
				else if(tempEndMonth == 12)
				{
					eMon = "December";
				}
				
				do{
					cout << "\tDay:\n";
					cin >> tempEndDate;
					
					if(tempEndDate < 1 || tempEndDate > 31)
						cout << "ERROR - Invalid Date. Try again.\n";
					else if((tempEndDate < tempStartDate) && tempEndDate != 1)
						cout << "ERROR - End date must be same day or after start date. Try again.\n";
				}while((tempEndDate < 1 || tempEndDate > 31) || ((tempEndDate < tempStartDate) && tempStartDate != 1));
				
				do{
					cout << "\tYear:\n";
					cin >> tempEndYear;
					
					if(tempEndYear < 2018)
						cout << "ERROR - Cannot add flights in past. Try again.\n";
				}while(tempEndYear < 2018);	
			
				cout << "Enter end time (GMT)\n";
				do{
					cout << "\tHour: ";
					cin >> tempEndHour;
					
					if(tempEndHour > 24 || tempEndHour < 0)
					{
						cout << "ERROR - Invalid entry. End hour must be between 0 and 24. Try again.\n";
					}
					else if((tempEndHour < tempStartHour) && tempEndDate == tempStartDate)
					{
						cout << "ERROR - Invalid entry. End hour must come after start hour. Try again.\n";
					}	
				}while((tempEndHour > 24 || tempEndHour < 0) || ((tempEndHour < tempStartHour) && tempEndDate == tempStartDate));
				
				do{	
					cout << "\tMin: ";
					cin >> tempEndMin;
					
					if(tempEndMin > 59 || tempEndMin < 0)
					{
						cout << "ERROR - Invalid entry. End minute must be between 0 and 59. Try again.\n";
					}
					else if((tempStartHour == tempEndHour) && (tempEndMin < tempStartMin))
					{
						cout << "ERROR - Invalid entry. End time must come after start time. Try again.\n";
					}
				}while((tempEndMin > 59 || tempEndMin < 0) || ((tempStartHour == tempEndHour) && (tempEndMin < tempStartMin)));

				//check if plane and crew are available at new time
				string tplID = (FlightList.at(index)).GetPlaneID();
				plBusy = isPlaneBusy(tplID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				string tpiID = (FlightList.at(index)).GetPilotID();
				piBusy = isCrewMemberBusy(tpiID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				string tcoID = (FlightList.at(index)).GetCoPilotID();
				coBusy = isCrewMemberBusy(tcoID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				string tc1ID = (FlightList.at(index)).Get1CabinID();
				c1Busy = isCrewMemberBusy(tc1ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				string tc2ID = (FlightList.at(index)).Get2CabinID();
				c2Busy = isCrewMemberBusy(tc2ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				string tc3ID = (FlightList.at(index)).Get3CabinID();
				c3Busy = isCrewMemberBusy(tc3ID, sMon, tempStartDate, tempStartYear, tempStartHour, tempStartMin, eMon, tempEndDate, tempEndYear, tempEndHour, tempEndMin);
				
				if(plBusy == false)
				{
					cout << "ERROR - Plane is busy at this time. Enter a new start/end time.\n";
					plBusy = false;
				}
				else if(piBusy == false)
				{
					cout << "ERROR - Pilot is busy at this time. Enter a new start/end time.\n";
					piBusy = false;
				}
				else if(coBusy == false)
				{
					cout << "ERROR - CoPilot is busy at this time. Enter a new start/end time.\n";
					coBusy = false;
				}
				else if(c1Busy == false)
				{
					cout << "ERROR - Cabin Crew 1 is busy at this time. Enter a new start/end time.\n";
					c1Busy = false;
				}
				else if(c2Busy == false)
				{
					cout << "ERROR - Cabin Crew 2 is busy at this time. Enter a new start/end time.\n";
					c2Busy = false;
				}
				else if(c3Busy == false)
				{
					cout << "ERROR - Cabin Crew 3 is busy at this time. Enter a new start/end time.\n";
					c3Busy = false;
				}
				
			}while(plBusy != true || piBusy != true || coBusy != true || c1Busy != true || c2Busy != true || c3Busy != true);
			
			if(tempStartMonth == 1)
			{
				(FlightList.at(index)).SetStartMonth("January");
				sMon = "January";
			}
			else if(tempStartMonth == 2)
			{
				(FlightList.at(index)).SetStartMonth("February");
				sMon = "February";
			}
			else if(tempStartMonth == 3)
			{
				(FlightList.at(index)).SetStartMonth("March");	
				sMon = "March";
			}
			else if(tempStartMonth == 4)
			{
				(FlightList.at(index)).SetStartMonth("April");
				sMon = "April";
			}
			else if(tempStartMonth == 5)
			{
				(FlightList.at(index)).SetStartMonth("May");
				sMon = "May";
			}
			else if(tempStartMonth == 6)
			{
				(FlightList.at(index)).SetStartMonth("June");
				sMon = "June";
			}
			else if(tempStartMonth == 7)
			{
				(FlightList.at(index)).SetStartMonth("July");
				sMon = "July";
			}
			else if(tempStartMonth == 8)
			{
				(FlightList.at(index)).SetStartMonth("August");
				sMon = "August";
			}
			else if(tempStartMonth == 9)
			{
				(FlightList.at(index)).SetStartMonth("September");
				sMon = "September";
			}
			else if(tempStartMonth == 10)
			{
				(FlightList.at(index)).SetStartMonth("October");
				sMon = "October";
			}
			else if(tempStartMonth == 11)
			{
				(FlightList.at(index)).SetStartMonth("November");
				sMon = "November";
			}
			else if(tempStartMonth == 12)
			{
				(FlightList.at(index)).SetStartMonth("December");
				sMon = "December";
			}
			(FlightList.at(index)).SetStartDate(tempStartDate);
			(FlightList.at(index)).SetStartYear(tempStartYear);
			(FlightList.at(index)).SetStartHour(tempStartHour);
			(FlightList.at(index)).SetStartMin(tempStartMin);	
			
			if(tempEndMonth == 1)
			{
				(FlightList.at(index)).SetEndMonth("January");
				eMon = "January";
			}
			else if(tempEndMonth == 2)
			{
				(FlightList.at(index)).SetEndMonth("February");
				eMon = "February";
			}
			else if(tempEndMonth == 3)
			{
				(FlightList.at(index)).SetEndMonth("March");	
				eMon = "March";
			}
			else if(tempEndMonth == 4)
			{
				(FlightList.at(index)).SetEndMonth("April");
				eMon = "April";
			}
			else if(tempEndMonth == 5)
			{
				(FlightList.at(index)).SetEndMonth("May");
				eMon = "May";
			}
			else if(tempEndMonth == 6)
			{
				(FlightList.at(index)).SetEndMonth("June");
				eMon = "June";
			}
			else if(tempEndMonth == 7)
			{
				(FlightList.at(index)).SetEndMonth("July");
				eMon = "July";
			}
			else if(tempEndMonth == 8)
			{
				(FlightList.at(index)).SetEndMonth("August");
				eMon = "August";
			}
			else if(tempEndMonth == 9)
			{
				(FlightList.at(index)).SetEndMonth("September");
				eMon = "September";
			}
			else if(tempEndMonth == 10)
			{
				(FlightList.at(index)).SetEndMonth("October");
				eMon = "October";
			}
			else if(tempEndMonth == 11)
			{
				(FlightList.at(index)).SetEndMonth("November");
				eMon = "November";
			}
			else if(tempEndMonth == 12)
			{
				(FlightList.at(index)).SetEndMonth("December");
				eMon = "December";
			}
			(FlightList.at(index)).SetEndDate(tempEndDate);
			(FlightList.at(index)).SetEndYear(tempEndYear);
			(FlightList.at(index)).SetEndHour(tempEndHour);
			(FlightList.at(index)).SetEndMin(tempEndMin);
		}
		else if(choice == 9)
		{
			//prompt for starting airport code
			cout << "Enter new starting airport code:\n";
			cin >> tempStartAir;
			
			(FlightList.at(index)).SetStartAirport(tempStartAir);		
		}
		else if(choice == 10)
		{
			//prompt for ending airport code
			do{
				cout << "Enter ending airport code:\n";
				cin >> tempEndAir;
				
				if(tempEndAir == (FlightList.at(index)).GetStartAirport())
					cout << "ERROR - Airport codes must be different. Try again.\n";
			}while(tempEndAir == (FlightList.at(index)).GetStartAirport());
			
			(FlightList.at(index)).SetEndAirport(tempEndAir);
		}
		else if(choice == 11)
		{
			//prompt for number of passengers
			int numberPass = plane.GetNumSeats(tempPlaneID);
			do{
				cout << "Enter number of passengers:\n";
				cin >> tempNumPass;
			
				if(tempNumPass > numberPass)
					cout << "ERROR - Not enough room in plane. Try again.\n";	
			}while(tempNumPass > numberPass);
			
			(FlightList.at(index)).SetNumPassengers(tempNumPass);
		}
		else if(choice == 12)
		{
			//prompt user for status
			do{
				cout << "Enter flight status.\n";
				cout << "\t1 - Active\n\t2 - Cancelled\n\t3 - Completed\n";
				
				cin >> tempStatus;
				
				if(tempStatus < 1 || tempStatus > 3)
					cout << "ERROR - Invalid entry. Try again.\n";	
			}while(tempStatus < 1 || tempStatus > 3);
			
			if(tempStatus == 1)
				(FlightList.at(index)).SetStatus("Active");
			else if(tempStatus == 2)
				(FlightList.at(index)).SetStatus("Cancelled");
			else if(tempStatus == 3)
				(FlightList.at(index)).SetStatus("Completed");		
		}
		
		cout << "Would you like to edit anything else (y/n)? ";
		cin >> again;
	}while(again != 'n' && again != 'N');

	return;
}

void Flights::DeleteFlight() //function to delete a flight
{
	cout << "\nDELETE FLIGHT\n";

	flightCount = FlightList.size();
	
	int flightNum;
	
	//prompt user for flight number
	cout << "Enter the flight number of the flight you want to delete:\n";
	cin >> flightNum;
	
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetFlightNum() == flightNum)
		{
			FlightList.erase(FlightList.begin() + i); //delete flight
			index = i;
			flightCount--;
		}
	}
	
	if(index == -1)
	{
		cout << "ERROR - Flight not found. Nothing deleted.\n";
	}

	return;
}

void Flights::PrintFlights(CrewMembers &crew) //function to print a list of all flights
{
	cout << "\nFLIGHTS\n";
	
	flightCount = FlightList.size();
	
	if(flightCount == 0)
	{
		cout << "No flights scheduled.\n";
		return;
	}
	
	//print details for each flight
	for(int i=0; i<flightCount; i++)
	{
		cout << "\t" << i+1 << ".\n";
		cout << "\tFlight Number: " << (FlightList.at(i)).GetFlightNum() << endl
			 << "\tPlane ID: " << (FlightList.at(i)).GetPlaneID() << endl
			 << "\tPilot: " << crew.GetName((FlightList.at(i)).GetPilotID()) << endl
			 << "\tCoPilot: " << crew.GetName((FlightList.at(i)).GetCoPilotID()) << endl
			 << "\tCabin 1: " << crew.GetName((FlightList.at(i)).Get1CabinID()) << endl
			 << "\tCabin 2: " << crew.GetName((FlightList.at(i)).Get2CabinID()) << endl
			 << "\tCabin 3: " << crew.GetName((FlightList.at(i)).Get3CabinID()) << endl;
		cout << "\tStart Time: " << (FlightList.at(i)).GetStartDate() << " " << (FlightList.at(i)).GetStartMonth() << " " << (FlightList.at(i)).GetStartYear() << " at ";
			if((FlightList.at(i)).GetStartHour() == 0)
			{
				cout << "00";
			}
			else if((FlightList.at(i)).GetStartHour() < 10)
			{
				cout << "0" << (FlightList.at(i)).GetStartHour();
			}
			else if((FlightList.at(i)).GetStartHour() >= 10)
			{
				cout << (FlightList.at(i)).GetStartHour();
			}
			if((FlightList.at(i)).GetStartMin() == 0)
			{
				cout << "00\n";
			}
			else if((FlightList.at(i)).GetStartMin() < 10)
			{
				cout << "0" << (FlightList.at(i)).GetStartMin() << endl;
			}
			else if((FlightList.at(i)).GetStartMin() >= 10)
			{
				cout << (FlightList.at(i)).GetStartMin() << endl;
			}
		cout << "\tEnd Time: " << (FlightList.at(i)).GetEndDate() << " " << (FlightList.at(i)).GetEndMonth() << " " << (FlightList.at(i)).GetEndYear() << " at ";
			if((FlightList.at(i)).GetEndHour() == 0)
			{
				cout << "00";
			}
			else if((FlightList.at(i)).GetEndHour() < 10)
			{
				cout << "0" << (FlightList.at(i)).GetEndHour();
			}
			else if((FlightList.at(i)).GetEndHour() >= 10)
			{
				cout << (FlightList.at(i)).GetEndHour();
			}
			if((FlightList.at(i)).GetEndMin() == 0)
			{
				cout << "00\n";
			}
			else if((FlightList.at(i)).GetEndMin() < 10)
			{
				cout << "0" << (FlightList.at(i)).GetEndMin() << endl;
			}
			else if((FlightList.at(i)).GetEndMin() >= 10)
			{
				cout << (FlightList.at(i)).GetEndMin() << endl;
			}
		cout << "\tStarting Airport: " << (FlightList.at(i)).GetStartAirport() << endl
			 << "\tEnding Airport: " << (FlightList.at(i)).GetEndAirport() << endl
			 << "\tNumber of Passengers: " << (FlightList.at(i)).GetNumPassengers() << endl
			 << "\tStatus: " << (FlightList.at(i)).GetStatus() << endl << endl;
	}
	
	return;
}

void Flights::PrintDetailsForFlight(CrewMembers &crew) //function to print details for a specific flight
{
	cout << "\nPRINT DETAILS FOR FLIGHT\n";

	flightCount = FlightList.size();
	
	int flightNum;
	
	//prompt for flight number
	cout << "Enter the flight number:\n";
	cin >> flightNum;
	
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetFlightNum() == flightNum) //print details if match
		{
			index = i;
			cout << "\tFlight Number: " << (FlightList.at(i)).GetFlightNum() << endl
				 << "\tPlane ID: " << (FlightList.at(i)).GetPlaneID() << endl
				 << "\tPilot: " << crew.GetName((FlightList.at(i)).GetPilotID()) << endl
				 << "\tCoPilot: " << crew.GetName((FlightList.at(i)).GetCoPilotID()) << endl
				 << "\tCabin 1: " << crew.GetName((FlightList.at(i)).Get1CabinID()) << endl
				 << "\tCabin 2: " << crew.GetName((FlightList.at(i)).Get2CabinID()) << endl
				 << "\tCabin 3: " << crew.GetName((FlightList.at(i)).Get3CabinID()) << endl;
			cout << "\tStart Time: " << (FlightList.at(i)).GetStartDate() << " " << (FlightList.at(i)).GetStartMonth() << " " << (FlightList.at(i)).GetStartYear() << " at ";
				if((FlightList.at(i)).GetStartHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetStartHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartHour();
				}
				else if((FlightList.at(i)).GetStartHour() >= 10)
				{
					cout << (FlightList.at(i)).GetStartHour();
				}
				if((FlightList.at(i)).GetStartMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetStartMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartMin() << endl;
				}
				else if((FlightList.at(i)).GetStartMin() >= 10)
				{
					cout << (FlightList.at(i)).GetStartMin() << endl;
				}
			cout << "\tEnd Time: " << (FlightList.at(i)).GetEndDate() << " " << (FlightList.at(i)).GetEndMonth() << " " << (FlightList.at(i)).GetEndYear() << " at ";
				if((FlightList.at(i)).GetEndHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetEndHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndHour();
				}
				else if((FlightList.at(i)).GetEndHour() >= 10)
				{
					cout << (FlightList.at(i)).GetEndHour();
				}
				if((FlightList.at(i)).GetEndMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetEndMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndMin() << endl;
				}
				else if((FlightList.at(i)).GetEndMin() >= 10)
				{
					cout << (FlightList.at(i)).GetEndMin() << endl;
				}
			cout << "\tStarting Airport: " << (FlightList.at(i)).GetStartAirport() << endl
				 << "\tEnding Airport: " << (FlightList.at(i)).GetEndAirport() << endl
				 << "\tNumber of Passengers: " << (FlightList.at(i)).GetNumPassengers() << endl
				 << "\tStatus: " << (FlightList.at(i)).GetStatus() << endl << endl;
		}
	}
	
	if(index == -1)
	{
		cout << "ERROR - Flight not found.\n";
	}
	
	return;
}

void Flights::PrintDetailsForAircraft(CrewMembers &crew) //function to print a plane's scheduled flights
{
	cout << "\nPRINT DETAILS FOR AIRCRAFT\n";

	flightCount = FlightList.size();
	
	string tNum;
	//prompt user for tail number
	cout << "Enter the tail number of aircraft:\n";
	cin >> tNum;
	
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetPlaneID() == tNum) //print info if matches
		{
			index = i;
			cout << "FLIGHT " << i+1 << endl;
			cout << "\tFlight Number: " << (FlightList.at(i)).GetFlightNum() << endl
				 << "\tPlane ID: " << (FlightList.at(i)).GetPlaneID() << endl
				 << "\tPilot: " << crew.GetName((FlightList.at(i)).GetPilotID()) << endl
				 << "\tCoPilot: " << crew.GetName((FlightList.at(i)).GetCoPilotID()) << endl
				 << "\tCabin 1: " << crew.GetName((FlightList.at(i)).Get1CabinID()) << endl
				 << "\tCabin 2: " << crew.GetName((FlightList.at(i)).Get2CabinID()) << endl
				 << "\tCabin 3: " << crew.GetName((FlightList.at(i)).Get3CabinID()) << endl;
			cout << "\tStart Time: " << (FlightList.at(i)).GetStartDate() << " " << (FlightList.at(i)).GetStartMonth() << " " << (FlightList.at(i)).GetStartYear() << " at ";
				if((FlightList.at(i)).GetStartHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetStartHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartHour();
				}
				else if((FlightList.at(i)).GetStartHour() >= 10)
				{
					cout << (FlightList.at(i)).GetStartHour();
				}
				if((FlightList.at(i)).GetStartMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetStartMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartMin() << endl;
				}
				else if((FlightList.at(i)).GetStartMin() >= 10)
				{
					cout << (FlightList.at(i)).GetStartMin() << endl;
				}
			cout << "\tEnd Time: " << (FlightList.at(i)).GetEndDate() << " " << (FlightList.at(i)).GetEndMonth() << " " << (FlightList.at(i)).GetEndYear() << " at ";
				if((FlightList.at(i)).GetEndHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetEndHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndHour();
				}
				else if((FlightList.at(i)).GetEndHour() >= 10)
				{
					cout << (FlightList.at(i)).GetEndHour();
				}
				if((FlightList.at(i)).GetEndMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetEndMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndMin() << endl;
				}
				else if((FlightList.at(i)).GetEndMin() >= 10)
				{
					cout << (FlightList.at(i)).GetEndMin() << endl;
				}
			cout << "\tStarting Airport: " << (FlightList.at(i)).GetStartAirport() << endl
				 << "\tEnding Airport: " << (FlightList.at(i)).GetEndAirport() << endl
				 << "\tNumber of Passengers: " << (FlightList.at(i)).GetNumPassengers() << endl
				 << "\tStatus: " << (FlightList.at(i)).GetStatus() << endl << endl;
			cout << endl;
		}
	}
	
	if(index == -1)
	{
		cout << "No flights with that aircraft found.\n";
	}
	
	return;
}

void Flights::PrintDetailsForCrewMember(CrewMembers &crew) //function to print flights a crew member is working
{
	cout << "\nPRINT DETAILS FOR CREW MEMBER\n";

	flightCount = FlightList.size();
	
	string cID;
	//prompt for crew id
	cout << "Enter the crew member ID:\n";
	cin >> cID;
	
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if(((FlightList.at(i)).GetPilotID() == cID) || ((FlightList.at(i)).GetCoPilotID() == cID) || ((FlightList.at(i)).Get1CabinID() == cID) || ((FlightList.at(i)).Get2CabinID() == cID) || ((FlightList.at(i)).Get3CabinID() == cID))
		{
			index = i;
			cout << "FLIGHT " << i+1 << endl;
			cout << "\tFlight Number: " << (FlightList.at(i)).GetFlightNum() << endl
				 << "\tPlane ID: " << (FlightList.at(i)).GetPlaneID() << endl
				 << "\tPilot: " << crew.GetName((FlightList.at(i)).GetPilotID()) << endl
				 << "\tCoPilot: " << crew.GetName((FlightList.at(i)).GetCoPilotID()) << endl
				 << "\tCabin 1: " << crew.GetName((FlightList.at(i)).Get1CabinID()) << endl
				 << "\tCabin 2: " << crew.GetName((FlightList.at(i)).Get2CabinID()) << endl
				 << "\tCabin 3: " << crew.GetName((FlightList.at(i)).Get3CabinID()) << endl;
			cout << "\tStart Time: " << (FlightList.at(i)).GetStartDate() << " " << (FlightList.at(i)).GetStartMonth() << " " << (FlightList.at(i)).GetStartYear() << " at ";
				if((FlightList.at(i)).GetStartHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetStartHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartHour();
				}
				else if((FlightList.at(i)).GetStartHour() >= 10)
				{
					cout << (FlightList.at(i)).GetStartHour();
				}
				if((FlightList.at(i)).GetStartMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetStartMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartMin() << endl;
				}
				else if((FlightList.at(i)).GetStartMin() >= 10)
				{
					cout << (FlightList.at(i)).GetStartMin() << endl;
				}
			cout << "\tEnd Time: " << (FlightList.at(i)).GetEndDate() << " " << (FlightList.at(i)).GetEndMonth() << " " << (FlightList.at(i)).GetEndYear() << " at ";
				if((FlightList.at(i)).GetEndHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetEndHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndHour();
				}
				else if((FlightList.at(i)).GetEndHour() >= 10)
				{
					cout << (FlightList.at(i)).GetEndHour();
				}
				if((FlightList.at(i)).GetEndMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetEndMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndMin() << endl;
				}
				else if((FlightList.at(i)).GetEndMin() >= 10)
				{
					cout << (FlightList.at(i)).GetEndMin() << endl;
				}
			cout << "\tStarting Airport: " << (FlightList.at(i)).GetStartAirport() << endl
				 << "\tEnding Airport: " << (FlightList.at(i)).GetEndAirport() << endl
				 << "\tNumber of Passengers: " << (FlightList.at(i)).GetNumPassengers() << endl
				 << "\tStatus: " << (FlightList.at(i)).GetStatus() << endl;
			cout << endl;
		}
	}
	
	if(index == -1)
	{
		cout << "No flights with that crew member found.\n";
	}	
	
	return;
}

void Flights::PrintFlightsByStatus(CrewMembers &crew) //function to print flights based on status
{
	cout << "\nPRINT FLIGHTS BY STATUS\n";

	flightCount = FlightList.size();
	
	int tempStatus;
	string stat;
	
	//prompt user for status
	do{
		cout << "Enter flight status.\n";
		cout << "\t1 - Active\n\t2 - Cancelled\n\t3 - Completed\n";
		
		cin >> tempStatus;
		
		if(tempStatus < 1 || tempStatus > 3)
			cout << "ERROR - Invalid entry. Try again.\n";	
	}while(tempStatus < 1 || tempStatus > 3);
	
	if(tempStatus == 1)
		stat = "Active";
	else if(tempStatus == 2)
		stat = "Cancelled";
	else if(tempStatus == 3)
		stat = "Completed";
	
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetStatus() == stat) //print if match
		{
			index = i;
			cout << "FLIGHT " << i+1 << endl;
			cout << "\tFlight Number: " << (FlightList.at(i)).GetFlightNum() << endl
				 << "\tPlane ID: " << (FlightList.at(i)).GetPlaneID() << endl
				 << "\tPilot: " << crew.GetName((FlightList.at(i)).GetPilotID()) << endl
				 << "\tCoPilot: " << crew.GetName((FlightList.at(i)).GetCoPilotID()) << endl
				 << "\tCabin 1: " << crew.GetName((FlightList.at(i)).Get1CabinID()) << endl
				 << "\tCabin 2: " << crew.GetName((FlightList.at(i)).Get2CabinID()) << endl
				 << "\tCabin 3: " << crew.GetName((FlightList.at(i)).Get3CabinID()) << endl;
			cout << "\tStart Time: " << (FlightList.at(i)).GetStartDate() << " " << (FlightList.at(i)).GetStartMonth() << " " << (FlightList.at(i)).GetStartYear() << " at ";
				if((FlightList.at(i)).GetStartHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetStartHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartHour();
				}
				else if((FlightList.at(i)).GetStartHour() >= 10)
				{
					cout << (FlightList.at(i)).GetStartHour();
				}
				if((FlightList.at(i)).GetStartMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetStartMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetStartMin() << endl;
				}
				else if((FlightList.at(i)).GetStartMin() >= 10)
				{
					cout << (FlightList.at(i)).GetStartMin() << endl;
				}
			cout << "\tEnd Time: " << (FlightList.at(i)).GetEndDate() << " " << (FlightList.at(i)).GetEndMonth() << " " << (FlightList.at(i)).GetEndYear() << " at ";
				if((FlightList.at(i)).GetEndHour() == 0)
				{
					cout << "00";
				}
				else if((FlightList.at(i)).GetEndHour() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndHour();
				}
				else if((FlightList.at(i)).GetEndHour() >= 10)
				{
					cout << (FlightList.at(i)).GetEndHour();
				}
				if((FlightList.at(i)).GetEndMin() == 0)
				{
					cout << "00\n";
				}
				else if((FlightList.at(i)).GetEndMin() < 10)
				{
					cout << "0" << (FlightList.at(i)).GetEndMin() << endl;
				}
				else if((FlightList.at(i)).GetEndMin() >= 10)
				{
					cout << (FlightList.at(i)).GetEndMin() << endl;
				}
			cout << "\tStarting Airport: " << (FlightList.at(i)).GetStartAirport() << endl
				 << "\tEnding Airport: " << (FlightList.at(i)).GetEndAirport() << endl
				 << "\tNumber of Passengers: " << (FlightList.at(i)).GetNumPassengers() << endl
				 << "\tStatus: " << (FlightList.at(i)).GetStatus() << endl;
			cout << endl;
		}
	}
	
	if(index == -1)
	{
		cout << "No flights found with that status.\n";
	}

	return;
}

void Flights::DeleteOldFlights() //function to delete completed/cancelled flights
{
	flightCount = FlightList.size();
	
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetStatus() != "Active")
		{
			FlightList.erase(FlightList.begin() + i); //delete flights that are cancelled or completed
			flightCount--;
		}
	}
	
	return;
}

void Flights::UpdateStatus() //function to update status of flight based on time
{
	time_t now;
	
	struct tm nowLocal;
	
	now = time(NULL); //get time from OS
	
	nowLocal = *localtime(&now);
	
	flightCount = FlightList.size();
	int month=0;
	
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetEndMonth() == "January")
			month = 1;
		else if((FlightList.at(i)).GetEndMonth() == "February")
			month = 2;
		else if((FlightList.at(i)).GetEndMonth() == "March")
			month = 3;
		else if((FlightList.at(i)).GetEndMonth() == "April")
			month = 4;
		else if((FlightList.at(i)).GetEndMonth() == "May")
			month = 5;
		else if((FlightList.at(i)).GetEndMonth() == "June")
			month = 6;
		else if((FlightList.at(i)).GetEndMonth() == "July")
			month = 7;
		else if((FlightList.at(i)).GetEndMonth() == "August")
			month = 8;
		else if((FlightList.at(i)).GetEndMonth() == "September")
			month = 9;
		else if((FlightList.at(i)).GetEndMonth() == "October")
			month = 10;
		else if((FlightList.at(i)).GetEndMonth() == "November")
			month = 11;
		else if((FlightList.at(i)).GetEndMonth() == "December")
			month = 12;
		
		//uptdate status
		if((nowLocal.tm_year+1900 > (FlightList.at(i)).GetEndYear()) && (FlightList.at(i)).GetStatus() != "Cancelled")
		{
			(FlightList.at(i)).SetStatus("Completed");
		}
		else if((nowLocal.tm_mon+1 > month) && (FlightList.at(i)).GetStatus() != "Cancelled")
		{
			(FlightList.at(i)).SetStatus("Completed");
		}
		else if(((nowLocal.tm_mon+1 == month) && (nowLocal.tm_mday > (FlightList.at(i)).GetEndDate())) && (FlightList.at(i)).GetStatus() != "Cancelled")
		{
			(FlightList.at(i)).SetStatus("Completed");
		}
		else if(((nowLocal.tm_mon+1 == month) && (nowLocal.tm_mday == (FlightList.at(i)).GetEndDate()) && (nowLocal.tm_hour > (FlightList.at(i)).GetEndHour())) && (FlightList.at(i)).GetStatus() != "Cancelled")
		{
			(FlightList.at(i)).SetStatus("Completed");
		}
		else if(((nowLocal.tm_mon+1 == month) && (nowLocal.tm_mday == (FlightList.at(i)).GetEndDate()) && (nowLocal.tm_hour == (FlightList.at(i)).GetEndHour()) && (nowLocal.tm_min > (FlightList.at(i)).GetEndMin())) && (FlightList.at(i)).GetStatus() != "Cancelled")
		{
			(FlightList.at(i)).SetStatus("Completed");
		}
		else if((FlightList.at(i)).GetStatus() == "Cancelled")
		{
			;
		}// if status is cancelled, do nothing
		else
			(FlightList.at(i)).SetStatus("Active");
	}
	
	return;
}

void Flights::loaddata()
{
	//create input file stream
	ifstream infile;
	//open file and check if failed
	infile.open("flights");
	if(!infile.is_open())
	{
		cout << "File opening failed...\n";
		return;
	}
	
	//read from the file, storing data
	infile >> flightCount;
	infile.ignore();

	Flight tempFlight;
	
	int tempFlightNum, tempStatus;
	string tempPilotID, tempCoPilotID, tempC1ID, tempC2ID, tempC3ID;
	int tempStartDate, tempStartYear, tempEndDate, tempEndYear, tempNumPass, tempStartMonth, tempEndMonth;
	string tempPlaneID, tempStartAir, tempEndAir;
	int tempStartHour, tempStartMin, tempEndHour, tempEndMin;
	
	for(int i=0; i<flightCount; i++)
	{
		infile >> tempFlightNum;
		tempFlight.SetFlightNum(tempFlightNum);
		
		infile >> tempStartMonth;

		if(tempStartMonth == 1)
			tempFlight.SetStartMonth("January");
		else if(tempStartMonth == 2)
			tempFlight.SetStartMonth("February");
		else if(tempStartMonth == 3)
			tempFlight.SetStartMonth("March");	
		else if(tempStartMonth == 4)
			tempFlight.SetStartMonth("April");
		else if(tempStartMonth == 5)
			tempFlight.SetStartMonth("May");
		else if(tempStartMonth == 6)
			tempFlight.SetStartMonth("June");
		else if(tempStartMonth == 7)
			tempFlight.SetStartMonth("July");
		else if(tempStartMonth == 8)
			tempFlight.SetStartMonth("August");
		else if(tempStartMonth == 9)
			tempFlight.SetStartMonth("September");
		else if(tempStartMonth == 10)
			tempFlight.SetStartMonth("October");
		else if(tempStartMonth == 11)
			tempFlight.SetStartMonth("November");
		else if(tempStartMonth == 12)
			tempFlight.SetStartMonth("December");
		
		infile >> tempStartDate;
		tempFlight.SetStartDate(tempStartDate);
		
		infile >> tempStartYear;
		tempFlight.SetStartYear(tempStartYear);
		
		infile >> tempStartHour;
		tempFlight.SetStartHour(tempStartHour);
		
		infile >> tempStartMin;
		tempFlight.SetStartMin(tempStartMin);
		
		infile >> tempEndMonth;
		
		if(tempEndMonth == 1)
			tempFlight.SetEndMonth("January");
		else if(tempEndMonth == 2)
			tempFlight.SetEndMonth("February");
		else if(tempEndMonth == 3)
			tempFlight.SetEndMonth("March");	
		else if(tempEndMonth == 4)
			tempFlight.SetEndMonth("April");
		else if(tempEndMonth == 5)
			tempFlight.SetEndMonth("May");
		else if(tempEndMonth == 6)
			tempFlight.SetEndMonth("June");
		else if(tempEndMonth == 7)
			tempFlight.SetEndMonth("July");
		else if(tempEndMonth == 8)
			tempFlight.SetEndMonth("August");
		else if(tempEndMonth == 9)
			tempFlight.SetEndMonth("September");
		else if(tempEndMonth == 10)
			tempFlight.SetEndMonth("October");
		else if(tempEndMonth == 11)
			tempFlight.SetEndMonth("November");
		else if(tempEndMonth == 12)
			tempFlight.SetEndMonth("December");
		
		infile >> tempEndDate;
		tempFlight.SetEndDate(tempEndDate);
	
		infile >> tempEndYear;
		tempFlight.SetEndYear(tempEndYear);
		
		infile >> tempEndHour;
		tempFlight.SetEndHour(tempEndHour);
		
		infile >> tempEndMin;
		tempFlight.SetEndMin(tempEndMin);
		
		infile >> tempPlaneID;
		tempFlight.SetPlaneID(tempPlaneID);
	
		infile >> tempPilotID;
		tempFlight.SetPilotID(tempPilotID);
		
		infile >> tempCoPilotID;
		tempFlight.SetCoPilotID(tempCoPilotID);
		
		infile >> tempC1ID;
		tempFlight.Set1CabinID(tempC1ID);
		
		infile >> tempC2ID;
		tempFlight.Set2CabinID(tempC2ID);
		
		infile >> tempC3ID;
		tempFlight.Set3CabinID(tempC3ID);
		
		infile >> tempStartAir;
		tempFlight.SetStartAirport(tempStartAir);
	
		infile >> tempEndAir;
		tempFlight.SetEndAirport(tempEndAir);
		
		infile >> tempNumPass;
		tempFlight.SetNumPassengers(tempNumPass);
	
		infile >> tempStatus;
		if(tempStatus == 1)
			tempFlight.SetStatus("Active");
		else if(tempStatus == 2)
			tempFlight.SetStatus("Cancelled");
		else if(tempStatus == 3)
			tempFlight.SetStatus("Completed");

		FlightList.push_back(tempFlight);
	
		tempFlight.clear();
	}
		
	//close file
	infile.close();
	
	cout << "Read in flights.\n";
	
	return;
}

void Flights::storedata()
{
	//create input file stream
	ofstream outfile;
	//open file and check if failed
	outfile.open("flights");
	if(!outfile.is_open())
	{
		cout << "File opening failed...\n";
		return;
	}

	flightCount = FlightList.size();
	outfile << flightCount << endl;
	
	for(int i=0; i<flightCount; i++)
	{
		outfile << (FlightList.at(i)).GetFlightNum() << endl;
		
		if((FlightList.at(i)).GetStartMonth() == "January")
			outfile << 1 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "February")
			outfile << 2 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "March")
			outfile << 3 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "April")
			outfile << 4 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "May")
			outfile << 5 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "June")
			outfile << 6 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "July")
			outfile << 7 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "August")
			outfile << 8 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "September")
			outfile << 9 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "October")
			outfile << 10 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "November")
			outfile << 11 << endl;
		else if((FlightList.at(i)).GetStartMonth() == "December")
			outfile << 12 << endl;
		
		outfile << (FlightList.at(i)).GetStartDate() << endl;
		
		outfile << (FlightList.at(i)).GetStartYear() << endl;
		
		outfile << (FlightList.at(i)).GetStartHour() << endl;
		
		outfile << (FlightList.at(i)).GetStartMin() << endl;
		
		if((FlightList.at(i)).GetEndMonth() == "January")
			outfile << 1 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "February")
			outfile << 2 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "March")
			outfile << 3 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "April")
			outfile << 4 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "May")
			outfile << 5 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "June")
			outfile << 6 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "July")
			outfile << 7 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "August")
			outfile << 8 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "September")
			outfile << 9 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "October")
			outfile << 10 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "November")
			outfile << 11 << endl;
		else if((FlightList.at(i)).GetEndMonth() == "December")
			outfile << 12 << endl;
		
		outfile << (FlightList.at(i)).GetEndDate() << endl;
		
		outfile << (FlightList.at(i)).GetEndYear() << endl;
		
		outfile << (FlightList.at(i)).GetEndHour() << endl;
		
		outfile << (FlightList.at(i)).GetEndMin() << endl;
		
		outfile << (FlightList.at(i)).GetPlaneID() << endl;
		
		outfile << (FlightList.at(i)).GetPilotID() << endl;
		
		outfile << (FlightList.at(i)).GetCoPilotID() << endl;
		
		outfile << (FlightList.at(i)).Get1CabinID() << endl;
		
		outfile << (FlightList.at(i)).Get2CabinID() << endl;
		
		outfile << (FlightList.at(i)).Get3CabinID() << endl;
		
		outfile << (FlightList.at(i)).GetStartAirport() << endl;
		
		outfile << (FlightList.at(i)).GetEndAirport() << endl;
		
		outfile << (FlightList.at(i)).GetNumPassengers() << endl;
		
		if((FlightList.at(i)).GetStatus() == "Active")
			outfile << 1 << " ";
		else if((FlightList.at(i)).GetStatus() == "Cancelled")
			outfile << 2 << " ";
		else if((FlightList.at(i)).GetStatus() == "Completed")
			outfile << 3 << " ";
	}
	
	cout << "Stored flights.\n";
	
	return;
}

bool Flights::isCrewMemberBusy(string cID, string startMonth, int startDate, int startYear, int startHour, int startMin, string endMonth, int endDate, int endYear, int endHour, int endMin)
{
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if(((FlightList.at(i)).GetPilotID() == cID) || ((FlightList.at(i)).GetCoPilotID() == cID) || ((FlightList.at(i)).Get1CabinID() == cID) || ((FlightList.at(i)).Get2CabinID() == cID) || ((FlightList.at(i)).Get3CabinID() == cID))
		{
			index = i;
			if(((FlightList.at(i)).GetStartMonth() == startMonth) && ((FlightList.at(i)).GetStartDate() == startDate) && ((FlightList.at(i)).GetStartYear() == startYear))
			{
				if((FlightList.at(i)).GetStartHour() == startHour)
				{
					if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetEndHour() == startHour))
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else if(((startMonth == endMonth) && (startDate == endDate)) && ((FlightList.at(i)).GetStartHour() == endHour))
					{
						if(endMin < (FlightList.at(i)).GetStartMin())
							return true;
						else 
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetStartHour() > startHour)
				{
					if((FlightList.at(i)).GetStartHour() > endHour)
						return true;
					else if((FlightList.at(i)).GetStartHour() == endHour)
					{
						if((FlightList.at(i)).GetStartMin() > endMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetStartHour() < startHour)
				{
					if((FlightList.at(i)).GetEndHour() < startHour)
						return true;
					else if((FlightList.at(i)).GetEndHour() == startHour)
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
			}
			if(((FlightList.at(i)).GetEndMonth() == endMonth) && ((FlightList.at(i)).GetEndDate() == endDate) && ((FlightList.at(i)).GetEndYear() == endYear))
			{
				if((FlightList.at(i)).GetEndHour() == endHour)
				{
					if(((startMonth == endMonth) && (startDate == endDate)) && (startHour == endHour))
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetStartHour() == endHour))
					{
						if(endMin < (FlightList.at(i)).GetStartMin())
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetEndHour() > endHour)
				{
					if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetStartHour() > endHour))
						return true;
					else if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetStartHour() == endHour))
					{
						if((FlightList.at(i)).GetStartMin() > endMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetEndHour() < endHour)
				{
					if(((FlightList.at(i)).GetEndHour() < startHour) && (((startMonth == endMonth) && (startDate == endDate)) && (startHour == endHour)))
						return true;
					else if(((FlightList.at(i)).GetEndHour() == startHour)  && (((startMonth == endMonth) && (startDate == endDate)) && (startHour == endHour)))
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
			}
			if(((FlightList.at(i)).GetStartDate() == endDate) && ((FlightList.at(i)).GetStartMonth() == endMonth) && ((FlightList.at(i)).GetStartYear() == endYear))
			{
				if((FlightList.at(i)).GetStartHour() > endHour)
					return true;
				else if((FlightList.at(i)).GetStartHour() == endHour)
				{
					if((FlightList.at(i)).GetStartMin() > endMin)
						return true;
					else
						return true;
				}
				else
					return false;
			}
			if(((FlightList.at(i)).GetEndDate() == startDate) && ((FlightList.at(i)).GetEndMonth() == startMonth) && ((FlightList.at(i)).GetEndYear() == startYear))
			{
				if((FlightList.at(i)).GetEndHour() < startHour)
					return true;
				else if((FlightList.at(i)).GetEndHour() == startHour)
				{
					if((FlightList.at(i)).GetEndMin() < startMin)
						return true;
					else
						return false;
				}
				else
					return false;
			}
		}
	}
	
	if(index == -1)
		return true;
	
	return true;
}

bool Flights::isPlaneBusy(string pID, string startMonth, int startDate, int startYear, int startHour, int startMin, string endMonth, int endDate, int endYear, int endHour, int endMin)
{
	int index = -1;
	for(int i=0; i<flightCount; i++)
	{
		if((FlightList.at(i)).GetPlaneID() == pID)
		{
			index = i;
			if(((FlightList.at(i)).GetStartMonth() == startMonth) && ((FlightList.at(i)).GetStartDate() == startDate) && ((FlightList.at(i)).GetStartYear() == startYear))
			{
				if((FlightList.at(i)).GetStartHour() == startHour)
				{
					if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetEndHour() == startHour))
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else if(((startMonth == endMonth) && (startDate == endDate)) && ((FlightList.at(i)).GetStartHour() == endHour))
					{
						if(endMin < (FlightList.at(i)).GetStartMin())
							return true;
						else 
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetStartHour() > startHour)
				{
					if((FlightList.at(i)).GetStartHour() > endHour)
						return true;
					else if((FlightList.at(i)).GetStartHour() == endHour)
					{
						if((FlightList.at(i)).GetStartMin() > endMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetStartHour() < startHour)
				{
					if((FlightList.at(i)).GetEndHour() < startHour)
						return true;
					else if((FlightList.at(i)).GetEndHour() == startHour)
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
			}
			if(((FlightList.at(i)).GetEndMonth() == endMonth) && ((FlightList.at(i)).GetEndDate() == endDate) && ((FlightList.at(i)).GetEndYear() == endYear))
			{
				if((FlightList.at(i)).GetEndHour() == endHour)
				{
					if(((startMonth == endMonth) && (startDate == endDate)) && (startHour == endHour))
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetStartHour() == endHour))
					{
						if(endMin < (FlightList.at(i)).GetStartMin())
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetEndHour() > endHour)
				{
					if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetStartHour() > endHour))
						return true;
					else if((((FlightList.at(i)).GetStartDate() == (FlightList.at(i)).GetEndDate()) && ((FlightList.at(i)).GetStartMonth() == (FlightList.at(i)).GetEndMonth())) && ((FlightList.at(i)).GetStartHour() == endHour))
					{
						if((FlightList.at(i)).GetStartMin() > endMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
				else if((FlightList.at(i)).GetEndHour() < endHour)
				{
					if(((FlightList.at(i)).GetEndHour() < startHour) && (((startMonth == endMonth) && (startDate == endDate)) && (startHour == endHour)))
						return true;
					else if(((FlightList.at(i)).GetEndHour() == startHour)  && (((startMonth == endMonth) && (startDate == endDate)) && (startHour == endHour)))
					{
						if((FlightList.at(i)).GetEndMin() < startMin)
							return true;
						else
							return false;
					}
					else
						return false;
				}
			}
			if(((FlightList.at(i)).GetStartDate() == endDate) && ((FlightList.at(i)).GetStartMonth() == endMonth) && ((FlightList.at(i)).GetStartYear() == endYear))
			{
				if((FlightList.at(i)).GetStartHour() > endHour)
					return true;
				else if((FlightList.at(i)).GetStartHour() == endHour)
				{
					if((FlightList.at(i)).GetStartMin() > endMin)
						return true;
					else
						return true;
				}
				else
					return false;
			}
			if(((FlightList.at(i)).GetEndDate() == startDate) && ((FlightList.at(i)).GetEndMonth() == startMonth) && ((FlightList.at(i)).GetEndYear() == startYear))
			{
				if((FlightList.at(i)).GetEndHour() < startHour)
					return true;
				else if((FlightList.at(i)).GetEndHour() == startHour)
				{
					if((FlightList.at(i)).GetEndMin() < startMin)
						return true;
					else
						return false;
				}
				else
					return false;
			}
		}
	}
	
	if(index == -1)
		return true;

	return true;
}