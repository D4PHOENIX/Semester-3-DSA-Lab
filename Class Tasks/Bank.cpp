#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
const int size = 3;

struct Account{
    int accountNumber;
    string fullName;
    double balance;
    double amount;
};
Account customer[size];

void getDetails(){
    for(int i = 0; i < size; i++){
        cout<<"Enter Account Number: "; cin>>customer[i].accountNumber;
        cin.ignore();
        cout<<"Enter Full Name: "; getline(cin, customer[i].fullName);
        cout<<"Enter Balance: "; cin>>customer[i].balance;
    }
}
void printAccount(){
    int accNumber;
    cout<<"Enter Account Number: "; cin>>accNumber;
    for(int i = 0; i < size; i++){
        if (accNumber == customer[i].accountNumber)
        {
            cout<<"Account Number: "<<customer[i].accountNumber<<endl;
            cout<<"Full Name: "<<customer[i].fullName<<endl;
            cout<<"Balance: "<<customer[i].balance<<endl;
        }
        else{
            cout<<"Account Not Found"<<endl;
        }
    }
}
void depositCash(){
    int accNumber;
    cout<<"Enter Account Number: "; cin>>accNumber;
    for(int i = 0; i < size; i++){
        if (accNumber == customer[i].accountNumber)
        {
            cout<<"Enter amount to deposit: "; cin>>customer[i].amount;
            customer[i].balance += customer[i].amount;
            cout<<"Deposit Successful"<<endl;
        }
    }
        else{
            cout<<"Account Not Found"<<endl;
        }
}
void withdrawCash(){
    int accNumber;
    cout<<"Enter Account Number: "; cin>>accNumber;
    for(int i = 0; i < size; i++){
        if (accNumber == customer[i].accountNumber)
        {
            cout<<"Enter amount to withdraw: "; cin>>customer[i].amount;
            if (customer[i].amount > customer[i].balance)
            {
                cout<<"Insufficient Balance"<<endl;
                break;
            }
            else if (customer[i].amount <= customer[i].balance){
                customer[i].balance -= customer[i].amount;
                cout<<"Withdraw Successful"<<endl;
            }
        }
        else{
            cout<<"Account Not Found"<<endl;
        }
    }
}
void printAllAccounts(){
    for(int i = 0; i < size; i++){
        cout<<"Account Number: "<<customer[i].accountNumber<<endl;
        cout<<"Full Name: "<<customer[i].fullName<<endl;
        cout<<"Balance: "<<customer[i].balance<<endl;
        cout<<"\n\n";
    }
}
void back(){
    cout<<"\nPress any key to go back...\n";
    getch();
    system("CLS");
}

void mainScreen(){
    int option = 0;
    cout<<"Welcome to Ghost Bank"<<endl;
    cout<<"\n1. Create Account"<<endl; 
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Print Account"<<endl;
    cout<<"5. Print All Accounts"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"\nSelect an option: ";
    cin >> option;
    system("CLS");
    switch(option){
        case 1:
            getDetails();
            back();
            mainScreen();
            break;
        case 2:
            depositCash();
            back();
            mainScreen();
            break;
        case 3:
            withdrawCash();
            back();
            mainScreen();
            break;
        case 4:
            printAccount();
            back();
            mainScreen();
            break;
        case 5:
            printAllAccounts();
            back();
            mainScreen();
            break;
        case 6:
            exit(0);
            break;    
        default:
            cout<<"Invalid Option"<<endl;
    }
}

int main(){
    mainScreen();

return 0;
}