#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {
    int V;  //size - total number of vertices
    list<pair<int, int>> * l;   //<neighbor, wt>
    bool undirected;
public:
    Graph(int V, bool undirected=true) {
        this->V = V;
        l = new list<pair<int, int>> [V];
        this->undirected = undirected;
    }

    void addEdge(int u, int v, int wt) {    //u and v are connected nodes (u--v) and wt associated with edvge u---v
        l[u].push_back(make_pair(v, wt));
        if(undirected) {
            l[v].push_back(make_pair(u, wt));
        }
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //min heap ; <wt, v>   
        vector<bool> mstSet(V, false);

        pq.push(make_pair(0, src));
        int finalCost = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mstSet[u]) {
                mstSet[u] = true;
                finalCost += wt;

                list<pair<int, int>> neighbors = l[u];
                for(pair<int, int> n : neighbors) {
                    int v = n.first;    //graph (list) mai access karte time <v, wt> default order
                    int currWt = n.second;

                    pq.push(make_pair(currWt, v));  //pq mai push karte time <wt, v> kyuki wt ke bases pe minHeap banana hai 
                }
            }
        }

        cout<<"Final cost of MST = "<<finalCost<<endl;
    }

    

    

    

};

int main() {
    //Prim's Algorithm
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);

    graph.addEdge(1,3,40);
    
    graph.addEdge(2,3,50);

    graph.primsAlgo(0);

    return 0;
}