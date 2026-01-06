#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec;    //CBT

    void heapify(int i) {   //i = parent index  //TC=O(log n)
        if(i > vec.size()) {
            return;
        }

        int l = 2*i+1;
        int r = 2*i+2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }

        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i) {   //swapping with child node
            heapify(maxIdx);
        }
    }

public:

    void push(int val) {    //O(log n)
        //step1
        vec.push_back(val); //TC=O(1)

        //step2 - fix heap
        int childIdx = vec.size()-1;    //last element of vec is child
        int parentIdx = (childIdx-1)/2;

        while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]) {   //maxHeap (child<parent)    TC=O(log n)
            swap(vec[childIdx], vec[parentIdx]);
            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }

    void pop() {
        //step1
        swap(vec[0], vec[vec.size()-1]);    //TC=O(1)

        //step2
        vec.pop_back();     //TC=O(1)

        //step3
        heapify(0);     //TC=O(log n)
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }


};

int main() {
    Heap h1;

    h1.push(10);
    h1.push(20);
    h1.push(5);
    h1.push(1);
    h1.push(100);

    cout<<"Top = "<<h1.top()<<endl;  //100
    
    while(!h1.empty()) {
        cout<<"Top = "<<h1.top()<<endl;  //100
        h1.pop();
    }


    return 0;
}