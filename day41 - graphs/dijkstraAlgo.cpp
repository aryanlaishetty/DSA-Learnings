#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Edge {
public:
    int v;  //u---v
    int wt; //weight

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }

};

void dijkstrasAlgo(int src, vector<vector<Edge>> graph) {   //TC = O((V+E) log V)
    int V = graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    //min heap  //pair<dist[v], v>

    vector<int> dist(V, INT16_MAX);

    dist[src] = 0;
    pq.push(make_pair(dist[src], src)); //distance of reaching src from src is zero
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e : edges) {   //e.v   e.wt
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    for(int d : dist) {
        cout<<d<<" ";
    }
    cout<<endl;
}

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));
    
    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    dijkstrasAlgo(0, graph);

    return 0;
}