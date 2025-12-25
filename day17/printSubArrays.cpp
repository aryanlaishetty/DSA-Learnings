#include<iostream>
#include<vector>

using namespace std;

void printSubArrays(int arr[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=i; j<size; j++) {
            for(int k=i; k<=j; k++) {
                cout<<arr[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};

    printSubArrays(arr, 5);

    return 0;
}