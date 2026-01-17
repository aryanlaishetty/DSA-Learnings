#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, int m, int n, vector<vector<int>> &image, vector<vector<bool>> &visited, int newColor, int oldColor) {
    visited[row][col] = true;
    image[row][col] = newColor;

    //up
    if(row-1>=0 && !visited[row-1][col] && image[row-1][col] == oldColor)
        dfs(row-1, col, m, n, image, visited, newColor, oldColor);

    //down
    if(row+1<m && !visited[row+1][col] && image[row+1][col] == oldColor)
        dfs(row+1, col, m, n, image, visited, newColor, oldColor);
    
    //left
    if(col-1>=0 && !visited[row][col-1] && image[row][col-1] == oldColor)
        dfs(row, col-1, m, n, image, visited, newColor, oldColor);
    
    //right
    if(col+1<n && !visited[row][col+1] && image[row][col+1] == oldColor)
        dfs(row, col+1, m, n, image, visited, newColor, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();   //rows
    int n = image[0].size();    //cols

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    dfs(sr, sc, m, n, image, visited, color, image[sr][sc]);

    return image;
}

int main() {


    return 0;
}