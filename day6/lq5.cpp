#include <iostream>
using namespace std;

int main() {

    int i, j, n=4;

    for (i=1; i<=n; i++) {

        cout<<"*";  //First row

        for (j=1; j<=n-1; j++) {
            if(i==1 || i==n) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<"*"<<endl;  //Last row
    }
    return 0;
}