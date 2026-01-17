#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class DisjointSet {
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        this->n = n;

        for(int i=0; i<n; i++) {
            parent.push_back(i);
            rank.push_back(0);            
        }
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]); //path compression
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]) {
            parent[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]) {
            parent[parB] = parA;
        } else {
            parent[parA] = parB;
        }
    }


    void getInfo() {
        for(int i=0; i<n; i++) {
            cout<<i<<": Parent = "<<parent[i]<<", Rank = "<<rank[i]<<endl;
        }
    }
};

class Edge {
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public:
    vector<Edge> edges;
    int V;

    //for union find/disjoint set
    vector<int> parent;
    vector<int> rank;

    Graph(int V) {
        this->V = V;

        //for disjoint set
        for(int i=0; i<V; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    //functions for disjoint set
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }


    void unionByRank(int u, int v) {
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]) {
            rank[parV] = parU;
            rank[parU]++;
        } else if(rank[parU] > rank[parV]) {
            rank[parV] = parU;
        } else {
            rank[parU] = parV;
        }
    }

    void kruskals() {   //TC = O(ElogE)
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});    //TC = O(ElogE)
        int minCost = 0;
        int edgeCount = 0;

        for(int i=0; i<edges.size() && edgeCount<V-1; i++) {
            Edge e = edges[i];

            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV) {  //no cycle edge condition - if no two edges have same parents than this will execute because if two edges have same parent and we connect them than it will form a cycle
                unionByRank(parU, parV);
                minCost += e.wt;
                edgeCount++;    //for a MST, total number of edges = total number of vertices - 1;
            }
        }

        cout<<"Minimum Cost = "<<minCost<<endl;
    }

};




int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(0, 3, 40);
    graph.addEdge(0, 3, 50);

    graph.kruskals();

    return 0;
}   