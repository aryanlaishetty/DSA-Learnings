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

    bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &prerequisites) {
        visited[src] = true;
        recPath[src] = true;

        for(int i=0; i<prerequisites.size(); i++) {
            //v <----- u
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src) {
                if(!visited[v]) {
                    if(isCycle(v, visited, recPath, prerequisites)) {
                        return true;
                    }
                } else {
                    if(recPath[v]) {
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {    //prerequisites = graph points
        int V = numCourses;

        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(isCycle(i, visited, recPath, prerequisites)) {
                    return false;
                }
            }
        }

        return true;
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


    return 0;
}