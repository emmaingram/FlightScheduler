/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the function definitions for Plane functions
*/

#include "plane.h"

//default constructor
Plane::Plane()
{
	make = " ";
	model = 0;
	tailNumber = " ";
	range = 0;
	status = " ";
	numSeats = 0;
	return;
}

void Plane::SetMake(string pMake)//function to set make
{
	make = pMake;
	return;
}

string Plane::GetMake() //function to get make
{
	return make;
}

void Plane::SetModel(int pModel) //function to set model
{
	model = pModel;
	return;
}

int Plane::GetModel() //function to get model
{
	return model;
}

void Plane::SetTailNumber(string pTailNumber) //function to set tail number
{
	tailNumber = pTailNumber;
	return;
}

string Plane::GetTailNumber() //function to get tail number
{
	return tailNumber;
}

void Plane::SetRange(int pRange) //function to set plane range
{
	range = pRange;
	return;
}

int Plane::GetRange() //function to get range
{
	return range;
}

void Plane::SetStatus(string pStatus) //function to set status
{
	status = pStatus;
	return;
}

string Plane::GetStatus() //function to get status
{
	return status;
}

void Plane::SetNumSeats(int pSeats) //function to set plane range
{
	numSeats = pSeats;
	return;
}

int Plane::GetNumSeats() //function to get range
{
	return numSeats;
}

void Plane::PrintDetails() //function to print details
{
	cout << "\tMake: " << make << endl;
	cout << "\tModel: " << model << endl;
	cout << "\tTail Number: " << tailNumber << endl;
	cout << "\tRange: " << range << endl;
	cout << "\tNumber of Seats: " << numSeats << endl;
	cout << "\tStatus: " << status << endl;
}

void Plane::clear() //function to clear data
{
	make = " ";
	model = 0;
	tailNumber = " ";
	range = 0;
	status = " ";
	numSeats = 0;
	return;	
}