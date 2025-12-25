#include<iostream>
using namespace std;

int Reverse(int arr[], int n) {
    int arr2[n];
    int i,j;

    for(i=0; i<n; i++) {
        j=n-i-1;
        arr2[j]=arr[i];
    }
    for(int i=0; i<n; i++) {
        cout<<arr2[i]<<", ";
    }
    cout<<endl;
}

int PrintArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main() {
    
    int arr[] = {2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    PrintArr(arr, n);
    Reverse(arr, n);


    return 0;
}