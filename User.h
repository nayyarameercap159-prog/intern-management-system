#include<iostream>
#include<string>
#ifndef USER_H
#define USER_H
using namespace std; 
 
class User {
protected:
    string username;
    string password;
    string email;
 
public:
	
	class PasswordException{
		private:
			string msg;
		public:
			PasswordException(string m){
				msg=m;
			}
			
			void showmsg(){
				cout<<"the length of password must be 4 digits\n";
				cout<<"you entered this one : "<<msg<<endl;
			}
	};
 
    User(){
        username="";
        password="";
        email="";
    }
 
    User(string un,string p,string e){
        username=un;
        password=p;
        if(password.length()!=4){
        	throw PasswordException(password);
		}
        email=e;
    }
 
    User(const User& obj){
        username=obj.username;
        password=obj.password;
        email=obj.email;
    }
 
   
 
    void setUserData(){
        cout<<"NAME:\t";
        cin >>username;
        cout<<"PASSWORD:\t";
        cin>>password;
        cout<<"EMAIL:\t";
        cin>>email;
    }
 
    string getName() const{ 
		return username; 
		}
		
		
    string getpassword()const{
		 return password;
	}
		 
		 
		 
    string getEmail()const{
    	return email; 
	}
 
    virtual void display()=0;
    virtual bool login()=0;
 
    virtual ~User(){}
    
     User& operator=(const User& obj){
     	
        if(this != &obj){
            username=obj.username;
            password=obj.password;
            email=obj.email;
        }
        return *this;
        
        
    }
};
 
#endif