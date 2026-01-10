#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public: 
    unordered_map<char, Node*> children;    //this map will store char and node pointer of children of current node
    bool endOfWord; //T - a word ends here, F - word does not end

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) {   //O(L)  
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {     //agar trie mai wo character exist nahi karta 
                temp->children[key[i]] = new Node();    //insert
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

    bool startsWith(string prefix) {    //O(L)
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++) {
            if(temp->children.count(prefix[i])) {
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }

        return true;
    }

};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    cout<<trie.startsWith("their")<<endl;
    cout<<trie.startsWith("thei")<<endl;
    cout<<trie.startsWith("an")<<endl;
    cout<<trie.startsWith("ab")<<endl;

    return 0;
}