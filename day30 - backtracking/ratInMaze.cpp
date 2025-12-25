#include<iostream>
#include<vector>
#include<string>

using namespace std;

int ratInMaze(vector<vector<int>> maze, int row, int col, string ans) {
    int n = maze.size();

    if(maze[row][col] == 0) {
        return 0;
    }

    if(row == n-1 && col == n-1) {
        cout<<ans<<endl;
        return 1;
    }

    if(row >= 0 || col >= 0) {
        return 0;
    }

    int ways1 = ratInMaze(maze, row-1, col, ans+"U"); //UP
    int ways2 = ratInMaze(maze, row+1, col, ans+"D"); //DOWN
    int ways3 = ratInMaze(maze, row, col-1, ans+"L"); //LEFT
    int ways4 = ratInMaze(maze, row, col+1, ans+"R"); //RIGHT
    

    int totalWays = ways1 + ways2 + ways3 + ways4;
    
    return totalWays;
    
}

int main() {
    vector<vector<int>> maze = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};

    string ans="";

    cout<<ratInMaze(maze, 0, 0, ans);

    return 0;
}