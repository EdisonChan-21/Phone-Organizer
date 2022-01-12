/*
Objective:	The implementation of class pEntry.
The member functions renew or initialize the value of a phone entry.
Moreover, some functions return the value of member variable of pEntry.
version:	6
Date:	Nov 27,2015
Author:	Chan Shui Fung
Library required:	iostream, string.h
Define:	Disable _CRT_SECURE_NO_WARNINGS 
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include "pEntry.h"
#include <iostream>
#include <string.h>
using namespace std;

// Set function is used for input the information of a contact.
// Input parameter:	The user-given infomation of a phone entry.
// Output parameter:	Nil
void pEntry::setName(const char name[])
{
	strncpy(itsName, name, 79);
}
void pEntry::setNickname(const char nickname[])
{
	strncpy(itsNickname, nickname, 49);
}
void pEntry::setPhoneNumber(const char phoneNo[])
{
	strncpy(itsPhoneNo, phoneNo, 14);
}
void pEntry::setEmail(const char email[])
{
	strncpy(itsEmail, email, 99);
}
void pEntry::setLastCallDateAndTime(int dateAndTime)
{
	itsLastCallDateAndTime = dateAndTime;
}
// Get function is used for retrieve the information of a contact.
// Input parameter:	Nil
// Output parameter:	The value of a phone entry's information.
char * const pEntry::getName()
{
	return itsName;
}
char * const pEntry::getNickname()
{
	return itsNickname;
}
char * const pEntry::getPhoneNo()
{
	return itsPhoneNo;
}
char * const pEntry::getEmail()
{
	return pEntry::itsEmail;
}
int const pEntry::getLastCallDateAndTime()
{
	return itsLastCallDateAndTime;
}

