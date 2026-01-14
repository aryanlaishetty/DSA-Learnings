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

    bool isBipartite() {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> color(V, -1);   //0-blue    1-white

        q.push(0);
        visited[0] = 0;
        color[0] = 0;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    color[v] = !color[curr];
                } else {
                    if(color[v] == color[curr]) {   //neighbor have same color
                        return false;   //not bipartite
                    }
                }
            }
        }

        return true;

        // in this we can remove visitied array and track elements with color array 
        // if color[v] == -1 => not visited, 
        // else => visited
    }

    

};

int main() {
    Graph graph(4);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);

    cout<<graph.isBipartite()<<endl;
    
    graph.addEdge(0,3);
    
    cout<<graph.isBipartite()<<endl;

    return 0;
}