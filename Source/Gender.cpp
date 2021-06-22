/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include "Gender.h"
#include<iostream>

using namespace std;

Gender::Gender(const string& name) : name_(name) { }
const Gender& Gender::operator=(const Gender& g){
	if(g.GetName()=="Male")
		return Male::Type();
}

Gender::~Gender() { }
const string Gender::GetTitle() const { }
const string& Gender::GetName() const { return name_; }
	// In a good OOP design we must not have /// need such an interface!
Male::Male() : Gender(Male::sName) {}

const Gender& Male::Type() {
	static const Male theObj;
	return theObj;
}
const string Male::GetTitle() { return "Mr."; }

Female::Female() : Gender(Female::sName) { }
const Gender& Female::Type() {
	static const Female theObj;
	return theObj;
}
const string Female::GetTitle() { return "Ms."; }

// Explicit checking of type
bool Gender::IsMale(const Gender& g) { 
	return g.GetName()=="Male";
}

void Gender::TestGender(){
	cout<<"TEST GENDER********************"<<endl;
	//Test GetName
	if(Male::Type().GetName()!="Male") cout<<"FAILED GetName"<<endl;
	else cout<<"PASSED GetName"<<endl;
	//Test GetTitle
	if(Male::GetTitle()!="Mr.") cout<<"FAILED GetTitle"<<endl;
	else cout<<"PASSED GetTitle"<<endl;
}

// Names defined as static constants
const string Male::sName = "Male";
const string Female::sName = "Female";
