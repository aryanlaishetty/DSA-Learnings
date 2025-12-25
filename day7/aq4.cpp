#include <iostream>
using namespace std;

void compare(int a, int b, int c) {
    if (a>b) {
        if (a>c) {
            cout<<a<<" is greater.";
        } else {
            cout<<c<<" is greater.";
        }
    } else {
        if (b>c) {
            cout<<b<<" is greater.";
        } else {
            cout<<c<<" is greater.";
        }
    }
}

int main() {
    compare(50,4,5);
    return 0;
}