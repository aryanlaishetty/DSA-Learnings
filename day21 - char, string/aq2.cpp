#include<iostream>
#include<string>
#include<string.h>

using namespace std;

bool SwapCheck(string s1, string s2) {

    if(s1.length() != s2.length()) {
        return false;
    } else if(s1 == s2) {
        return true;
    } else {
        for(int i=0; i<s1.length(); i++) {
            for(int j=i+1; j<s1.length(); j++) {
                swap(s1[i], s1[j]);
                if(s1 == s2) {
                    return true;
                }
                swap(s1[i], s1[j]);
            }
        }
    }
    return false;
}

int main() {

    string s1="bank", s2="kanb";
    
    cout<<SwapCheck(s1, s2)<<endl;;

    return 0;
}