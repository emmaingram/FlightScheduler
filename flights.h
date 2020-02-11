/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the class definition for Flights class
*/

#include "flight.h"

class Flights{
	public:
		void AddFlight(Planes &plane, CrewMembers &crew); //function to add a flight
		void EditFlight(Planes &plane, CrewMembers &crew); //function to edit a flight
		void DeleteFlight(); //function to delete a flight
		void PrintFlights(CrewMembers &crew); //function to print a list of all flights
		void PrintDetailsForFlight(CrewMembers &crew); //function to print details for a specific flight
		void PrintDetailsForAircraft(CrewMembers &crew); //function to print a plane's scheduled flights
		void PrintDetailsForCrewMember(CrewMembers &crew); //function to print flights a crew member is working
		void PrintFlightsByStatus(CrewMembers &crew); //function to print flights based on status
		void DeleteOldFlights(); //function to delete completed/cancelled flights
		void UpdateStatus(); //function to update status of flights
		bool isCrewMemberBusy(string cID, string startMonth, int startDate, int startYear, int startHour, int startMin, string endMonth, int endDate, int endYear, int endHour, int endMin); //function to check if crew member is busy
		bool isPlaneBusy(string pID, string startMonth, int startDate, int startYear, int startHour, int startMin, string endMonth, int endDate, int endYear, int endHour, int endMin); //function to check if plane is busy
		void loaddata(); //function to load data
		void storedata(); //function to store data
	private:
		int flightCount;
		vector <Flight> FlightList;
};