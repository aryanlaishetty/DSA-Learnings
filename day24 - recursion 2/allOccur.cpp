#include<iostream>
#include<string>
#include<vector>
using namespace std;

void allOccur(vector<int> arr, int key, int stIdx) {
    if(stIdx == arr.size()) {
        return;
    }

    if(arr[stIdx] == key) {
        cout<<stIdx<<" ";
    }

    allOccur(arr, key, stIdx+1);    

}

int main() {
    vector<int> arr1 = {3,2,4,5,6,2,7,2,2};

    allOccur(arr1, 2, 0);

    return 0;
}