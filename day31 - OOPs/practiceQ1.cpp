#include<iostream>
#include<string>

using namespace std;

class User{
    int id;
    string password;

public:
    string username;

    User(int id) {  //parameterised constructor
        this->id = id;
    }

    void setPassword(string password) {  //setter
        this->password = password;
    }

    // void setPassword(string passwordVal) {  //setter - this is also correct
    //     password = passwordVal;
    // }

    string getPassword() {  //getter
        return password;
    }

};

int main() {
    User user1(4001);
    user1.username = "aryan_laishetty";
    user1.setPassword("abCD@0258");
    
    cout<<"username : "<< user1.username <<endl;
    cout<<"password : "<< user1.getPassword() <<endl;

    return 0;
}