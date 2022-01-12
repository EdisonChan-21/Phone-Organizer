/*
Objective:	
The application organises phone entries in a contact book.
When a user wants to start it, he/she needs to login the application with a username first, 
which will be checked with a file that stores username-password pairs. 
After a successful login, the application read the content of the current contact book from a file 
and store the information into the three group arrays if the file exist and contain data. 
Upon the user's request, the input of phone entry is stored into a pContactB object under one of the three groups specified by the user. 
Upon the user's request, the application can remove the information of a phone entry under a user-given group and user-given phone number.
Upon the user's request, the application can display the information of phone entries under a user-given group.
When the user request to end the application, it saves the content of the current contact book into a file.
version:	6
Date:	Nov 27,2015
Author:	Chan Shui Fung
Library required:	iostream, string.h, fstream, pContact.h
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include <fstream>
#include "pContactB.h"
using namespace std;
int gChoose(); // Function prototype
bool menu(pContactB); // Function prototype
bool login(); // Function prototype
bool menu(pContactB *book)
/*
menu() will receive the object pointed by a pointer which is passed by caller.
The function show a user menu and follow the user's request.
*/
// Input parameter : A pointer of pContactB object.
// Output parameter : A boolean that determine the end of function.
{
	char option; // Store the user-given menu choice.
	int group; // Store the user-given group choice.
	/*****************Display menu*****************/
	cout << "************MENU*************" << endl;
	cout << "*********Contact book********" << endl;
	cout << "1.Input a contact" << endl;
	cout << "2.Remove a contact" << endl;
	cout << "3.Check storage status" << endl;
	cout << "4.Read contact" << endl;
	cout << "5.Quit" << endl << endl;
	cout << "Please input your option:";
	cin >> option;
	cout << "*****************************" << endl;
	switch (option)
	{
	case '1':	do // User input '1' to input a phone entry.
				{
					group = gChoose(); // User choose a group for phone entry.
				} while (group == 0); // If user input invalid, input again.
				switch (group) 
				{
					case 1: book->inputFamily(); break; // Input a phone entry under Family if 1 is returned by gChoose.
					case 2:	book->inputFriend(); break; // Input a phone entry under Friend if 2 is returned by gChoose.
					case 3:	book->inputJunk(); break; // Input a phone entry under Junk if 3 is returned by gChoose.
					case 4:	return false; // Back to menu if 4 is returned by gChoose(User choose to quit).
				}break;

	case '2':	do // User input '2' to remove a phone entry.
				{
					group = gChoose(); // User choose a group for remove the phone entry.
				} while (group == 0); // If user input invalid, input again.
				if (group == 4) 
					return false ;
				book->deleteF(group); break; // Call deleteF() to remove a phone entry under user-given group.
	case '3':	// User input '3' to read the the valid element for each group.
				cout << "The number of valid element of group Family:" << book->getFamilyA() << endl; // Display the valid element for each group.
				cout << "The number of valid element of group Friend:" << book->getFriendA() << endl;
				cout << "The number of valid element of group Junk:" << book->getJunkA() << endl; break;
	case '4':	// User input '4' to read all of the phone entry under user-given group.
				book->display(gChoose()); break; // Display all the phone entry under user-given group.
	case '5':	// User input '5' to end the program.
				cout << "Good Bye!!" << endl;
				return true; // Program ends if user input '5'.

	default:	cout << "Input Invalid!! Please input again!!" << endl; //Show error message if invalid input.

	}
	return false;
}
int gChoose()
/*
gChoose() will show a menu and ask for user to decide the type of group.
It will return an integer to indicate the decision of user for further use.
*/
// Input parameter : Nil
// Output parameter : Nil
{
	char option; // Store the user-given group choice.
	/*****************Display menu*****************/
	cout << "************GROUP************" << endl; //show menu.
	cout << "1.Family" << endl;
	cout << "2.Friend" << endl;
	cout << "3.Junk" << endl;
	cout << "4.Quit" << endl << endl;
	cout << "Please input your decision:";
	cin >> option;
	cout << "*****************************" << endl;
	switch (option)
	{
	case '1':	return 1; // For Family, return 1.
	case '2':	return 2; // For Friend, return 2.
	case '3':	return 3; // For Junk, return 3.
	case '4':	return 4; // For exit, return 4.
	default:	cout << "Invalid input!! Please input again!!" << endl; // Show error message if invalid input.
		return 0;
	}
	return 0;
}
bool login()
/*
If the user want to use the application, he/she need to login first.
The function will check a file that stores username-password pairs.
If the username is new, the application will ask for a password from the user and store it into that file.
If the username can be found in that file, the application will start only when the password is correct. 
The application will end if the user fails to provide the correct password in three consecutive trials.
*/
// Input parameter : Nil
// Output parameter : A boolean that indicate the sucessful of login.
{
	char username[30], password[30], usernameData[30], passwordData[30];
	cout << "Please enter your user name to login:"; //Ask the user to input a user name
	cin.getline(username, 30);
	ifstream loginFile("logindata.txt");// Read data from a file "logindata.txt" which is used to store username and password.
	if (loginFile)// Check if the open operation is success.
	{
		while (!loginFile.eof() && (loginFile >> usernameData >> passwordData))//Input data from file
		{
			for (int i = 1; strcmp(username, usernameData) == 0; i++)
				// Check if both user name are the same, if not, check next.

			{
				cout << "Please input your password:"; //Ask the user to input password.
				cin.getline(password, 30);

				if (strcmp(password, passwordData) == 0) // Check if both password are the same, if not, input again.
				{
					cout << "Welcome," << username << '.' << endl;
					loginFile.close(); // Close file
					return true; // Return true when login is success.
				}
				else
					cout << "Password incorrect, input again!\n"; // Display a message if the password is incorrect and input again.
				if (i == 3)// The application will end if the user fails to provide the correct password in three consective trials.
				{
					cout << "Fails to provide correct password. Program ends." << endl;
					loginFile.close(); // Close file
					return false; // Return false when login is fail and program will end.
				}
			}
		}
		// If the username is new, the program will ask the user to input a new password.
		cout << "Welcome, new user!" << endl;
		cout << "Please input your new password:";
		cin.getline(password, 30);
		cout << "New account has been created." << endl;
		ofstream loginFile("logindata.txt", ios::app); // Write data to a file "logindata.txt" which is used to store username and password.
		loginFile << username << ' ' << password << endl; // New username and password is inputted into the file "logindata.txt".
		loginFile.close(); // Close file
		cout << "Welcome," << username << '.' << endl;
	}
	else // Create a new account for new user as there is no such a file that stores username-password pairs. 
	{
		ofstream loginFile("logindata.txt");// Create a file "logindata.txt" which is used to store username and password and write data to it .
		cout << "Welcome, new user!" << endl;
		cout << "Please input your new password:";
		cin.getline(password, 30);
		cout << "New account has been created." << endl;
		loginFile << username << ' ' << password << endl;
		loginFile.close(); // Close file
		cout << "Welcome," << username << '.' << endl;
	}
	return true; // Return true when login is success.
}
int main()
{
	bool exitFlag = false;
	exitFlag = login();
	if (!exitFlag) // Program ends if fail to provide correct password three times.
		return 0;
	pContactB *book = new pContactB; // Create a pointer of an object of a class pContactB in the heap.
	do
		exitFlag = menu(book); // Pass a pointer to Bmenu()
	while (!exitFlag); // Program ends if menu() return true.
	delete book; // Release the memory which allocated bt object pContactB in the heap to the system to avoid memory leakage.
	book = 0; // Assign the pointer to 0.
	return 0;
}