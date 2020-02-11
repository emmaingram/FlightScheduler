/*
	Name: Emma Ingram (emmaingram@my.unt.edu)
	Date: 2 April 2018
	Instructor: Keathly
	Program: This file contains the function definitions for Crew Members functions
*/

#include "crews.h"

void CrewMembers::AddCrewMember() //function to add a crew member
{
	crewCount = CrewList.size();
	
	string tempName, tempID;
	int tempType, tempStatus;
	
	CrewMember tempCrewMember;
	
	cout << "\nADD CREW MEMBER\n";
	
	//prompt user for name
	cout << "Enter name of crew member:\n";
	getline(cin, tempName);
	
	tempCrewMember.SetName(tempName);
	
	//prompt user for id
	cout << "Enter ID for crew member:\n";
	cin >> tempID;
	
	int test = -1;
	//check if id is already used
	do{
		for(int i=0; i<crewCount; i++)
		{
			test = -1;
			if((CrewList.at(i)).GetID() == tempID)
			{
				cout << "ERROR - ID already taken.\n";
				cout << "Try again:\n";
				cin >> tempID;
				test++;
			}
		}
	}while(test != -1);//if id is used, test will not be -1
	//if id is not used, test will still be -1
	
	tempCrewMember.SetID(tempID);
	
	//prompt user for type
	do{
		cout << "Enter crew member type:\n";
		cout << "\t1 - Pilot\n"
			 << "\t2 - CoPilot\n"
			 << "\t3 - Cabin\n";
		cin >> tempType;
		
		if(tempType == 1)
			tempCrewMember.SetType("Pilot");
		else if(tempType == 2)
			tempCrewMember.SetType("CoPilot");
		else if(tempType == 3)
			tempCrewMember.SetType("Cabin");
		else
			cout << "ERROR - Invalid entry.\n";
	}while(tempType != 1 && tempType != 2 && tempType != 3);
	
	//prompt user for status
	do{
		cout << "Enter crew member status:\n";
		cout << "\t1 - Available\n"
			 << "\t2 - On Leave\n"
			 << "\t3 - Sick\n";
		cin >> tempStatus;
		
		if(tempStatus == 1)
			tempCrewMember.SetStatus("Available");
		else if(tempStatus == 2)
			tempCrewMember.SetStatus("On Leave");
		else if(tempStatus == 3)
			tempCrewMember.SetStatus("Sick");
		else
			cout << "ERROR - Invalid entry.\n";
	}while(tempStatus != 1 && tempStatus != 2 && tempStatus != 3);
	
	CrewList.push_back(tempCrewMember);
	
	tempCrewMember.clear();
	
	return;
}

