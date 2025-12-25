#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int n = heights.size();

    vector<int> nsl(n);
    vector<int> nsr(n);

    //to fill nsl
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<n; i++) {    
        int curr = heights[i];

        while(!s.empty() && curr <= heights[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()) {     
        s.pop();
    } 

    //to fill nsr
    nsr[n-1] = n;
    s.push(n);
    for(int i=n-1; i>=0; i--) {
        int curr = heights[i];

        while(!s.empty() && curr <= heights[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = 0;
    for(int i=0; i<n; i++) {
        int r = nsr[i];
        int l = nsl[i];

        int width = r-l-1;
        int area = heights[i] * width;

        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}


int main() {
    vector<int> h1 = {2,1,5,6,2,3};
    vector<int> h2 = {2,4};

    cout<<largestRectangleArea(h1)<<endl;
    cout<<largestRectangleArea(h2)<<endl;

    return 0;
}