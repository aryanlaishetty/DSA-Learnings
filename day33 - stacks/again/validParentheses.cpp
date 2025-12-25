#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;
    
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            
            if(s.empty()) {
                return false;
            }

            char top = s.top();
            if((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([])";
    string s5 = "([)]";
    string s6 = "[";

    cout<<isValid(s1)<<endl;
    cout<<isValid(s2)<<endl;
    cout<<isValid(s3)<<endl;
    cout<<isValid(s4)<<endl;
    cout<<isValid(s5)<<endl;
    cout<<isValid(s6)<<endl;

    return 0;
}