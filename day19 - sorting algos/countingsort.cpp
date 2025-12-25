#include<iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void CountingSort(int arr[], int n) {
    int freq[100000]={0};
    int minVal = INT16_MAX, maxVal = INT16_MIN;
    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }

    for(int i=minVal, j=0; i<=maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
    

    printArr(arr, n);
}

int main() {

    int arr[]={1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);

    CountingSort(arr, n);

    return 0;
}