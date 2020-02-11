/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the class definition for Crew Members
*/

#include "crew.h"

class CrewMembers{
	public:
		void AddCrewMember(); //function to add a crew member
		void EditCrewMember(); //function to edit a crew member
		void DeleteCrewMember(); //function to delete a crew member
		void PrintCrewMembers(); //function to print details for every crew member
		void PrintDetailsForCrew(); //function to print details for a specific crew member
		bool SearchForCrew(string cID); //function to see if crew member exists
		bool IsPilot(string cID); //function to see if crew member is pilot
		bool IsCopilot(string cID); //function to see if crew member is copilot
		bool IsCabin(string cID); //function to see if crew member is cabin
		bool IsAvailable(string cID); //function to see if crew member is available
		void loaddata(); //function to load data
		void storedata(); //function to store data
		string GetName(string cID); //function to get crew member name
	private:
		int crewCount;
		vector <CrewMember> CrewList;
};