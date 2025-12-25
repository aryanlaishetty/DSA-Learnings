#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key) {
    int st=0, end=n-1;
    
    while(st<end) {
        int mid=(st+end)/2;
        if(key==arr[mid]) {
            return mid;
        } else if (key>arr[mid]) {
            st=mid+1;
        } else {
            end=mid-1;
        }
    }
    
}

int main() {
    int arr[] = {2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    cout<<BinarySearch(arr, n, 4)<<endl;

    return 0;
}