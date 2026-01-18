#include<iostream>
#include<vector>
using namespace std;

int fiboUsingTabulation(int n) {    //O(n)
    vector<int> fibTable(n+1, 0);   //fib[i] = ith fib  --meaning assigned

    fibTable[0] = 0;
    fibTable[1] = 1;

    for(int i=2; i<=n; i++) {
        fibTable[i] = fibTable[i-1] + fibTable[i-2];
    }

    return fibTable[n];
}

int main() {

    cout<<fiboUsingTabulation(6)<<endl;


    return 0;
}