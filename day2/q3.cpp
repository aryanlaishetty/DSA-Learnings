#include <iostream>
using namespace std;

int main() {

    int p, r, t;

    cout<<"Enter Principal amount : ";
    cin>>p;

    cout<<"Enter rate : ";
    cin>>r;

    cout<<"Enter time: ";
    cin>>t;

    float total=(p*r*t)/100;

    cout<<"Total amount : "<<total<<endl;

    return 0;
}