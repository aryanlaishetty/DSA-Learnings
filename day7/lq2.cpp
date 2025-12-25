#include <iostream>
using namespace std;

int oddeven(int num) {
    if (num%2==0) {
        cout<<num<<" is even";
        return 0;
    } else {    
        cout<<num<<" is odd";
        return 0;
    }
}

int main() {
    int num = 15;
    oddeven(num);
    return 0;
}