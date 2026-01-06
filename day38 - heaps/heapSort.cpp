#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int idx, vector<int> &arr, int size) {
    int left = 2*idx+1;
    int right = 2*idx+2;
    int maxIdx = idx;

    if(left < size && arr[left] > arr[maxIdx]) {    //reverse condition '<' for descending
        maxIdx = left;
    }

    if(right < size && arr[right] > arr[maxIdx]) {  //reverse condition '<' for descending
        maxIdx = right;
    }

    if(maxIdx != idx) {
        swap(arr[idx], arr[maxIdx]);
        heapify(maxIdx, arr, size);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    //step1 : build maxHeap
    for(int i=n/2-1; i>=0; i--) {
        heapify(i, arr, n);
    }

    //step2 : taking elements to correct position
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);
    printArr(arr);



    return 0;
}