/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include<iostream>
#include <ctime>
#include "Date.h"

using namespace std;

Date::Date(string s){
    if(s.length()==10){
        date_ = stoi(s.substr(0,2));
        month_ = Month(stoi(s.substr(3,2)));
        year_ = stoi(s.substr(6,4));
    }
    else{
        date_ = stoi(s.substr(0,2));
        string m = s.substr(3,3);
        for(int i=0;i<12;i++){
            if(monthNames[i]==m)
                month_ = Month(i+1);        
        }
        year_ = stoi(s.substr(7,4));   
    }
}

Date::~Date(){}

int Date::GetDay() const{
    tm time_in = { 0, 0, 0, static_cast<int>(date_), month_-1, static_cast<int>(year_ - 1900 )};
    time_t time_temp = std::mktime(&time_in);
    const tm * time_out = std::localtime(&time_temp);
    return time_out->tm_wday;
}

bool Date::IsLeap(){ 
	return (((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0)); 
}

void Date::Print() const{ 
    if(this->GetDay()==-1){
        cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_ <<endl;    
    }
    else
	   cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_ <<" "<<dayNames[this->GetDay()]<< endl; 
}

bool Date::IsValid() { 
    try{
    	if (year_ > MAX_VALID_YR || year_ < MIN_VALID_YR) {
            throw(Bad_Date("Invalid Year"));
        }
    	if (month_ < 1 || month_ > 12) {
            throw(Bad_Date("Invalid Month"));   
        }
    	if (date_ < 1 || date_ > 31) {
            throw(Bad_Date("Invalid Day"));   
        }

        if (month_ == 2) { 
            if (this->IsLeap()){
                if (date_ > 29) throw(Bad_Date("Invalid Day"));   
            } 
            else{
                if (date_ > 28) throw(Bad_Date("Invalid Day (NOT Leap Year)")); 
            }
        } 
        if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
            if (date_ > 30) throw(Bad_Date("Invalid Date")); 
        }
    	return true; 
    }
    catch(Bad_Date d){
        cout<<d.message<<endl;
        return false;
    }
}

string Date::ToString(){
    string s = to_string(date_)+"/"+to_string(month_)+"/"+to_string(year_);
    return s;
}

int Date::CalcAge(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int res = (1900 + ltm->tm_year - year_);
    if(1 + ltm->tm_mon < month_) res--;
    else if(1 + ltm->tm_mon == month_){
        if(ltm->tm_mday < date_) res--;
    }
    return res;
}

int Date::CalcSpan(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(this->date_==ltm->tm_mday+1 && this->month_==1 + ltm->tm_mon && this->year_==1900 + ltm->tm_year) return 1;
    if(this->CalcAge()==-1) return 10;
    else return 0;
}

ostream& operator<<(ostream& os, const Date& dt){
    os << dt.date_ << "/" << dt.monthNames[dt.month_ - 1] << "/" << dt.year_ ;
    return os;
}

istream& operator>>(istream& is, Date& dt){
    string d;
    is>>d;
    dt = Date(d);
    return is;
}

void Date::TestDate(){
    cout<<"TEST DATE********************"<<endl;
    Date d("05/Mar/2021");
    //Test ToString
    if(d.ToString()!="5/3/2021") cout<<"FAILED ToString"<<endl;
    else cout<<"PASSED ToString"<<endl;
    //Test Default Date
    if(Date().ToString()!="1/1/2021") cout<<"FAILED Default Date"<<endl;
    else cout<<"PASSED Default Date"<<endl;
    //Test GetDay
    if(Date("07/03/2021").GetDay()!=0) cout<<"FAILED GetDay"<<endl;
    else cout<<"PASSED GetDay"<<endl;
    //Test Validity(Valid)
    if(!(d.IsValid())) cout<<"FAILED IsValid"<<endl;
    else cout<<"PASSED IsValid"<<endl;
    if(!(Date("29/Feb/2020").IsValid())) cout<<"FAILED IsValid for Leap Years"<<endl;
    else cout<<"PASSED IsValid for Leap Years"<<endl;
    //Test Age
    if(Date("06/04/2001").CalcAge()!=20) cout<<"FAILED CalcAge"<<endl;
    else cout<<"PASSED CalcAge"<<endl;
    //Test Span
    if(!Date("06/04/2022").CalcSpan())cout<<"FAILED CalcSpan"<<endl;
    else cout<<"PASSED CalcSpan"<<endl;
    cout<<"TESTING INVALID DATES"<<endl;
    Date("29/Feb/2021").IsValid();
    Date("32/Apr/2021").IsValid();
    Date("13/13/2020").IsValid();
    Date("13/10/2220").IsValid();
}