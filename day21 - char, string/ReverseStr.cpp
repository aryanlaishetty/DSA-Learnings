#include<iostream>
#include<string.h>
using namespace std;

void Reverse(char word[], int n) {
    int st=0, end=n-1;

    while(st<=end) {
        swap(word[st], word[end]);
        st++;
        end--;
    }

    cout<<word<<endl;
}

int main() {
    char word[] = "ARYAN";

    Reverse(word, strlen(word));    

    return 0;
}