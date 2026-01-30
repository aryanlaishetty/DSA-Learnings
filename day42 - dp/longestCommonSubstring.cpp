#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longestCommonSubstring(string str1, string str2) {  //TC = O(n*m)
    int n = str1.size();
    int m = str2.size();
    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {  //if character matched
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else {    //if character did not match
                dp[i][j] = 0;   //because substring is found consecutively
            }
        }
    }

    return ans;
}

int main() {
    string str1 = "abcde";
    string str2 = "abgce";

    cout<<longestCommonSubstring(str1, str2)<<endl;

    return 0;
}