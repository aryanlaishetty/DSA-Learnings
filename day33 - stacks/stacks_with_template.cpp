#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>   //keyword to initialize the stack with variable data type
class Stack {
    vector<T> vec;  //T is a data type variable 
public:

    void push(T val) {
        vec.push_back(val);
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    T top() {
        // if(isEmpty()) {
        //     cout<<"Stack is empty\n";
        //     return -1;
        // }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty() {
        return vec.size() == 0;
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