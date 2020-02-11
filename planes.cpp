/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the function definitions for Planes class
*/

#include "planes.h"

void Planes::AddPlane() //function to add a plane
{
	planeCount = PlaneList.size();
	
	string tempMake, tempTNum;
	int tempModel, tempRange, tempStatus, tempSeats;
	
	Plane tempPlane;

	cout << "\nADD PLANE\n";
	
	//prompt user for make
	cout << "Enter make of plane:\n";
	getline(cin, tempMake);
	
	tempPlane.SetMake(tempMake);
	
	//promt user for model
	cout << "Enter model of plane:\n";
	cin >> tempModel;
	
	tempPlane.SetModel(tempModel);
	
	//prompt user for tail number
	cout << "Enter plane tail number:\n";
	cin >> tempTNum;
	
	int test=-1;
	//check if tail number is already used
	do{
		for(int i=0; i<planeCount; i++)
		{
			test = -1;
			if((PlaneList.at(i)).GetTailNumber() == tempTNum)
			{
				cout << "ERROR - Tail Number already taken.\n";
				cout << "Try again:\n";
				cin >> tempTNum;
				test++;
			}
		}
	}while(test != -1);//if tail number is used, test will not be -1
	//if tail number is not used, test will still be -1
	
	tempPlane.SetTailNumber(tempTNum);
	
	//prompt user for range of plane
	cout << "Enter range of plane in miles:\n";
	cin >> tempRange;
	
	//check if range is positive and re-promopt if not
	while(tempRange <= 0)
	{
		cout << "ERROR - Invalid range. Please enter a positive number.\n";
		cout << "Enter range of plane:\n";
		cin >> tempRange;
	}
	
	tempPlane.SetRange(tempRange);
	
	//prompt user for number of seats
	cout << "Enter number of seats:\n";
	cin >> tempSeats;
	
	//check if range is positive and re-promopt if not
	while(tempSeats <= 0)
	{
		cout << "ERROR - Invalid number of seats. Please enter a positive number.\n";
		cout << "Enter number of seats on plane:\n";
		cin >> tempSeats;
	}
	
	tempPlane.SetNumSeats(tempSeats);
	
	//prompt user for status
	cout << "Enter status of plane:\n"
		 << "\t1 - In\n\t2 - Out\n\t3 - Repair\n";
	cin >> tempStatus;
	
	//check for valid input
	while(tempStatus != 1 && tempStatus != 2 && tempStatus != 3)
	{
		cout << "ERROR - Invalid Entry.\n";
		cout << "Enter status of plane:\n"
			 << "\t1 - In\n\t2 - Out\n\t3 - Repair\n";
		cin >> tempStatus;
	}
	
	//set status according to menu and user input
	if(tempStatus == 1)
		tempPlane.SetStatus("In");
	else if(tempStatus == 2)
		tempPlane.SetStatus("Out");
	else if(tempStatus == 3)
		tempPlane.SetStatus("Repair");
	else
		cout << "ERROR TO PROGRAMMER:\n\tStatus: " << tempStatus << endl;
	
	PlaneList.push_back(tempPlane);
	
	tempPlane.clear();
	
	return;
}

