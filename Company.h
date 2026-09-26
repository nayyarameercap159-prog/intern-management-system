#include<iostream>
#include<string>
#include"User.h"
#include"Student.h"
#include"Course.h"
#include"Location.h"
#include"University.h"
#ifndef COMPANY_H
#define COMPANY_H
using namespace std;
 
class Company{
private:
    string companyName;
    University* uni;
    int unicount;
    Student* student;
    int stcnt;
    Course* course;
    int crcnt;
    Location loc;
    float reqCGPA;
    string reqCOURSE;
    string reqLOC;
    string reqSKILLS;
 
public:
    Company(){
        companyName="";
        unicount=0;
        uni=nullptr;
        stcnt=0;
        student=nullptr;
        crcnt=0;
        course=nullptr;
        loc=Location();
        reqCGPA=0;
        reqCOURSE="";
        reqLOC="";
        reqSKILLS ="";
        
    }
 
    Company(string cn,int uc,int stc,int cc,Location l,float rcg,string rc,string rl,string rsk){
    	
        companyName=cn;
        loc=l;
        reqCGPA=rcg;
        reqCOURSE=rc;
        reqLOC=rl;
        reqSKILLS=rsk;
 
        unicount = uc;
        if(unicount>0){
        	uni=new University[unicount];
		}
		else
			uni=nullptr;
         
        stcnt=stc;
        if(stcnt>0){
        	student=new Student[stcnt];
		}
		else
			student=nullptr;
      
 
        crcnt  = cc;
        if(crcnt>0){
        	course=new Course[crcnt];
		}
		
		else
			course=nullptr;
  
    }
 
 
   
    
 

    bool criteriaForCGPA(float cpa){
    	
        bool found=false;
        for(int i=0;i<stcnt;i++){
            if(student[i].getCGPA()>cpa){
            	\
                student[i].display();
                found = true;
            }
        }
        
        	if(!found){
        	cout<<"No student above this CGPA criteria.\n";
		} 
        return found;
        
        
    }
 
    bool criteriaForSKIL(string s){
    	
        bool found=false;
       	 for(int i=0;i<stcnt;i++){
            if(student[i].hasSkill(s)){
                 student[i].display();
                
                found = true;
            }
        }
        if(!found)
		 cout<<"No student with this skill.\n";
        return found;
        
    }
 
    bool criteriaForCity(string ct){
        bool found=false;
        
        for(int i=0;i<stcnt;i++){
            if(student[i].getStudentCity()==ct){
                student[i].display();
                found = true;
                
            }
        }
        if(!found){
        	cout<<"No student in this city.\n";
		} 
        return found;
        
        
    }
    
     Company(const Company& obj){
    	
        companyName=obj.companyName;
        loc=obj.loc;
        reqCGPA=obj.reqCGPA;
        reqCOURSE=obj.reqCOURSE;
        reqLOC=obj.reqLOC;
        reqSKILLS=obj.reqSKILLS;
 
        unicount=obj.unicount;
        if(unicount>0){
        	
            uni=new University[unicount];
            for(int i=0;i<unicount;i++){
            	uni[i] = obj.uni[i];
			}
			
        } 
		else{ 
			uni=nullptr;
			 }
 
        stcnt=obj.stcnt;
        if(stcnt>0){
            student=new Student[stcnt];
            
            for(int i=0;i<stcnt;i++){
            	student[i]=obj.student[i];
			} 
        }
		 else{
		  student=nullptr; 
		  }
 
        crcnt=obj.crcnt;
        if(crcnt>0){
            course=new Course[crcnt];
            
            for(int i=0;i<crcnt;i++){
            	course[i]=obj.course[i];
			} 
			
        }
		 else {
		  course=nullptr; }
		  
		  
    }
    
    
    
    Company& operator=(const Company& obj){
        if(this != &obj){
        	
            companyName=obj.companyName;
            loc=obj.loc;
            reqCGPA=obj.reqCGPA;
            reqCOURSE=obj.reqCOURSE;
            reqLOC=obj.reqLOC;
            reqSKILLS=obj.reqSKILLS;
 
            delete[] uni;
            
            unicount=obj.unicount;
            
            if(unicount>0){
            	
                uni=new University[unicount];
                
                for(int i=0;i<unicount;i++){
                	uni[i]=obj.uni[i];
				}
				
            } 
			
			else {
			 uni=nullptr; }
 
            delete[] student;
            stcnt=obj.stcnt;
            if(stcnt>0){
            	
                student=new Student[stcnt];
                
                for(int i=0;i<stcnt;i++){
                	student[i]=obj.student[i];
				}
            } 
			else{ 
			student=nullptr;
			 }
 
            delete[] course;
            
            crcnt=obj.crcnt;
            if(crcnt>0){
            	
                course=new Course[crcnt];
                
                for(int i=0;i<crcnt;i++)
				{
					course[i]=obj.course[i];
				}
            } 
			else{
			 course=nullptr;
			  }
			  
        }
        
        return *this;
    }
    
    
 
 
 //															APPROVAL !@
    void sendApproval(){
        string sk,lc,cr;
        float cp;
        
        cout<<"ENTER SKILL: ";
        
	    cin>>sk;
        cout<<"ENTER CITY: ";
		cin>>lc;
		
        cout<<"ENTER CGPA: ";
		cin>>cp;
        cout<<"ENTER COURSE: ";
		cin>>cr;
 
        bool found = false;
        
        
        for (int i = 0; i < stcnt; i++){
        	
            if(student[i].hasSkill(sk) && student[i].hasCity(lc) && student[i].hasCGPA(cp) && student[i].checkCourse(cr)){
            
                student[i].setSit("SELECTED");
                cout<<"\nSTUDENT #"<<i+1<<"MATCHES ALL REQUIREMENTS\n";
                cout<<"Name: "<<student[i].getName()<<endl;
                cout<<"Enrollment: "<<student[i].getENum()<<endl;
                cout<<"Status: "<<student[i].getSit()<<endl;
                
                found=true;
            }
        }
        if(!found)
			 cout<<"NONE MATCHED THIS CRITERIA\n";
			 
    }
 

