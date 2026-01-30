#include<iostream>
#include<vector>
using namespace std;

int unboundedKnapsack(vector<int> val, vector<int> wt, int W, int n) {   //O(n*W)
    
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) {   //j = capacity
                dp[i][j] = max(itemVal + dp[i][j-itemWt], dp[i-1][j]);   //max(included, excluded)
            } else {
                dp[i][j] = dp[i-1][j];  //excluded
            }
        }
    }

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30}, wt = {2, 5, 1, 3, 4};
    int W = 7, n = 5;

    cout<<unboundedKnapsack(val, wt, W, n)<<endl;

    return 0;
}