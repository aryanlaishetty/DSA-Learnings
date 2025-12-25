#include<iostream>
using namespace std;

void Print7s(int matrix[][3], int n, int m) {
    int count=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 7) {
                count++;
            }
        }
    }
    cout<<"Number of 7s in the matrix are = "<<count<<endl;
}

int main() {
    int matrix[2][3] = {{4,7,8},
                        {8,8,7}};

    Print7s(matrix, 2, 3);
    
    return 0;
}