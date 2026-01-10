#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public: 
    unordered_map<char, Node*> children;    //this map will store char and node pointer of children of current node
    bool endOfWord; //T - a word ends here, F - word does not end
    int freq;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) {   //O(L)  
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {     //agar trie mai wo character exist nahi karta 
                temp->children[key[i]] = new Node();    //insert
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string key) {   //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i])) {  //exists
                temp = temp->children[key[i]];
            } else {    //does not exists
                return false;
            }
        }

        return temp->endOfWord; //T-if exists
    }

    string getPrefix(string key) {
        Node* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++) {
            prefix += key[i];
            if(temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }

        return prefix;
    }
};

void prefixProblem(vector<string> dict) {   //O(n*L)
    Trie trie;
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++) {
        cout<<trie.getPrefix(dict[i])<<endl;
    }
}



int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    
    prefixProblem(words);

    return 0;
}