void Planes::EditPlane() //function to edit a plane
{
	planeCount = PlaneList.size();
	
	string tNum, tempMake, tempTNum;
	int tempModel, tempRange, tempStatus, tempSeats;
	
	cout << "\nEDIT PLANE\n";

	int index = -1;
	//prompt user for tail number
	do{
		cout << "Enter tail number of plane to edit:\n";
		cin >> tNum;		
		
		index = -1;
		for(int i=0; i<planeCount; i++)
		{
			if((PlaneList.at(i)).GetTailNumber() == tNum)
				index = i;
		}
		
		if(index == -1)
			cout << "ERROR - Plane not found. Try again.\n";
	}while(index == -1);
	
	int choice;
	char again;
	
	//prompt user for entity to edit
	do{
		cout << "What would you like to edit?\n";
		cout << "\t1 - Make\n"
			 << "\t2 - Model\n"
			 << "\t3 - Tail Number\n"
			 << "\t4 - Range\n"
			 << "\t5 - Number of Seats\n"
			 << "\t6 - Status\n"
			 << "\t7 - Cancel\n";

		cin >> choice;
		
		//edit make
		if(choice == 1)
		{
			//prompt user for make
			cout << "Enter make of plane:\n";
			cin.ignore();
			getline(cin, tempMake);
			
			(PlaneList.at(index)).SetMake(tempMake);
		}
		else if(choice == 2) //edit model
		{
			//promt user for model
			cout << "Enter model of plane:\n";
			cin >> tempModel;
	
			(PlaneList.at(index)).SetModel(tempModel);
		}
		else if(choice == 3) //edit tail number
		{
			//prompt user for tail number
			cout << "Enter plane tail number:\n";
			cin >> tempTNum;
			
			int test=-1;
			//check if tail number is already used
			do{
				for(int i=0; i<planeCount; i++)
				{
					test = -1;
					if((PlaneList.at(i)).GetTailNumber() == tempTNum)
					{
						cout << "ERROR - Tail Number already taken.\n";
						cout << "Try again:\n";
						cin >> tempTNum;
						test++;
					}
				}
			}while(test != -1);//if tail number is used, test will not be -1
			//if tail number is not used, test will still be -1
			
			(PlaneList.at(index)).SetTailNumber(tempTNum);
					
		}
		else if(choice == 4)
		{
			//prompt user for range of plane
			cout << "Enter range of plane in miles:\n";
			cin >> tempRange;
			
			//check if range is positive and re-promopt if not
			while(tempRange <= 0)
			{
				cout << "ERROR - Invalid range. Please enter a positive number.\n";
				cout << "Enter range of plane:\n";
				cin >> tempRange;
			}
			
			(PlaneList.at(index)).SetRange(tempRange);
		}
		else if(choice == 5)
		{
			//prompt user for number of seats
			cout << "Enter number of seats:\n";
			cin >> tempSeats;
			
			//check if range is positive and re-promopt if not
			while(tempSeats <= 0)
			{
				cout << "ERROR - Invalid number of seats. Please enter a positive number.\n";
				cout << "Enter number of seats on plane:\n";
				cin >> tempSeats;
			}
			
			(PlaneList.at(index)).SetNumSeats(tempSeats);
		}
		else if(choice == 6)
		{
			//prompt user for status
			cout << "Enter status of plane:\n"
				 << "\t1 - In\n\t2 - Out\n\t3 - Repair\n";
			cin >> tempStatus;
			
			//check for valid input
			while(tempStatus != 1 && tempStatus != 2 && tempStatus != 3)
			{
				cout << "ERROR - Invalid Entry.\n";
				cout << "Enter status of plane:\n"
					 << "\t1 - In\n\t2 - Out\n\t3 - Repair\n";
				cin >> tempStatus;
			}
			
			//set status according to menu and user input
			if(tempStatus == 1)
				(PlaneList.at(index)).SetStatus("In");
			else if(tempStatus == 2)
				(PlaneList.at(index)).SetStatus("Out");
			else if(tempStatus == 3)
				(PlaneList.at(index)).SetStatus("Repair");
			else
				cout << "ERROR TO PROGRAMMER:\n\tStatus: " << tempStatus << endl;			
		}
		else if(choice == 7)
		{
			break;
		}
		
		cout << "Do you want to edit anything else? (y/n):\n";
		cin >> again;
		
	}while(again != 'N' && again != 'n');
	
	return;
}

void Planes::DeletePlane() //function to delete plane
{
	planeCount = PlaneList.size();

	cout << "\nDELETE PLANE\n";
	
	string tNum;
	
	//prompt user for tail number
	cout << "Enter tail number of plane to delete:\n";
	cin >> tNum;
	
	int index = -1;
	for(int i=0; i<planeCount; i++)
	{
		if((PlaneList.at(i)).GetTailNumber() == tNum)
		{
			//delete plane
			PlaneList.erase(PlaneList.begin() + i);
			index = i;
			planeCount--;
		}
	}
	
	if(index == -1)
	{
		cout << "Plane not found. Nothing deleted\n";		
	}
	
	return;
}

void Planes::PrintPlanes() //function to print list of all planes
{
	planeCount = PlaneList.size();
	
	if(planeCount == 0)
	{
		cout << "No planes in system.\n";
		return;
	}
	
	cout << "PLANES:\n";
	
	//print details for each plane
	for(int i=0; i<planeCount; i++)
	{
		(PlaneList.at(i)).PrintDetails();
		cout << endl;
	}
	
	return;
}

