#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void firstNonRepeatingChar(string str) {
    queue<char> q;
    int freq[26] = {0};

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front() - 'a']>1) {
            q.pop();
        }

        if(q.empty()) {
            cout<<"-1"<<" ";
        } else {
            cout<<q.front()<<" ";
        }
    }
    cout<<endl;
}

int main() {
    string str = "aabccxb";

    firstNonRepeatingChar(str);

    return 0;
}