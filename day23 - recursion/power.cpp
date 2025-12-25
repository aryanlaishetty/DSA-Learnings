#include<iostream>
using namespace std;

double getPower(double num, int pow) {
    double ans = 1;
    
    if(pow == 0) {
        return 1;
    }

    if(pow > 0) {
        ans = num * getPower(num, pow-1);
    } 
    
    if(pow < 0) {
        ans = (1/num) * getPower(num, pow+1);
    }
    return ans;
}


int main() {

    double power = getPower(2.000000, -4);

    cout<<power<<endl;

    return 0;
}


