#include<iostream>
#include<vector>
using namespace std;

//Leetcode Q No. 96
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;  //When there are 0 nodes we can still arrange them in 1 way i.e by not arranging them same for 1 node

    for(int i=2; i<=n; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    cout<<numTrees(3)<<endl;
    cout<<numTrees(1)<<endl;

    return 0;
}
