#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int> &arr, int st, int end, int mid) {     //O(n)
    vector<int> temp;
    int i=st, j=mid+1;

    while(i<=mid && j<=end) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid) {
        temp.push_back(arr[i++]);
    }
    
    while(j<=end) {
        temp.push_back(arr[j++]);
    }

    //temp to original
    for(int idx = st, x=0; idx<=end; idx++) {
        arr[idx] = temp[x++];
    }
}

void mergeSort(vector<int> &arr, int st, int end) {  //O(nlogn)
    if(st>=end) {
        return;
    }

    int mid = st + (end - st)/2;

    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, st, end, mid);
}

int main() {

    vector<int> arr = {6,3,7,5,2,4};

    printArr(arr);
    mergeSort(arr, 0, arr.size()-1);
    printArr(arr);

    return 0; 
}