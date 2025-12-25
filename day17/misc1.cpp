#include<iostream>
using namespace std;

int check(int *nums, int n) {

    bool flag=0;
    int x=0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            
            if(nums[i]==nums[j]) {
                flag=1;
                x++;
                break;
            }
        }
    }

    return x;

}

int main() {
    
    int nums1[]={1,2,3,4}, nums2[]={1,1,1,3,3,4,3,2,4,2}, nums3[] = {1,2,4,34,4546,23232,34}; 
    int n1=sizeof(nums1)/sizeof(int);
    int n2=sizeof(nums2)/sizeof(int);
    int n3=sizeof(nums3)/sizeof(int);

    cout<<"For nums1 = "<<check(nums1, n1)<<endl;
    cout<<"For nums2 = "<<check(nums2, n2)<<endl;
    cout<<"For nums3 = "<<check(nums3, n3)<<endl;


    return 0;
}