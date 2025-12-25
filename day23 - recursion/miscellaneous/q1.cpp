#include<iostream>
using namespace std;


void print1toN(int n) { //print 1 to N
    if(n == 1) {
        cout<< 1 <<", ";
        return;
    }

    print1toN(n-1);

    cout<<n<<", ";

}


int main() {

    print1toN(5);
    return 0;
}