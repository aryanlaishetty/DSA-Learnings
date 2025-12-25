#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

void pushAtBottom(stack<int> &s, int val) {
    if(s.empty()) {
        s.push(val);
        return; 
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

string revStr(string str) {
    string ans;
    stack<char> s;

    for(int i=0; i<str.size(); i++) {
        s.push(str[i]);
    }

    while(!s.empty()) {
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

void revStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();
    revStack(s);
    pushAtBottom(s, temp);
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);

    revStack(s);
    printStack(s);

    // cout<<revStr("abcd")<<endl;

    return 0;
}