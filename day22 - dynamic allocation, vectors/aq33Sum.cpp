#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<int> ans = {0};
    int i=0;

    while(i<nums.size()-3) {
        int a=i;
        int b=i+1;
        int c=i+2;

        if(a+b+c == 0) {
            ans = ans + {a,b,c};
            i+=3;
        } else {
            i++;
        }
    }
    return ans;
}

int main() {
    
    vector<int> nums = {2, 2}; 
        
    vector<int> ans = threeSum(nums);

    return 0;
}