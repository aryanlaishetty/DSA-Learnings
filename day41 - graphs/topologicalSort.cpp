#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {
    int V;  //size - total number of nodes
    list<int> * l;
    bool undirected;
public:
    Graph(int V, bool undirected=true) {
        this->V = V;
        l = new list<int> [V];
        this->undirected = undirected;
    }

    void addEdge(int u, int v) {    //u and v are connected nodes (u--v)
        l[u].push_back(v);
        if(undirected) {
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

    void topoHelper(int src, vector<bool> &visited, stack<int> &s) {    //TC = O(V+E)
        visited[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if(!visited[v]) {
                topoHelper(v, visited, s);
            }
        }

        s.push(src);    //dependent node will be pushed into stack first
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> s;

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                topoHelper(i, visited, s);
            }
        }

        //print topological sort
        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    

};

int main() {
    //DAG
    Graph graph(6, false);

    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(5, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 1);

    graph.topologicalSort();

    return 0;
}