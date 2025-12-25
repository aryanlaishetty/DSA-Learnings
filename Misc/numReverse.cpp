#include<iostream>
using namespace std;

int Reverse(int num) {

    int rev = 0;

    while(num != 0) {
        int digit = num % 10;
        rev = rev*10 + digit;
        num = num/10;
    }
    return rev;
}

int main() {
    cout<<Reverse(1534236469)<<endl;
    return 0;
}