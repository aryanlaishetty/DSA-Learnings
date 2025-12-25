#include <iostream>
#include <string>

using namespace std;

void subsets(string str, string subset) {

    if(str.size() == 0) {
        cout<<subset<<endl;
        return;
    }

    char ch = str[0];

    subsets(str.substr(1, str.size()-1), subset+ch);    //yes - add ch to substring

    subsets(str.substr(1, str.size()-1), subset);   //no - do not add ch to substring
}

int main() {

    string str = "abc", subset = "";

    subsets(str, subset);

    return 0;
}