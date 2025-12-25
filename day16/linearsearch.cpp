#include<iostream>
using namespace std;

int LinearSearch(int arr[], int n, int key) {

    for(int i=0; i<n; i++) {
        if (key == arr[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {5,6,7,2,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout<<LinearSearch(arr, n, 1)<<endl;

    return 0;
}