#include<iostream>
#include<string>
#ifndef LOCATION_H
#define LOCATION_H
using namespace std;
 
class Location{
private:
    string address;
    string district;
    string state;
    string city;
 
public:
 
    Location(){
        address="";
        district="";
        state="";
        city="";
    }
 
    Location(string add,string dis,string st,string ct){
        address=add;
        district=dis;
        state=st;
        city=ct;
    }
 
    void setLocation(string add, string dis, string st, string ct){
        address=add;
        district=dis;
        state=st;
        city=ct;
        
        
    }
 

 
    string getCity()const { 
		return city; 
		
		}
		
    string getDistrict()const {
		 return district; 
		 
		 }
		 
		 
    string getState()const { 
		return state;
		 }
		
		
    string getAddress()const {
		 return address; 
		 
		 }
		 
		     void setLocation(){
        cout<<"ADDRESS:\t";
        cin>>address;
        cout<<"DISTRICT:\t";
        cin>>district;
        cout<<"STATE:\t";
        cin>>state;
        cout<<"CITY:\t";
        cin>>city;
    }
 
    void showLocation()const{
        cout<<"LOCATION DETAILS\n";
        cout<<"ADDRESS:\t"<< address<<endl;
        cout<<"DISTRICT:\t"<< district<<endl;
        cout<<"STATE:\t"<< state<<endl;
        cout<<"CITY:\t"<< city<<endl;
        
        
    }
 
    ~Location(){}
};
#endif