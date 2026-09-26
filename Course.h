#include<iostream>
#include<string>
#ifndef COURSE_H
#define COURSE_H
using namespace std;
 
class Course {
private:
    string courseName;
    string acronym;
 
public:
 
    Course(){
        courseName="";
        acronym="";
    }
 
    Course(string cn, string ac){
        courseName=cn;
        acronym=ac;
    }
 
    void setCourse(string cn, string ac){
        courseName=cn;
        acronym=ac;
    }
 
    string getCname()const{ 
		return courseName; }
		
		
    string getAcronym()const{
		 return acronym; 
		 }
		 
		 
		 
 
    void displayCourse()const{
    	
        cout<<"COURSE NAME....\t"<<courseName<<endl;
        cout<<"COURSE ACRONYM.\t"<<acronym<<endl;
    }
 
    bool operator==(const Course& obj)const{
    	
        return courseName==obj.courseName &&acronym== obj.acronym;
               
    }
    
    
    	bool operator==(const string& name)const{
    		
        return courseName==name;
    }
 
    ~Course(){}
};
#endif