/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _STATION_H
#define _STATION_H

#include<iostream>

using namespace std;

class Station{
	string name_;											//Name of the station
public:
	//CONSTRUCTOR
	Station(string s);
	//DESTRUCTOR
	~Station();
	//Returns name of the Station
	string GetName()const;
	//Equality operator overload
	friend bool operator==(const Station& s1,const Station& s2) ;
	//Returns distance between 2 stations
    double GetDistance(const Station& other) const;
    //Ostream overload
    friend ostream& operator<<(ostream&, const Station&);
    //Istream overload: Input String name
    friend istream& operator>>(istream&, Station&);
    //Unit Test
    static void TestStation();
};

#endif