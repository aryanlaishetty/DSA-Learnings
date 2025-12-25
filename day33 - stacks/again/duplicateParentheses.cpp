#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

        if(ch != ')') {
            s.push(ch);
        } else {
            if(s.top() == '(') {
                return true;
            }

            while(s.top() != '(') {
                s.pop();
            }
            s.pop();
        }
    }
    
    return false;
}

int main() {

    string str1 = "((a+b))";
    string str2 = "((a+b)+(c+d))";
    string str3 = "((x+y)+((z)))";

    cout<<isDuplicate(str1)<<endl;
    cout<<isDuplicate(str2)<<endl;
    cout<<isDuplicate(str3)<<endl;

    return 0;
}