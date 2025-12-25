#include<iostream>
#include<stack>
using namespace std;

class Queue2 {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int data) {
        s1.push(data);
    }

    void pop() {
        //s1 -> s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s2.pop();

        //s2 -> s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front() {
        //s1 -> s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int data = s2.top();

        //s2 -> s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return data;
    }

    bool empty() {
        return s1.empty();
    }

};

int main() {
    Queue2 q2;

    q2.push(1);
    q2.push(2);
    cout<<q2.front()<<endl; //1
    q2.pop();
    cout<<q2.front()<<endl; //2
    q2.push(3);
    q2.push(4);
    q2.push(5);

    cout<<q2.front()<<endl; //2
    q2.pop();
    cout<<q2.front()<<endl; //3

    while(!q2.empty()) {    //3 4 5
        cout<<q2.front()<<" ";
        q2.pop();
    }
    cout<<endl;

    return 0;
}