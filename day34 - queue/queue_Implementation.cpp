#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;
public:
    Queue() {
        head = tail = NULL;
    }

    void push(int val) { //push_back
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() { //pop_front
        if(empty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    int front() {   //value of head
        if(empty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    bool empty() {  //check is empty
        return head == NULL;
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) {
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}