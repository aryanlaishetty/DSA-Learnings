#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {   //opening ki condition
            s.push(ch);
        } else {    //closing

            if(s.empty()) { //insufficient opening brackets
                return false;
            }

            //match
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
    string str1 = "{[)]";
    string str2 = "{([]){}}";

    cout<<isValid(str1)<<endl;
    cout<<isValid(str2)<<endl;

    return 0;
}