/*
Objective:	The header file "pContact.h" is to store class pContact 's information.
version:	6
Date:	Nov 27,2015
Author:	Chan Shui Fung
Library required:	pEntry.h
*/
#include "pEntry.h"

class pContactB
	/*
	Class pContactB will hold a number of pEntry object under three groups: Family, Friend and Junk.
	pContactB has three member array of pEntry objects.
	The size of each array is assigned to 100.
	*/
{
public:
	pContactB();
	/*
	Constractor create three array of object of pEntry in the heap which pointed by Family, Friend and Junk first. 
	Read the content of the file "contactB.txt" and store the information into three member arrays of pEntry object.
	Input parameter:	Nil
	Output parameter:	Nil
	*/

	~pContactB();
	/*
	Desturacot will save the content of the current contact book into a file "contactB.dat"
	Release the memory which allocated by pEntry object to the system.
	Input parameter:	Nil
	Output parameter:	Nil
	*/

	void inputFamily();
	void inputFriend();
	void inputJunk();
	/*
	Input function is used for the input of phone entry.
	There are three input function for each group: Family, Friend and Junk.
	The data will store into a pContactB object under one of the three groups
	which specified by the user request.
	Input parameter:	Nil
	Output parameter:	Nil
	*/

	bool display(int gchoose);
	/*
	The function display() is used for display the contact information under one of the three groups
	specified by the user.
	*/
	// Input parameter : An integer which indicate the user-given group.
	// Output parameter : A boolean that determine the sucessful of display.


	int getFamilyA() const;
	int getFriendA() const;
	int getJunkA() const;
	/*
	Get function is used for retrieving the number of valid elements of each array.
	*/
	// Input parameter: Nil
	// Output parameter: The number of valid elements of each array.

	int deleteF(int group);
	// Delete function is used for moving the phone entry of a user-input phone number under a user-given group. 
	// Input parameter:	An integer which indicate the user-given group.
	// Output parameter: The number of valid elements of each array.

private:
	pEntry * Family; // Three pointer of pEntry object.
	pEntry * Friend;
	pEntry * Junk;
	int familyA = 100; //The number of valid elements of each array.
	int friendA = 100; //The value is initialized to 100 which equal to the size of array.
	int junkA = 100;
};