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

void bellmanFordAlgo(int src, vector<vector<Edge>> graph) {   //TC = O(V*E)
    int V = graph.size();

    vector<int> dist(V, INT16_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++) {
        for(int u=0; u<V; u++) {
            for(Edge e : graph[u]) {
                if(dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int d : dist) {
        cout<<d<<" ";
    }
    cout<<endl;
}

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));
    
    graph[1].push_back(Edge(2, -4));

    graph[2].push_back(Edge(3, 2));
    
    graph[3].push_back(Edge(4, 4));
    
    graph[4].push_back(Edge(1, -1));
    
    bellmanFordAlgo(0, graph);

    return 0;
}