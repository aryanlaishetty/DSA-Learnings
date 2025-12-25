#include<iostream>
#include<string>
using namespace std;

class Complex{
    //properties which are private
    int real;
    int img;

public:

    //constructor
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    //function / method
    void showNum() {
        cout<<real<<" + "<<img<<"i\n";
    }

    //operator overloading
    Complex operator + (Complex &c2) {
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex c3(resReal, resImg);
        return c3;
    }
    Complex operator - (Complex &c2) {
        int resReal = c2.real - this->real;
        int resImg = c2.img - this->img;
        Complex c3(resReal, resImg);
        return c3;
    }


};

int main() {
    Complex c1(2,4);
    
    Complex c2(3,5);

    c1.showNum();
    c2.showNum();

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    c3.showNum();
    c4.showNum();

    

    return 0;
}