#include <iostream>
using namespace std;

bool isPal(int n, int st, int end) {         //Check if a number is palindrome or not 
    if(n / 10 == 0) {
        return true;
    }

    bool check = isPal(n, st+1, end-1);


}


int main() {

    cout<<isPal(1221, )<<endl;

    return 0;
}