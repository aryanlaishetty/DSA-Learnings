#include<iostream>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

bool isAnagram(string s, string t) {

    if(s.length() != t.length()) {
        return 0;
    }

    int count[26] = {0};

    for(int i=0; i<s.length(); i++) {
        int idx = s[i] - 'a';
        count[idx]++;
    }

    for(int i=0; i<t.length(); i++) {
        int idx = t[i] - 'a';
        
        if(count[idx]==0) {
            return false;
        }
        count[idx]--;
    }

    return true;

}


int main() {

    string s="anagram", t="nagaram";

    cout<<isAnagram(s, t);

    return 0;
}