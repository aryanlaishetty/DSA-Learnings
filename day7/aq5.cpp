#include <iostream>
using namespace std;

char nxtchar(char ch) {
    if (ch=='Z' || int(ch)==90) {
        return 'A';
    } else if (ch=='z' || int(ch)==122) {
        return 'a';
    } else {
        return ch+1;
    }
}

int main() {    
    char ch1;

    cout<<"Enter the character: ";
    cin>>ch1;
    char ch2 = nxtchar(ch1);
    cout<<"Next character: "<<ch2;
    
    return 0;
}