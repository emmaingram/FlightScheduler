/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the class definition for Crew Member
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class CrewMember{
	public:
		CrewMember(); //default constructor
		void SetName(string cmName); //function to set name
		string GetName(); //function to get name
		void SetID(string cmID); //function to set id
		string GetID(); //function to get id
		void SetType(string cmType); //function to set type
		string GetType(); //function to get type
		void SetStatus(string cmStatus); //functiton to set status
		string GetStatus(); //function to get status
		void clear(); //function to clear data
		void PrintDetails(); //function to print details
	private:
		string name; //string for name
		string id; // int for crew id
		string type; //string for type
		string status; //string for status
};