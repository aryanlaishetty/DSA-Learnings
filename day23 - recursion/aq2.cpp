#include <iostream>
#include <vector>
using namespace std;

void AllOccur(int nums[], int arrsize, int i, int key) {
    if(i == arrsize) {
        return;
    }

    if(nums[i] == key) {
        cout<< i <<", ";
    }

    AllOccur(nums, arrsize, i+1, key);
    
}

int main() {
    int nums[] = {3,2,4,5,6,2,7,2,2};
    int n = sizeof(nums) / sizeof(int);

    AllOccur(nums, n, 0, 2);
    return 0;
}