#include<iostream>
#include<list>  //includes prebuilt Standard Template Library lists 
#include<iterator>  //Pointer used to traverse through different data structures
using namespace std;

void printLL(list<int> ll) {
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++) {
        cout<< (*itr) <<" -> ";
    }
    cout<<"NULL"<<endl;
}

int main() {
    list<int> ll;   //initialized Linked List (similar to vector initialization)
    list<int> ll2 = {1,2,3,4};
    printLL(ll2);


    ll.push_front(2);
    ll.push_front(1);
    printLL(ll);    

    ll.push_back(3);
    ll.push_back(4);
    printLL(ll);

    cout<<"LL Size = "<<ll.size()<<endl;

    ll.pop_front();
    printLL(ll);

    ll.pop_back();
    printLL(ll);

    cout<<"Head = "<<ll.front()<<endl;
    cout<<"Tail = "<<ll.back()<<endl;

    auto itr2 = ll.begin(); //auto - detects type directly
    advance(itr2, 2);   //advance(iterator, nSteps) - iterator moves n steps forward

    ll.insert(itr2, 5); //insert(position, val) - insert 5 at pos = 2 (itr2=2)
    printLL(ll);

    auto itr3 = ll.begin();

    ll.insert(itr3, 3, 99); //insert(position, countOfInsertion, value) - inserts 99 three times at itr2 position
    printLL(ll);

    return 0;
}