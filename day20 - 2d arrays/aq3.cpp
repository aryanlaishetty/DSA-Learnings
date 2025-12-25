#include<iostream>
using namespace std;

void Transpose(int matrix[][3], int n, int m) {
    
    int Transpose[3][2] = {{0}};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            Transpose[j][i] += matrix[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout<<Transpose[i][j]<<", ";
        }
        cout<<endl;
    }
}

int main() {
    int matA[2][3] = {{1,2,3},
                      {4,5,6}};
                    
    Transpose(matA, 2, 3);

    return 0;
}