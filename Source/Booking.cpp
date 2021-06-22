/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include<iostream>
#include<cmath>
#include<vector>
#include <ctime>

#include "Booking.h"

using namespace std;

Booking::Booking(Station f,Station t,Date d,BookingClass c,BookingCategory b,Passenger* p): frmStn_(f),toStn_(t),date_(d),bkgCls_(c),bkgCtg_(b),psngr_(p){
	try{
		if(!this->IsValid())
			throw(Bad_Booking("Invalid Booking Details"));
		sBookingPNRSerial++;
		pnr_=sBookingPNRSerial;
		Booking::sBookings.push_back(this);
	}
	catch(Bad_Booking b){
		cout<<b.message<<endl<<"Booking cancelled"<<endl<<endl;
	}
}

bool Booking::IsValid(){
	try{
		if(!date_.IsValid())
			throw(Bad_Date(date_.ToString()));
		if(date_.CalcAge()>=0)
			throw(Bad_Date(date_.ToString()));
		if(!date_.CalcSpan())
			throw(Bad_Date(date_.ToString()));
		if(!psngr_->IsValid())
			throw(Bad_Passenger(psngr_->GetName()));
	}
	catch(Bad_Date b){
		cout<<"Bad Date: "<<b.message<<endl;
		return false;
	}
	catch(Bad_Passenger b){
		cout<<"Invalid Passenger Details for: "<<b.message<<endl;
		return false;
	}
	return true;
}

int Booking::ComputeFare() const{
	if(bkgCtg_.GetName()=="General") return GeneralBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_);
	if(bkgCtg_.GetName()=="Tatkal") return TatkalBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_);
	if(bkgCtg_.GetName()=="Premium Tatkal") return PremTatkalBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_);
	if(bkgCtg_.GetName()=="Senior") return SeniorBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc());
	if(bkgCtg_.GetName()=="Ladies") return LadiesBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc());
	if(bkgCtg_.GetName()=="Blind") return BlindBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc());
	if(bkgCtg_.GetName()=="Ortho") return OrthoBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc());
	if(bkgCtg_.GetName()=="TB") return TBBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc());
	if(bkgCtg_.GetName()=="Cancer") return CancerBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc());
}

void Booking::Print() const{
	cout<<"BOOKING SUCCEEDED"<<endl;
	cout<<"PNR Number: "<<pnr_<<endl;
	const Passenger* p = psngr_;
	cout<<*p<<endl;
	cout<<"From Station: "<<frmStn_.GetName()<<endl;
	cout<<"To Station: "<<toStn_.GetName()<<endl;
	time_t now = time(0);
    tm *ltm = localtime(&now);
    cout<<"Booking Date: "<<ltm->tm_mday<<"/"<<ltm->tm_mon+1<<"/"<<1900+ltm->tm_year<<endl;	
	cout<<"Travel Date: ";
	date_.Print();
	cout<<"Travel Class: ";
	bkgCls_.Print();
	//If not eligible, booking is done for General Category
	if(bkgCtg_.GetName()=="General" || !bkgCtg_.IsEligible())
		cout<<"Category: General"<<endl<<"Fare: "<<GeneralBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_)<<endl;
	else if(bkgCtg_.GetName()=="Tatkal")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<TatkalBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_)<<endl;
	else if(bkgCtg_.GetName()=="Premium Tatkal")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<PremTatkalBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_)<<endl;
	else if(bkgCtg_.GetName()=="Senior")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<SeniorBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc())<<endl;
	else if(bkgCtg_.GetName()=="Ladies")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<LadiesBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc())<<endl;
	else if(bkgCtg_.GetName()=="Blind")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<BlindBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc())<<endl;
	else if(bkgCtg_.GetName()=="Ortho")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<OrthoBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc())<<endl;
	else if(bkgCtg_.GetName()=="TB")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<TBBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc())<<endl;
	else if(bkgCtg_.GetName()=="Cancer")
		cout<<"Category: "<<bkgCtg_.GetName()<<endl<<"Fare: "<<CancerBook::ComputeFare(sBaseFarePerKM,toStn_.GetDistance(frmStn_),bkgCls_,bkgCtg_.CalConc())<<endl;
} 

