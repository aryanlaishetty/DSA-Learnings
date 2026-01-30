#include<iostream>
#include<vector>
using namespace std;

//This is a variation of 0-1 Knapsack
int minimumDifference(vector<int> nums) {
    int totalSum = 0;
    for(int el : nums) {
        totalSum += el;
    }

    int n = nums.size();
    int W = totalSum / 2;
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(nums[i-1] <= j) {
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int group1Sum = dp[n][W];
    int group2Sum = totalSum - group1Sum;

    return abs(group1Sum - group2Sum);
}

int main() {
    vector<int> nums1 = {1,6,11,5};
    cout<<minimumDifference(nums1)<<endl;
    vector<int> nums2 = {3,9,7,3};
    cout<<minimumDifference(nums2)<<endl;

    return 0;
}