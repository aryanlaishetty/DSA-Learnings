#include<iostream>
#include<set>
#include<string>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(3);

    cout<<s.size()<<endl;
    
    s.insert(1);
    s.insert(1);
    
    cout<<s.size()<<endl;

    for(auto el : s) {
        cout<<el<<" ";
    }
    cout<<endl;

    if(s.find(5) != s.end()) {  //s.end() returns NULL pointer
        cout<<"5 exists"<<endl; //1 != NULL
    } else {
        cout<<"5 doesn't exists"<<endl; //0 == NULL
    }

    s.erase(2);
     
    cout<<s.size()<<endl;

    for(auto el : s) {
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}