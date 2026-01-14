#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;  //size
    list<int> * l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {    //u and v are connected nodes (u--v)
        l[u].push_back(v);
        l[v].push_back(u);
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

    bool undirCycleHelper(int src, int parent, vector<bool> &visited) {     //dfs
        visited[src] = true;
        list<int> neighbor = l[src];

        for(int v : neighbor) {
            if(!visited[v]) {
                if(undirCycleHelper(v, src, visited)) {
                    return true;
                }
            } else {
                if(v != parent) {   //cycle condition - back edge found
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleUndirected() {
        vector<bool> visited(V, false);
        return undirCycleHelper(0, -1, visited);
    }
    

    

};

int main() {
    Graph graph(10);

    //undirected graph with cycle
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);    //back edge
    graph.addEdge(0, 3);

    graph.addEdge(1, 2);

    graph.addEdge(3, 4);

    cout<<graph.isCycleUndirected()<<endl;


    return 0;
}