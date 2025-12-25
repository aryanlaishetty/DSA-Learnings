#include<iostream>
#include<deque>
using namespace std;

class Queue {
    deque<int> dq;
public:
    void push(int data) {
        dq.push_back(data);
    }

    void pop() {
        dq.pop_front();
    }

    int front() {
        return dq.front();
    }

    bool empty() {
        return dq.empty();
    }
};

class Stack1 {
    deque<int> dq;
public:
    void push(int data) {
        dq.push_front(data);
    }

    void pop() {
        dq.pop_front();
    }

    int top() {
        return dq.front();
    }

    bool empty() {
        return dq.empty();
    }
};


class Stack2 {
    deque<int> dq;
    public:
    void push(int data) {
        dq.push_back(data);
    }
    
    void pop() {
        dq.pop_back();
    }
    
    int top() {
        dq.back();
    }
    
    bool empty() {
        return dq.empty();
    }
};

void printQ(Queue q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main() {
    Queue q;

    for(int i=1; i<11; i++) {
        q.push(i);
    }
    printQ(q);

    Stack1 s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    cout<<s1.top()<<endl;

    Stack1 s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.pop();
    cout<<s2.top()<<endl;


    return 0;
}