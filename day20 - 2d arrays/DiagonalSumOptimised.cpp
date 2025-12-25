#include<iostream>
using namespace std;

void DiagonalSum(int matrix[][3], int n) {

    int sum=0;
    
    for(int i=0; i<n; i++) {
        sum += matrix[i][i];
        if(i!=n-i-1) {
            sum += matrix[i][i];
        }
    }

    cout<<"sum = "<<sum<<endl;
}

int main() {

    int matrix1[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};

    int matrix2[3][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}};

    DiagonalSum(matrix2, 3);
    return 0;
}