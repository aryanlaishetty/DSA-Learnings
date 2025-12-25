#include<iostream>
#include<string>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int st, int end) {
    if(st>end) {
        return -1;
    }

    int mid = st + (end-st) / 2;
    
    if(arr[mid] == target) {
        return mid;
    } else if(arr[mid] < target) {      //left half call
        return binarySearch(arr, target, mid+1, end);
    } else if(arr[mid] > target) {      //right half call
        return binarySearch(arr, target, st, mid-1);
    }
}


int main() {
    vector<int> arr1 = {1,5,7,9,11,32,57,99,100};
    
    cout<<binarySearch(arr1, 32, 0, arr1.size()-1)<<endl;

    return 0;
}