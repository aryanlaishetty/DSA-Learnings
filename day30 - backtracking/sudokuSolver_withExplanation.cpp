#include<iostream>
#include<vector>
#include<string> // This is included but not used, kept for completeness

using namespace std;

// Function to print the 9x9 Sudoku board to the console
void printSudoku(vector<vector<int>> sudoku) {
    // Loop through each row of the board
    for(int i=0; i<sudoku.size(); i++) {
        // Loop through each column in the current row
        for(int j=0; j<sudoku.size(); j++) {
            // Print the number at (i, j), followed by a space
            cout<<sudoku[i][j]<<" ";
        }
        // Move to the next line after finishing a row
        cout<<endl;
    }
}

// Function to check if placing a 'digit' at (row, col) is valid
bool isSafe(vector<vector<int>> &sudoku, int row, int col, int digit) {
    
    // Check for conflicts in the current vertical column
    for(int i=0; i<=8; i++) {
        // If the digit is already present in this column, it's NOT safe
        if(sudoku[i][col] == digit) {
            return false;
        }
    }

    // Check for conflicts in the current horizontal row
    for(int j=0; j<=8; j++) {
        // If the digit is already present in this row, it's NOT safe
        if(sudoku[row][j] == digit) {
            return false;
        }
    }

    // --- Check for conflicts in the 3x3 subgrid (the box) ---

    // Calculate the starting row index (0, 3, or 6) of the current 3x3 box
    int startRow = (row/3)*3;
    // Calculate the starting column index (0, 3, or 6) of the current 3x3 box
    int startCol = (col/3)*3;

    // Loop through the 3 rows within the 3x3 box
    for(int i=startRow; i<=startRow+2; i++) {
        // Loop through the 3 columns within the 3x3 box
        for(int j=startCol; j<=startCol+2; j++) {
            // If the digit is already present in this 3x3 box, it's NOT safe
            if(sudoku[i][j] == digit) {
                return false;
            }
        }
    }

    // If no conflicts were found in the row, column, or 3x3 box, the move IS safe
    return true;
}

// The main recursive backtracking function to solve the puzzle
bool sudokuSolver(vector<vector<int>> &sudoku, int row, int col) {
    
    // Base Case 1: If we have successfully moved past the last row (row=8, now row=9), the Sudoku is solved
    if(row == 9) { 
        // Print the final solved board
        printSudoku(sudoku);
        // Return true to stop all recursion and signal success
        return true;
    }

    // Determine the coordinates of the next cell to process
    int nextRow = row;
    int nextCol = col + 1;

    // If the current column is the last one (col=8), wrap to the next row (row+1) and column 0
    if(col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // Base Case 2: If the current cell is already filled (not 0), skip it and move to the next cell
    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    // --- Backtracking Logic for Empty Cells (sudoku[row][col] == 0) ---

    // Try placing digits 1 through 9 in the empty cell
    for(int digit=1; digit<=9; digit++) {
        // Check if the current digit can be legally placed here
        if(isSafe(sudoku, row, col, digit)) {
            
            // 1. PLACE: Tentatively place the digit
            sudoku[row][col] = digit;
            
            // 2. RECURSE: Try to solve the rest of the board from the next cell
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                // If the recursive call returns true, it means a valid solution was found!
                return true;
            }
            
            // 3. BACKTRACK: If the solution failed down the line, undo the placement 
            //    (Reset the cell to 0) and try the next digit in the loop.
            sudoku[row][col] = 0; 
        }
    }

    // If the loop finishes without finding any safe digit that leads to a solution, 
    // this path is a dead end. Return false to backtrack to the previous cell.
    return false;
}

int main() {
    // Initial 9x9 Sudoku board setup (0 represents an empty cell)
    vector<vector<int>> sudoku = {{0,0,8,0,0,0,0,0,0},
                                  {4,9,0,1,5,7,0,0,2},
                                  {0,0,3,0,0,4,1,9,0},
                                  {1,8,5,0,6,0,0,2,0},
                                  {0,0,0,0,2,0,0,6,0},
                                  {9,6,0,4,0,5,3,0,0},
                                  {0,3,0,0,7,2,0,0,4},
                                  {0,4,9,0,3,0,0,5,7},
                                  {8,2,7,0,0,9,0,1,3}};

    // Start the solver from the top-left corner (0, 0)
    cout << sudokuSolver(sudoku, 0, 0) << endl; 

    return 0;
}