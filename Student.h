#include<iostream>
#include<string>
#include"User.h"
#include"Course.h"
#include"Location.h"
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
 
class Student:public User{
private:
    string enrollmentNo;
    int enrollmentYear;
    float cgpa;
    string* skills;
    int totalSkills;
    string situation;
    Course* course;
    int courseSize;
    Location loc;
 
public:
	
	class InvalidCgpaException{
		private:
			float msg;
		public:
			InvalidCgpaException(float m){
				msg=m;
			}
			void showMsg(){
				cout<<"you entered the cgpa invalid in number less then zero\n";
				cout<<"you enterd : "<<msg<<endl; 
			}
			
	};
	
    Student():User(){
        enrollmentNo="";
        enrollmentYear=0;
        cgpa=0;
        totalSkills=0;
        skills=nullptr;
        situation="PENDING";
        courseSize=0;
        course=nullptr;
        loc=Location();
    }
 
    Student(string n,string p,string em,string en,int ey,float cg,int t,string sit,int cs,Location l):User(n,p,em){
        enrollmentNo=en;
        enrollmentYear=ey;
        cgpa=cg;
        if(cgpa<0){
        	throw InvalidCgpaException(cgpa);
		}
        totalSkills=t;
        
        if(totalSkills > 0){
        	skills=new string[totalSkills];
		}
		else
			skills=nullptr;
       
        situation=sit;
        
        courseSize=cs;
        
                if(courseSize>0){
        	course=new Course[courseSize];
		}
		else
			course=nullptr;
      
        loc=l;
    }
    
    
        // 											 
		 
    string getENum()const{
		 return enrollmentNo; }
		 
		 
    string getEnrollmentNo()const{
	 return enrollmentNo; 
	 }
	 
    int getEyear()const{
	 return enrollmentYear;
	  }
	 
    float getCGPA()const{
	 return cgpa; 
	 }
	 
    string getStudentName()const{
	 return username; 
	 }
	 

    

 
    // 												 ASSIGNMNET OPEARTOR
    
    
    Student& operator=(const Student& obj){
        if(this != &obj){
            User::operator=(obj);
 
            enrollmentNo=obj.enrollmentNo;
            enrollmentYear=obj.enrollmentYear;
            
            cgpa=obj.cgpa;
            
            situation=obj.situation;
 
            delete[] skills;
            
            totalSkills=obj.totalSkills;
            
            
            if(totalSkills>0){
                skills=new string[totalSkills];
                for(int i=0;i<totalSkills;i++)
                    skills[i]=obj.skills[i];
                    
            } 
			else {
				
				
                skills = nullptr;
            }
 
            delete[] course;
            courseSize = obj.courseSize;
            if(courseSize>0){
            	
                course=new Course[courseSize];
                for(int i=0;i<courseSize;i++){
                	course[i]=obj.course[i];
				}
                    
            } 
			
			else{
                course=nullptr;
            }
 
            loc=obj.loc;
        }
        return *this;
    }
    
        string getSit()const{
	return situation; 
	
	}
    void setSit(string s)
	{ situation = s;
	 }
 
    // 												 LOGIN
    
    bool login(){
    	
        string un,pass;
        
        cout<<"ENTER USERNAME: ";
        cin>>un;
        
        cout<<"PASSWORD: ";
        cin>>pass;
        
        if(getName()==un&&getpassword()==pass){
            cout<<"ACCESS GRANTED\n";
            return true;
        }
        
        cout<<"ACCESS DENIED\n";
        return false;
    }
 
    //												SKILLS FUNC.
    
    
    void addSkills(string skill,int idx){
        if(idx>=0 && idx<totalSkills)
            skills[idx]=skill;
            
    }
 
    void displaySkills()const{
    	
        		if (totalSkills == 0) {
        		
            cout<<"No skills added yet.\n";
            return;
        }
        for(int i=0;i<totalSkills;i++)
        
            cout<<" "<<i + 1<<". "<<skills[i]<<endl;
            
            
            
    }
 
    bool hasSkill(string skill)const{
    	
        for (int i = 0; i < totalSkills; i++)
           	 if (skills[i] == skill) 
				return true;
            
        return false;
    }
 
    // 												COUSRE FUNCS
    
    
    void addCourse(Course& obj){
    	
        Course* temp=new Course[courseSize + 1];
        for(int i=0;i<courseSize;i++){
        	temp[i]=course[i];
		}
            
        temp[courseSize]=obj;
        delete[] course;
        course=temp;
        courseSize++;
        
        
    }
 
