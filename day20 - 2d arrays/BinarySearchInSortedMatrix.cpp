#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key) {
    int st=0, end=n-1, flag=0;
    
    while(st<end) {
        int mid=(st+end)/2;
        if(key==arr[mid]) {
            return mid;
            flag=1;
        } else if (key>arr[mid]) {
            st=mid+1;
        } else {
            end=mid-1;
        }
    }
    
}

bool Search(int matrix[][4], int n, int key) {

    int i, j, flag=0, st=0, end=n-1;

    for(i=0; i<n; i++) {
        BinarySearch(matrix[4], n, key);
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

    int matrix1[4][4] = {{1,2,3,4},
                         {5,6,7,8},
                         {9,10,11,12},
                         {13,14,15,16}};

    int matrix2[3][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}};
    
    cout<<Search(matrix1, 4, 6)<<endl;

    // cout<<Search(matrix2, 3, 3, 9)<<endl;
    return 0;
}