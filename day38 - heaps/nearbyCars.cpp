#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<cmath>
using namespace std;

class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Car &obj) const {
        return this->distSq > obj.distSq;   //minHeap
    }
};

void nearbyCars(vector<pair<int, int>> pos, int K) {    //O(k*log n)
    vector<Car> cars;

    for(int i=0; i<pos.size(); i++) {   //O(n)
        int distSq = (pos[i].first*pos[i].first) + (pos[i].second*pos[i].second);   //x^2 + y^2
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());   //O(n), directly assigned

    for(int i=0; i<K; i++) {    //O(K*log n + n)
        cout<<"Car "<<pq.top().idx<<" with dist "<<sqrt(pq.top().distSq)<<endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int K = 2;

    nearbyCars(pos, K);

    return 0;
}