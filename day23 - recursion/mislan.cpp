#include <iostream>
using namespace std;

bool isArraySorted(int arr[], int index, int length) {

    //base case
    if(arr[index] <= arr[index+1]) {
        return true;
    } else {
        return false;
    }

    isArraySorted(arr, index+1, length);
}

int main() {

    int arr1[] = {2,4,8,9,9,15};
    int arr2[] = {5,8,2,9,3};

    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);

    cout << isArraySorted(arr2, 0, n2);

    return 0;
}


