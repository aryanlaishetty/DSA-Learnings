#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxSubArrSum0(vector<int> arr) {
    unordered_map<int, int> m;  //<sum, idx>
    int sum = 0, maxLen = 0;

    for(int j=0; j<arr.size(); j++) {
        sum += arr[j];

        if(m.count(sum)) {
            int currLen = j-m[sum]; //j-idx
            maxLen = max(currLen, maxLen);
        } else {
            m[sum] = j;
        }
    }

    return maxLen;
}


int main() {
    vector<int> arr1 = {15,-2,2,-8,1,7,10};
    vector<int> arr2 = {-31, -48, -90, 54, 20, 95, 6, -86, 22};

    cout<<"Max subarray with sum 0 : "<<maxSubArrSum0(arr2);

    return 0;
}