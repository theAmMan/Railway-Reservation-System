/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _RAILWAY_H
#define _RAILWAY_H

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

#include "Station.h"
#include "Error.h"

using namespace std;

//Special Hash Function for unordered map sDistStations
class HashFunc{
public:  
    size_t operator()(const pair<Station,Station>& p) const{ 
        return p.first.GetName().length()*5 + p.second.GetName().length(); 
    } 
};

class Railways{
	string name_;                                                                  //Name of the Railway - IndianRailways
	static vector<Station> sStations;                                              //Vector of Stations 
	static unordered_map<pair<Station,Station>,double,HashFunc> sDistStations ;    //Unorderd Map of Distances
    //Private CONSTRUCTOR
    Railways(string s = "IndianRailways"): name_(s) {};
    
public:
    //DESTRUCTOR
    ~Railways();
    //Returns instance of the SIngletaon Class Railways
    static const Railways& GetInst();
    //Returns distance between two stations
    double GetDistance(const Station& st1, const Station& st2) const;
    //Prints all details about the Railway
    void Print() const;
    //Check Validity
    bool IsValid();
    //Unit Test
    static void TestRailway();
};


#endif