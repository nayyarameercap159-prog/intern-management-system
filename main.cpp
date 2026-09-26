#include<iostream>
#include<string>
#include"User.h"
#include"Student.h"
#include"Admin.h"
#include"Course.h"
#include"Location.h"
#include"University.h"
#include"Company.h"
#include"Recruiter.h"
using namespace std;
 
int main() {
 

    Admin admin("adm","1234","admin@uni.edu",1);
 
    Recruiter rec("rec","1234","rec@company.com",101);
 
    University uni;
    Company comp;
    Student obj;
 
    cout<<"\n				WELCOME TO INTERNEE MANAGEMENT SYSTEM\n";
    cout << "			A COMPANY AT YOUR DOOR STEP TO PROVIDE YOU WITH GOLDEN OPPORTUNITIES\n\n";
 
    int ini;
    do {
        cout << "\n		===INITIAL INTERFACE===\n";
        cout << "1. STUDENT LOGIN\n";
        cout << "2. ADMIN LOGIN\n";
        cout << "3. RECRUITER LOGIN\n";
        cout << "4. EXIT\n";
        cout << "Select one please: ";
        cin  >> ini;
 
        switch (ini) {
        case 1: {								//STUDNET OPTIONS
            int st;
            do {
                cout << "\n\t-- STUDENT MENU --\n";
                cout << "1. Enter Details\n";
                cout << "2. Check Skills\n";
                cout << "3. Update Info\n";
                cout << "4. Check Your Location\n";
                cout << "5. Full Display\n";
                cout << "6. Check Status\n";
                cout << "7. Exit Student Menu\n";
                cout << "Select one please: ";
                cin  >> st;
 
                switch (st) {
                	
                case 1:
                    cout<<"ENTER YOUR DETAILS CALMLY\n";
                    try{
                    	obj.setStudentData();
					}
                    catch(Student::InvalidCgpaException inv){
                    	inv.showMsg();
					}
                    break;
                    
                case 2:
                    cout<<"YOUR SKILLS:\n";
                    
                    obj.displaySkills();
                    break;
                case 3:
                    cout<<"UPDATE INFO\n";
                    obj.updateStudent();
                    break;
                case 4:
                    cout<<"YOUR LOCATION:\n";
                    obj.getStudentLoc();
                    
                    break;
                case 5:
                    obj.display();
                    break;
                case 6:
                    cout<<"YOUR SELECTION STATUS IS: "<<obj.getSit()<<endl;
                   	 break;
                case 7:
                    cout<<"Exiting Student Menu...\n";
                    break;		
                default:
                  	  cout <<"Invalid Entry!\n";
                }
                
                
            } while (st != 7);
            
            break;
            
            
            
            
        }
        
        //										MAIN OPTIONS
        case 2:
            cout << "ADMIN LOGIN\n";
            try{
              if (admin.login()){
            	
            	
                admin.adminMenu(uni);
            } 
			
			else{
               		 cout << "Invalid login details.\n";
            }          	
			}
			catch(User::PasswordException pe){
				pe.showmsg();
			}

            break;
            
        case 3:
            cout<<"RECRUITER LOGIN\n";
            try{
            if(rec.login()){
                rec.recruiterMenu(comp);
            }             	
			
//			catch

			else{
                cout << "Invalid login details.\n";
            }
            
          }
          catch(User::PasswordException pe){
				pe.showmsg();
			}
            break;
        case 4:
            cout << "EXITING...\n";
            break;
 
        default:
            cout << "Invalid Entry!\n";
        }
        
        
 
    } while (ini != 4);
    
    //								END OF PROGRAM
 
    cout << "\nEND OF SYSTEM\n";
    cout << "BY AI ENGINEER\n";
 
    return 0;
}