#include <iostream>
using namespace std;

int main() {

    int n, ans=1, i;

    cout<<"Enter number : ";
    cin>>n;

    for(i=1; i<=n; i++) {
        ans=ans*i;
    }

    cout<<"n! = "<<ans<<endl;

    return 0;
}