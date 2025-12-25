#include<iostream>
#include<stack>
using namespace std;

class Queue1 {
    stack<int> s1;
    stack<int> s2;
    
public:
    void push(int data) {   //O(n)
        //s1 -> s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        //s2 -> s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if(s1.empty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        s1.pop();
    }

    int front() {
        if(s1.empty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue1 q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout<<q1.front()<<endl;
    q1.pop();
    cout<<q1.front()<<endl;

    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;

    return 0;
}