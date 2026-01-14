#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;  //size
    list<int> * l;
    bool isUndirected;
public:
    Graph(int V, bool isUndirected=true) {
        this->V = V;
        l = new list<int> [V];
        this->isUndirected = isUndirected;
    }

    void addEdge(int u, int v) {    //u and v are connected nodes (u--v)
        l[u].push_back(v);
        if(isUndirected) {  //if graph is undirected, than only bidirectional or both ways
            l[v].push_back(u);
        }
    }

    void print() {
        for(int u=0; u<V; u++) {
            list<int> neighbours = l[u];
            cout<<u<<" : ";
            for(int v : neighbours) {
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    bool dirCycleHelper(int src, vector<bool> &visited, vector<bool> &recPath) {     //dfs
        visited[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!visited[v]) {
                if(dirCycleHelper(v, visited, recPath)) {   //agar visited nahi hai toh visit karwayenge
                    return true;
                }
            } else {    
                if(recPath[v]) {    //if visited=true and recPath=true
                    return true;
                }
            }
        }
    
        recPath[src] = false;
        return false;
    }

    bool isCycleDirected() {
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++) {    //compulsory //also if more than 1 component exist in graph
            if(!visited[i]) {
                if(dirCycleHelper(i, visited, recPath)) {
                    return true;
                }
            }
        }

        return false;
    }   
    
};

int main() {
    //directed graph
    Graph graph(4, false);

    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);    //back edge


    cout<<graph.isCycleDirected()<<endl;


    return 0;
}