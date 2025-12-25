#include<iostream>
#include<vector>

using namespace std;

int gridWays(int row, int col, int n, int m, string ans) {  //row & col = initial || n & m = destination  || ans = directions

    if(row == n-1 && col == m-1) {  //destination reached so base case hit
        cout<<ans<<endl;
        return 1;
    }

    if(row>=n || col>=m) {  //returns 0 if control exceeds range
        return 0;
    }

    int ways1 = gridWays(row, col+1, n, m, ans+"R"); // right ki turn lelo 
    int ways2 = gridWays(row+1, col, n, m, ans+"D"); // down ki turn lelo

    return ways1+ways2;
}

int main() {

    int n=3, m=3;
    string ans = "";

    cout<<gridWays(0, 0, n, m, ans)<<endl;

    return 0;
}