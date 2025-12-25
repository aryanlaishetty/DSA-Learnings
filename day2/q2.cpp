#include <iostream>
using namespace std;

int main() {

    float penc, pen, eras;

    cout<<"Enter cost of pencil : ";
    cin>>penc;

    cout<<"Enter cost of pen : ";
    cin>>pen;
    
    cout<<"Enter cost of eraser : ";
    cin>>eras;

    cout<<"Cost of pencil, pen and eraser is "<<(0.18*(penc+pen+eras))+(penc+pen+eras)<<endl;

    return 0;
}