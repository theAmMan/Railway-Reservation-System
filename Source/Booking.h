/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _BOOKING_H
#define _BOOKING_H

#include<iostream>
#include<cmath>
#include<vector>

#include"Railways.h"
#include "BookingClass.h"
#include "BookingCategory.h"

using namespace std;

class Booking{
protected:
	static const double sBaseFarePerKM;								//Base Fare per Km set to 0.5 (see Booking.cpp)
	static int sBookingPNRSerial;									//Stores the largest unavailable PNR serial
	
	Station frmStn_,toStn_;											//Departure and Arrival Station
	Date date_;														//Journey Date
	BookingClass bkgCls_;											//Booking Class
	BookingCategory bkgCtg_;										//Booking Category
	Passenger* psngr_;												//Passenger
	int pnr_;														//PNR serial of the Booking	

public:
	
	static vector<Booking*> sBookings;								//Stores all Bookings made
	//CONSTRUCTOR
	//BookingClass defaulted to SecondSitting and Passenger* to NULL
	Booking(Station f,Station t,Date d,BookingClass c = SecondSitting::Type(), BookingCategory b = General::Type(), Passenger* p = NULL);
	//Returns the fare of the Booking rounded to nearest int
	int ComputeFare() const;
	//Check Validity
	bool IsValid();
	//Prints all booking details
	void Print() const;
	//Unit Test
	static void TestBooking();
	//Ostream overload
	friend ostream& operator<<(ostream& os, Booking& b);
};

class GeneralBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c);
};

class TatkalBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c);
};

class PremTatkalBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c);
};

class SeniorBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c, double con);
};

class LadiesBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c, double con);
};

class BlindBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c, double con);
};

class OrthoBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c, double con);
};

class TBBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c, double con);
};

class CancerBook: public Booking{
public:
	//Returns the fare of the Booking rounded to nearest int
	static int ComputeFare(const double fare, int dis, BookingClass c, double con);
};

#endif