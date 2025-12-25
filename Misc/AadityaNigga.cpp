#include <iostream>
using namespace std;

void MinMaxDigit(int num) {
    int Min = 9, Max = 0, lastDigit = 0;

    while(num > 0) {
        lastDigit = num % 10;
        num = num / 10;

        if(lastDigit > Max) {
            Max = lastDigit;
        } 
        if(lastDigit < Min) {
            Min = lastDigit;
        }
    
    }

    cout<<"Minimum digit of the given number : "<< Min <<endl; 
    cout<<"Maximum digit of the given number : "<< Max <<endl; 

}


int main() {

    MinMaxDigit(1280);

    return 0;
}