#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum(vector<int> numbers, int target) {
    int st=0, end=numbers.size()-1;
    int currSum=0;
    vector<int> ans;

    while(st < end) {
        currSum = numbers[st] + numbers[end];

        if(currSum == target) {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        } else if (currSum > target) {
            end--;
        } else {    //(currSum < target)
            st++;
        }
    }

    return ans;
}

int main() {
    
    vector<int> nums = {2, 7, 11, 15}; 
    
    int target = 9;
    
    vector<int> ans = pairSum(nums, target);

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<", ";
    }
    cout<<endl;

    return 0;
}