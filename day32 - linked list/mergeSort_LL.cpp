#include<iostream>
using namespace std;

class Node{     //Node class
public:
    int data;
    Node* next;

    Node(int val) {     //constructor
        data = val;
        next = NULL;
    }

    // ~Node() {
    //     // if(next != NULL) {
    //     //     delete next;
    //     //     next = NULL;
    //     // }
    // }
};

class List{ 
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    // ~List() {   //for deleting LL
    //     Node* current = head;
    //     while(current != NULL) {
    //         Node* nextNode = current->next;
    //         delete current;
    //         current = nextNode;
    //     }
    //     head = NULL;
    //     tail = NULL;
    // }

    void push_front(int val) {      
        Node* newNode = new Node(val);  //dynamic

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
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

    void insert(int val, int pos) {     //considering first pos is 0
        Node* newNode = new Node(val);
        Node* temp = head;

        for(int i=0; i<pos-1; i++) {
            temp = temp->next;
        }   //now temp points at pos-1;
        
        newNode->next = temp->next; 
        temp->next = newNode;
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        Node* temp = head;

        while(temp->next != tail) { // (temp->next->next != NULL) also works
            temp = temp->next;
        } //here temp->next == tail

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

};

void printLL(Node* head) {
    Node* temp = head;

        while(temp != NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}

Node* merge(Node* h1, Node*h2) {
    List ans;
    Node* i = h1;
    Node* j = h2;

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);
    Node* sortedLeft = mergeSort(head);
    Node* sortedRight = mergeSort(rightHead);

    return merge(sortedLeft, sortedRight);
}

int main() {
    List ll;
    List llSorted;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    printLL(ll.head);

    ll.head = mergeSort(ll.head);
    printLL(ll.head);

    return 0;
}


