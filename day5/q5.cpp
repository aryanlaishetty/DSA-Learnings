#include <iostream>
using namespace std;

int main() {

    int num, first=0, sec=1, third;

    cout<<"Enter number: ";
    cin>>num;

    cout<<"Fibonacci series of "<<num<<" is: "<<" "<<first<<" "<<sec<<" ";

    for(int i=2; i<num; i++) {
        third = first + sec;
        cout<<third<<" ";
        first = sec;
        sec = third;
    }

    cout<<endl;

    return 0;
}