/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#ifndef _BOOKINGCLASS_H
#define _BOOKINGCLASS_H

#include<iostream>

using namespace std;

class BookingClass{
protected:
    string name_;                                               //Name of the Booking Class
    bool sit_;                                                  //True if Seat, False if Berth
    bool ac_;                                                   //True if AC
    int tier_;                                                  //Number of Tiers
    double loadFct_;                                            //Load Factor of the Booking Class
    bool lxr_;                                                  //True if Luxury
    int resChrg_;                                               //Reservation Charge
    int ttklLoad_;                                              //Tatkal Load
    int minCh_;                                                 //Minimum Tatkal Charge  
    int maxCh_;                                                 //Maximum Tatkal Charge
    int minDis_;                                                //Minimum Distance

public:
    
    //CONSTRUCTOR
    BookingClass();
    //DESTRUCTOR
    ~BookingClass();
    
    //Returns Name of the Booking Class
    string GetName() const;
    //Whether Seat or Berth
    bool IsSitting() const;
    //Whether AC
    bool IsAc() const;
    //Returns number of Tiers
    int GetNumberOfTiers() const;
    //Return Load Factor
    double GetLoadFactor() const;
    //Whether Luxury
    bool IsLuxury() const ;
    //Change Luxury ststus
    void SetLuxury(bool b = 1);
    //Change Load Factor
    void SetLoadFactor(int x);
    //Change Charge
    void SetCharge(double x);
    //Change Tatkal Load
    void SetTtklLoad(int x);
    //Change Min Charge
    void SetMinChrg(int x);
    //Change Max Charge
    void SetMaxChrg(int x);
    //Change Min Distance
    void SetMinDis(int x);
    //Get Reservation Charge
    double GetCharge() const;
    //Get Tatkal Load
    int GetTtklLoad();
    //Get Minimum Charge
    int GetMinChrg();
    //Get Maximum Charge
    int GetMaxChrg();
    //Get Minimum Distance
    int GetMinDis();
    //Print all details
    void Print() const;
    //Unit Test
    static void TestBookingClass();
    //Ostream overload
    friend ostream& operator<<(ostream& os, BookingClass& b);
};

//Type() returns instance of each Singleton BookingClass 
//ACChairCar
class ExecutiveChairCar: public BookingClass{
    //CONSTRUCTOR
    ExecutiveChairCar(){
        name_ = "Executive Chair Car";
        loadFct_ = 5;
        sit_ = true;
        ac_ = true; 
        tier_= 0;
        lxr_ = true;
        resChrg_ = 60;
        ttklLoad_=30;
        minCh_=400;
        maxCh_=500;
        minDis_=250;
    }
    ~ExecutiveChairCar(){}
public:
    static const ExecutiveChairCar& Type();
};

//ACChairCar
class ACChairCar: public BookingClass{
    //CONSTRUCTOR
    ACChairCar(){
	    name_ = "AC Chair Car";
	    loadFct_ = 2;
	    sit_ = true;
	    ac_ = true; 
	    tier_= 0;
	    lxr_ = false;
        resChrg_ = 40;
        ttklLoad_=30;
        minCh_=125;
        maxCh_=225;
        minDis_=250;
	}
    ~ACChairCar(){}
public:
	static const ACChairCar& Type();
};

//SecondSitting
class SecondSitting:public BookingClass{
    //CONSTRUCTOR
    SecondSitting(){
        name_ = "Second Sitting";
        loadFct_ = 0.6; 
        sit_ = true;
        ac_ = false;
        tier_ = 0;
        lxr_ = false;
        resChrg_ = 15;
        ttklLoad_=10;
        minCh_=10;
        maxCh_=15;
        minDis_=100;
    }
    ~SecondSitting(){}
public:
	static const SecondSitting& Type();
};

//ACFirstClass
class ACFirstClass :public BookingClass{
    //CONSTRUCTOR
    ACFirstClass(){
	    name_ = "AC First Class";
	    loadFct_ = 6.5;
	    sit_ = false;
	    ac_ = true;
	    tier_ = 2;
	    lxr_ = true;
        resChrg_ = 60;
        ttklLoad_=30;
        minCh_=400;
        maxCh_=500;
        minDis_=500;
	}
    ~ACFirstClass(){}
public:
	static const ACFirstClass& Type();
};

//AC2Tier
class AC2Tier :public BookingClass{
    //CONSTRUCTOR
    AC2Tier(){
	    name_ = "AC 2 Tier";
	    loadFct_ = 4;
	    sit_ = false;
	    ac_ = true;
	    tier_ = 2;
	    lxr_ = false;
        resChrg_ = 50;
        ttklLoad_=30;
        minCh_=400;
        maxCh_=500;
        minDis_=500;
	}
    ~AC2Tier(){}
public:
	static const AC2Tier& Type();
};

//FirstClass
class FirstClass :public BookingClass{
    //CONSTRUCTOR
    FirstClass(){
        name_ = "First Class";
        loadFct_ = 3;
        sit_ = false;
        ac_ = false;
        tier_ = 2;
        lxr_ = true;
        resChrg_ = 50;
        ttklLoad_=30;
        minCh_=400;
        maxCh_=500;
        minDis_=500;
    }
    ~FirstClass(){}
    public:
	static const FirstClass& Type();
};

//AC3Tier
class AC3Tier :public BookingClass{
    //CONSTRUCTOR
    AC3Tier(){
        name_ = "AC 3 Tier";
        loadFct_ = 2.5;
        sit_ = false;
        ac_ = true;
        tier_ = 3;
        lxr_ = false;
        resChrg_ = 40;
        ttklLoad_=30;
        minCh_=300;
        maxCh_=400;
        minDis_=500;
    }
    ~AC3Tier(){}
public:
	static const AC3Tier& Type();
};

//Sleeper
class Sleeper :public BookingClass{
    //CONSTRUCTOR
    Sleeper(){
        name_ = "Sleeper";
        loadFct_ = 1;
        sit_ = false;
        ac_ = false;
        tier_ = 3;
        lxr_ = false;
        resChrg_ = 20;
        ttklLoad_=30;
        minCh_=100;
        maxCh_=200;
        minDis_=500;
    }
    ~Sleeper(){}
public:
	static const Sleeper& Type();
};

#endif