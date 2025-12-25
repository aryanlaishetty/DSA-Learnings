#include<iostream>
using namespace std;

int MaxSubArrays(int arr[], int n) {
    int currSum=0;
    int maxSum=INT16_MIN;
    for (int i=0; i<n; i++) {
        currSum+=arr[i];
        maxSum=max(currSum, maxSum);
        if (currSum<0) {
            currSum=0;
        }
    }
    cout<<"Maximum of all subarrays = "<<maxSum;
}

int main() {
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    MaxSubArrays(arr, n);

    return 0;
}