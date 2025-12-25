#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(char word[], int n) {
    int st=0, end=n-1;

    while(st<=end) {
        if(word[st] != word[end]) {
            cout<<"Not a palindrome"<<endl;
            return false;
        }
        st++;
        end--;
    }

    cout<<"Valid Palindrome"<<endl;
    return true;
}

int main() {
    char word1[] = "ARYAN";
    char word2[] = "NAMAN";

    isPalindrome(word1, strlen(word1));    
    isPalindrome(word2, strlen(word2));    


    return 0;
}