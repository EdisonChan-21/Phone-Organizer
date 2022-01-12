/*
Objective:	The cpp file "pEntry.cpp" is to store the implementation of class pEntry.
The member functions renew or initialize the value of a phone entry.
Moreover, some functions return the value of member variable of pEntry.
version:	6
Date:	Nov 27,2015
Author:	Chan Shui Fung
Library required:	iostream, string.h, fstream
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include "pContactB.h"

using namespace std;

pContactB::pContactB()
/*
Constractor create three array of object of pEntry in the heap which pointed by Family, Friend and Junk first.
Read the content of the file "contactB.txt" and store the information into three member arrays of pEntry object.
Input parameter:	Nil
Output parameter:	Nil
*/
{
	/*
	Three pointer of each group is pointing to an array of pEntry object.
	When an object of pContactB has been created, the constructor will create three pointer of array of object of pEntry.
	*/
	Family = new pEntry[100]; //Three group that holding an array of pEntry objects.
	Friend = new pEntry[100]; //The size of array is assigned to 100.
	Junk = new pEntry[100];
	/*
	Read the content of the file "contactB.txt", store the information into three group.
	*/

	int dateAndTime, group; //Integer "group" is used to determine the group of the data.
	char name[79], nickname[49], phoneNo[14], email[99];
	/*For these variable is used to store the data from file input temporily*/

	ifstream dataFile("contactB.txt"); //Open file "contactB.txt" to read data.
	if (dataFile) {


		for (int i = 0, j = 0, k = 0; !dataFile.eof() && (dataFile >> group >> name >> nickname >> phoneNo >> email >> dateAndTime);)
			// If the file is not end, continue to input data into the variable.
		{
			switch (group)
			{
			case 0: //If group is 0, it means that the data is under Family group.
				if (i != 100) // The number of each group of data should not exceed 100.
				{
					Family[i].setName(name);
					Family[i].setNickname(nickname);
					Family[i].setPhoneNumber(phoneNo);
					Family[i].setEmail(email);
					Family[i].setLastCallDateAndTime(dateAndTime);
					familyA--; // The number of valid elements of member array should be minus 1.
					i += 1; break; // Index increment by 1. 
				}break;
			case 1: //If group is 1, it means that the data is under Friend group.
				if (j != 100)
				{
					Friend[j].setName(name);
					Friend[j].setNickname(nickname);
					Friend[j].setPhoneNumber(phoneNo);
					Friend[j].setEmail(email);
					Friend[j].setLastCallDateAndTime(dateAndTime);
					friendA--; // The number of valid elements of member array should be minus 1.
					j += 1; break; // Index increment by 1. 
				}break;
			case 2: //If group is 2, it means that the data is under Friend group.
				if (k != 100)
				{
					Junk[k].setName(name);
					Junk[k].setNickname(nickname);
					Junk[k].setPhoneNumber(phoneNo);
					Junk[k].setEmail(email);
					Junk[k].setLastCallDateAndTime(dateAndTime);
					junkA--; // The number of valid elements of member array should be minus 1.
					k++; break; // Index increment by 1. 
				}break;

			}


		}

	}
	dataFile.close(); // Close the file.
}
pContactB::~pContactB()//Destructor
					   /*
					   Save the content of the current contact book into a file "contactB.txt"
					   Release the memory which allocated by pEntry object to the system.
					   */
					   // Input parameter : Nil
					   // Output parameter : Nil
{
	ofstream dataFile("contactB.txt"); //Open file "contactB.txt" to store data.

	for (int i = 0; i < (100 - familyA); i++) //for-looping is used to input all the phone entry in each group.
	{
		dataFile  << 0 << '\t' << Family[i].getName() << '\t' << Family[i].getNickname() << '\t' << Family[i].getPhoneNo() << '\t'
			<< Family[i].getEmail() << '\t' << Family[i].getLastCallDateAndTime() << endl;
	}

	for (int i = 0; i < (100 - friendA); i++)
	{
		dataFile << 1 << '\t' << Friend[i].getName() << '\t' << Friend[i].getNickname() << '\t' << Friend[i].getPhoneNo() << '\t'
			<< Friend[i].getEmail() << '\t' << Friend[i].getLastCallDateAndTime() << endl;
	}

	for (int i = 0; i < (100 - junkA); i++)
	{
		dataFile << 2 << '\t' << Junk[i].getName() << '\t' << Junk[i].getNickname() << '\t' << Junk[i].getPhoneNo() << '\t'
			<< Junk[i].getEmail() << '\t' << Junk[i].getLastCallDateAndTime() << endl;
	}

	dataFile.close(); // Close the file.

	delete[] Family; // Release the memory to the system.
	delete[] Friend;
	delete[] Junk;
	Family = 0; // Ensure one will not use the deleted heap memory again.
	Friend = 0;
	Junk = 0;
}



