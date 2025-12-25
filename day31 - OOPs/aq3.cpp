#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : public Person{
protected:
    string studentId;

public:

    Student(string n, int a, string studentId) : Person(n, a) {
       this->studentId = studentId; 
    }

    void displayStudentInfo() {
        cout<<"Name: "<<this->name<<endl;
        cout<<"Age: "<<this->age<<endl;
        cout<<"Student Id: "<<this->studentId<<endl;
    }
    
};

int main() {
    Student student("Aryan", 20, "12312045");
    student.displayStudentInfo();

    return 0;
}