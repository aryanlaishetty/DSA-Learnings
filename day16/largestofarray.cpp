#include<iostream>
using namespace std;

int Largest(int arr[], int n) {
    int max = arr[0]; 

    for(int i=1; i<n; i++) {
        if (arr[i]>max) {
            max=arr[i];
        } 
    }
    return max;
}

int main() {
    int arr[] = {2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    cout<<Largest(arr, n)<<endl;

    return 0;
}