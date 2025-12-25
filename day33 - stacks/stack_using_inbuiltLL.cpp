#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

template<class T>   //keyword to initialize the stack with variable data type
class Stack {
public:
    list<T> ll;  //T is a data type variable 

    void push(T val) {
        ll.push_front(val);
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Stack is empty\n";
            return;
        }
        ll.pop_front();
    }

    T top() {
        // if(isEmpty()) {
        //     cout<<"Stack is empty\n";
        //     return -1;
        // }
        // int lastIdx = ll.size()-1;
        return ll.front();
    }

    bool isEmpty() {
        return ll.size() == 0;
    }

};

int main() {
    Stack<string> s;

    s.push("ARYAN");
    s.push("SRINIVAS");
    s.push("LAISHETTY");

    while(!s.isEmpty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}