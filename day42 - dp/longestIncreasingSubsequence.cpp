#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longestIncreaseingSubsequence(vector<int> arr) {    //O(n^2)
    unordered_set<int> s(arr.begin(), arr.end());   //unique elements   //O(n)
    vector<int> arr2(s.begin(), s.end());   //copy of original array but with unique elements
    sort(arr2.begin(), arr2.end());   //sorted in ascending   O(nlogn)

    //LCS
    int n = arr.size();
    int m = arr2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {  //O(n*m)
        for(int j=1; j<m+1; j++) {
            if(arr[i-1] == arr2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    vector<int> arr = {50,3,10,7,40,80};

    cout<<longestIncreaseingSubsequence(arr)<<endl;

    return 0;
}