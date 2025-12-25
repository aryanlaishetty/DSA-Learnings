#include <iostream>
#include <cmath>
using namespace std;

int digitCount(int n) {
    if(n / 10 == 0) return 1;
    return 1 + digitCount(n / 10);
}

int reverseNumber(int n, int digits) {      //Reverse digits in a number
    if(n < 10) return n; // base case: single digit

    int last = n % 10;
    return last * pow(10, digits - 1) + reverseNumber(n / 10, digits - 1);
}

int main() {
    int n = 1234;
    int digits = digitCount(n);
    cout << reverseNumber(n, digits);
    return 0;
}
