#include<iostream>
using namespace std;

int arrSum(int arr[], int size) {
   
    if(size == 0) {
        return 0;
    }

    if(size == 1) {
        return arr[size];
    }

    sum = sum + arrSum(arr+1, size-1); 

    return sum;
}


int main() {

    int arr[5] = {3,2,5,1,6};
    int size = 5;

    cout<<arrSum(arr, size)<<endl;

    return 0;
}