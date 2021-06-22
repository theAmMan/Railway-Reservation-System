/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _BOOKINGCAT_H
#define _BOOKINGCAT_H

#include<iostream>
#include "Passenger.h"

using namespace std;

class BookingCategory{
protected:
	string name_;
	double conc_;
	bool elig_;

public:
    
    //CONSTRUCTOR
    BookingCategory();
    //DESTRUCTOR
    ~BookingCategory();
    
    //Returns Name of the Booking Category
    string GetName() const;
    //Whether eligible
    virtual bool IsEligible() const;
    // Calculate Concession
    double CalConc()const;
    //Print
    void Print()const;
 	static void TestBookingCategory();
};

class General: public BookingCategory{
	General(){
		name_="General";
	}
	~General(){}
public:
	static const General& Type();
};

class Tatkal: public BookingCategory{
	Tatkal(){
		name_="Tatkal";
	}
	~Tatkal(){}
public:
	static const Tatkal& Type(Date d);
};

class PremiumTatkal: public BookingCategory{
	PremiumTatkal(){
		name_="Premium Tatkal";
	}
	~PremiumTatkal(){}
public:
	static const PremiumTatkal& Type(Date d);
};

class Concession: public BookingCategory{
public:
	Concession(){elig_=0;}
};

class Senior: public Concession{
	Senior(){
		name_="Senior";
	}
	~Senior(){}
public:
	static const Senior& Type(Passenger p);
};

class Ladies: public Concession{
	Ladies(){
		name_="Ladies";
	}
	~Ladies(){}
public:
	static const Ladies& Type(Passenger p);
};

class Divyang: public Concession{
};

class Blind: public Divyang{
	Blind(){
		name_="Blind";
	}
	~Blind(){}
public:
	static const Blind& Type(Passenger p);
};

class Ortho: public Divyang{
	Ortho(){
		name_="Ortho";
	}
	~Ortho(){}
public:
	static const Ortho& Type(Passenger p);
};

class TB: public Divyang{
	TB(){
		name_="TB";
	}
	~TB(){}
public:
	static const TB& Type(Passenger p);
};

class Cancer: public Divyang{
	Cancer(){
		name_="Cancer";
	}
	~Cancer(){}
public:
	static const Cancer& Type(Passenger p);
};

#endif