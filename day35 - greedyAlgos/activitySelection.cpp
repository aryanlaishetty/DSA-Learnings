#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maxActivitySelection(vector<int> start, vector<int> end) {
    int n = start.size();
    
    vector<pair<int, int>> both(n, make_pair(0,0));

    for(int i=0; i<n; i++) {
        both[i] = make_pair(start[i], end[i]);
    }

    sort(both.begin(), both.end(), compare);
    
    for(int i=0; i<both.size(); i++) {
        cout<<both[i].first<<","<<both[i].second<<endl;
    }

    int count = 1;
    int currEndTime = both[0].second;

    for(int i=1; i<n; i++) {
        if(both[i].first >= currEndTime) {
            count++;
            currEndTime = both[i].second;
        }
    }

    cout<<"Maximum Number of Activities can be selected: "<<count<<endl;
    return count;
}

int main() {
    vector<int> start1 = {1,3,0,5,8,5};
    vector<int> end1 = {2,4,6,7,9,9};

    vector<int> start2 = {1,3,2,5};
    vector<int> end2 = {2,4,3,6};

    maxActivitySelection(start2, end2);

    return 0;
}