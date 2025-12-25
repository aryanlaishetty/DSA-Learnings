#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<string> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<string> &arr, int st, int end, int mid) {     //O(n)
    vector<string> temp;
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

void mergeSort(vector<string> &arr, int st, int end) {  //O(nlogn)
    if(st>=end) {
        return;
    }

    int mid = st + (end - st)/2;

    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, st, end, mid);
}

int main() {

    vector<string> arr = {"sun", "earth", "mars", "mercury"};

    printArr(arr);
    mergeSort(arr, 0, arr.size()-1);
    printArr(arr);

    return 0; 
}