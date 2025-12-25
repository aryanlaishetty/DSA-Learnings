#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    for(int i=0; i<n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    }); //descending order on the basis of profit

    cout<<"Selecting Job "<<jobs[0].idx<<endl;
    int maxProfit = jobs[0].profit;
    int safeDeadline = 2;
    
    for(int i=0; i<n; i++) {
        if(jobs[i].deadline >= safeDeadline) {
            cout<<"Selecting Job "<<jobs[i].idx<<endl;
            maxProfit += jobs[i].profit;
            safeDeadline++;
        }
    }
    return maxProfit;
}

int main() {
    vector<pair<int, int>> jobs(4, make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    cout<<maxProfit(jobs)<<endl;

    return 0;
}