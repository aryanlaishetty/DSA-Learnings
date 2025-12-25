#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printBoard(vector<vector<char>> board) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board.size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();
    
    //horizontal safety check
    for(int j=0; j<col; j++) {
        if(board[row][j] == 'Q') {
            return false;
        }
    }

    //vertical safety check
    for(int i=0; i<row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    //Left diagonal safety check
    for(int i=row, j=col; i>=0 && j>=0; i--,j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    //Right diagonal safety check
    for(int i=row, j=col; i>=0 && j<n; i--,j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

int nQueens(vector<vector<char>> board, int row) {
    int n = board.size();

    if(row == n) {
        printBoard(board);
        return 1;
    }

    int count = 0;

    for(int j=0; j<n; j++) {    //to access and assign Q to columns

        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';
            // count++;
        }
    }

    return count;
}


int main() {
    vector<vector<char>> board;
    int n = 4;

    for(int i=0; i<n; i++) {
        vector<char> newRow;
        for(int j=0; j<n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    cout<<"Total Number of solution for "<<n<<"x"<<n<<" board is: "<<nQueens(board, 0)<<endl;


    return 0;
}

