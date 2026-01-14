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

    void bfsHelper(int st, vector<bool> &visited) {    //TC = O(V + E)
        queue<int> q;
        
        q.push(st);
        visited[st] = true;

        while(q.size() > 0) {
            int u = q.front();  //curr vertex
            q.pop();
            cout<<u<<" ";

            list<int> neighbours = l[u];    //u----v
            for(int v : neighbours) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        // cout<<endl;
    }

    void bfs() {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bfsHelper(i, visited);
                cout<<endl;
            }
        }
        cout<<endl;
    }

    void dfsHelper(int u, vector<bool> &visited) {  //TC = O(V + E)
        visited[u] = true;
        cout<<u<<" ";

        list<int> neighbours = l[u];
        for(int v : neighbours) {
            if(!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfsHelper(i, visited);
                cout<<endl;
            }
        }
        cout<<endl;
    }

    

};

int main() {
    Graph graph(10);

    graph.addEdge(0,2);
    graph.addEdge(2,5);
    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(3,8);
    graph.addEdge(4,3);
    graph.addEdge(3,7);

    graph.bfs();
    graph.dfs();


    return 0;
}