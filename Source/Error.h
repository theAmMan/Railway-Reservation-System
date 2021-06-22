/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _ERROR_H
#define _ERROR_H

#include<iostream>

using namespace std;
//Base Class
class Exception: public exception{
public:
	//Unit Test
	static void TestException();
};
//For exception in date
class Bad_Date: public Exception{
public:
	string message;
	Bad_Date(string s="Bad Date");
};
//For exception in passenger
class Bad_Passenger: public Exception{
public:
	string message;
	Bad_Passenger(string s="Bad Passenger");
};
//For exception in railway
class Bad_Railway: public Exception{
public:
	string message;
	Bad_Railway(string s="Bad Railway");
};
//For exception in booking
class Bad_Booking: public Exception{
public:
	string message;
	Bad_Booking(string s="Bad Bookking");
};

#endif