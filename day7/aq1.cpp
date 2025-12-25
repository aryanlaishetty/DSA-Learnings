#include <iostream>
using namespace std;

void isPal(int n) {
    int temp=n, res=0;

    while (n>0) {
        int lastdig = n%10;
        res = res*10 + lastdig;
        n=n/10;
    }
    
    if(temp==res) {
        cout<<temp<<" is Palindrome";
    } else {
        cout<<temp<<" is not a Palindrome";
    }
}

int main() {
    isPal(4334);
    return 0;
}