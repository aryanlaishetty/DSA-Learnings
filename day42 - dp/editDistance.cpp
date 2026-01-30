#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode Q no. 72
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j<m+1; j++) {  //0th row initialize - insert 
        //when str1.length = 0 and str2.length = j then we have to perform insert operation j times to convert str1 to str2
        dp[0][j] = j;
    }

    for(int i=0; i<n+1; i++) {  //0th col initialize - delete
        //when str1.length = i and str2.length = 0 then we have to perform delete operation i times to convert str1 to str2
        dp[i][0] = i;
    }

    //bottom up fill
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = 0 + dp[i-1][j-1];    //0 represents no. of operations when char matches
            } else {
                                        //insert    delete      replace
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);  
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout<<minDistance(word1, word2)<<endl;
    
    word1 = "intention", word2 = "execution";
    cout<<minDistance(word1, word2)<<endl;

    return 0;
}