#include <iostream>
using namespace std;

int factorial(int n) {
    int fact=1;
    for(int i=1; i<=n; i++) {
        fact=fact*i;
    }
    cout<<n<<"!="<<fact;
    return 0;
}

int main() {
    int n=4;
    factorial(n);
    return 0;
}