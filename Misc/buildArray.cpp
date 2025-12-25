#include <iostream>
#include <vector>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> ans(nums.size());

    for(int i=0; i<nums.size(); i++) {
        ans[i] = nums[nums[i]];
    }
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<", ";
    }
    cout<<endl;
    return ans;
}

int main() {

    vector<int> nums = {0,2,1,5,3,4};
    buildArray(nums);


    return 0;
}