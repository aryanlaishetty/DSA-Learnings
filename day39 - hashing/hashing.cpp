#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totalSize;
    int currSize;   //current number of elements stored 
    Node** table;

    int hashFunction(string key) {  //O(n) as length of string is mostly small
        int idx = 0;

        for(int i=0; i<key.size(); i++) {
            idx = idx + ((key[i] * key[i]) % totalSize);    //hashing logic
        }

        return idx % totalSize;
    }

    void rehash() {     //O(n)
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2*totalSize;
        currSize = 0;
        table = new Node*[totalSize];

        for(int i=0; i<totalSize; i++) {    //O(n)
            table[i] = NULL;
        }

        //copy old values
        for(int i=0; i<oldSize; i++) {  //O(n)
            Node* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }  

        delete[] oldTable;
    }

public:
    HashTable(int size) {
        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];

        for(int i=0; i<totalSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {  //O(1) - avg case
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totalSize;
        if(lambda > 1) {
            rehash();   //O(n) - worst case
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) {
                return true;    //found, return immediately
            }

            temp = temp->next;
        }

        return false;   //not found
    }

    int search(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) {
                return temp->value;    //found, return immediately
            }

            temp = temp->next;
        }

        return -1;   //not found
    }

    void remove(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while(temp != NULL) {
            if(temp->key == key) {  //node found
                if(temp == prev) {  //head node
                    table[idx] = temp->next;
                } else {    //non head node
                    prev->next = temp->next;
                }
                break;
            }

            prev = temp;
            temp = temp->next;
        }        
    }

    void print() {
        for(int i=0; i<totalSize; i++) {
            cout<<"Idx "<<i<<" -> ";
            
            Node* temp = table[i];
            while(temp != NULL) {
                cout<<"("<<temp->key<<", "<<temp->value<<") -> ";
                temp = temp->next;
            }
            cout<<endl;            
        }
    }
};

int main() {
    HashTable ht(5);

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    ht.print();
    cout<<"--------"<<endl;

    ht.remove("China");
    ht.print();

    
    return 0;
}