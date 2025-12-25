#include <iostream>
using namespace std;

int clearRange(int num, int i, int j) {
    
    for(int x = i; x<=j; x++) {
        int bitMask = ~(1<<x);
        num = num & bitMask;
    }
    return num;
}

int main() {
    cout<<clearRange(31, 1, 3);
    return 0;
}