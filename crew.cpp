/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the function definitions for Crew Member functions
*/

#include "crew.h"

CrewMember::CrewMember()
{
	name = " ";
	id = " ";
	type = " ";
	status = " ";
	return;
}

void CrewMember::SetName(string cmName) //function to set name
{
	name = cmName;
	return;
}

string CrewMember::GetName() //function to get name
{
	return name;
}

void CrewMember::SetID(string cmID) //function to set id
{
	id = cmID;
	return;
}

string CrewMember::GetID() //function to get id
{
	return id;
}

void CrewMember::SetType(string cmType) //function to set type
{
	type = cmType;
	return;
}

string CrewMember::GetType() //function to get type
{
	return type;
}

void CrewMember::SetStatus(string cmStatus) //functiton to set status
{
	status = cmStatus;
	return;
}

string CrewMember::GetStatus() //function to get status
{
	return status;
}

void CrewMember::PrintDetails() //function to print details for crew member
{
	cout << "\tName: " << name << endl
		 << "\tID: " << id << endl
		 << "\tType: " << type << endl
		 << "\tStatus: " << status << endl;
}

void CrewMember::clear() //function to clear data
{
	name = " ";
	id = " ";
	type = " ";
	status = " ";
	return;	
}