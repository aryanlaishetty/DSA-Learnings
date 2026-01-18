#include<iostream>
#include<vector>
using namespace  std;

int fibo(int n) {   //normal recursion - TC= O(2^n) - in this recursion, 2^n calls are made which includes repetitive calls
    if(n==0 || n==1) {
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}

int fiboDP(int n, vector<int> &f) { //optimised recursion - TC= O(n) - int this recursion, only n calls are made, the answer is stored in f array, if fibo(n) exists in that array then value is returned and repetitive calls are not made, and if fibo(n) does not exist, than fibo(n) is calculated and that value is stored in f array on nth index
    if(n==0 || n==1) {
        return f[n] = n;
    }

    if(f[n] != -1) {
        return f[n];
    }

    f[n] = fiboDP(n-1, f) + fiboDP(n-2, f);
    return f[n];
}



int main() {
    int n = 6;
    cout<<fibo(n)<<endl;

    vector<int> f(n+1, -1);
    cout<<fiboDP(n, f)<<endl;

    return 0;
}