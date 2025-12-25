#include<iostream>
using namespace std;

int sumN(int n) {       //sum first n numbers 
    if(n == 0) {
        return 0;
    }

    return n + sumN(n-1);
}

int main() {

    cout<< sumN(2) << endl;

    return 0;
}