    void removeCourse(Course& obj){
        int index=-1;
        	for(int i=0;i<courseSize;i++){
            if(course[i]==obj){
            	
			 index = i;
			  break; 
			}
        }
        
        if(index==-1) 
		return;
		
        Course* temp=new Course[courseSize-1];
        int j=0;
        	for(int i=0;i<courseSize;i++)
            if(i !=index){
            	temp[j++] = course[i];
			} 
        delete[] course;
        course=temp;
        courseSize--;
        
        
    }
 
    bool checkCourse(string cr)const{
    	
        	for(int i=0;i<courseSize;i++){
            if(course[i].getCname()==cr){
                cout<<"Cousre matched successfully\n";
                return true;
            }
        }
        return false;
        
    }
 
    // 												ENTRY
    void setStudentData(){
        cout<<"ENTER STUDENT DETAILS\n";
        setUserData();
 
        cout<<"ENROLLMENT#: ";
        cin >>enrollmentNo;
        
        cout<<"ENROLLMENT YEAR: ";
        cin>>enrollmentYear;
        cout<<"CGPA: ";
        cin>>cgpa;
                if(cgpa<0){
        	throw InvalidCgpaException(cgpa);
		}
 
        cout<<"HOW MANY SKILLS DO YOU WANT TO ADD!";
        delete[] skills;
        cin>>totalSkills;
        if(totalSkills>0){
        	
        	skills=new string[totalSkills];
		}
		else
			skills=nullptr;
			
        
        for(int i=0;i<totalSkills;i++){
            string skil;
            
            cout<<"SKILL "<<i+1<<": ";
            cin  >> skil;
            
            addSkills(skil,i);
            
        }
 
        cout<<"SET LOCATION\n";
        loc.setLocation();
        
        cout<<"STUDENT DATA SAVED \n";
    }
 
    bool updateStudent(){
    	
        setStudentData();
        return true;
    }
 
    // 														LOACTION
    void getStudentLoc()const{
    	
        cout<<"STUDENT LOCATION\n";
        cout<<"NAME: "<<username<<endl;
        loc.showLocation();
        
        
    }
    
    	//												COPY CONSTRUCTOR
    Student(const Student& obj):User(obj){
        enrollmentNo=obj.enrollmentNo;
        enrollmentYear=obj.enrollmentYear;
        
        cgpa=obj.cgpa;
        
        situation=obj.situation;
 
        totalSkills = obj.totalSkills;
        if (totalSkills>0){
        	
            skills = new string[totalSkills];
            
            for(int i=0;i<totalSkills;i++)
                skills[i] = obj.skills[i];
        } 
		else{
            skills = nullptr;
        }
 
        courseSize=obj.courseSize;
        if(courseSize>0){
        	
            course=new Course[courseSize];
            for(int i=0;i<courseSize;i++)
                course[i]=obj.course[i];
        }
		 else{
            course = nullptr;
        }
 
        loc=obj.loc;
    }
 
    string getStudentCity()const{
		 return loc.getCity(); 
		 }
    string getStudentDIS()const{
	 return loc.getDistrict(); 
	 }
 

 
    bool hasCity(string ct)const{
			return getStudentCity()==ct;
			 }
			 
    bool hasCGPA(float ca)const{
	
		 return cgpa>=ca; 
		 }
 
 
    void display(){
        cout<<"==================================\n";
        
        
        cout<<"STUDENT DETAILS\n";
        
        cout<<"NAME:\t"<< getName()<<endl;
        cout<<"EMAIL:\t"<< getEmail()<<endl;
        cout<<"ENROLLMENT#:\t"<< enrollmentNo<<endl;
        cout<<"ENROLLMENT YEAR:\t"<< enrollmentYear<<endl;
        
        cout<<"CGPA:\t"<< cgpa<<endl;
        
        cout<<"SITUATION:\t"<<situation<<endl;
        cout<<"SKILLS:\n";
        displaySkills();
        
        cout<<"REGISTERED COURSES:\n";
        for(int i=0;i<courseSize;i++){
            cout<<" "<<course[i].getCname()<<"|"<<course[i].getAcronym()<<" |\n";
            
        }
        cout << "==================================\n";
    }
 
    bool searchStudent(string en){
    	
        if(en==enrollmentNo){
        	
            cout<<"FOUND SUCCESSFULLY\n";
            display();
            
            return true;
        }
        cout<<"!!!NOT FOUND!!\n";
        
        return false;
    }
 
    bool operator>(const Student& obj)const{
		return cgpa>obj.cgpa; 
		}
 
    bool operator==(const Student& obj)const{
    	
        return enrollmentNo==obj.enrollmentNo;
    }
 
    ~Student(){
        delete[] skills;
        delete[] course;
    }
};
#endif