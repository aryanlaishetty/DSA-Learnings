#include<iostream>
#include<string>
#include<vector>

using namespace std;

int countSubStrs(string str, int i, int j, int n) {
    if(n==1) {
        return 1;
    }
    if(n<=0) {
        return 0;
    }

    int res = countSubStrs(str, i+1, j, n-1) + countSubStrs(str, i, j-1, n-1) - countSubStrs(str, i+1, j-1, n-2);

    if(str[i] == str[j]) {
        res++;
    }

    return res;

}

int main() {
    string str = "abcab";
    int n=str.size();

    cout<<countSubStrs(str, 0, n-1, n)<<endl;

    return 0;
}
