#include <iostream>
using namespace std;

int digSum(int n) {
    int res = 0;
    while (n>0) {
        int lastdig = n%10;
        res = res + lastdig;
        n=n/10;
    }
    return res;
}

int main() {
    int n=123;
    cout<<"Sum of digits of "<<n<<" is "<<digSum(n);
    return 0;
}