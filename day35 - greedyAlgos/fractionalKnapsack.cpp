#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;
}

int fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<pair<double, int>> ratio (n, make_pair(0.0, 0));     //pair(ratio, i)

    for(int i=0; i<n; i++) {
        double r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);

    int ans=0;
    for(int i=0; i<n; i++) {
        int idx = ratio[i].second;
        if(wt[idx] <= capacity) {
            ans += val[idx];
            capacity -= wt[idx];
        } else {
            ans += ratio[i].first * capacity;
            capacity = 0;
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int W = 50;

    cout<<fractionalKnapsack(val, wt, W);

    return 0;
}