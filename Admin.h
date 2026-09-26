#include<iostream>
#include<string>
#include"User.h"
#include"Student.h"
#include"Course.h"
#include"Location.h"
#include"University.h"
#ifndef ADMIN_H
#define ADMIN_H
using namespace std;
 
class Admin:public User{
private:
    int userId;
 
public:
 	Admin():User(){
	 	userId=0;
	}
 
    Admin(string n,string p,string em,int id):User(n,p,em){
        userId=id;
    }
 
    void setAdmin(string n,string p,string em,int id){
        username=n;
        password=p;
        email=em;
        userId=id;
        
    }
 
    bool login(){
    	
        string un,pass;
        cout<<"ENTER USERNAME: ";
        cin>>un;
        cout<<"PASSWORD: ";
        cin>>pass;
        if(getName()==un && getpassword()==pass){
        	
            cout<<"ACCESS GRANTED\n";
            return true;
        }
        
        cout<<"ACCESS DENIED\n";
        return false;
    }
 
    void adminMenu(University& uni){
        int choice;
        do {
            cout<<"\n . ADMIN MENU .\n";
            cout<<"1. Add Student\n";
            cout<<"2. Add Course\n";
            cout<<"3. Display Students\n";
            cout<<"4. Display Courses\n";
            cout<<"5. Remove Student\n";
            cout<<"6. Remove Course\n";
            cout<<"7. Display University\n";
            cout<<"8. Search In University\n";
            cout<<"9. Exit Admin Menu\n";
            cout<<"Select:	";
            cin>>choice;
 
 
 
            switch(choice){
            	
            case 1: {
            	Student s;
                s.setStudentData();
                uni.addStudent(s);
                break;
				
			}
                
            
            case 2:{
            	string cname,acronym;
                
                cout<<"ENTER COURSE NAME:";    
				cin>>cname;
                cout<<"ENTER COURSE ACRONYM: "; 
				cin>>acronym;
                Course c(cname,acronym);
                
                uni.addCourse(c);
                break;
				
			} 
                
            
            case 3:
                uni.uniStudentDisplay();
                break;
                
            case 4:
                uni.uniCourseDisplay();
                break;
                
            case 5: {
            	string en;
                cout<<"ENTER ENROLLMENT#: ";
                cin>>en;
                uni.removeStudent(en);
                break;
				
			}
                
            
            case 6:{
            	string cn;
                cout<<"ENTER COURSE NAME: ";
                cin>>cn;
                uni.removeCourse(cn);
				break;
			}
                
                
              
            
            case 7:
                uni.displayUni();
                break;
                
                
            case 8:{
            	
                int search;
                do {
                    cout<<"\nSEARCH IN UNIVERSITY\n";
                    cout<<"1. Student Name\n";
                    cout<<"2. Enrollment Number\n";
                    cout<<"3. CGPA\n";
                    cout<<"4. Course Name\n";
                    cout<<"5. Exit Search\n";
                    cout<<"Select: ";
                    cin>>search;
 
                    if(search==1){
                    	
                        string name;
                        
                        cout<<"ENTER STUDENT NAME:"; 
						cin>>name;
						
                        uni.searchinUNIforSt(name);
                        
                    } 
					
					else if(search==2){
						
                        string en;
                        
                        cout<<"ENTER ENROLLMENT# ";
						cin>>en;
						
                        uni.searchBYenrollUNI(en);
                    } 
					else if(search==3){
						
                        float cg;
                        
                        cout<<"ENTER CGPA: "; 
						cin>>cg;
						
                        uni.searchBYCGPAUNI(cg);
                    }
					 else if(search==4){
					 	
                        string cn;
                        
                        cout<<"ENTER COURSE NAME: ";
						 cin >> cn;
                        uni.searchBYconameUNI(cn);
                    }
                    
                } while (search != 5);
                
                break;
            }
            
            
            case 9:
                cout<<"Exiting Admin Menu..\n";
                break;
                
                
            default:
                cout<<"Invalid Entry!\n";
            }
            
            
        } while (choice != 9);
        
        
        
    }
 
    void display(){
    	
    	
        cout<<"Username:	"<<username<<endl;
        cout<<"email:	"<<email<<endl;
        cout<<"User Id:	"<<userId<<endl;
        
    }
 
    ~Admin(){}
};
#endif