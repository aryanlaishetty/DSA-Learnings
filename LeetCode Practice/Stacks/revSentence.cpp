#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseWords(string s) {
    string temp = "";
    stack<string> st;
    
    for(int i=0; i<s.size(); i++) {
        
        if(s[i] != ' ') {   //not a space
            temp += s[i];
        } else {            //space
            if(temp.size() > 0) {   
                st.push(temp);
                temp = "";
            }
        }
    }
    
    if(temp.size() > 0) {   //when there is no space in after last word and temp hai the last word
        st.push(temp);
    }
    
    string ans = "";

    while(!st.empty()) {
        ans += st.top();
        st.pop();
        if(!st.empty()) {
            ans += " ";
        }
    }

    return ans;
}


int main() {
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";

    cout<<reverseWords(s1)<<endl;
    cout<<reverseWords(s2)<<endl;
    cout<<reverseWords(s3)<<endl;    
    
    return 0;
}