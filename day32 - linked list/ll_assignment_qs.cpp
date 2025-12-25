#include<iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    ListNode* head;
    ListNode* tail;

    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        ListNode* newNode = new ListNode(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLL(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

    int getSize(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int sizeA = getSize(headA);
        int sizeB = getSize(headB);
        int diff = abs(sizeA - sizeB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        if(sizeA > sizeB) {
            for(int i=0; i<=diff; i++) {
                tempA = tempA->next;
            }
        } else if(sizeB > sizeA) {
            for(int i=0; i<=diff; i++) {
                tempB = tempB->next;
            }
        }
        
        while(tempA != NULL && tempB != NULL && tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        if(tempA == NULL) {
            return NULL;
        } else {
            return headA;
        }
    }

    ListNode* delNafM(ListNode* head, int m, int n) {   //incomplete
        ListNode* temp = head;

        while(temp != NULL) {
            
            for(int i=0; i<m-1; i++) {
                temp = temp->next;
            }

            ListNode* nxt = temp->next;

            for(int i=0; i<n-1; i++) {
                temp->next = NULL;
                temp->next = nxt->next;
                nxt->next = NULL;
                delete nxt;

                nxt = temp->next;
            }
        }

        return head;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* head1 = head;
        ListNode* head2 = head;

        for(int i=0; i<k-1; i++) {
            head1 = head1->next;
        }

        int size = getSize(head);

        for(int i=0; i<size-k; i++) {
            head2 = head2->next;
        }

        swap(head1->data, head2->data);

        return head;
    }

    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* evenStart = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;

        while(odd->next != NULL && even->next != NULL) {
            odd->next = NULL;
            odd->next = even->next;
            even->next = NULL;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = evenStart;
        return head;
    }
};

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    
    ll.printLL(ll.head);

    // ll.delNafM(ll.head, 2, 2);
    // ll.swapNodes(ll.head, 2);

    ll.oddEvenList(ll.head);
    ll.printLL(ll.head);

    return 0;
}