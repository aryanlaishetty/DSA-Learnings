#include<iostream>
#include<queue>
using namespace std;

void interleave2queues(queue<int> &q) {
    int n = q.size();
    queue<int> firstHalf;

    for(int i=0; i<n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while(!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void printQ(queue<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main() {
    queue<int> q;

    for(int i=1; i<11; i++) {
        q.push(i);
    }

    printQ(q);
    interleave2queues(q);
    printQ(q);

    return 0;
}