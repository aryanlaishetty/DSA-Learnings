#include<iostream>
#include<vector>
using namespace std;

//climbing 1, 2 or 3 stairs allowed at a time


//normal recursion
int climbStairsByNormalRecursion(int n) {   //O(2^n) - Exponential Time Complexity
    if(n == 0 || n == 1) {
        return 1;
    }

    if(n == 2) {
        return 2;
    }

    return climbStairsByNormalRecursion(n-1) + climbStairsByNormalRecursion(n-2) + climbStairsByNormalRecursion(n-3);
}

//Memoization DP
int climbStairsByMemoizationDP(int n, vector<int>& dp) {   //O(n) - Linear Time Complexity
    if(n == 0 || n == 1) {
        return dp[n] = 1;
    }

    if(n == 2) {
        return dp[n] = 2;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = climbStairsByMemoizationDP(n-1, dp) + climbStairsByMemoizationDP(n-2, dp) + climbStairsByMemoizationDP(n-3, dp);
    return dp[n];
}


//Tabulation DP
int climbStairsByTabulationDP(int n) {  //O(n) - Linear Time Complexity
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}


int main() {
    int n=5;

    cout<<climbStairsByNormalRecursion(n)<<endl;    //ans - 13

    vector<int> dp(n+1, -1);
    cout<<climbStairsByMemoizationDP(n, dp)<<endl;

    cout<<climbStairsByTabulationDP(n)<<endl;



    return 0;
}