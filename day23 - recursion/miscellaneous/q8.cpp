#include<iostream>
using namespace std;

int digitProduct(int n) {       //Product of digits in a number
    if(n / 10 == 0) {
        return n;
    }

    int dig = n % 10;
    int ans = dig * digitProduct(n/10);

    return ans;
}

int main() {

    cout<< digitProduct(26) <<endl;

    return 0;
}
