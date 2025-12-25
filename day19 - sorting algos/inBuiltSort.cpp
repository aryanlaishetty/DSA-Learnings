#include<iostream>
#include<algorithm>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main() {

    int arr[]={1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);

    printArr(arr, 8);

    sort(arr+2, arr+5);
    printArr(arr, 8);

    sort(arr, arr+8);   //sort(start, end);
    printArr(arr, 8);

    sort(arr, arr+8, greater<int>());
    printArr(arr, 8);

    return 0;
}