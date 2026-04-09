#include<iostream>
#include<cstring>
using namespace std;

struct Student{
    int rollNo;
    string name;
    string course;
    Student *next;
};

class RegistrationSystem{
private:
    Student *head;
public:
    RegistrationSystem(){
        head=NULL;
    }    
    void insertStudent(int rollNo,string name,string course){
        Student *newStudent=new Student;
        newStudent->rollNo=rollNo;
        newStudent->name=name;
        newStudent->course=course;
        newStudent->next=NULL;

        if(head==NULL){
            head=newStudent;
        }else{
            Student *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newStudent;
        }
        cout<<"Student "<<name<<" with Roll No "<<rollNo<<" registered"<<endl;
    }
    void deleteStudent(int rollNo){
        if(head==NULL){
            cout<<"No students registered"<<endl;
            return;
        }
        Student *temp=head;
        Student *prev=NULL;

        if(temp!=NULL && temp->rollNo==rollNo){
            head=temp->next;
            delete temp;
            cout<<"Student with roll "<<rollNo<<" dropped the course"<<endl;
            return;
        }

        while(temp!=NULL && temp->rollNo!=rollNo){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Student with rollNo "<<rollNo<< " not found"<<endl;
            return;
        }

        prev->next=temp->next;
        delete temp;
        cout<<"Student with roll "<<rollNo<<" dropped the course"<<endl;
    }

    void displayStudents(){
        if(head==NULL){
            cout<<"No students registered"<<endl;
            return;
        }
        
        Student *temp=head;
        cout<<"Registered students"<<endl;
        while(temp!=NULL){
             cout << "Roll: " << temp->rollNo
                 << ", Name: " << temp->name
                 << ", Course: " << temp->course << "\n";
            temp = temp->next;
        }
    }
    void searchStudent(int rollNo){
        Student *temp=head;
        if(head==NULL){
            cout<<"No students registered"<<endl;
            return;
        }

        while(temp!=NULL){
           if(temp->rollNo==rollNo){
            cout<<"Student found"<<endl;
            cout<<"Name "<<temp->name<<endl;
            cout<<"RollNo "<<temp->rollNo<<endl;
            return;
           }
           temp=temp->next;
        }
    }
};
int main(){
    RegistrationSystem rs;

    rs.insertStudent(48,"Muhammad Raheel","Mern Stack");
    rs.displayStudents();

    rs.searchStudent(48);
    rs.deleteStudent(48);
    rs.displayStudents();

    return 0;
}