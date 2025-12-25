#include <iostream>
using namespace std;

int main() {

    int i, j, n=4;

    for (i=1; i<=n; i++) {
        for (j=n; j>=i; j--) {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}