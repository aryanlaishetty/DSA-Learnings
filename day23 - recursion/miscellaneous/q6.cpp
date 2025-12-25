#include<iostream>
using namespace std;

int digitSum(int n) {       //Sum of digits in a number
    if(n / 10 == 0) {
        return n;
    }

    int dig = n%10;
    // n = n/10;

    int ans = dig + digitSum(n/10);

    return ans;

}


int main() {

    cout<<digitSum(369)<<endl;

    return 0;
}