#include <iostream>
using namespace std;

// int factorial(int n) {
//     int fact=1;

//     for(i=1; i<=n; i++) {
//         fact=fact*i;
//     }
//     cout<<n<<"!="<<fact;
//     return fact;
// }

int factorial (int n) {
    if(n==0) {
        int fact=1;
        return fact;
    } else {
        int fact=1;
        fact = fact * factorial(n-1);
        return fact;
    }
}

int main() {
    int n=4;
    cout<<n<<"!="<<factorial(3)<<endl;
    return 0;
}