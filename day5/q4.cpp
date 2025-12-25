#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int N;

    cout<<"Enter the value of N: ";
    cin>>N;

    for(int i=2; i<=N; i++) {
        int current = i;
        bool isPrime = true;

        for(int j=2; j<=sqrt(i); j++) {
            if(current%j==0) {
                isPrime = false;
            }
        }

        if(isPrime) {
            cout<<current<<" ";
        }
    }

    cout<<endl;
    return 0;
}