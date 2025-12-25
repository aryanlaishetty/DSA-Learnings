#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int lowerVowels(string s) {

    int count=0;
    string vowels = "aeiou";

    for(int i=0; i<s.length(); i++) {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            count++;
        } 
    }
    return count;
}

int main() {

    string str = "aryan";
    cout<<lowerVowels(str)<<endl;;

    return 0;
}