/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include<iostream>

#include "Passenger.h"

Passenger::Passenger(string n, string a, Date d, Gender g,string m,string dt, string di): name_(n),aadhar_(a),dob_(d),gender_(g),mobile_(m),disType_(dt),disId_(di){}

Passenger& Passenger::operator=(const Passenger& p){
	name_=(p.name_);
	aadhar_=(p.aadhar_);
	dob_=(p.dob_);
	gender_=(p.gender_);
	mobile_=(p.mobile_);
	disType_=(p.disType_);
	disId_=(p.disId_);
}

Passenger::~Passenger(){}

string Passenger::GetName() const{
	return this->name_;
}

string Passenger::GetFname() const{
	char str[name_.length()+1];
	strcpy(str,name_.c_str());
	char *token = strtok(str, " ");
	return string(token);
}

string Passenger::GetLname() const{
	char str[name_.length()+1];
	strcpy(str,name_.c_str());
	char *res;
	char *token = strtok(str, " ");
	while (token != NULL){
		res=token;
        token = strtok(NULL, " ");
    }
	return string(res);
}

string Passenger::GetDis() const{
	return this->disType_;
}

bool Passenger::IsValid(){
	try{
		if(name_.length()<1)
			throw (Bad_Passenger("Invalid Name"));
		if(aadhar_.length()!=12 || stod(aadhar_)<1e11)
			throw (Bad_Passenger("Invalid Aadhar"));
		if(dob_.CalcAge()<0 || !dob_.IsValid())
			throw (Bad_Passenger("Invalid DOB"));
		if(mobile_.length()!=10 || stod(mobile_)<1e9)
			throw (Bad_Passenger("Invalid Mobile Number"));
		if(disType_!="None" && disId_=="-")
			throw (Bad_Passenger("Invalid Disability"));
	}
	catch(Bad_Passenger p){
		cout<<p.message<<endl;
		return false;
	}
	return true;
}

void Passenger::Print() const{
	cout<<"   Name: ";
	if(gender_.GetName()=="Male") cout<<Male::GetTitle()<<" ";
	else cout<<Female::GetTitle()<<" ";
	cout<<name_<<endl;
	cout<<"   Aadhar #"<<aadhar_<<endl;
	cout<<"   DoB: ";
	dob_.Print();
	cout<<"   Gender: "<<gender_.GetName()<<endl;
	cout<<"   Mobile: "<<mobile_<<endl;
	cout<<"   Disability Type: "<<disType_<<endl;
	cout<<"   Disability Id: "<<disId_<<endl;
}

ostream& operator<<(ostream& os, const Passenger& p){
    os<<"   Name: ";
    if(p.gender_.GetName()=="Male") os<<Male::GetTitle()<<" ";
    else os<<Female::GetTitle()<<" ";
    os<<p.name_<<endl;
	os<<"   Aadhar #"<<p.aadhar_<<endl;
	os<<"   DoB: "<<p.dob_<<endl;
	os<<"   Gender: "<<p.gender_.GetName()<<endl;
	os<<"   Mobile: "<<p.mobile_<<endl;
	os<<"   Disability Type: "<<p.disType_<<endl;
	os<<"   Disability Id: "<<p.disId_<<endl;
    return os;
}

istream& operator>>(istream& is, Passenger& p){
    string n,a,g,m,c;
    Date d;
    getline(is,n);
    is>>a>>d>>g>>m>>c;
    if(g[0]=='M' || g[0]=='m')
    	p= Passenger(n,a,d,Male::Type(),m);
    else p = Passenger(n,a,d,Female::Type(),m);
    return is;
}

void Passenger::TestPassenger(){
	cout<<"TEST PASSENGER********************"<<endl;
	Passenger p("Anthony Edward","123498763456",Date("20/12/2020"),Male::Type(),"9876543210","Cancer","Can123");
	//Test GetName
	if(p.GetName()!="Anthony Edward") cout<<"FAILED GetName"<<endl;
	else cout<<"PASSED GetName"<<endl;
	//Test GetFname
	if(p.GetFname()!="Anthony") cout<<"FAILED GetFirstname"<<endl;
	else cout<<"PASSED GetFirstname"<<endl;
	//Test GetLname
	if(p.GetLname()!="Edward") cout<<"FAILED GetLastname"<<endl;
	else cout<<"PASSED GetLastname"<<endl;
	//Test GetDis
	if(p.GetDis()!="Cancer") cout<<"FAILED GetDis"<<endl;
	else cout<<"PASSED GetDis"<<endl;
	//Test IsValid
	if(p.IsValid()) cout<<"PASSED IsValid"<<endl;
	else cout<<"FAILED IsValid"<<endl;
	cout<<"TESTING INVALID PASSENGERS"<<endl;
	//Invalid name
	Passenger("","123498763456",Date("20/12/2020"),Male::Type(),"9876543210","Cancer","Can123").IsValid();
	//Invalid Aadhaar
	Passenger("Anthony Edward","12348763456",Date("20/12/2020"),Male::Type(),"9876543210","Cancer","Can123").IsValid();
	//Invalid DOB
	Passenger("Anthony Edward","123498763456",Date("20/13/2020"),Male::Type(),"9876543210","Cancer","Can123").IsValid();
	//Invalid Mobile
	Passenger("Anthony Edward","123498763456",Date("20/12/2020"),Male::Type(),"986543210","Cancer","Can123").IsValid();
	//Invalid Disability
	Passenger("Anthony Edward","123498763456",Date("20/12/2020"),Male::Type(),"9876543210","Cancer").IsValid();
}