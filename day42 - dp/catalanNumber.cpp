#include<iostream>
#include<vector>
using namespace std;

//By Recursion
int catalanByRecursion(int n) { //TC => O(2^n)
    if(n == 0 || n == 1) {
        return 1;   
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += catalanByRecursion(i) * catalanByRecursion(n-i-1);   //Ci * Cn-i-1   -   C0 * Cn-1
    }

    return ans;
}


//By Memoization
int catalanByMemoization(int n, vector<int> &dp) { //TC => O(n^2)
    if(n == 0 || n == 1) {
        return 1;   
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += catalanByMemoization(i, dp) * catalanByMemoization(n-i-1, dp);   //Ci * Cn-i-1   -   C0 * Cn-1
    }

    return dp[n] = ans;
}


//By Tabulation
int catalanByTabulation(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;  //base case

    for(int i=2; i<=n; i++) {   //picking ith catalan
        for(int j=0; j<i; j++) {    //calculating ith catalan - 0 to i
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}


int main() {
    int n = 4;

    // //By Recursion----------
    // cout<<catalanByRecursion(n)<<endl;  //14 - 4th number of Catalan Sequence

    // for(int i=0; i<=6; i++) {   //Catalan Sequence of first 7 numbers
    //     cout<<catalanByRecursion(i)<<" ";
    // }
    // cout<<endl;

    //By Memoization---------
    n = 6;
    vector<int> dp(n+1, -1);

    for(int i=0; i<=n; i++) {
        cout<<catalanByMemoization(i, dp)<<" ";
    }
    cout<<endl;

    //By Tabulation
    n = 6;

    for(int i=0; i<=n; i++) {
        cout<<catalanByTabulation(i)<<" ";
    }
    cout<<endl;

    return 0;
}