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

    void longestHelper(Node* root, string &ans, string temp) {
        for(pair<char, Node*> child : root->children) {
            if(child.second->endOfWord) {
                temp += child.first;

                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestStringWithEOW() {
        string ans = "";
        longestHelper(root, ans, "");

        return ans;
    }
};

string longestString(vector<string> dict) {
    Trie trie;

    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}


int main() {
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout<<longestString(dict)<<endl;

    return 0;
}