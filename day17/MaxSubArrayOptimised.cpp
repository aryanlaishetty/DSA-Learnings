#include<iostream>
using namespace std;

int MaxSubArrays(int arr[], int n) {
    int maxSum=INT16_MIN;
    for (int start=0; start<n; start++) {
        int currSum=0;
        for (int end=start; end<n; end++) {
            currSum+=arr[end];
            maxSum=max(maxSum, currSum);
        }
        cout<<endl;
    }
    cout<<"Maximum of all subarrays = "<<maxSum;
}

int main() {
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    MaxSubArrays(arr, n);

    return 0;
}