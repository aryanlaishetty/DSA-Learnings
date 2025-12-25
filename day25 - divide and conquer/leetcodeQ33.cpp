#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& arr, int si, int ei, int target) {

    if(si>ei) {
        return -1;
    }

    int mid = si + (ei-si)/2;

    if(arr[mid] == target) {
        return mid;
    }

    if(arr[si] <= arr[mid]) {   //L1
        if(arr[si] <= target && target <= arr[mid]) {
            //Left Half
            return search(arr, si, mid-1, target);
        } else {
            //Right Half
            return search(arr, mid+1, ei, target);
        }
    } else {    //L2
        if(arr[ei] >= target && target >= arr[mid]) {
            //Right Half
            return search(arr, mid+1, ei, target);
        } else {
            //Left Half
            return search(arr, si, mid-1, target);
        }
    }

}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};

    cout<<search(arr, 0, arr.size()-1, 0)<<endl;

    return 0;
}