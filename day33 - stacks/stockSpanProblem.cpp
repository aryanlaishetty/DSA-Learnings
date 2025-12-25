#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpanProblem(vector<int> stock) {
    int n = stock.size();
    vector<int> span(n);
    stack<int> s;   //stores indexs of prev high from stock arr
    s.push(0);
    span[0] = 1;

    for(int i=1; i<n; i++) {
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            span[i] = i+1;
        } else {
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }
        s.push(i);
    }

    for(int i=0; i<n; i++) {
        cout<<span[i]<<" ";
    }
    cout<<endl;

}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> stock2 = {100, 80, 60, 70, 60, 75, 85};

    stockSpanProblem(stock); 

    return 0;
}