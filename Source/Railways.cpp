/*	Name: Amartya Mandal
	Roll: 19CS10009*/

#include "Railways.h"

Railways::~Railways(){}

const Railways& Railways::GetInst(){
    static Railways sRail;
    return sRail;
}

double Railways::GetDistance(const Station& st1, const Station& st2) const{
    return sDistStations[make_pair(st1,st2)];
}

bool Railways::IsValid(){
    for(auto i:sStations){
        for(auto j:sStations){
            try{
                if(!(i==j) && GetDistance(i,j)!=GetDistance(j,i))
                    throw(Bad_Railway("Bad Distances"));
            }
            catch(Bad_Railway r){
                cout<<r.message<<endl;
                return false;
            }
        }
    }
    return true;
}

void Railways::Print() const{
    cout<<"INDIAN RAILWAYS"<<endl;
    cout<<"   Stations:"<<endl;
    for(auto i:sStations) cout<<"      "<<i.GetName()<<endl;
    cout<<"   Distances:"<<endl;
    for(auto i:sDistStations ){
        cout<<"      "<<i.first.first.GetName()<<" to "<<i.first.second.GetName()<<": "<<i.second<<endl;
    }
    cout<<endl;
}

//Vector initialized to the 5 stations
vector<Station> Railways::sStations = {Station("Mumbai"),Station("Delhi"),Station("Bangalore"),Station("Kolkata"),Station("Chennai")};

//Function returning the map containing distance between stations
unordered_map<pair<Station,Station>,double,HashFunc> GetMap(){
    unordered_map<pair<Station,Station>,double,HashFunc> t;

    t[make_pair(Station("Mumbai"),Station("Delhi"))] = 1447;
    t[make_pair(Station("Delhi"),Station("Mumbai"))] = 1447;

    t[make_pair(Station("Mumbai"),Station("Bangalore"))] = 981;
    t[make_pair(Station("Bangalore"),Station("Mumbai"))] = 981;

    t[make_pair(Station("Mumbai"),Station("Kolkata"))] = 2014;
    t[make_pair(Station("Kolkata"),Station("Mumbai"))] = 2014;

    t[make_pair(Station("Mumbai"),Station("Chennai"))] = 1338;
    t[make_pair(Station("Chennai"),Station("Mumbai"))] = 1338;

    t[make_pair(Station("Delhi"),Station("Bangalore"))] = 2150;
    t[make_pair(Station("Bangalore"),Station("Delhi"))] = 2150;

    t[make_pair(Station("Delhi"),Station("Kolkata"))] = 1472;
    t[make_pair(Station("Kolkata"),Station("Delhi"))] = 1472;

    t[make_pair(Station("Delhi"),Station("Chennai"))] = 2180;
    t[make_pair(Station("Chennai"),Station("Delhi"))] = 2180;
    
    t[make_pair(Station("Bangalore"),Station("Kolkata"))] = 1871;
    t[make_pair(Station("Kolkata"),Station("Bangalore"))] = 1871;

    t[make_pair(Station("Bangalore"),Station("Chennai"))] = 350;
    t[make_pair(Station("Chennai"),Station("Bangalore"))] = 350;

    t[make_pair(Station("Kolkata"),Station("Chennai"))] = 1659;
    t[make_pair(Station("Chennai"),Station("Kolkata"))] = 1659;

    return t;
}

//Unordere Map initialized to the given distances
unordered_map<pair<Station,Station>,double,HashFunc> Railways::sDistStations = GetMap();

void Railways::TestRailway(){
    cout<<"TEST RAILWAYS********************"<<endl;
    Railways Ind = Ind.GetInst();
    //Test GetDistance
    if(Ind.GetDistance(Station("Mumbai"),Station("Delhi"))!=1447)cout<<"FAILED GetDistance"<<endl;
    else cout<<"PASSED Railways::GetDistance"<<endl;
    //Test IsValid
    if(Ind.IsValid()) cout<<"PASSED IsValid"<<endl;
    else cout<<"FAILED IsValid"<<endl;
}
