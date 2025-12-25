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

    ~Node() {
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List{ 
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {   //for deleting LL
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }

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

    void printLL(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
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

    int searchIdx(int val) {
        Node* temp = head;
        int idx=0;

        while(temp != NULL) {
            if(temp->data == val) {
                return idx;
            }
            
            temp = temp->next;
            idx++;
        }

        return -1;
    }

    int helper(Node* temp, int val) {   //uses recursion

        if(temp == NULL) {
            return -1;
        }

        if(temp->data == val) {
            return 0;
        } 

        int idx = helper(temp->next, val);

        if(idx == -1) {
            return -1;
        }

        return idx + 1;
    }

    int recSearch(int val) {
        return helper(head, val);
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            
            //updations for next itr
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    int getSize() {
        Node* temp = head;
        int sz = 0;
        while(temp != NULL) {
            sz++;
            temp = temp->next;
        }
        return sz; 
    }

    void delNthEnd(int idxN) {
        int size = getSize();
        Node* prev = head;
        
        for(int i=1; i<(size-idxN); i++) {
            prev = prev->next;
        }

        Node* toDel = prev->next;

        prev->next = prev->next->next;

        toDel->next = NULL;
        delete toDel;
    }

    bool isCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){      //for even and odd
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                cout<<"cycle exists\n";
                return true;
            }
        } 

        cout<<"cycle does not exists\n";
        return false;
    }

    void remCycle(Node* head) {
        //detect cycle
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL) {      
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                cout<<"cycle exists\n";
                isCycle = true;
                break;
            }
        } 

        if(!isCycle) {
            cout<<"cycle doesn't exist\n";
            return;
        }

        slow = head;
        if(slow == fast) {  //special case: when tail->head
            while(fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;      //cycle removed
        } else {
            Node* prev = fast;
            while(slow != fast) {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }  
            prev->next = NULL;      //cycle removed
        }
    }

};

int main() {
    List ll;

    ll.printLL(ll.head);   //NULL

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printLL(ll.head);

    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.printLL(ll.head);

    ll.insert(100, 2);
    ll.printLL(ll.head);

    ll.pop_front();
    ll.printLL(ll.head);

    cout<<ll.searchIdx(5)<<endl;

    cout<<ll.recSearch(6)<<endl;

    ll.reverse();
    ll.printLL(ll.head);

    cout<<ll.getSize()<<endl;

    ll.delNthEnd(2);
    ll.printLL(ll.head);

    ll.tail->next = ll.head;
    ll.isCycle(ll.head);

    ll.remCycle(ll.head);
    ll.isCycle(ll.head);
    ll.printLL(ll.head);

    

    return 0;
}