#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    } 

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};



void delNafM(int m, int n, Node* head) {    //not accurate
    Node* temp = head;
    Node* prev = temp;
    for(int i=0; i<m; i++) {
        prev = temp;
        temp = temp->next;
    }
    Node* toDel = temp;
    for(int i=0; i<n; i++) {
        temp = temp->next;
    }
    prev->next = NULL;
    prev->next = temp;
    while(toDel != temp) {
        Node* delPrev = toDel;
        toDel = toDel->next;
        delPrev->next = NULL;
        delete delPrev;
    }
}

void swapNodes(int x, int y, Node* head) {      //correct
    Node* first = head;
    Node* fprev = NULL;
    Node* fnext = first->next;

    Node* sec = head;
    Node* secprev = NULL;
    Node* secnext = sec->next;

    while(first->data != x) {
        fprev = first;
        first = first->next;
        fnext = first->next;
    }

    while(sec->data != y) {
        secprev = sec;
        sec = sec->next;
        secnext = sec->next;
    }

    fprev->next = NULL;
    fprev->next = sec;
    sec->next = NULL;
    sec->next = fnext;

    secprev->next = NULL;
    secprev->next = first;
    first->next = NULL;
    first->next = secnext;
}



int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    
    ll.printLL();

    // delNafM(2, 2, ll.head);  //not accurate

    // swapNodes(2, 4, ll.head);    //correct

    ll.printLL();




    return 0;
}