void CrewMembers::EditCrewMember() //function to edit a crew member
{
	cout << "\nEDIT CREW MEMBER\n";
	
	crewCount = CrewList.size();
	
	string tempName, cID, tempID;
	int tempType, tempStatus;
	
	//prompt for crew member id
	cout << "Enter crew member ID:\n";
	cin >> cID;
	
	//find crew member
	int index = -1;
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
			index = i;
	}
	
	if(index == -1)
	{
		cout << "Crew member not found.\n";
	}

	int choice;
	char again;
	
	cout << "Editing " << (CrewList.at(index)).GetName() << "'s Profile\n";
	
	do{
		//print menu
		cout << "What would you like to edit?\n";
		cout << "\t1 - Name\n"
			 << "\t2 - ID\n"
			 << "\t3 - Type\n"
			 << "\t4 - Status\n"
			 << "\t5 - Cancel\n";
		//read in choice
		cin >> choice;
		
		if(choice == 1)
		{
			//prompt user for name
			cout << "Enter name of crew member:\n";
			cin.ignore();
			getline(cin, tempName);
			
			(CrewList.at(index)).SetName(tempName);
		}
		else if(choice == 2)
		{
			//prompt user for id
			cout << "Enter ID for crew member:\n";
			cin >> tempID;
			
			int test = -1;
			//check if id is already used
			do{
				for(int i=0; i<crewCount; i++)
				{
					test = -1;
					if((CrewList.at(i)).GetID() == tempID)
					{
						cout << "ERROR - ID already taken.\n";
						cout << "Try again:\n";
						cin >> tempID;
						test++;
					}
				}
			}while(test != -1);//if id is used, test will not be -1
			//if id is not used, test will still be -1
			
			(CrewList.at(index)).SetID(tempID);
		}
		else if(choice == 3)
		{
			//prompt user for type
			do{
				cout << "Enter crew member type:\n";
				cout << "\t1 - Pilot\n"
					 << "\t2 - CoPilot\n"
					 << "\t3 - Cabin\n";
				cin >> tempType;
				
				if(tempType == 1)
					(CrewList.at(index)).SetType("Pilot");
				else if(tempType == 2)
					(CrewList.at(index)).SetType("CoPilot");
				else if(tempType == 3)
					(CrewList.at(index)).SetType("Cabin");
				else
					cout << "ERROR - Invalid entry.\n";
			}while(tempType != 1 && tempType != 2 && tempType != 3);
		}
		else if(choice == 4)
		{
			//prompt user for status
			do{
				cout << "Enter crew member status:\n";
				cout << "\t1 - Available\n"
					 << "\t2 - On Leave\n"
					 << "\t3 - Sick\n";
				cin >> tempStatus;
				
				if(tempStatus == 1)
					(CrewList.at(index)).SetStatus("Available");
				else if(tempStatus == 2)
					(CrewList.at(index)).SetStatus("On Leave");
				else if(tempStatus == 3)
					(CrewList.at(index)).SetStatus("Sick");
				else
					cout << "ERROR - Invalid entry.\n";
			}while(tempStatus != 1 && tempStatus != 2 && tempStatus != 3);
		}
		else if(choice == 5)
		{
			break;
		}
		
		cout << "Do you want to edit anything else? (y/n):\n";
		cin >> again;
	}while(again != 'N' && again != 'n');
	
	return;
}

void CrewMembers::DeleteCrewMember() //function to delete a crew member
{
	cout << "\nDELETE CREW MEMBER\n";
	
	crewCount = CrewList.size();
	
	//prompt user for crew member id
	string cID;
	cout << "Enter crew member ID:\n";
	cin >> cID;
	
	int index = -1;
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			CrewList.erase(CrewList.begin() + i); //delete crew member
			index = i;
			crewCount--;
		}
	}
	
	if(index == -1)
	{
		cout << "Crew member not found. Nothing deleted.\n";
	}
	
	return;
}

void CrewMembers::PrintCrewMembers() //function to print details for every crew member
{
	crewCount = CrewList.size();
	
	if(crewCount == 0)
	{
		cout << "No crew members in system.\n";
		return;
	}
	
	cout << "\nCREW MEMBERS:\n";
	
	//print details for all crew members
	for(int i=0; i<crewCount; i++)
	{
		(CrewList.at(i)).PrintDetails();
		cout << endl;
	}
	
	return;
}

void CrewMembers::PrintDetailsForCrew() //function to print details for a specific crew member
{
	crewCount = CrewList.size();
	
	cout << "\nPRINT DETAILS FOR CREW MEMBERS\n";
	
	//prompt for crew member id
	cout << "Enter crew member ID:\n";
	string cID;
	cin >> cID;
	
	int index = -1;
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			(CrewList.at(i)).PrintDetails(); //print details for crew member
			index = i;
		}

	}
	
	if(index == -1)
	{
		cout << "Crew member not found.\n";		
	}
	
	return;
}

bool CrewMembers::SearchForCrew(string cID) //function to see if crew member exists
{
	crewCount = CrewList.size();
		
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID) //crew member exists
			return true;
	}
	
	return false;
}

bool CrewMembers::IsPilot(string cID) //function to see if crew member is pilot
{
	crewCount = CrewList.size();
	
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			if((CrewList.at(i)).GetType() == "Pilot") //crew  member is pilot
				return true;
		}
	}

	return false;
}

