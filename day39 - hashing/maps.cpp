#include<iostream>
#include<string>
#include<map>
using namespace std;


int main() {
    map<string, int> m;   //<key, map>

    //insertion
    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 20;
    m["UK"] = 30;
    cout<<"Insertion completed"<<endl;
    cout<<"---------"<<endl;

    //accessing and printing
    cout<<m["India"]<<endl;
    cout<<m["France"]<<endl;    //inserts France and assigns its value as 0
    cout<<"---------"<<endl;

    //print
    for(pair<string, int> country : m) {
        cout<<country.first<<", "<<country.second<<endl;    //<key, value>
    }
    cout<<"---------"<<endl;

    //isExists
    cout<<m.count("France")<<endl;
    cout<<m.count("Nepal")<<endl;
    cout<<m.count("Germany")<<endl;
    cout<<"---------"<<endl;

    //erase
    m.erase("China");
    cout<<"After erasing"<<endl;
    for(pair<string, int> country : m) {
        cout<<country.first<<", "<<country.second<<endl;    //<key, value>
    }
    cout<<"---------"<<endl;

    //override
    m["UK"] = 60;
    cout<<"After override"<<endl;
    for(pair<string, int> country : m) {
        cout<<country.first<<", "<<country.second<<endl;    //<key, value>
    }

    return 0;
}