#include<iostream>
using namespace std;

int digitCount(int n) {       //count of digits in a number
    if(n / 10 == 0) {
        return 1;
    }

    int count = digitCount(n/10);
    return count+=1;
}


int main() {

    cout<<digitCount(36915)<<endl;

    return 0;
}