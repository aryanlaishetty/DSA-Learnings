#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pqMax;  //by default greatest element is on the top

    pqMax.push(5);
    pqMax.push(10);
    pqMax.push(1);
    pqMax.push(7);
    pqMax.push(2);
    pqMax.push(9);

    cout<<"Top = "<<pqMax.top()<<endl;
    
    while(!pqMax.empty()) {
        cout<<"Top = "<<pqMax.top()<<endl;
        pqMax.pop();
    }

    cout<<"-----------"<<endl;

    priority_queue<int, vector<int>, greater<int>> pqMin;  //explicitly changes are made so that top is always smallest

    pqMin.push(5);
    pqMin.push(10);
    pqMin.push(1);
    pqMin.push(7);
    pqMin.push(2);
    pqMin.push(9);

    cout<<"Top = "<<pqMin.top()<<endl;
    
    while(!pqMin.empty()) {
        cout<<"Top = "<<pqMin.top()<<endl;
        pqMin.pop();
    }


    return 0;
}