void pContactB::inputFamily()
/*
Input function is used for the input of phone entry.
There are three input function for each group: Family, Friend and Junk.
The data will store into a pContactB object under one of the three groups
which specified by the user request.
*/
// Input parameter : Nil
// Output parameter : Nil
{
	if (familyA == 0) // Display am error message when the array of pEntry object is full.
		cout << "Memory in Family is full, please delete record to release." << endl;
	else
	{
		char name[80], nickname[50], phoneNo[15], email[100]; // Some varibles is used for storing the user's input temporarily.
		int LastCallDateAndTime, i = (100 - familyA); // Integer i indicate the index value of pEntry object.
		cout << "Please use underscore(_) to represent a space!!" << endl; // If there is any space in a input, the format of the file "contactB.txt" become incompatible.
		cout << "Name:";
		cin.get(); // Prevent the skip of cin.getline() by newline character.
		cin.getline(name, 80);
		Family[i].setName(name);
		cout << "Nickname:";
		cin.getline(nickname, 50);
		Family[i].setNickname(nickname);
		cout << "Phone Number:";
		cin.getline(phoneNo, 15);
		Family[i].setPhoneNumber(phoneNo);
		cout << "Email:";
		cin.getline(email, 100);
		Family[i].setEmail(email);
		cout << "Last-call date and time(MMDDHHSS):";
		cin >> LastCallDateAndTime;
		Family[i].setLastCallDateAndTime(LastCallDateAndTime);
		familyA--; // Number of valid element in Family decrement by 1.
		cout << "Record " << i + 1 << " in Family has been created." << endl;
		cout << "Available elements in Family :" << familyA << endl;
	}
	/*
	familyA is a varible which store the number of valid elements of Family can be
	kept inside the pContactB object.
	If a contact is inputted by user, the number of valid elements should be minus 1.
	*/
}
void pContactB::inputFriend()
{
	if (friendA == 0) // Display am error message when the array of pEntry object is full.
		cout << "Memory in Family is full, please delete record to release." << endl;
	else
	{
		char name[80], nickname[50], phoneNo[15], email[100]; // Some varibles is used for storing the user's input temporarily.
		int LastCallDateAndTime, i = (100 - friendA); // Integer i indicate the index value of pEntry object.
		cout << "Please use underscore(_) to represent a space!!" << endl; // If there is any space in a input, the format of the file "contactB.txt" become incompatible.
		cout << "Name:";
		cin.get(); // Prevent the skip of cin.getline() by newline character.
		cin.getline(name, 80);
		Friend[i].setName(name);
		cout << "Nickname:";
		cin.getline(nickname, 50);
		Friend[i].setNickname(nickname);
		cout << "Phone Number:";
		cin.getline(phoneNo, 15);
		Friend[i].setPhoneNumber(phoneNo);
		cout << "Email:";
		cin.getline(email, 100);
		Friend[i].setEmail(email);
		cout << "Last-call date and time(MMDDHHSS):";
		cin >> LastCallDateAndTime;
		Friend[i].setLastCallDateAndTime(LastCallDateAndTime);
		friendA--; // Number of valid element in Friend decrement by 1.
		cout << "Record " << i + 1 << " in Friend has been created." << endl;
		cout << "Available elements in Friend :" << friendA << endl;
	}
	/*
	friendA is a varible which store the number of valid elements of Friend can be
	kept inside the pContactB object.
	If a contact is inputted by user, the number of valid elements should be minus 1.
	*/
}
void pContactB::inputJunk()
{
	if (junkA == 0) // Display am error message when the array of pEntry object is full.
		cout << "Memory in Family is full, please delete record to release." << endl;
	else
	{
		char name[80], nickname[50], phoneNo[15], email[100]; // Some varibles is used for storing the user's input temporarily.
		int LastCallDateAndTime, i = (100 - junkA); // Integer i indicate the index value of pEntry object.
		cout << "Please use underscore(_) to represent a space!!" << endl; // If there is any space in a input, the format of the file "contactB.txt" become incompatible.
		cout << "Name:";
		cin.get(); // Prevent the skip of cin.getline() by newline character.
		cin.getline(name, 80);
		Junk[i].setName(name);
		cout << "Nickname:";
		cin.getline(nickname, 50);
		Junk[i].setNickname(nickname);
		cout << "Phone Number:";
		cin.getline(phoneNo, 15);
		Junk[i].setPhoneNumber(phoneNo);
		cout << "Email:";
		cin.getline(email, 100);
		Junk[i].setEmail(email);
		cout << "Last-call date and time(MMDDHHSS):";
		cin >> LastCallDateAndTime;
		Junk[i].setLastCallDateAndTime(LastCallDateAndTime);
		junkA--; // Number of valid element in Junk decrement by 1.
		cout << "Record " << i + 1 << " in Junk has been created." << endl;
		cout << "Available elements in Junk :" << junkA << endl;
	}
	/*
	junkA is a varible which store the number of valid elements of Friend can be
	kept inside the pContactB object.
	If a contact is inputted by user, the number of valid elements should be minus 1.
	*/
}
bool pContactB::display(int group)
/*
The function display() is used for display the contact information under one of the three groups
specified by the user.
If group is 1, display the phone entry under Family.
If group is 2, display the phone entry under Friend.
If group is 3, display the phone entry under Junk.
Return false if there is no phone entry under a user-given group.
Return true if there is any phone entry under a user-given group.
*/
// Input parameter : An integer which indicate the user-given group.
// Output parameter : A boolean that determine the sucessful of display.
{
	switch (group) // Determine the group which is going to display.
	{
	case 1: if (familyA != 100) //check if any phone entry
	{
		for (int i = 0; i < (100 - familyA); i++) //for-looping is used to show all the phone entry.
		{
			cout << "**************" << i + 1 << "**************" << endl; //Display the Record number.
			cout << "Name:" << Family[i].getName() << endl;
			cout << "Nickname:" << Family[i].getNickname() << endl;
			cout << "Phone Number:" << Family[i].getPhoneNo() << endl;
			cout << "Email:" << Family[i].getEmail() << endl;
			cout << "Last-call date and time(MMDDHHSS):" << Family[i].getLastCallDateAndTime() << endl;
		}break;
	}
			else
				cout << "No record is found." << endl; return false; //A message will show if no phone entry is inputted into the group Family and return false.
	case 2:	if (friendA != 100)
	{
		for (int i = 0; i < (100 - friendA); i++)
		{
			cout << "**************" << i + 1 << "**************" << endl;
			cout << "Name:" << Friend[i].getName() << endl;
			cout << "Nickname:" << Friend[i].getNickname() << endl;
			cout << "Phone Number:" << Friend[i].getPhoneNo() << endl;
			cout << "Email:" << Friend[i].getEmail() << endl;
			cout << "Last-call date and time(MMDDHHSS):" << Friend[i].getLastCallDateAndTime() << endl;
		}break;
	}
			else
				cout << "No record is found." << endl; return false; //A message will show if no phone entry is inputted into the group Friend and return false.
	case 3:	if (junkA != 100)
	{
		for (int i = 0; i < (100 - junkA); i++)
		{
			cout << "**************" << i + 1 << "**************" << endl;
			cout << "Name:" << Junk[i].getName() << endl;
			cout << "Nickname:" << Junk[i].getNickname() << endl;
			cout << "Phone Number:" << Junk[i].getPhoneNo() << endl;
			cout << "Email:" << Junk[i].getEmail() << endl;
			cout << "Last-call date and time(MMDDHHSS):" << Junk[i].getLastCallDateAndTime() << endl;
		}break;
	}
			else
				cout << "No record is found." << endl; return false; //A message will show if no phone entry is inputted into the group Junk and return false.
	}
	return true; // Return true for the sucessful of display.
}