    void displayCompany(){
        cout<<"=============================\n";
        cout<<"COMPANY: "<<companyName<<endl;
        loc.showLocation();
 		
 		
 		cout<<endl;
 		
        int choice;
        do {
            cout<<"1. Available Universities\n";
            cout<<"2. Available Students\n";
            cout<<"3. Exit\n";
            cout<<"Select: ";
            
            cin>> choice;
 
 
            switch(choice){
            case 1:
                cout<<"UNIVERSITIES:\n";
                if(unicount==0){
					 cout<<"(none)\n";
					 
					  break;
					   }
                for(int i=0;i<unicount;i++){
                	uni[i].displayUni();
				}
				
                break;
                
            case 2:
                cout<<"STUDENTS:\n";
                if(stcnt==0){ 
					cout<<"(none)\n"; 
					break; 
					}
                for(int i=0;i<stcnt;i++){
                	student[i].display();
				} 
                break;
                
                
            case 3:
                cout<<"Exiting company view...\n";
                break;
                
            default:
                cout<<"Invalid input.\n";
            }
            
            
            
        } while (choice != 3);
    }
 
 
    void addUniversity(){
        string uniName;
        
        cout<<"ENTER UNIVERSITY NAME: "; 
		cin>>uniName;
 
        Location l;
        cout<<"ENTER UNIVERSITY LOCATION\n";
        
        l.setLocation();
 
        int stsize,crsize;
        
        cout<<"ENTER NUMBER OF STUDENTS:\n"; 
		cin>>stcnt;
		for(int i=0;i<stcnt;i++){
			student[i].setStudentData();
		}
        cout<<"ENTER NUMBER OF COURSES:\n";
        
		cin>>crcnt;
//		for(int i=0;i<crcnt;i++){
//			course[i].setCourse();
//		} 
        University* temp=new University[unicount + 1];
        
        for(int i=0;i<unicount;i++){
        	temp[i] = uni[i];
		} 
		
        temp[unicount].setUniversity(uniName,l,stsize,crsize);
        delete[] uni;
        uni = temp;
        unicount++;
        
        cout << "UNIVERSITY ADDED SUCCESSFULLY\n";
        
        
        
        
    }
 
    void deleteUniversity(){
    	
        string uniName;
        cout<<"ENTER UNIVERSITY NAME TO DELETE:\n";
		cin>>uniName;
 
        int index=-1;
        for(int i=0;i<unicount;i++)
        	if (uni[i].getUniName() == uniName){ 
		
        index = i;
		
		 break; 
		 }
 
        if(index==-1){
		 cout<<"UNIVERSITY NOT FOUND\n"; 
		 return;
		  }
 
        University* temp=new University[unicount-1];
        int j=0;
        for(int i=0;i<unicount;i++)
            if(i != index){
            	temp[j++]=uni[i];
			}
        delete[] uni;
        uni=temp;
        unicount--;
        
        cout << "UNIVERSITY DELETED SUCCESSFULLY\n";
        
        
    }
 
    bool searchinCOMPforSt(string studentname){
        for(int i=0;i<stcnt;i++){
            if(student[i].getStudentName()==studentname){
                cout<<"FOUND\n"; 
				student[i].display(); 
				return true;
            }
            
            
        }
        cout<<"NOT FOUND\n"; 
		return false;
    }
 
    bool searchBYenrollCOMP(string enroll){
        for(int i=0;i<stcnt;i++){
            if(student[i].getENum()==enroll){
                cout<<"FOUND\n"; 
				student[i].display(); 
				return true;
            }
        }
        cout<<"NOT FOUND\n"; 
		return false;
    }
 
    bool searchBYCGPACOMP(float cg){
        bool found = false;
        
        for(int i = 0; i < stcnt; i++){
        	
            if(student[i].getCGPA() >= cg){
                cout<<"FOUND\n";
				 student[i].display();
				  found=true;
				  
				  
				  
				  
            }
        }
        
        
        if (!found){
        	cout<<"NOT FOUND\n";
		}
        return found;
    }
 
    bool searchByUniversityName(string uniName){
        for(int i=0;i<unicount;i++){
            if(uni[i].getUniName()==uniName){
                cout << "FOUND\n"; 
				uni[i].displayUni(); 
				return true;
            }
        }
        cout<<"NOT FOUND\n"; return false;
    }
 
    bool searchBYconameUNI(string coursename){
        for(int i=0;i<crcnt;i++){
            if(course[i].getCname()==coursename){
            	
                cout<<"FOUND\n"; 
				course[i].displayCourse();  
				return true;
            }
            
            
        }
        cout << "NOT FOUND\n"; return false;
    }
 
    bool searchBYcityCOMP(string citi){
    	
    	
        bool found = false;
        for(int i=0;i<stcnt; i++){
        	
            if(student[i].getStudentCity()==citi){
                student[i].display(); 
				found=true;
            }
            
            
        }
        if (!found){
        	cout<<"No student in this area.\n";
		} 
        return found;
    }
 
    bool searchBYcityDIS(string dis){
        bool found=false;
        for(int i=0;i<stcnt;i++){
            if(student[i].getStudentDIS()==dis){
                student[i].display(); 
				found = true;
            }
        }
        
        
        if (!found){
        	cout<<"No student in this district.\n";
		} 
        return found;
    }

    ~Company() {
        delete[] uni;
        delete[] student;
        delete[] course;
    }
};
#endif