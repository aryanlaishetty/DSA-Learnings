#include <iostream>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    vector<bool> isPresent(n+1, false);

    for(int i=0; i<n; i++) {
        if(isPresent[nums[i]]) {
            ans.push_back(nums[i]);
        }
        isPresent[nums[i]] = true;
    }

    for(int i=1; i<isPresent.size(); i++) {
        if(!isPresent[i]) {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

int main() {
    
    vector<int> nums = {2, 2}; 
        
    vector<int> ans = findErrorNums(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", ";
    }
    cout << endl;

    return 0;
}