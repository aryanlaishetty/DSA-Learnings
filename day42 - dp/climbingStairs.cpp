#include<iostream>
#include<vector>
using namespace std;

//Leetcode Question No. 70 - Climbing Stairs : we need to calculate total number of ways to climb n stairs 

//normal recursion
int climbStairsByNormalRecursion(int n) {   //O(2^n) - Exponential Time Complexity
    if(n == 0 || n == 1) {
        return 1;
    }

    return climbStairsByNormalRecursion(n-1) + climbStairsByNormalRecursion(n-2);
}

//Memoization DP
int climbStairsByMemoizationDP(int n, vector<int>& dp) {   //O(n) - Linear Time Complexity
    if(n == 0 || n == 1) {
        return dp[n] = 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = climbStairsByMemoizationDP(n-1, dp) + climbStairsByMemoizationDP(n-2, dp);
    return dp[n];
}


//Tabulation DP
int climbStairsByTabulationDP(int n) {  //O(n) - Linear Time Complexity
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int main() {
    int n=5;

    cout<<climbStairsByNormalRecursion(n)<<endl;    //ans - 8

    vector<int> dp(n+1, -1);
    cout<<climbStairsByMemoizationDP(n, dp)<<endl;

    cout<<climbStairsByTabulationDP(n)<<endl;



    return 0;
}