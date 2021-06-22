/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _DATE_H
#define _DATE_H

#include<iostream>

#include "Error.h"

using namespace std;

const int MAX_VALID_YR = 2099; 						//Max Valid Year
const int MIN_VALID_YR = 1900; 						//Min Valid Year
 

class Date {
	enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };			//Months enumerated
	enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };											//Days enumerated
	typedef unsigned int UINT;
	//Month Names
	char monthNames[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	//Day Names 
	char dayNames[7][10] = {  "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday" };
	UINT date_; 					//Date
	Month month_; 					//Month
	UINT year_;						//Year	

public:
	//CONSTRUCTOR
	Date(string s="01/01/2021");
	//DESTRUCTOR
	~Date();
	//returns day of the date, Sunday being 0 and so on
	int GetDay() const;
	//Check whether Leap Year
	bool IsLeap();
	//Prints the Date
	void Print() const;
	//Checks Validity of date
	bool IsValid();
	//Return Date as string
	string ToString();
	//Calculate Age
	int CalcAge();
	//Calculate Span, returns 1 if next day, 10 if within the year, else 0
	int CalcSpan();
	//Ostream overload
	friend ostream& operator<<(ostream&, const Date&);
	//Istream overlaod, takes three int as input
    friend istream& operator>>(istream&, Date&);
    //Unit Test
    static void TestDate();
};

#endif