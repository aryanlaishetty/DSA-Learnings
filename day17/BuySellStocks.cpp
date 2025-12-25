#include<iostream>
using namespace std;

void maxProfits(int prices[], int n) {
    int bestbuy[100000];
    bestbuy[0] = INT16_MAX;
    for (int i=1; i<n; i++) {
        bestbuy[i]=min(bestbuy[i-1], prices[i-1]);
    }

    int maxProfit=0;
    for (int i=0; i<n; i++) {
        int currProfit = prices[i] - bestbuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    cout<<"Max Profit = "<< maxProfit <<endl;
}

int main() {
    int prices[6]={7,1,5,3,6,4};
    int n = sizeof(prices) / sizeof(int);

    maxProfits(prices, n);

    return 0;
}