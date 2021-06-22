/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _GENDER_H
#define _GENDER_H

#include<iostream>

using namespace std;
//Base Class
class Gender {
	const string& name_;
protected:
	Gender(const string& name);

public:
	const Gender& operator=(const Gender&);
	virtual ~Gender();
	//Returns title
	const string GetTitle() const;
	//Returns name
	const string& GetName() const;
	//Test whether Male
	static bool IsMale(const Gender& g);  
	//Unit Test
	static void TestGender();
};
//Male
class Male : public Gender {
	Male();
	static const string sName;
public:
	static const Gender& Type();
	static const string GetTitle();
};
//Female
class Female : public Gender {
	Female();
	static const string sName;
public:
	static const Gender& Type();
	static const string GetTitle();
};

#endif