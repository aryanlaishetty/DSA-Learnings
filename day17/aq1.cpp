#include<iostream>
using namespace std;

bool check(int *nums, int n) {

    bool flag=0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i]==nums[j]) {
                flag=1;
                break;
            }
        }
    }

    return flag;

}

int main() {
    
    int nums1[]={1,2,3,4}, nums2[]={1,1,1,3,3,4,3,2,4,2}; 
    int n1=sizeof(nums1)/sizeof(int);
    int n2=sizeof(nums2)/sizeof(int);

    cout<<"For nums1 = "<<check(nums1, n1)<<endl;
    cout<<"For nums2 = "<<check(nums2, n2)<<endl;

    return 0;
}