#include<iostream>
#include<string.h>
using namespace std;

void toUpper(char word[], int n) {
    
    for(int i=0; i<n; i++) {
        if(word[i]>='a' && word[i]<='z') {
            word[i] = word[i] - 32;
        }
    }
    cout<<word<<endl;
}


int main() {
    char word[] = "aryan";

    toUpper(word, strlen(word));

    return 0;
}