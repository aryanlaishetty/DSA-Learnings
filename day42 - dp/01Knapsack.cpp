#include<iostream>
#include<vector>
using namespace std;

//normal recursion
int _01KnapsackByRec(vector<int> val, vector<int> wt, int W, int n) {   //O(2^n)
    if(n == 0 || W == 0) {  //no item or bag is full
        return 0;
    }

    int itemVal = val[n-1]; 
    int itemWt = wt[n-1];

    if(itemWt <= W) {   //valid Wt
        //include
        int ans1 = _01KnapsackByRec(val, wt, W-itemWt, n-1) + itemVal;

        //exclude
        int ans2 = _01KnapsackByRec(val, wt, W, n-1);

        return max(ans1, ans2);
    } else {
        //exclude
        return _01KnapsackByRec(val, wt, W, n-1);
    }
}

//Memoization DP
int _01KnapsackByMemoization(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp) {   //O(n*W)
    if(n == 0 || W == 0) {  //no item or bag is full
        return 0;
    }

    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    int itemVal = val[n-1]; 
    int itemWt = wt[n-1];

    if(itemWt <= W) {   //valid Wt
        //include
        int ans1 = _01KnapsackByMemoization(val, wt, W-itemWt, n-1, dp) + itemVal;

        //exclude
        int ans2 = _01KnapsackByMemoization(val, wt, W, n-1, dp);

        dp[n][W] = max(ans1, ans2);
    } else {
        //exclude
        dp[n][W] = _01KnapsackByMemoization(val, wt, W, n-1, dp);
    }

    return dp[n][W];
}

int _01KnapsackByTabulation(vector<int> val, vector<int> wt, int W, int n) {   //O(n*W)
    
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) {   //j = capacity
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);   //max(included, excluded)
            } else {
                dp[i][j] = dp[i-1][j];  //excluded
            }
        }
    }

    cout<<"---Tabulation DP Table--------"<<endl;

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

    //normal recursion
    cout<<_01KnapsackByRec(val, wt, W, n)<<endl;

    cout<<"----------------------"<<endl;

    //memoization DP
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout<<_01KnapsackByMemoization(val, wt, W, n, dp)<<endl;

    cout<<"--Memoization DP Table-----------"<<endl;

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // cout<<"----------------------"<<endl;

    cout<<_01KnapsackByTabulation(val, wt, W, n)<<endl;

    return 0;
}