// Get function is used for retrieving the number of valid elements of each array.
// Input parameter : Nil
// Output parameter : The number of valid elements of each array.
int pContactB::getFamilyA() const
{
	return familyA;
}
int pContactB::getFriendA() const
{
	return friendA;
}
int pContactB::getJunkA() const
{
	return junkA;
}


int pContactB::deleteF(int group)
// Delete function is used for moving the phone entry of a user-input phone number under a user-given group. 
// Input parameter:	An integer which indicate the user-given group.	
// Output parameter: The number of valid elements of each array.
{
	char phoneNo[15];
	int RecordNo;// RecordNo store the number of phone entry in order to indicate the position of phone entry which is needed to remove.
	if (!display(group))// If there is no phone entry under user-given group, function ends.
		return 0;
	cout << "*****************************" << endl;
	cout << "Please input the phone number of record which you would like to delete or 'q' to quit:";
	cin.get(); // Prevent the skip of cin.getline() by newline character.
	cin.getline(phoneNo, 15);
	if (strcmp(phoneNo, "q") == 0) // Function ends if user input 'q'.
		return 0;
	switch (group)
	{
	case 0:break;// If there is no phone entry inside a given group, the function ends.
	case 1:	for (int i = 0; i < (100 - familyA); i++) // Remove the phone entry under Family.

	{
		if (strcmp(phoneNo, Family[i].getPhoneNo()) == 0) // Find the number of array which have the same phone number with the user-given phone number.
		{
			RecordNo = i;
			break;
		}
		if (i == (100 - familyA - 1)) // If the last phone entry has been searched and no phone entry match the user-given phone number, show an error message.
		{
			cout << "The phone number does not have any phone entry!" << endl;
			// If no phone number of phone entry match the user-given phone number, show an error message and function ends.
			return 0;
		}
	}

			for (int i = 0; i < (100 - familyA - RecordNo - 1); i++)
				// Cover the entry which to be remove by the follow entry, then all the elements in the array that follow the removed entry
				// will be moved forward in order to assure the valid entried are stored consectively.
			{
				Family[RecordNo + i].setName(Family[RecordNo + i + 1].getName());
				Family[RecordNo + i].setNickname(Family[RecordNo + i + 1].getNickname());
				Family[RecordNo + i].setPhoneNumber(Family[RecordNo + i + 1].getPhoneNo());
				Family[RecordNo + i].setEmail(Family[RecordNo + i + 1].getEmail());
				Family[RecordNo + i].setLastCallDateAndTime(Family[RecordNo + i + 1].getLastCallDateAndTime());
			}
			// The last entry will be removed by setting all the variable to null.
			Family[100 - familyA - 1].setName("");
			Family[100 - familyA - 1].setNickname("");
			Family[100 - familyA - 1].setPhoneNumber("");
			Family[100 - familyA - 1].setEmail("");
			Family[100 - familyA - 1].setLastCallDateAndTime(NULL);
			familyA += 1;
			cout << "Record " << RecordNo + 1 << " has been deleted." << endl; // Display a message to inform the user a record is removed.
			cout << "Available elements in Family :" << familyA << endl; break; // Display the number of valid elements.

	case 2:	for (int i = 0; i < (100 - friendA); i++)  // Remove the phone entry under Friend.
	{
		if (strcmp(phoneNo, Friend[i].getPhoneNo()) == 0)
		{
			RecordNo = i;
			break;
		}
		if (i == (100 - friendA - 1))
		{
			cout << "The phone number does not have any phone entry!" << endl;
			return 0;
		}
	}

			for (int i = 0; i < (100 - friendA - RecordNo); i++)
			{
				Friend[RecordNo + i].setName(Friend[RecordNo + i + 1].getName());
				Friend[RecordNo + i].setNickname(Friend[RecordNo + i + 1].getNickname());
				Friend[RecordNo + i].setPhoneNumber(Friend[RecordNo + i + 1].getPhoneNo());
				Friend[RecordNo + i].setEmail(Friend[RecordNo + i + 1].getEmail());
				Friend[RecordNo + i].setLastCallDateAndTime(Friend[RecordNo + i + 1].getLastCallDateAndTime());
			}
			Friend[100 - friendA - 1].setName("");
			Friend[100 - friendA - 1].setNickname("");
			Friend[100 - friendA - 1].setPhoneNumber("");
			Friend[100 - friendA - 1].setEmail("");
			Friend[100 - friendA - 1].setLastCallDateAndTime(NULL);
			friendA += 1;
			cout << "Record " << RecordNo + 1 << " has been deleted." << endl;
			cout << "Available elements in Friend :" << friendA << endl; break;
	case 3:	for (int i = 0; i < (100 - junkA); i++) // Remove the phone entry under Junk.
	{
		if (strcmp(phoneNo, Junk[i].getPhoneNo()) == 0)
		{
			RecordNo = i;
			break;
		}
		if (i == (100 - junkA - 1))
		{
			cout << "The phone number does not have any phone entry!" << endl;
			return 0;
		}
	}

			for (int i = 0; i < (100 - junkA - RecordNo); i++)
			{
				Junk[RecordNo + i].setName(Junk[RecordNo + i + 1].getName());
				Junk[RecordNo + i].setNickname(Junk[RecordNo + i + 1].getNickname());
				Junk[RecordNo + i].setPhoneNumber(Junk[RecordNo + i + 1].getPhoneNo());
				Junk[RecordNo + i].setEmail(Junk[RecordNo + i + 1].getEmail());
				Junk[RecordNo + i].setLastCallDateAndTime(Junk[RecordNo + i + 1].getLastCallDateAndTime());
			}
			Junk[100 - junkA - 1].setName("");
			Junk[100 - junkA - 1].setNickname("");
			Junk[100 - junkA - 1].setPhoneNumber("");
			Junk[100 - junkA - 1].setEmail("");
			Junk[100 - junkA - 1].setLastCallDateAndTime(NULL);
			junkA += 1;
			cout << "Record " << RecordNo + 1 << " has been deleted." << endl;
			cout << "Available elements in Junk :" << junkA << endl; break;
	}
	return 0;
}
