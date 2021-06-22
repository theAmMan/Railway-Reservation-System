/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include<iostream>

#include "BookingClass.h"

BookingClass::BookingClass(){}
BookingClass::~BookingClass(){}

string BookingClass::GetName() const { return this->name_ ; }
bool BookingClass::IsSitting() const { return this->sit_ ; }
bool BookingClass::IsAc() const { return this->ac_ ; }
int BookingClass::GetNumberOfTiers() const { return this->tier_ ; }
double BookingClass::GetLoadFactor() const { return this->loadFct_ ; }
bool BookingClass::IsLuxury() const { return this->lxr_ ; }
void BookingClass::SetLuxury(bool b){ this->lxr_ = b; return;}
void BookingClass::SetLoadFactor(int x){this->loadFct_=x;}
void BookingClass::SetCharge(double x){this->resChrg_=x;}
void BookingClass::SetTtklLoad(int x){this->ttklLoad_=x;}
void BookingClass::SetMinChrg(int x){this->minCh_=x;}
void BookingClass::SetMaxChrg(int x){this->maxCh_=x;}
void BookingClass::SetMinDis(int x){this->minDis_=x;}
double BookingClass::GetCharge() const{return this->resChrg_;}
int BookingClass::GetTtklLoad(){return this->ttklLoad_;}
int BookingClass::GetMinChrg(){return this->minCh_;}
int BookingClass::GetMaxChrg(){return this->maxCh_;}
int BookingClass::GetMinDis(){return this->minDis_;}
void BookingClass::Print() const{
	cout<<name_<<endl;
	cout<<"   Mode: ";
	sit_?cout<<"Sitting":cout<<"Sleeping";
	cout<<endl<<"   Comfort: ";
	ac_?cout<<"AC":cout<<"Non-AC";
	cout<<endl<<"   Bunks: "<<tier_<<endl<<"   Luxury: ";
	lxr_?cout<<"Yes":cout<<"No";
	cout<<endl;
}
void BookingClass::TestBookingClass(){
	cout<<"TEST BOOKINGCLASS********************"<<endl;
	BookingClass b = ACChairCar::Type();
	//Test GetName
	if(b.GetName()!="AC Chair Car") cout<<"FAILED GetName"<<endl;
	else cout<<"PASSED GetName"<<endl;
	//Test IsSitting
	if(!(b.IsSitting())) cout<<"FAILED IsSitting"<<endl;
	else cout<<"PASSED IsSitting"<<endl;
	//Test IsAc
	if(!(b.IsAc())) cout<<"FAILED IsAc"<<endl;
	else cout<<"PASSED IsAc"<<endl;
	//Test GetNumberOfTiers
	if(b.GetNumberOfTiers()) cout<<"FAILED GetNumberOfTiers"<<endl;
	else cout<<"PASSED GetNumberOfTiers"<<endl;
	//Test GetLoadFactor
	if(b.GetLoadFactor()!=2) cout<<"FAILED GetLoadFactor"<<endl;
	else cout<<"PASSED GetLoadFactor"<<endl;
	//Test IsLuxury
	if(b.IsLuxury()) cout<<"FAILED IsLuxury"<<endl;
	else cout<<"PASSED IsLuxury"<<endl;
	//Test GetTtklLoad
	if(b.GetTtklLoad()!=30) cout<<"FAILED GetTtklLoad"<<endl;
	else cout<<"PASSED GetTtklLoad"<<endl;
	//Test GetLoadFactor
	if(b.GetMaxChrg()!=225) cout<<"FAILED GetMaxChrg"<<endl;
	else cout<<"PASSED GetMaxChrg"<<endl;
	//Test GetMinChrg
	if(b.GetMinChrg()!=125) cout<<"FAILED GetMinChrg"<<endl;
	else cout<<"PASSED GetMinChrg"<<endl;
	//Test GetMinDis
	if(b.GetMinDis()!=250) cout<<"FAILED GetMinDis"<<endl;
	else cout<<"PASSED GetMinDis"<<endl;
}
ostream& operator<<(ostream& os, BookingClass& b){
	os<<b.name_<<endl;
	os<<"   Mode: ";
	b.sit_?os<<"Sitting":os<<"Sleeping";
	os<<endl<<"   Comfort: ";
	b.ac_?os<<"AC":os<<"Non-AC";
	os<<endl<<"   Bunks: "<<b.tier_<<endl<<"   Luxury: ";
	b.lxr_?os<<"Yes":os<<"No";
}

const ExecutiveChairCar& ExecutiveChairCar::Type(){
	static ExecutiveChairCar sCoach;
	return sCoach;
}

const ACChairCar& ACChairCar::Type(){
	static ACChairCar sCoach;
	return sCoach;
}

const SecondSitting& SecondSitting::Type(){
	static SecondSitting sCoach;
	return sCoach;
}

const ACFirstClass& ACFirstClass::Type(){
	static ACFirstClass sCoach;
	return sCoach;
}

const AC2Tier& AC2Tier::Type(){
	static AC2Tier sCoach;
	return sCoach;
}    

const FirstClass& FirstClass::Type(){
	static FirstClass sCoach;
	return sCoach;
}

const AC3Tier& AC3Tier::Type(){
	static AC3Tier sCoach;
	return sCoach;
}

const Sleeper& Sleeper::Type(){
	static Sleeper sCoach;
	return sCoach;
}  