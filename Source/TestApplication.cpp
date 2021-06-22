/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include "Booking.h"
#include <iostream>

int main(){
	freopen("TestApplication.txt", "w", stdout);
	//Test Railway
	Railways Ind = Ind.GetInst();
	Ind.Print();
	//Male passenger
	Passenger p1("Anthony Edward","123498763456",Date("20/12/1960"),Male::Type(),"9876543210","Cancer","Can123");
	//Female Passenger
	Passenger p2("Wanda Maximoff","123498763456",Date("20/12/1960"),Female::Type(),"9876543210","Blind","Blin234");
	//Invalid DOB
	Passenger p3("Steve Rogers","123498763456",Date("32/12/1960"),Male::Type(),"9876543210","Blind","Blin365");
	//Invalid Date of Booking
	Booking(Station("Mumbai"), Station("Delhi"), Date("09/04/2021"), ACFirstClass::Type(),General::Type(),&p1);
	Booking(Station("Mumbai"), Station("Delhi"), Date("09/06/2022"), ACFirstClass::Type(),General::Type(),&p1);
	//Valid tatkal booking
	//Change the date to tomorrow, to make Valid, else Invalid
	Booking(Station("Delhi"), Station("Mumbai"), Date("10/04/2021"), AC3Tier::Type(),Tatkal::Type(Date("10/04/2021")),&p1);
	//Invalid Passenger
	Booking(Station("Delhi"), Station("Mumbai"), Date("16/04/2021"), ACFirstClass::Type(),Senior::Type(p3),&p3);
	//Senior Female
	Booking(Station("Delhi"), Station("Mumbai"), Date("26/04/2021"), AC3Tier::Type(),Senior::Type(p2),&p2);
	//Trying Ladies booking for male
	//If category is not valid software automatically redirects to General Category
	Booking(Station("Mumbai"), Station("Delhi"), Date("18/04/2021"), ACFirstClass::Type(),Ladies::Type(p1),&p1);
	//Blind Booking
	Booking(Station("Mumbai"), Station("Delhi"), Date("12/05/2021"), ACFirstClass::Type(),Blind::Type(p2),&p2);
	//Cancer Booking
	Booking(Station("Mumbai"), Station("Delhi"), Date("09/06/2021"), ACFirstClass::Type(),Cancer::Type(p1),&p1);
	for(auto i:Booking::sBookings){
		cout<<*i;
		cout<<"********************************"<<endl<<endl;
	}
	return 0;
}