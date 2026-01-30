#include<iostream>
#include<vector>
using namespace std;

int mountainRanges(int pairs) {
    vector<int> dp(pairs+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=pairs; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[pairs];
}

int main() {
    cout<<mountainRanges(3)<<endl;
    cout<<mountainRanges(4)<<endl;

    return 0;    
}