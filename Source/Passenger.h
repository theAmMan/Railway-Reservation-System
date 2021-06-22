/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _PASSENGER_H
#define _PASSENGER_H

#include<bits/stdc++.h>

#include "Error.h"
#include "Date.h"
#include "Gender.h"

using namespace std;

class Passenger{
	//All traits except Date of Birth implemented as string
	//For future extension Category can be enumerated and Passenger made abstract base class for polymorphism
	string name_,aadhar_,mobile_,disType_;

public:
	string disId_;
	Date dob_;										//Date of Birth
	Gender gender_;
	//CONSTRUCTOR
	Passenger(string n, string a, Date d, Gender g,string m="-",string dt="None", string di="-");
	Passenger& operator=(const Passenger&);
	//DESTRUCTOR
	~Passenger();
	//Returns Name of the Passenger
	string GetName() const;
	string GetFname() const;
	string GetLname() const;
	//Print Passenger deatils
	void Print() const;
	//Check details
	bool IsValid();
	//Get Disability
	string GetDis() const;
	//Ostream overload
	friend ostream& operator<<(ostream& os, const Passenger& p);
	//Istream overload: String name, aadhar, Date dob, String gender, mobile, category 
	friend istream& operator>>(istream& is, Passenger& p);
	//Unit Test
	static void TestPassenger();
};

#endif