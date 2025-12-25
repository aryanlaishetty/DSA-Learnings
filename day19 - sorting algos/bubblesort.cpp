#include<iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n) {
    bool isSwap = false;

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap=true;
            }
        
        }

        if(!isSwap) {   //here if swap is happend then isSwap will be true and if not then isSwap will be false 
            return;
        }
    }

    printArr(arr, n);
}

int main() {

    int arr1[]={5,4,1,3,2}, arr2[]={1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(arr2)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);

    bubbleSort(arr1, n1);
    cout<<endl;
    bubbleSort(arr2, n2);


    return 0;
}