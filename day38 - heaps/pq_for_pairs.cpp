#include<iostream>
#include<queue>
using namespace std;

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second > p2.second;
    }
};

int main() {
    priority_queue<pair<string, int>> pq;   //by default it compares with first element of pairs

    pq.push(make_pair("A", 1000));
    pq.push(make_pair("B", 2000));
    pq.push(make_pair("C", 3000));
    pq.push(make_pair("D", 4000));

    while(!pq.empty()) {
        cout<<pq.top().first<<endl;
        pq.pop();
    }

    cout<<"----------"<<endl;

    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq2;

    pq2.push(make_pair("A", 1000));
    pq2.push(make_pair("B", 2000));
    pq2.push(make_pair("C", 3000));
    pq2.push(make_pair("D", 4000));

    while(!pq2.empty()) {
        cout<<pq2.top().first<<endl;
        pq2.pop();
    }

    return 0;
}