/*
Objective:	The header file "pEntry.h" is to store class pEntry 's information.
version:	6
Date:	Nov 27,2015
Author:	Chan Shui Fung
*/
class pEntry
	/*
	Class pEntry is used to hold the information of the contact which include
	name, nickname, phone number, email address, last-call date and time.
	*/
{
public:
	// Set function is used for input the information of a contact.
	// Input parameter:	The user-given infomation of a phone entry.
	// Output parameter:	Nil
	void setName(const char name[]); 
	void setNickname(const char nickname[]);
	void setPhoneNumber(const char phoneNo[]);
	void setEmail(const char email[]);
	void setLastCallDateAndTime(int dateAndTime);
	// Get function is used for retrieve the information of a contact.
	// Input parameter:	Nil
	// Output parameter:	The value of a phone entry's information.
	char * const getName() ;
	char * const getNickname() ;
	char  * const getPhoneNo() ;
	char * const getEmail() ;
	int const getLastCallDateAndTime() ;

private:
	// Some member variables are used for storing the information of a phone entry.
	char itsName[80]; 
	// Name of contact.
	// The length of name is assigned to 80.
	char itsNickname[50]; 
	// Nickname of contact.
	// The length of nickname is assigned to 50.
	char itsPhoneNo[15]; 
	// Phone number of contact.
	// The length of phone is assigned to 15.
	char itsEmail[100]; 
	// Email of contact.
	// The length of email is assigned to 100.
	int itsLastCallDateAndTime; 
	// Last call date and time of contact.
};