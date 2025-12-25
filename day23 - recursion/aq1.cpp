#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int nums[], int st, int end, int key) {
    
    if(st>end) {
        return -1;
    }

    int mid = (st+end) / 2;

    if(nums[mid] == key) {
        return mid;
    } else if(nums[mid] > key) {
        return BinarySearch(nums, st, mid-1, key);
    } else {
        return BinarySearch(nums, mid+1, end, key);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(int);
    cout << BinarySearch(nums, 0, 7, 5) << endl;
    return 0;
}