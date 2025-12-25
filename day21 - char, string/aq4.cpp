#include<iostream>
#include<string>
#include<string.h>

using namespace std;

bool isValid(string s) {

    int spair = (s.length())/2;
    char st=0, end=s.length()-1;
    int count=0; 

    if(s.length() % 2 == 0) {
        while(st<end) {
            if(s[st] == s[end]) {
                if(s[st] == '(' && s[end] == ')') {
                    count++;
                } else if (s[st] == '{' && s[end] == '}') {
                    count++;
                } else if (s[st] == '[' && s[end] == ']') {
                    count++;
                }
            st++;
            end--;
            } else {
                if(s[st] == '(' && s[st+1] == ')') {
                    count++;                   
                } else if (s[st] == '{' && s[st+1] == '}') {
                    count++;
                } else if (s[st] == '[' && s[st+1] == ']') {
                    count++;
                }
            st+=2;
            }
        }
        if(spair == count) {
            return true;
        }
    }
    return false;
}

    

int main() {

    string s1="([])";
    
    cout<<isValid(s1)<<endl;

    return 0;
}