#include<iostream>
#include<queue>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {    //operator overloading
        return this->marks < obj.marks;     //maxHeap
    }

};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("A", 1000));
    pq.push(Student("B", 2000));
    pq.push(Student("C", 3000));
    pq.push(Student("D", 4000));

    while(!pq.empty()) {
        cout<<pq.top().name<<endl;
        pq.pop();
    }

    return 0;
}