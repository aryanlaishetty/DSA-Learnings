#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void changeArr(vector<int> &arr, int n, int i) {
    if(i == n) {
        printArr(arr);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;    //backtrack
}

int main() {

    vector<int> arr(5, 0);

    changeArr(arr, 5, 0);
    printArr(arr);

    return 0;
}