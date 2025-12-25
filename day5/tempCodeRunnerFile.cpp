#include <iostream>
using namespace std;

int main() {

    int n=1, ans, i;

    cout<<"Enter number : ";
    cin>>n;

    for(i=1; i=n; i++) {
        n=n*i;
    }

    cout<<"n! = "<<n;

    return 0;
}