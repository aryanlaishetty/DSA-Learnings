#include<iostream>
using namespace std;

int Reverse(int arr[], int n) {
    int st=0, end=n-1, temp;
    
    while(st<=end) {
        temp=arr[st];           //we can also use swap function
        arr[st]=arr[end];
        arr[end]=temp;
        st++;
        end--;
    }
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<", ";
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