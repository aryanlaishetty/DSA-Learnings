#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

//see leetcode question no. 1584
int minCostConnectPoints(vector<vector<int>>& points) {
    int V = points.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //(wt, u)

    int src = 0;
    vector<bool> mstSet(V, false);

    pq.push(make_pair(0, src));
    int minCost = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(!mstSet[u]) {
            mstSet[u] = true;
            minCost += cost;
            
            for(int v=0; v<V; v++) {
                if(u != v) {    //u---v
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push(make_pair(wt, v));
                }
            }
        }
    }

    return minCost;
}

int main() {
    
    return 0;
}