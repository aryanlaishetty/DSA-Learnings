#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int getMinCoins(int V) {
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int n = coins.size();
    int numOfCoins = 0;

    for(int i=n-1; i>=0 && V>0; i--) {
        if(V >= coins[i]) {
            numOfCoins += V/coins[i];
            V %= coins[i];
        }
    }

    return numOfCoins;
}

int main() {
    cout<<getMinCoins(121)<<endl;

    return 0;
}