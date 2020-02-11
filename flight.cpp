/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the function definitions for Flight class
*/

#include "flight.h"

Flight::Flight()
{
	flightNum = 0;
	planeID = " ";
	pilotID = " ";
	copilotID = " ";
	cabin1ID = " ";
	cabin2ID = " ";
	cabin3ID = " ";
	startDate = 0;
	startMonth = " ";
	startYear = 0;
	endDate = 0;
	endMonth = " ";
	endYear = 0;
	startAirport = " ";
	endAirport = " ";
	numPassengers = 0;
	status = " ";
}

void Flight::SetFlightNum(int fNum) //function to set flight number (ID)
{
	flightNum = fNum;
	return;
}

int Flight::GetFlightNum() //function to get flight number (ID)
{
	return flightNum;
}

void Flight::SetPlaneID(string pID) //function to set plane id (tail number)
{
	planeID = pID;
	return;
}

string Flight::GetPlaneID() //function to get plane id (tail number)
{
	return planeID;
}

void Flight::SetPilotID(string pilID) //function to set pilot id
{
	pilotID = pilID;
	return;
}

string Flight::GetPilotID() //function to get pilot id
{
	return pilotID;
}

void Flight::SetCoPilotID(string copID) //function to set copilot id
{
	copilotID = copID;
	return;
}

string Flight::GetCoPilotID() //function to get copilot id
{
	return copilotID;
}

void Flight::Set1CabinID(string c1ID) //function to set first cabin id
{
	cabin1ID = c1ID;
	return;
}

string Flight::Get1CabinID() //function to get first cabin id
{
	return cabin1ID;
}

void Flight::Set2CabinID(string c2ID) //function to set second cabin id
{
	cabin2ID = c2ID;
	return;
}

string Flight::Get2CabinID() //function to get second cabin id
{
	return cabin2ID;
}

void Flight::Set3CabinID(string c3ID) //function to set third cabin id
{
	cabin3ID = c3ID;
	return;
}

string Flight::Get3CabinID() //function to get third cabin id
{
	return cabin3ID;
}

void Flight::SetStartDate(int sDate) //function to set start date
{
	startDate = sDate;
	return;
}

int Flight::GetStartDate() //function to get start date
{
	return startDate;
}

void Flight::SetStartMonth(string sMonth) //function to set start month
{
	startMonth = sMonth;
	return;
}

string Flight::GetStartMonth() //function to get start month
{
	return startMonth;
}

void Flight::SetStartYear(int sYear) //function to set start year
{
	startYear = sYear;
	return;
}

int Flight::GetStartYear() //function to get start year
{
	return startYear;
}

void Flight::SetEndDate(int eDate) //function to set End date
{
	endDate = eDate;
	return;
}

int Flight::GetEndDate() //function to get End date
{
	return endDate;
}

void Flight::SetEndMonth(string eMonth) //function to set End month
{
	endMonth = eMonth;
	return;
}

string Flight::GetEndMonth() //function to get End month
{
	return endMonth;
}

void Flight::SetEndYear(int eYear) //function to set End year
{
	endYear = eYear;
	return;
}

int Flight::GetEndYear() //function to get end year
{
	return endYear;
}

void Flight::SetStartAirport(string sAir) //function to set starting airport code
{
	startAirport = sAir;
	return;
}

string Flight::GetStartAirport() //function to get starting airport code
{
	return startAirport;
}

void Flight::SetEndAirport(string eAir) //function to set ending airport code
{
	endAirport = eAir;
	return;
}

string Flight::GetEndAirport() //function to get ending airport code
{
	return endAirport;
}

void Flight::SetNumPassengers(int numPass) //function to set number of passengers
{
	numPassengers = numPass;
	return;
}

int Flight::GetNumPassengers() //function to get number of passengers
{
	return numPassengers;
}

void Flight::SetStatus(string fStatus) //function to set status of flight
{
	status = fStatus;
	return;
}

string Flight::GetStatus() //function to get status of flight
{
	return status;
}

void Flight::PrintDetails() //function to print details for flight
{
	cout << "\tFlight Number: " << flightNum << endl
		 << "\tPlane ID: " << planeID << endl
		 << "\tPilot: " << pilotID << endl
		 << "\tCoPilot: " << copilotID << endl
		 << "\tCabin 1: " << cabin1ID << endl
		 << "\tCabin 2: " << cabin2ID << endl
		 << "\tCabin 3: " << cabin3ID << endl
		 << "\tStart Time: " << startDate << " " << startMonth << " " << startYear << endl
		 << "\tEnd Time: " << endDate << " " << endMonth  << " " << endYear << endl
		 << "\tStarting Airport: " << startAirport << endl
		 << "\tEnding Airport: " << endAirport << endl
		 << "\tNumber of Passengers: " << numPassengers << endl
		 << "\tStatus: " << status << endl;
}

void Flight::SetStartHour(int sHour) //function to set start time
{
	startHour = sHour;
	return;
}

int Flight::GetStartHour()//function to get start time
{
	return startHour;
}

void Flight::SetStartMin(int sMin)//function to set start time
{
	startMin = sMin;
	return;
}

int Flight::GetStartMin()//function to get start time
{
	return startMin;
}

void Flight::SetEndHour(int eHour)//function to set end time
{
	endHour = eHour;
	return;
}

int Flight::GetEndHour() //function to get end time
{
	return endHour;
}

void Flight::SetEndMin(int eMin)//function to set end time
{
	endMin = eMin;
	return;
}

int Flight::GetEndMin() //function to get end time
{
	return endMin;
}

void Flight::clear() //fuction to clear values
{
	flightNum = 0;
	planeID = " ";
	pilotID = " ";
	copilotID = " ";
	cabin1ID = " ";
	cabin2ID = " ";
	cabin3ID = " ";
	startDate = 0;
	startMonth = " ";
	startYear = 0;
	endDate = 0;
	endMonth = " ";
	endYear = 0;
	startAirport = " ";
	endAirport = " ";
	numPassengers = 0;
	status = " ";
}