bool CrewMembers::IsCopilot(string cID) //function to see if crew member is copilot
{
	crewCount = CrewList.size();
	
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			if((CrewList.at(i)).GetType() == "CoPilot") //crew member is copilot
				return true;
		}
	}	
	
	return false;
}

bool CrewMembers::IsCabin(string cID) //function to see if crew member is cabin
{
	crewCount = CrewList.size();
	
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			if((CrewList.at(i)).GetType() == "Cabin") //crew member is cabin
				return true;
		}
	}	
	
	return false;
}

bool CrewMembers::IsAvailable(string cID) //function to see if crew member is available
{
	crewCount = CrewList.size();
	
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			if((CrewList.at(i)).GetStatus() == "Available") //crew member is available
				return true;
		}
	}	
	
	return false;
}

void CrewMembers::loaddata()
{
	//create input file stream
	ifstream infile;
	//open file and check if failed
	infile.open("crew");
	if(!infile.is_open())
	{
		cout << "File opening failed...\n";
		return;
	}
	
	//read from the file, storing data
	infile >> crewCount;
	infile.ignore();
	
	string tempName, tempID;
	int tempType, tempStatus;

	CrewMember tempCrewMember;
	
	for(int i=0; i<crewCount; i++)
	{
		getline(infile, tempName);
		tempCrewMember.SetName(tempName);

		//get id
		infile >> tempID;
		tempCrewMember.SetID(tempID);

		//get type
		infile >> tempType;

		if(tempType == 1)
			tempCrewMember.SetType("Pilot");
		else if(tempType == 2)
			tempCrewMember.SetType("CoPilot");
		else if(tempType == 3)
			tempCrewMember.SetType("Cabin");
		else
			cout << "ERROR - Invalid entry.\n";
		
		//get status
		infile >> tempStatus;

		if(tempStatus == 1)
			tempCrewMember.SetStatus("Available");
		else if(tempStatus == 2)
			tempCrewMember.SetStatus("On Leave");
		else if(tempStatus == 3)
			tempCrewMember.SetStatus("Sick");
		else
			cout << "ERROR - Invalid entry.\n";
		
		CrewList.push_back(tempCrewMember);
	
		tempCrewMember.clear();
	}
		
	//close file
	infile.close();
	
	cout << "Read in crew members.\n";
	
	return;
}

void CrewMembers::storedata()
{
	//create input file stream
	ofstream outfile;
	//open file and check if failed
	outfile.open("crew");
	if(!outfile.is_open())
	{
		cout << "File opening failed...\n";
		return;
	}

	crewCount = CrewList.size();
	outfile << crewCount << endl;
	
	for(int i=0; i<crewCount; i++)
	{
		outfile << (CrewList.at(i)).GetName() << endl;
		outfile << (CrewList.at(i)).GetID() << endl;
		if((CrewList.at(i)).GetType() == "Pilot")
			outfile << 1 << endl;
		else if((CrewList.at(i)).GetType() == "CoPilot")
			outfile << 2 << endl;
		else if((CrewList.at(i)).GetType() == "Cabin")
			outfile << 3 << endl;
		if((CrewList.at(i)).GetStatus() == "Available")
			outfile << 1;
		else if((CrewList.at(i)).GetStatus() == "On Leave")
			outfile << 2;
		else if((CrewList.at(i)).GetStatus() == "Sick")
			outfile << 3;
	}
	
	//close file
	outfile.close();
	
	cout << "Stored crew members.\n";
	
	return;
}

string CrewMembers::GetName(string cID) //function to see if crew member is pilot
{
	crewCount = CrewList.size();
	
	for(int i=0; i<crewCount; i++)
	{
		if((CrewList.at(i)).GetID() == cID)
		{
			string name = (CrewList.at(i)).GetName();
			return name;
		}
	}

	string notFound = "Crew member not found.\n";
	return notFound;
}