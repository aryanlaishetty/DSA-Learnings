#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes (vector<int> lengths) {
    priority_queue<int, vector<int>, greater<int>> pq(lengths.begin(), lengths.end());

    int cost = 0;

    while(pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;

        pq.push(min1+min2);
    }

    cout<<"Final length of rope = "<<pq.top()<<endl;
    cout<<"Minimum cost to connect ropes = "<<cost<<endl;

    return cost;
}

int main() {
    vector<int> ropesLen = {4, 3, 2, 6};

    connectNRopes(ropesLen);

    return 0;
}