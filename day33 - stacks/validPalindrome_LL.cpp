#include<iostream>
#include<list>
#include<stack>
using namespace std;

bool isPalindrome(list<int>& ll) {
    stack<int> s;
    
    for(int val : ll) {
        s.push(val);
    }

    for(int val : ll) {
        if(s.top() != val) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    list<int> ll1 = {1,2,2,1};
    list<int> ll2 = {1,2};

    cout<<isPalindrome(ll1)<<endl;
    cout<<isPalindrome(ll2)<<endl;
}