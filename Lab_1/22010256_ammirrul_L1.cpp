

// ID = 22010256
// NAME = AMMIRRUL ADAM BIN AMRAN
// Group = G2

#include <iostream>
using namespace std;

struct Student{
    int id;
    string name;
    string contact;
    string email;
} ;


int main(){

    int numberStudents = 0;
    cout<<"Enter in the number of students: ";
    cin>>numberStudents;
    Student student[numberStudents];
    
    for (int i = 0; i < numberStudents; i++) {
 
    cout<<"Enter Student ID#"<< i+1<<": ";
    cin>>student[i].id;
    
    cout<<"Enter name of student #"<<i+1<<": ";
    cin>>student[i].name;
    
    cout<<"Enter in contact number of student #"<<i+1<<": ";
    cin>>student[i].contact;
    
    cout<<"Enter Student email#"<< i+1<<": ";
    cin>>student[i].email;
    
    cout<<"#####################";

 
}

for(int i = 0 ;i<numberStudents;i++){
    
    cout<<"-----------------------------------------";
    cout<<"Student #"<<i+1<<"details"<< endl;
    cout<<"id: "<<student[i].id<< endl;
    cout<<"name: "<<student[i].name<< endl;
    cout<<"contact: "<<student[i].contact<< endl;
    cout<<"email: "<<student[i].email<< endl;
    
        cout<<"-----------------------------------------";
}


    return 0;
}
