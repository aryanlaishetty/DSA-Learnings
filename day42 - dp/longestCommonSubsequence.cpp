#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcsByRecursion(string str1, string str2) {  //TC = O(2^n+m)
    int n = str1.size();
    int m = str2.size();
    
    if(n == 0 || m == 0) {
        return 0;
    }

    if(str1[n-1] == str2[m-1]) {
        return 1 + lcsByRecursion(str1.substr(0, n-1), str2.substr(0, m-1));
    } else {
        int ans1 = lcsByRecursion(str1.substr(0, n-1), str2);
        int ans2 = lcsByRecursion(str1, str2.substr(0, m-1));
        return max(ans1, ans2);
    }
}

int lcsByMemoization(string str1, string str2, vector<vector<int>> &dp) {  //TC = O(n*m)
    if(str1.size() == 0 || str2.size() == 0) {
        return 0;
    }

    int n = str1.size();
    int m = str2.size();

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    if(str1[n-1] == str2[m-1]) {    //if last character of both strings match 
        dp[n][m] = 1 + lcsByMemoization(str1.substr(0, n-1), str2.substr(0, m-1), dp);
    } else {    ////if last character of both strings does not match 
        int ans1 = lcsByMemoization(str1.substr(0, n-1), str2, dp);
        int ans2 = lcsByMemoization(str1, str2.substr(0, m-1), dp);
        dp[n][m] = max(ans1, ans2);
    }

    return dp[n][m];
}

int lcsByTabulation(string str1, string str2) { //TC = O(n*m)
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    //By Recursion
    cout<<lcsByRecursion(str1, str2)<<endl;

    //By Memoization DP
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<lcsByMemoization(str1, str2, dp)<<endl;

    //By Tabulation DP
    str1 = "abcde";
    str2 = "ace";
    cout<<lcsByTabulation(str1, str2)<<endl;

    return 0;
}