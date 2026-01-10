#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void countDistinct(vector<int> arr) {
    unordered_set<int> s;

    for(int i=0; i<arr.size(); i++) {
        s.insert(arr[i]);
    }

    cout<<"Number of distinct elements = "<<s.size()<<endl;

    for(int el : s) {
        cout<<el<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {4,3,2,5,6,7,3,4,2,1};

    countDistinct(arr);

    return 0;
}