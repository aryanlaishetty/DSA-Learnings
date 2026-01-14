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

    void calcIndegree(vector<int> &indegree) {
        for(int u=0; u<V; u++) {
            list<int> neighbors = l[u];
            for(int v : neighbors) {
                indegree[v]++;
            }
        }
    }

    void topologicalSort() {    //Kahn's Algorithm
        vector<int> indegree(V, 0);
        calcIndegree(indegree);

        queue<int> q;

        //0 indegree nodes = starting point
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> neighbors = l[curr];
            for(int v : neighbors) {
                indegree[v]--;
                if(indegree[v] == 0) {  //no pending dependancies
                    q.push(v);
                }
            }
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