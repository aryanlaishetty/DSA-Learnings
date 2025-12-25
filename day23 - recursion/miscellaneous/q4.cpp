#include<iostream>
using namespace std;

int fact(int n) {       //factorial of n 
    if(n == 0) {
        return 1;
    }

    int small = n * fact(n-1);
    return small;
}


int main() {
    
    cout<< fact(3) <<endl;

    return 0;
}
