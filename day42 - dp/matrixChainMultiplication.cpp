#include<iostream>
#include<vector>
#include <climits>
using namespace std;

//By Recursion
int mcmByRecursion(vector<int> arr, int i, int j) { //TC = O(2^n)
    if(i == j) {    //single matrix
        return 0;   //ops for multiplying single matrix is 0
    }

    int ans = INT16_MAX;

    for(int k=i; k<j; k++) {    //this loop will create partitions and divide matrices into two groups

        //first group - (i, k)
        int cost1 = mcmByRecursion(arr, i, k);
        
        //second group - (k+1, j)
        int cost2 = mcmByRecursion(arr, k+1, j);

        //current partition cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return ans;    
}


//By Memoization
int mcmByMemoization(vector<int> arr, int i, int j, vector<vector<int>> &dp) { //TC = O(n^3)
    if(i == j) {    //single matrix
        return 0;   //ops for multiplying single matrix is 0
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++) {    //this loop will create partitions and divide matrices into two groups

        //first group - (i, k)
        int cost1 = mcmByMemoization(arr, i, k, dp);
        
        //second group - (k+1, j)
        int cost2 = mcmByMemoization(arr, k+1, j, dp);

        //current partition cost
        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;    
}

//By tabulation
int mcmByTabulation(vector<int> arr) {  //TC = O(n^3)
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    //initialization for smallest problem i.e when i == j
    for(int i=1; i<n; i++) {
        dp[i][i] = 0;
    }

    //Botton Up fill 
    for(int len=2; len<n; len++) {  //we are filling the table w.r.t. length and for length = 1 we have already filled it (in initialization step)
        for(int i=1; i<=n-len; i++) { //start of the matrix chain
            int j = i+len-1;    //end of the matrix chain
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++) {    //this loop is to make partition 
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    return dp[1][n-1];  //when i=1, j=n-1 because this is the length of whole matrix chain and all matrices are multiplied 
}


int main() {

    vector<int> arr = {1,2,3,4,3};
    int n = arr.size();
    //array size = n, then no. of matrices = n-1 (1 to n-1)

    //By Recursion
    cout<<mcmByRecursion(arr, 1, n-1)<<endl;

    //By Memoization
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<mcmByMemoization(arr, 1, n-1, dp)<<endl;

    //By Tabulation
    cout<<mcmByTabulation(arr)<<endl;

    return 0;
}