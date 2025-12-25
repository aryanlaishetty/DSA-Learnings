#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string str, string ans, int index, int map[26]) {
    if(index == str.size()) {
        cout<<"ans: "<<ans<<endl;
        return;
    }

    int mapIndex = (int)(str[index] - 'a');

    if(map[mapIndex]) {    //duplicate
        removeDuplicates(str, ans, index+1, map);
    } else {        //not duplicate
        map[mapIndex] = true;
        removeDuplicates(str, ans+str[index], index+1, map);
    }
}

void remDups(string str, string ans, int i, int map[26]) {
    if(i==str.size()) {
        cout<<"ans :"<<ans<<endl;
        return;
    }

    int mapIndex = (int)(str[i] - 'a');
    if(map[mapIndex]) {
        remDups(str, ans, i+1, map);
    } else {
        map[mapIndex] = true;
        remDups(str, ans+str[i], i+1, map);
    }
}


int main() {

    string str = "aryanlaishetty";
    string ans = "";
    int map[26] = {false};
    
    remDups(str, ans, 0, map);

    return 0;
}