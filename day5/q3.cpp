#include <iostream>
using namespace std;

int main() {

    int num, ans=0, d1, temp;
    
    cout<<"Enter number : ";
    cin>>num;

    temp=num;

    // for(int i=1; i<; i++){
    //     d1 = num%10;
    //     ans = ans + d1*d1*d1;
    //     num = num/10;
    // }

    while (num>0) {
        d1 = num%10;
        ans = ans + d1*d1*d1;
        num = num/10;
    }

    if(ans==temp) {
        cout<<temp<<" is Armstrong number"<<endl;
    }
    else {
        cout<<temp<<" is not an Armstrong number"<<endl;
    }

    return 0;
}