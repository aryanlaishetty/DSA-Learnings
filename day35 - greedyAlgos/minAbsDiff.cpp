#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minAbsoluteDiff(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans=0;

    for(int i=0; i<A.size(); i++) {
        ans += abs(A[i] - B[i]);
    }

    return ans;
}

int main() {
    vector<int> A1 = {1,2,3};
    vector<int> B1 = {2,1,3};

    vector<int> A2 = {4,1,8,7};
    vector<int> B2 = {2,3,6,5};

    cout<<minAbsoluteDiff(A1, B1)<<endl;
    cout<<minAbsoluteDiff(A2, B2)<<endl;

    return 0;
}