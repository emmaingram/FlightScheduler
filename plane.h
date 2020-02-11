/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the class definition for Plane
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//define class
class Plane{
	public:
		Plane(); //default constructor
		void SetMake(string pMake);//function to set make
		string GetMake(); //function to get make
		void SetModel(int pModel); //function to set model
		int GetModel(); //function to get model
		void SetTailNumber(string pTailNumber); //function to set tail number
		string GetTailNumber(); //function to get tail number
		void SetRange(int pRange); //function to set plane range
		int GetRange(); //function to get range
		void SetStatus(string pStatus); //function to set status
		string GetStatus(); //function to get status
		void SetNumSeats(int pSeats); //function to set number of seats
		int GetNumSeats(); //function to get number of seats
		void clear(); //function to clear data in plane
		void PrintDetails(); //function to print details
	private:
		string make; //string for make of plane
		int model; //int for model of plane
		string tailNumber; //string for tail number
		int range; //int for range
		string status; //string for status
		int numSeats; //int for number of seats
};