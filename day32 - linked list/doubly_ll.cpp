#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;
        
        if(head != NULL) {
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        newNode->prev = temp;
        temp->next = newNode;
        newNode->next = NULL;
    }

    void pop_back() {
        Node* temp = head;
        Node* prev = temp;
        
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        temp->prev = NULL;
        prev->next = NULL;
        
        delete temp;
        prev = tail;
    }

    void printDBLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

};


int main() {
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printDBLL();

    dbll.pop_front();
    dbll.printDBLL();

    dbll.push_back(5);
    dbll.push_back(6);
    dbll.printDBLL();

    dbll.pop_back();
    dbll.pop_back();
    dbll.printDBLL();
    
    return 0;
}