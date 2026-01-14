#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    void printallPathsHelper(int src, int dest, vector<bool> &visited, string &path) {  //TC = O(V + E)
        if(src == dest) {
            cout<<path<<dest<<endl;
            return;
        }

        visited[src] = true;
        path += to_string(src);

        list<int> neighbours = l[src];
        for(int v : neighbours) {
            if(!visited[v]) {
                printallPathsHelper(v, dest, visited, path);
            }
        }

        visited[src] = false;
        path.pop_back();
    }

    void printallPaths(int src, int dest) {
        vector<bool> visited(V, false);
        string path = "";
        printallPathsHelper(src, dest, visited, path); 
    }

    

};

int main() {
    Graph graph(6, false);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(4, 0);
    graph.addEdge(3, 1);

    graph.printallPaths(5, 1);

    return 0;
}