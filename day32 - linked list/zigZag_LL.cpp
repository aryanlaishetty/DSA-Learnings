#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node{     //Node class
public:
    int data;
    Node* next;

    Node(int val) {     //constructor
        this->data = val;
        next = NULL;
    }

    // ~Node() {
    //     if(next != NULL) {
    //         delete next;
    //         next = NULL;
    //     }
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
    //     if(head != NULL) {
    //         delete head;
    //         head = NULL;
    //     }
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

    void printLL() {
        Node* temp = head;

            while(temp != NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

};



Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
        
    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
            
        //updations for next itr
        prev = curr;
        curr = next;
    }

    return prev;
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

Node* zigZagLL(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightRev = reverse(rightHead);
    
    //alternate merging
    Node* left = head;
    Node* right = rightRev;
    Node* nextLeft = NULL;
    Node* nextRight = NULL;
    Node* tail = head;
    
    while(left != NULL && right != NULL) {
        nextLeft = left->next;
        left->next = right;

        nextRight = right->next;
        right->next = nextLeft;
        
        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {     //only exeutes for odd sized LL 
        tail->next = right;
    }

    return head;
}


int main() {
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printLL();

    ll.head = zigZagLL(ll.head);
    ll.printLL();

    return 0;
}

