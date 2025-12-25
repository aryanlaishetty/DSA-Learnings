#include <iostream>
using namespace std;

int sqr (int x) {
    int ans = x*x;
    return ans;
}

int trigo(int a, int b) {
    
    int val1 = sqr(a);
    int val2 = sqr(b);
    int val3 = 2*a*b;

    int res = val1 + val2 + val3;
    return res;
}

int main() {
    int a=2, b=3;
    cout<<a<<".sqr + "<<b<<".sqr = "<<trigo(a,b);
    return 0;
}