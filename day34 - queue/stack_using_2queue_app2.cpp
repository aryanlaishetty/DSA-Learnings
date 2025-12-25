#include<iostream>
#include<queue>
using namespace std;

//wrong hai
class Stack {
    queue<int> q1;
    queue<int> q2;

public:

    void push(int data) {   //O(1)
        q1.push(data);
    }

    void pop() {    //O(n)
        if(q1.empty()) {
            cout<<"Stack is empty"<<endl;
            return;
        }

        //q1->q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q2.pop();

        //q2->q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int top() { //O(n)
        if(q1.empty()) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        //q1->q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        int data = q2.front();

        //q2->q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return data;
    }

    bool empty() {  //O(1)
        return q1.empty();
    }

};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.top()<<endl;    //4
    
    s.pop();
    
    cout<<s.top()<<endl;    //3

    while(!s.empty()) {     //3 2 1
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}