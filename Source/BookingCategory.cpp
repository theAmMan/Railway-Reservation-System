/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include<iostream>

#include "BookingCategory.h"

BookingCategory::BookingCategory(){
	conc_=0;
	elig_=1;
}
BookingCategory::~BookingCategory(){}

string BookingCategory::GetName() const{ return this->name_;}
bool BookingCategory::IsEligible() const{ return this->elig_;}
double BookingCategory::CalConc() const{ return this->conc_;}
void BookingCategory::Print()const{
	cout<<this->name_<<endl;
}

const General& General::Type(){
	static General sCat;
	return sCat;
}

const Tatkal& Tatkal::Type(Date d){
	static Tatkal sCat;
	if(d.CalcSpan()!=1) sCat.elig_=0;
	return sCat;
}

const PremiumTatkal& PremiumTatkal::Type(Date d){
	static PremiumTatkal sCat;
	if(d.CalcSpan()!=1) sCat.elig_=0;
	return sCat;
}

const Senior& Senior::Type(Passenger p){
	static Senior sCat;
	if(p.gender_.GetName()=="Male" && p.dob_.CalcAge()>59){
		sCat.conc_=40;
		sCat.elig_=1;
	}
	else if(p.gender_.GetName()=="Female" && p.dob_.CalcAge()>57){
		sCat.conc_=50;
		sCat.elig_=1;

	}
	return sCat;
}

const Ladies& Ladies::Type(Passenger p){
	static Ladies sCat;
	if(p.gender_.GetName()=="Female"){
		sCat.elig_=1;
	}
	return sCat;
}

const Blind& Blind::Type(Passenger p){
	static Blind sCat;
	if(p.GetDis()=="Blind" && p.disId_!="-"){
		sCat.conc_=75;
		sCat.elig_=1;
	}
	return sCat;
}

const Ortho& Ortho::Type(Passenger p){
	static Ortho sCat;
	if(p.GetDis()=="Ortho" && p.disId_!="-"){
		sCat.conc_=75;
		sCat.elig_=1;
	}
	return sCat;
}

const TB& TB::Type(Passenger p){
	static TB sCat;
	if(p.GetDis()=="TB" && p.disId_!="-"){
		sCat.conc_=0;
		sCat.elig_=1;
	}
	return sCat;
}

const Cancer& Cancer::Type(Passenger p){
	static Cancer sCat;
	if(p.GetDis()=="Cancer" && p.disId_!="-"){
		sCat.conc_=100;
		sCat.elig_=1;
	}
	return sCat;
}

void BookingCategory::TestBookingCategory(){
	cout<<"TEST BOOKINGCATEGORY********************"<<endl;
	Passenger p("Anthony Edward","123498763456",Date("20/12/1960"),Male::Type(),"9876543210");
	BookingCategory c = Senior::Type(p);
	if(c.GetName()!="Senior")  cout<<"FAILED GetName"<<endl;
	else cout<<"PASSED GetName"<<endl;
	if(c.IsEligible()) cout<<"PASSED IsEligible"<<endl;
	else cout<<"FAILED IsEligible"<<endl;
	if(c.CalConc()!=40) cout<<"FAILED CalConc"<<endl;
	else cout<<"PASSED CalConc"<<endl;
}