/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include "Station.h"

using namespace std;

Station::Station(string s){
    if(s.length()) name_=s;
    else cout<<"Can not construct Station with no name"<<endl;
}

Station::~Station(){}

string Station::GetName()const{
	return this->name_;
}

bool operator==(const Station& s1, const Station& s2) {
    return s1.name_==s2.name_;
}

double Station::GetDistance(const Station& other) const{
	if(this->name_=="Mumbai"){
        if(other.name_=="Delhi") return 1447;
        if(other.name_=="Bangalore") return 981;
        if(other.name_=="Kolkata") return 2014;
        if(other.name_=="Chennai") return 1338;
    }
    if(this->name_=="Delhi"){
        if(other.name_=="Mumbai") return 1447;
        if(other.name_=="Bangalore") return 2150;
        if(other.name_=="Kolkata") return 1471;
        if(other.name_=="Chennai") return 2180;
    }
    if(this->name_=="Bangalore"){
        if(other.name_=="Mumbai") return 981;
        if(other.name_=="Delhi") return 2150;
        if(other.name_=="Kolkata") return 1871;
        if(other.name_=="Chennai") return 350;
    }
    if(this->name_=="Kolkata"){
        if(other.name_=="Mumbai") return 2014;
        if(other.name_=="Delhi") return 1471;
        if(other.name_=="Bangalore") return 1871;
        if(other.name_=="Chennai") return 1659;
    }
    if(this->name_=="Chennai"){
        if(other.name_=="Mumbai") return 1338;
        if(other.name_=="Delhi") return 2180;
        if(other.name_=="Bangalore") return 350;
        if(other.name_=="Kolkata") return 1659;
    }
    if(*this==other)
        return 0;
    return -1;
}

ostream& operator<<(ostream& os, const Station& s){
    os<<s.name_;
    return os;
}
istream& operator>>(istream& is, Station& s){
    string n;
    is>>n;
    s = Station(n);
    return is;
}
void Station::TestStation(){
    cout<<"TEST STATION********************"<<endl;
    Station stn("Mumbai");
    //Test GetName 
    if(stn.GetName()!="Mumbai")cout<<"FAILED GetName"<<endl;
    else cout<<"PASSED GetName"<<endl;
    //Test Equality
    if(!(stn==Station("Mumbai")))cout<<"FAILED Equality"<<endl;
    else cout<<"PASSED Equality"<<endl;
    //Test GetDistance
    if(stn.GetDistance(Station("Delhi"))!=1447)cout<<"FAILED GetDistance"<<endl;
    else cout<<"PASSED GetDistance"<<endl;
}