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

};

bool helper(Trie &wordBreakTrie, string key) {
    if(key.size() == 0) {
        return true;
    }

    for(int i=0; i<key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(wordBreakTrie.search(first) && helper(wordBreakTrie, second)) {
            return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    Trie wordBreakTrie;

    for(int i=0; i<wordDict.size(); i++) {
        wordBreakTrie.insert(wordDict[i]);
    }

    return helper(wordBreakTrie, s);
}

int main() {
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    vector<string> dict2 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    // cout<<wordBreak("ilikesamsung", dict)<<endl;
    // cout<<wordBreak("ilikeung", dict)<<endl;
    cout<<wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict2)<<endl;
    

    return 0;
}