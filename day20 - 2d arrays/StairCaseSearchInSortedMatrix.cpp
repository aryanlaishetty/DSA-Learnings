#include<iostream>
using namespace std;

bool StairSearch(int matrix[][4], int n, int m, int key) {
    int i=0, j=m-1;

    while(i<n && j>=0) {
        if (matrix[i][j] == key) {
            cout<<"Key is at ("<<i<<","<<j<<")"<<endl;
            return true;
        } else if (matrix[i][j] > key) {
            j--;
        } else {
            i++;
        }
    }

    cout<<"Key not found"<<endl;
    return false;
}

int main() {
    
    int matrix1[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};

    int matrix2[3][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}};
    
    cout<<StairSearch(matrix1, 3, 4, 10)<<endl;
    return 0;
}