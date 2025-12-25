#include<iostream>
using namespace std;

int ndRowSum(int matrix[][3], int n, int m) {
    int sum = 0;

    for(int j=0, i=1; j<n; j++) {
        sum += matrix[i][j];        
    }
    return sum;
}

int main() {
    int nums[3][3] = {{1,4,9},
                      {11,4,3},
                      {2,2,3}};
    
    cout<<ndRowSum(nums, 3, 3)<<endl;
    return 0;
}