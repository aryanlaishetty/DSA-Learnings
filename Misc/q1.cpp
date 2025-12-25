#include <iostream>
using namespace std;

int RentABook(int X, int D, string S) {

    if(D < 7) {
        return X;
    } else if(D > 7 && S=="false") {
        X += 2*(D-7);
        return X;
    } else if(D > 7 && S=="true") {
        return X; 
    }
}


int main() {

    cout<<RentABook(50, 10, "false")<<endl;

    return 0;
}