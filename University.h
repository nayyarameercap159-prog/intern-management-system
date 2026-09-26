#include<iostream>
#include<string>
#include"User.h"
#include"Student.h"
#include"Course.h"
#include"Location.h"
#ifndef UNIVERSITY_H
#define UNIVERSITY_H
using namespace std;
 
class University{
private:
    string uniName;
    Location loc;
    Student* student;
    int studentsize;
    Course* course;
    int coursesize;
 
public:
    University(){
        uniName="";
        loc=Location();
        studentsize=0;
        student=nullptr;
        coursesize=0;
        course=nullptr;
    }
    University(string un,Location l,int ss,int cs){
        uniName=un;
        loc=l;
        studentsize=ss;
        if(studentsize>0){
        	student=new Student[studentsize];
        	
		}
		else
			student=nullptr;
			
         
        coursesize=cs;
        if(coursesize>0){
        	course=new Course[coursesize];
        	
		}
		else
			course=nullptr;
       
    }
 
    
 
    
    string getUniName()const{
		 return uniName;
		  }
 
    
    void setUniversity(string un,Location l,int ss,int cs){
        uniName=un;
        loc=l;
 
        delete[] student;
        studentsize=ss;
        if(studentsize>0){
        	student=new Student[studentsize];
		}
		else{
			student=nullptr;
			
		}
   
 
        delete[] course;
        coursesize = cs;
        if(coursesize>0){
        	course=new Course[coursesize];
		}
		else{
			course=nullptr;
			
		}

    }
 
    // 															 DISPLAY UNIVERSITY!! 
    void displayUni(){
        cout<<"=============================\n";
        cout<<"UNIVERSITY: "<<uniName<<endl;
        loc.showLocation();
        cout<<"STUDENTS:\n";
        if(studentsize==0)
			 cout<<"(none)\n";
			 
        for(int i=0;i<studentsize;i++) 
			student[i].display();
        cout<<"COURSES:\n";
        if(coursesize==0)
			 cout<<"(none)\n";
        for(int i=0;i<coursesize;i++) 
			course[i].displayCourse();
        cout<<"=============================\n";
    }
 
    void uniCourseDisplay(){
        cout<<"OUR COURSES\n";
        if(coursesize==0){
			 cout<<"(none)\n";
			  return; 
			  
			  }
        for(int i=0;i<coursesize;i++)
			 course[i].displayCourse();
			 
			 
			 
			 
			 
			 
			 
    }
 
    void uniStudentDisplay(){
        cout<<"OUR STUDENTS\n";
        if(studentsize==0){ 
			cout<<"(none)\n"; 
				return;
				 }
        for(int i=0;i<studentsize;i++) {
        	student[i].display();
		}
			
    }
 
 
    void addCourse(Course& obj){
        Course* temp=new Course[coursesize + 1];
        for(int i=0;i<coursesize; i++){
        	temp[i] = course[i];
		}
		 
        temp[coursesize]=obj;
        delete[] course;
        course=temp;
        coursesize++;
        
        
        
        
    }
 
    void removeCourse(string courseName){
        int index=-1;
        for(int i=0;i<coursesize;i++)
        	if(course[i].getCname() == courseName){
        		
		
              index=i;
			   break; 
			   }
        if(index==-1){
			 cout<<"!!!Course not found!\n";
			  return; }
        Course* temp=new Course[coursesize-1];
        int j = 0;
        for(int i=0;i<coursesize;i++)
            if(i != index){
            	temp[j++] = course[i];
			}
			 
        delete[] course;
        course=temp;
        coursesize--;
        
        cout << "Course removed successfully.\n";
        
        
        
    }
 
    void addStudent(Student& obj){
        Student* temp=new Student[studentsize + 1];
        for(int i=0;i<studentsize;i++){
        	temp[i] = student[i];
		}
			
        temp[studentsize]=obj;
        delete[] student;
        
        student=temp;
        studentsize++;
    }
    
    University(const University& obj){
        uniName=obj.uniName;
        loc=obj.loc;
 
        studentsize=obj.studentsize;
        if(studentsize>0){
            student=new Student[studentsize];
            for(int i=0;i<studentsize;i++)
                student[i]=obj.student[i];
                
        } 
		else{
            student=nullptr;
        }
 
        coursesize = obj.coursesize;
        
        if (coursesize > 0){
        	
            course = new Course[coursesize];
            for (int i = 0; i < coursesize; i++)
                course[i] = obj.course[i];
        } 
		else{
            course = nullptr;
        }
        
        
        
    }
 
 
    void removeStudent(string enrollmentNo){
        int index=-1;
        for(int i=0;i<studentsize;i++)
        	if (student[i].getEnrollmentNo() == enrollmentNo)
		
             {
			 
			  index=i;
			   break;
			   }
        if(index==-1){
			 cout<<"Student not found!\n";
			  return;
			   }
        Student* temp=new Student[studentsize-1];
        int j=0;
        	for(int i=0;i<studentsize;i++)
        	if(i !=index)
		
             temp[j++]=student[i];
        delete[] student;
        student=temp;
        studentsize--;
        cout << "Student removed successfully.\n";
        
        
        
    }
 
    // 																SERACHES 
    bool searchinUNIforSt(string studentname){
        for(int i=0;i<studentsize; i++){
            if(student[i].getStudentName()==studentname){
            	
                cout<<"FOUND\n";
               	 student[i].display();
                return true;
                
            }
        }
        cout<<"NOT FOUND\n";
        return false;
    }
 
    bool searchBYenrollUNI(string enroll){
        for(int i=0;i<studentsize;i++){
        	
            if(student[i].getENum()==enroll){
                cout<<"FOUND\n";
                	student[i].display();
                
                return true;
            }
        }
        cout<<"NOT FOUND\n";
        return false;
    }
 
    bool searchBYCGPAUNI(float cg){
        bool found=false;
        for(int i=0;i<studentsize;i++){
            if(student[i].getCGPA()==cg){
            	    cout<<"FOUND\n";
                student[i].display();
                found=true;
                
            }
            
            
    }
        if (!found) {
        	
		}
		cout << "NOT FOUND\n";
        return found;
    }
 
    bool searchBYconameUNI(string coursename){
    	
        	for(int i=0;i<coursesize;i++){
        	
            if(course[i].getCname()==coursename){
                cout<<"FOUND\n";
                course[i].displayCourse();
                return true;
            }
        }
        cout<<"NOT FOUND\n";
        return false;
    }
 
    bool operator==(const University& obj)const{
    	
        	return uniName==obj.uniName &&studentsize==obj.studentsize && coursesize==obj.coursesize;
    }
 
    bool hasStudentAboveCGPA(double cgpa){
        for(int i=0;i<studentsize;i++){
        	if (student[i].getCGPA()>cgpa)
        	return true;
		}
             
        return false;
    }
    
    
    
    University& operator=(const University& obj){
        if(this != &obj) {
           	 uniName=obj.uniName;
            loc=obj.loc;
 
            delete[] student;
            
            studentsize = obj.studentsize;
            if(studentsize>0){
            	
                student = new Student[studentsize];
                for (int i = 0; i < studentsize; i++)
                    student[i]=obj.student[i];
            } 
			else{
                student = nullptr;
            }
 
            delete[] course;
            coursesize=obj.coursesize;
           	 if(coursesize>0){
            	
                course=new Course[coursesize];
                
                for(int i=0;i<coursesize;i++)
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
    
    
 
    ~University(){
        delete[] student;
        delete[] course;
    }
};
#endif