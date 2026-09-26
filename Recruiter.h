#include<iostream>
#include<string>
#include"User.h"
#include"Company.h"
#ifndef RECRUITER_H
#define RECRUITER_H
using namespace std;


 
class Recruiter : public User{
private:
    int userId;
 
public:
 
    Recruiter():User(){
    	
		userId = 0; 
		}
 
   
    Recruiter(string n,string p,string em,int id):User(n,p,em){
        userId=id;
    }
 
    void setRecruiter(string n,string p,string em,int id){
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
 
    void recruiterMenu(Company& c){
        int choice;
    //    
        
        do {
            cout << "\n		===RECRUITER MENU ===\n";
            cout << "1. Add University\n";
            cout << "2. Delete University\n";
            cout << "3. View Company / Universities\n";
            cout << "4. Search In Company\n";
            cout << "5. Set Criteria & Send Approval\n";
            cout << "6. Exit\n";
            cout << "Select: ";
            
            cin  >> choice;
 
            switch(choice){
            case 1:
                c.addUniversity();
                break;
 
            case 2:
                c.deleteUniversity();
                break;
 
            case 3:
                c.displayCompany();
                break;
 
            case 4: {
                int searchChoice;
                do {
                    cout<<"\nSEARCH IN COMPANY\n";
                    cout<<"1. Search by Student Name\n";
                    cout<<"2. Search by Enrollment #\n";
                    cout<<"3. Search by Course Name\n";
                    cout<<"4. Search by University Name\n";
                    cout<<"5. Search by Student CGPA\n";
                    cout<<"6. Exit Search\n";
                    cout<<"Select: ";
                    cin>>searchChoice;
 
                    switch(searchChoice){
                    case 1:{
                        string name;
                        cout<<"ENTER STUDENT NAME: ";
						 cin>>name;
						 
                        c.searchinCOMPforSt(name);
                        break;
                        
                    }
                    case 2:{
                        string enroll;
                        cout<<"ENTER ENROLLMENT #:\n"; 
						cin>>enroll;
                        c.searchBYenrollCOMP(enroll);
                        break;
                    }
                    
                    case 3: {
                        string cname;
                        cout<<"ENTER COURSE NAME: ";
						 cin>>cname;
                        c.searchBYconameUNI(cname);
                        break;
                    }
                    case 4:{
                        string uname;
                        cout<<"ENTER UNIVERSITY NAME: ";
						 cin>>uname;
                        c.searchByUniversityName(uname);
                        break;
                    }
                    case 5:{
                        float minCGPA;
                        cout<<"ENTER MINIMUM CGPA:\n";
                        
						 cin>>minCGPA;
                        c.searchBYCGPACOMP(minCGPA);
                        break;
                    }
                    case 6:
                        cout<<"Exiting search...\n";
                        break;
                        
                    default:
                        cout<<"Invalid choice.\n";
                    }
                    
                    
                } while(searchChoice != 6);
                
                break;
                
                
                
            }
 
            case 5:{
                int cri;
                
                
                do {
                    cout << "		SET CRITERIA   \n";
                    cout << "1. Filter by CGPA\n";
                    cout << "2. Filter by Skill\n";
                    cout << "3. Filter by City\n";
                    cout << "4. Send Approval to Matching Students\n";
                    cout << "5. Exit Criteria Menu\n";
                    cout << "Select: ";
                    cin  >> cri;
 
                    switch(cri){
                    	
                    case 1:{

                        float cg;
                        cout<<"ENTER MINIMUM CGPA: "; 
						cin>>cg;
                        c.criteriaForCGPA(cg);
                        break;
                        
                    }
                    case 2:{
                        string sk;
                        cout<<"ENTER SKILL:";
						 cin>>sk;
                        c.criteriaForSKIL(sk);
                        
                        break;
                    }
                    case 3: {
                        string lc;
                        
                        cout<<"ENTER CITY:\n"; 
						cin>>lc;
						
                        c.criteriaForCity(lc);
                        break;
                    }
                    
                    case 4:
                        c.sendApproval();
                        break;
                        
                        
                        
                    case 5:
                    	
                        cout<<"Exiting criteria menu...\n";
                        break;
                        
                        
                        
                    default:
                        cout<<"Invalid entry.\n";
                    }
                    
                    
                } while (cri != 5);
                break;
                
            }
 
            case 6:
                cout<<"Exiting Recruiter Menu...\n";
                break;
 
            default:
                cout<<"Invalid choice.\n";
            }
            
        } while (choice != 6);
    }
   // 
    
 
    void display(){
        cout<<"USERNAME:\t" << username << endl;
        cout<<"EMAIL:\t"    << email    << endl;
        cout<<"USER-ID:\t"  << userId   << endl;
    }
 
    ~Recruiter() {}
};
#endif