void Planes::PrintDetailsForPlane() //function to print details for single plane
{
	cout << "\nPRINT DETAILS FOR PLANE\n";
	
	//prompt user for tail number
	cout << "Enter tail number of plane:\n";
	string tNum;
	cin >> tNum;
	
	planeCount = PlaneList.size();
	
	int index = -1;
	for(int i=0; i<planeCount; i++)
	{
		if((PlaneList.at(i)).GetTailNumber() == tNum)
		{
			//print details for plane
			(PlaneList.at(i)).PrintDetails();
			index = i;
		}
	}
	
	if(index == -1)
	{
		cout << "Plane not found.\n";
	}
	
	return;
}

bool Planes::SearchForPlane(string tNum) //function to search for plane
{
	planeCount = PlaneList.size();

	for(int i=0; i<planeCount; i++)
	{
		if((PlaneList.at(i)).GetTailNumber() == tNum) //plane exists
			return true;
	}
	
	return false;
}

bool Planes::PlaneAvailable(string tNum) //function to see if plane is available
{
	planeCount = PlaneList.size();

	for(int i=0; i<planeCount; i++)
	{
		if((PlaneList.at(i)).GetTailNumber() == tNum)
		{
			if((PlaneList.at(i)).GetStatus() == "In") //plane is available
				return true;
		}
	}
	
	return false;
}

int Planes::GetNumSeats(string tNum) //function to get number of seats
{
	planeCount = PlaneList.size();

	for(int i=0; i<planeCount; i++)
	{
		if((PlaneList.at(i)).GetTailNumber() == tNum)
		{
			int seats = (PlaneList.at(i)).GetNumSeats();
			return seats; //returns number of seats in plane
		}
	}

	return 0;
}

void Planes::loaddata()
{
	//create input file stream
	ifstream infile;
	//open file and check if failed
	infile.open("planes");
	if(!infile.is_open())
	{
		cout << "File opening failed...\n";
		return;
	}
	
	//read from the file, storing data
	infile >> planeCount;
	infile.ignore();
	
	string tempMake, tempTNum;
	int tempModel, tempRange, tempStatus, tempSeats;
	
	Plane tempPlane;

	for(int i=0; i<planeCount; i++)
	{
		//get make
		getline(infile, tempMake);
		tempPlane.SetMake(tempMake);

		//get model
		infile >> tempModel;
		tempPlane.SetModel(tempModel);

		//get tail number]
		infile >> tempTNum;
		tempPlane.SetTailNumber(tempTNum);

		//get range of plane
		infile >> tempRange;
		tempPlane.SetRange(tempRange);

		//get number of seats
		infile >> tempSeats;
		tempPlane.SetNumSeats(tempSeats);

		//get status
		infile >> tempStatus;

		//set status according to menu and user input
		if(tempStatus == 1)
			tempPlane.SetStatus("In");
		else if(tempStatus == 2)
			tempPlane.SetStatus("Out");
		else if(tempStatus == 3)
			tempPlane.SetStatus("Repair");
		else
			cout << "ERROR TO PROGRAMMER:\n\tStatus: " << tempStatus << endl;
		
		PlaneList.push_back(tempPlane);
		
		tempPlane.clear();
	}
	
	//close file
	infile.close();
	
	cout << "Read in planes.\n";
	
	return;
}

void Planes::storedata()
{
	//create input file stream
	ofstream outfile;
	//open file and check if failed
	outfile.open("planes");
	if(!outfile.is_open())
	{
		cout << "File opening failed...\n";
		return;
	}

	planeCount = PlaneList.size();
	outfile << planeCount << endl;
	
	for(int i=0; i<planeCount; i++)
	{
		outfile << (PlaneList.at(i)).GetMake() << endl;
		outfile << (PlaneList.at(i)).GetModel() << endl;
		outfile << (PlaneList.at(i)).GetTailNumber() << endl;
		outfile << (PlaneList.at(i)).GetRange() << endl;
		outfile << (PlaneList.at(i)).GetNumSeats() << endl;
		if((PlaneList.at(i)).GetStatus() == "In")
			outfile << 1;
		else if((PlaneList.at(i)).GetStatus() == "Out")
			outfile << 2;
		else if((PlaneList.at(i)).GetStatus() == "Repair")
			outfile << 3;
	}
	
	//close file
	outfile.close();
	
	cout << "Stored planes.\n";
	
	return;
}