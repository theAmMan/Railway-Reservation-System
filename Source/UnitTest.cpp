/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include "Booking.h"
#include <iostream>

int main(){
	freopen("UnitTest.txt", "w", stdout);
	Exception::TestException();
	Station::TestStation();
	Railways::TestRailway();
	Date::TestDate();
	Gender::TestGender();
	Passenger::TestPassenger();
	BookingClass::TestBookingClass();
	BookingCategory::TestBookingCategory();
	Booking::TestBooking();
	return 0;
}