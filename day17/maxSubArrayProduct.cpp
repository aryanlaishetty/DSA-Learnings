#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int currProd = 1;
    int maxProd = INT8_MIN;
    
    for(int i=0; i<nums.size(); i++) {      //Kadane's Algorithm
        currProd *= nums[i];
        maxProd = max(currProd, maxProd);

        if(currProd < 0) {
            currProd = 0;
        }
    }

    return maxProd;
}


int main() {
    vector<int> nums1 = {2,3,-2,4};
    vector<int> nums2 = {-2,0,-1};
    vector<int> nums3 = {-3,-1,-1};

    cout<<maxProduct(nums3)<<endl;

    return 0;
}