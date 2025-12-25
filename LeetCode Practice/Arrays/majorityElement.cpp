#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> nums) {
    int size = nums.size();

    int majority = size/2;

    int count = 0;
    int maj = 0;

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
            if(count > majority) {
                return nums[j];
            }
        }
        count = 0;
    }

    return -1;
}


int main() {

    vector<int> nums = {2,2,1,1,1,2,2};

    cout<< majorityElement(nums) <<endl;


    return 0;
}