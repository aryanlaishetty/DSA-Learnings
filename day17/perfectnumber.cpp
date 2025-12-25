#include<iostream>
using namespace std;

bool isPerfect(int n) {
    bool flag=0;
    int x=0;
    for(int i=1; i<=(n/2)+1; i++) {
        if(n%i==0) {
            x+=i;
        }
    }

    if(x==n) {
        return 1;
    } else {
        return 0;
    }

}

int main() {

    cout<<isPerfect(6)<<endl;
    cout<<isPerfect(7)<<endl;


    return 0;
}