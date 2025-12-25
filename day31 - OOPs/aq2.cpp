#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    int accNum;
    int balance = 0;

public:

    BankAccount(int accNum, int balance) {  //constructor
        this->accNum = accNum;
        this->balance = balance;
    } 
    
    void deposit(int money) {   //setter
        cout<<"Rs "<<money<<" deposited"<<endl;
        balance += money;
    }

    void withdraw(int money) {  
        if(balance == 0) {
            cout<<"Insufficient balance"<<endl;
        } else {
            cout<<"Rs "<<money<<" withdrawed"<<endl;
            balance -= money;
        }
    }

    int getBalance() {  //getter
        cout<<"Current balance: "<<balance<<endl;;
        return balance; 
    } 

};

int main() {
    BankAccount acc1(123456, 500);

    acc1.deposit(20);   //20
    acc1.getBalance();  //20
    acc1.deposit(100);  //100
    acc1.getBalance();  //120
    acc1.withdraw(80);  //80
    acc1.getBalance();  //40

    return 0;
}