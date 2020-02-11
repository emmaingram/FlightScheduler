/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the class definition for Planes
*/

#include "plane.h"

//define class
class Planes{
	public:
		void AddPlane(); //function to add a plane
		void EditPlane(); //function to edit a plane
		void DeletePlane(); //function to delete plane
		void PrintPlanes(); //function to print list of all planes
		void PrintDetailsForPlane(); //function to print details for single plane
		bool SearchForPlane(string tNum); //function to see if plane exists
		bool PlaneAvailable(string tNum); //function to see if plane is available
		int GetNumSeats(string tNum); //function to get number of seats
		void loaddata();//function to load data
		void storedata(); //function to store data
	private:
		int planeCount;
		vector <Plane> PlaneList;
};