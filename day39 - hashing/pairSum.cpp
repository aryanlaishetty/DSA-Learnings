#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;  //<nums[i], i>

    for(int i=0; i<nums[i]; i++) {
        int compliment = target - nums[i];

        if(m.count(compliment)) {
            cout<<"Ans idxs = "<<m[compliment]<<", "<<i<<endl;
            return {m[compliment], i};
        }
        
        m[nums[i]] = i;
    }
}

int main() {
    vector<int> nums = {1, 2,7,11,15};
    int target = 9;

    twoSum(nums, target);

    return 0;
}