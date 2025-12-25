#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int> &arr, int si, int ei) {
    int i=si-1, pivot=arr[ei];

    for(int j=si; j<ei; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);

    //pivotIdx = i;
    return i;
}

void quickSort(vector<int> &arr, int si, int ei) {  

    if(si>ei) {
        return;
    }

    int pivotIdx = partition(arr, si, ei);

    quickSort(arr, si, pivotIdx-1);     //left half
    quickSort(arr, pivotIdx+1, ei);     //right half

}



int main() {

    vector<int> arr = {6,3,7,5,2,4};

    printArr(arr);
    quickSort(arr, 0, arr.size()-1);
    printArr(arr);

    return 0; 
}