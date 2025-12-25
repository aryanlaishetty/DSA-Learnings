#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;


string removeDuplicates(string s) {
    stack<char> st;

    for(int i=0; i<s.size(); i++) {
        char ch = s[i];
        if(!st.empty() && st.top() == ch) { //stack has element and its top is same as curr char
            st.pop();
        } else {
            st.push(ch);
        }
    }

    string ans = "";

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main() {
    string s1 = "abbaca";
    string s2 = "azxxzy";
    string s3 = "cymueammmadhcwpvpf";   //cymuedhcwpvpf

    cout<<removeDuplicates(s1)<<endl;
    cout<<removeDuplicates(s2)<<endl;
    cout<<removeDuplicates(s3)<<endl;

    return 0;
}