/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include<iostream>
#include "Error.h"

using namespace std;

Bad_Date::Bad_Date(string s){
	message = s;
}

Bad_Passenger::Bad_Passenger(string s){
	message = s;
}

Bad_Railway::Bad_Railway(string s){
	message = s;
}

Bad_Booking::Bad_Booking(string s){
	message = s;
}

void Exception::TestException(){
	cout<<"TEST EXCEPTION********************"<<endl;
	Bad_Railway r("Invalid Railway");
	//Test Constructor
	if(r.message!="Invalid Railway") cout<<"FAILED Exception"<<endl;
	else cout<<"PASSED Exception"<<endl;
}