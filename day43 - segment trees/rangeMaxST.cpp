#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int> &nums, int start, int end, int node) {
        if(start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end-start) / 2;

        buildTree(nums, start, mid, 2*node+1);  //left
        buildTree(nums, mid+1, end, 2*node+2);  //right

        //bottom up fill
        tree[node] = max(tree[2*node+1], tree[2*node+2]); 
    }

    int maxQuery(int qi, int qj, int si, int sj, int node) {
        if(qj < si || qi > sj) {    //no overlap
            return INT_MIN;
        }

        if(qi >= si && qj <= sj) {  //complete overlap
            return tree[node];
        }

        //partial overlap
        int mid = si + (sj - si) / 2;

        int leftMax = maxQuery(qi, qj, si, mid, 2*node+1);  //left child
        int rightMax = maxQuery(qi, qj, mid+1, sj, 2*node+2);  //right child

        return max(leftMax, rightMax);
    }

    void updateUtil(int idx, int newVal, int start, int end, int node) {
        if(start == end) {
            tree[node] = newVal;
            return;
        }

        int mid = start + (end - start) / 2;

        if(idx >= start && idx <= mid) {    //search in left
            updateUtil(idx, newVal, start, mid, 2*node+1);  //left ki call
        } else {    //search in right
            updateUtil(idx, newVal, mid+1, end, 2*node+2);  //right ki call
        }

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

public:
    SegmentTree(vector<int> &nums) {
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, n-1, 0);
    }

    void printTree() {
        for(int el : tree) {
            cout<<el<<" ";
        }
        cout<<endl;
    }

    int rangeQuery(int qi, int qj) {
        return maxQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal) {
        return updateUtil(idx, newVal, 0, n-1, 0);
    }

};

int main() {
    //Range Max Queries
    vector<int> nums = {6,8,-1,2,17,1,3,2,4};

    SegmentTree st(nums);

    st.printTree();

    st.updateQuery(4, 0);
    cout<<st.rangeQuery(0, 8)<<endl;
    st.printTree();

    return 0;
}