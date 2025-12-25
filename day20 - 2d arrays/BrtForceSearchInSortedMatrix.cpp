#include<iostream>
using namespace std;

bool Search(int matrix[][4], int n, int m, int key) {

    int i, j, flag=0;

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(key==matrix[i][j]) {
                flag=1;
                break;
            } 
        }
        if(flag==1) {
            break;
        }
    }
    if(flag==1) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int matrix1[3][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12}};

    int matrix2[3][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}};
    
    cout<<Search(matrix1, 3, 4, 15)<<endl;

    // cout<<Search(matrix2, 3, 3, 9)<<endl;
    return 0;
}