#include<iostream>
#include<deque>
using namespace std;

void printQ(deque<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}

int main() {
    deque<int> q;

    q.push_back(2);     //2
    printQ(q);
    q.push_front(1);    //1 2 
    printQ(q);
    q.push_back(3);     //1 2 3
    printQ(q);
    q.push_front(-1);   //-1 1 2 3
    printQ(q);
    q.front();          //-1
    printQ(q);
    q.back();           //3
    printQ(q);
    
    q.pop_front();      //-1    q: 1 2 3
    printQ(q);
    q.pop_back();       //3     q: 1 2
    printQ(q);
    
    return 0;
}