ostream& operator<<(ostream& os, Booking& b){
	os<<"BOOKING SUCCEEDED"<<endl;
	os<<"PNR Number: "<<b.pnr_<<endl;
	const Passenger* p = b.psngr_;
	os<<*p<<endl;
	os<<"From Station: "<<b.frmStn_<<endl;
	os<<"To Station: "<<b.toStn_<<endl;
	time_t now = time(0);
    tm *ltm = localtime(&now);
    os<<"Booking Date: "<<ltm->tm_mday<<"/"<<ltm->tm_mon+1<<"/"<<1900+ltm->tm_year<<endl;	
	os<<"Travel Date: "<<b.date_<<endl;
	os<<"Travel Class: "<<b.bkgCls_<<endl;
	
	if(b.bkgCtg_.GetName()=="General" || !b.bkgCtg_.IsEligible())
		os<<"Category: General"<<endl<<"Fare: "<<GeneralBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_)<<endl;
	else if(b.bkgCtg_.GetName()=="Tatkal")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<TatkalBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_)<<endl;
	else if(b.bkgCtg_.GetName()=="Premium Tatkal")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<PremTatkalBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_)<<endl;
	else if(b.bkgCtg_.GetName()=="Senior")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<SeniorBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_,b.bkgCtg_.CalConc())<<endl;
	else if(b.bkgCtg_.GetName()=="Ladies")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<LadiesBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_,b.bkgCtg_.CalConc())<<endl;
	else if(b.bkgCtg_.GetName()=="Blind")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<BlindBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_,b.bkgCtg_.CalConc())<<endl;
	else if(b.bkgCtg_.GetName()=="Ortho")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<OrthoBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_,b.bkgCtg_.CalConc())<<endl;
	else if(b.bkgCtg_.GetName()=="TB")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<TBBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_,b.bkgCtg_.CalConc())<<endl;
	else if(b.bkgCtg_.GetName()=="Cancer")
		os<<"Category: "<<b.bkgCtg_.GetName()<<endl<<"Fare: "<<CancerBook::ComputeFare(b.sBaseFarePerKM,b.toStn_.GetDistance(b.frmStn_),b.bkgCls_,b.bkgCtg_.CalConc())<<endl;
	return os;
}


int GeneralBook::ComputeFare(const double fare, int dis, BookingClass c) {
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_ += c.GetCharge();
	return round(fare_);
}

int TatkalBook::ComputeFare(const double fare, int dis, BookingClass c) {
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	if(dis>=c.GetMinDis()){
		if(c.GetName()=="Second Sitting")
			fare_+=min(max(fare_/10,(double)c.GetMinChrg()),(double)c.GetMaxChrg());
		else 
			fare_+=min(max(3*fare_/10,(double)c.GetMinChrg()),(double)c.GetMaxChrg());
	}
	fare_ += c.GetCharge();
	return round(fare_);
}

int PremTatkalBook::ComputeFare(const double fare, int dis, BookingClass c) {
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	if(dis>=c.GetMinDis()){
		if(c.GetName()=="Second Sitting")
			fare_+=min(max(fare_/5,2*(double)c.GetMinChrg()),2*(double)c.GetMaxChrg());
		else 
			fare_+=min(max(3*fare_/5,2*(double)c.GetMinChrg()),2*(double)c.GetMaxChrg());
	}
	fare_ += c.GetCharge();
	return round(fare_);
}

int SeniorBook::ComputeFare(const double fare, int dis, BookingClass c, double con) {
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_*= (100-con)/100;
	fare_ += c.GetCharge();
	return round(fare_);
}

int LadiesBook::ComputeFare(const double fare, int dis, BookingClass c, double con) {
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_*= (100-con)/100;
	fare_ += c.GetCharge();
	return round(fare_);
}

int BlindBook::ComputeFare(const double fare, int dis, BookingClass c, double con) {
	if(c.GetName()=="AC First Class" || c.GetName()=="AC 2 Tier") con =50;
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_*= (100-con)/100;
	fare_ += c.GetCharge();
	return round(fare_);
}

int OrthoBook::ComputeFare(const double fare, int dis, BookingClass c, double con) {
	if(c.GetName()=="AC First Class" || c.GetName()=="AC 2 Tier") con =50;
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_*= (100-con)/100;
	fare_ += c.GetCharge();
	return round(fare_);
}

int TBBook::ComputeFare(const double fare, int dis, BookingClass c, double con) {
	if(c.GetName()=="First Class" || c.GetName()=="Sleeper" || c.GetName()=="Second Sitting") con =75;
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_*= (100-con)/100;
	fare_ += c.GetCharge();
	return round(fare_);
}

int CancerBook::ComputeFare(const double fare, int dis, BookingClass c, double con) {
	if(c.GetName()=="AC First Class" || c.GetName()=="AC 2 Tier") con =50;
	else if(c.GetName()=="First Class" || c.GetName()=="Executive Chair Car") con =75;
	double fare_ =  fare*dis;
	fare_ *= c.GetLoadFactor();
	fare_*= (100-con)/100;
	fare_ += c.GetCharge();
	return round(fare_);
}

void Booking::TestBooking(){
	cout<<"TEST BOOKING********************"<<endl;
	//Test IsValid
	Passenger p1("Anthony Edward","123498763456",Date("20/12/1960"),Male::Type(),"9876543210","Cancer","Can123");
	Booking b1(Station("Mumbai"), Station("Delhi"), Date("15/06/2021"), ACFirstClass::Type(),General::Type(),&p1);
	if(b1.IsValid())cout<<"PASSED IsValid"<<endl;
	else cout<<"FAILED IsValid"<<endl;
	//Test Compute Fare
	if(b1.ComputeFare()==4763)cout<<"PASSED ComputeFare"<<endl;
	else cout<<"FAILED ComputeFare"<<endl;
}

vector<Booking*> Booking::sBookings={};								//Vector of Bookings initialized to blank
int Booking::sBookingPNRSerial=0;									//PNR serial initialized to 0		
const double Booking::sBaseFarePerKM = 0.5;							//Base Fare per Km set to 0.5
