#include <iostream>
using namespace std;

int main() {
    int num, temp, cube, digit1, digit2, digit3;

    cout<<"Enter a 3 digit number : ";
    cin>>num;

    temp=num;

    digit1=num%10;
    num=num/10;
    digit2=num%10;
    num=num/10;
    digit3=num;

    cube = digit1*digit1*digit1 + digit2*digit2*digit2 + digit3*digit3*digit3;

    if(cube==temp) {
        cout << temp <<" is an Armstrong number." << endl;
    } else {
        cout << temp <<" is not an Armstrong number." << endl;
    }

    return 0;
}