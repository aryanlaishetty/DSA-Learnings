#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> freq; //<char, freq>
    
    //store freq of every char of string s in map
    for(int i=0; i<s.size(); i++) {
        if(freq.count(s[i])) {
            freq[s[i]]++;
        } else {
            freq[s[i]] = 1;
        }
    }

    //decrease freq of every char of string t from map
    for(int i=0; i<t.size(); i++) {
        if(freq.count(t[i])) {
            freq[t[i]]--;
            if(freq[t[i]] == 0) {
                freq.erase(t[i]);
            }
        } else {
            return false;
        }
    }

    return freq.size() == 0;
}

int main() {
    string s1 = "race";
    string t1 = "care";
    string s2 = "tulip";
    string t2 = "lipit";

    cout<<isAnagram(s1, t1)<<endl;
    cout<<isAnagram(s2, t2)<<endl;


    return 0;
}