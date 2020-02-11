/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the class definition for Flight class
*/

#include "crews.h"
#include "planes.h"

class Flight{
	public:
		Flight(); //default constructor
		void SetFlightNum(int fNum); //function to set flight number (ID)
		int GetFlightNum(); //function to get flight number (ID)
		void SetPlaneID(string pID); //function to set plane id (tail number)
		string GetPlaneID(); //function to get plane id (tail number)
		void SetPilotID(string pilID); //function to set pilot id
		string GetPilotID(); //function to get pilot id
		void SetCoPilotID(string copID); //function to set copilot id
		string GetCoPilotID(); //function to get copilot id
		void Set1CabinID(string c1ID); //function to set first cabin id
		string Get1CabinID(); //function to get first cabin id
		void Set2CabinID(string c2ID); //function to set second cabin id
		string Get2CabinID(); //function to get second cabin id
		void Set3CabinID(string c3ID); //function to set third cabin id
		string Get3CabinID(); //function to get third cabin id
		void SetStartDate(int sDate); //function to set start date
		int GetStartDate(); //function to get start date
		void SetStartMonth(string sMonth); //function to set start month
		string GetStartMonth(); //function to get start month
		void SetStartYear(int sYear); //function to set start year
		int GetStartYear(); //function to get start year
		void SetEndDate(int eDate); //function to set End date
		int GetEndDate(); //function to get End date
		void SetEndMonth(string eMonth); //function to set End month
		string GetEndMonth(); //function to get End month
		void SetEndYear(int eYear); //function to set End year
		int GetEndYear(); //function to get end year
		void SetStartAirport(string sAir); //function to set starting airport code
		string GetStartAirport(); //function to get starting airport code
		void SetEndAirport(string eAir); //function to set ending airport code
		string GetEndAirport(); //function to get ending airport code
		void SetNumPassengers(int numPass); //function to set number of passengers
		int GetNumPassengers(); //function to get number of passengers
		void SetStatus(string fStatus); //function to set status of flight
		string GetStatus(); //function to get status of flight
		void PrintDetails(); //function to print details of flight
		void clear(); //function to clear all variables
		void SetStartHour(int sHour); //function to set start time
		int GetStartHour(); //function to get start time
		void SetStartMin(int sMin);//function to set start time
		int GetStartMin(); //function to get start time
		void SetEndHour(int eHour);//function to set end time
		int GetEndHour(); //function to get end time
		void SetEndMin(int eMin);//function to set end time
		int GetEndMin(); //function to get end time
	private:
		int flightNum; //flight number (ID)
		string planeID; //tail number
		string pilotID; //string for pilot ID
		string copilotID; //string for copilot id
		string cabin1ID; //string for first cabin crew id
		string cabin2ID; //string for second cabin crew id
		string cabin3ID; //string for third cabin crew id
		int startDate; //int for date of start time
		string startMonth; //int for starting month
		int startYear; //int for starting year
		int endDate; //int for ending date
		string endMonth; //string for ending month
		int endYear; //int for ending year
		string startAirport; //string for starting airport code
		string endAirport; //string for ending airport code
		int numPassengers; //int for number of passengers
		string status; //string for status of flight
		int startHour; //int for start time
		int startMin;//int for start time
		int endHour;//int for end time
		int endMin; //int for end time
};