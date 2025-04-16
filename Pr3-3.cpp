/*
A community bank sought to enhance its account management system with 
a digital solution to improve efficiency and provide better customer 
service. The system was required to manage the essential details of 
each account, including the account number, account holder’s name, 
and balance. Additionally, the bank wanted to provide a secure mechanism 
for transferring money between accounts, allowing customers to easily 
manage their funds.
The bank also needed a way to track the total number of accounts created, 
which would be important for generating reports and understanding the growth 
of their customer base. This feature was aimed at helping the bank maintain 
an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store 
account information in a way that would allow easy access and updates. 
When new accounts were created, they would be added to the system dynamically. 
The management team planned for future scalability and performance improvements 
by considering more efficient storage and retrieval methods after the initial 
system was built, ensuring that the bank could easily accommodate more 
accounts and transactions as the customer base grew.

bank acount manager
acc num
name
balance
transfer money between accounts
total num of accounts
??new accounts to be added dynamically//???vectors
??efficient storage and retrival//??files
*/

#include<iostream>
#include<vector>
using namespace std;
    
class AccountManager
{
    int AccNumber;
    string Name;
    float Balance;
    static int Count;

public:

    int returnAccNum(){
        return AccNumber;
    }
    //utility functions
    static int returnCount(){
        return Count;
    }
    
    AccountManager(int accn, string n, float b){
        AccNumber = accn; //constructor
        Name = n;
        Balance = b;
        Count++;
    }

    void Transfer(AccountManager &A, float b){ //passing reference variable to change both objects data
        Balance-=b; //current to A
        A.Balance+=b;
    }

    void DisplayDetails(){
        cout<<"\nName: "<<Name;
        cout<<"\nAccount Number: "<<AccNumber;
        cout<<"\nBalance: "<<Balance;
    }
};
    
int AccountManager::Count = 0; //initialising static variable outside class

int main()
{
    vector<AccountManager> A; //vector or dinamic array of accounts
    int choice=0;

    do{
        cout<<"\n\nBank Account Management System";
        cout<<"\nChoices:\n1.Add New Account\n2.Transfer Money to another acccount\n3.Display all accounts\n0.Exit system.\nEnter your choice: ";
        cin>>choice; //choice based system
        
        string Name;
        float Bal=0; //temporary variables
        int AccNum=1, MyAccNum=1, i, chk;


        switch(choice){
        case 1:
            cout<<"\nAdding New Account:";
            cout<<"\nEnter Name: ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Enter Balance: ";
            cin>>Bal;
            cout<<"Enter Account Number: ";
            cin>>AccNum;
            A.push_back(AccountManager(AccNum, Name, Bal)); //adding new account to dynamic array
            cout<<"Account added succesfully!!";
            break;

        case 2:
            cout<<"\nTransferring Money to another Account:";
            cout<<"\nEnter your Account Number:";
            cin>>MyAccNum;
            cout<<"Enter Account Number in which to transfer money:";
            cin>>AccNum;
            cout<<"Enter amount of money to transfer:";
            cin>>Bal;
            chk=0;
            for(AccountManager &c:A){
                if(c.returnAccNum()==MyAccNum){//searching for sender account
                    chk++; 
                    for(AccountManager &a:A){
                        if(a.returnAccNum()==AccNum){//searching for receiver account
                            chk++;
                            c.Transfer(a, Bal);
                            break;
                        }
                    }
                    break;
                }
            }
            if(chk==0){
                cout<<"\nNo such Account found!!\nTry again"; //edge cases handling
                break;
            }
            cout<<endl<<Bal<<" Rupees transferred succesfully!!";
            break;

        case 3:
            cout<<"\nDisplaying "<<AccountManager::returnCount()<<" accounts:"; //ststic function call using class & not obj
            i=1;
            for(AccountManager &a:A){  //for loop for vectors using reference variable
                cout<<"\n\nAccount "<<i;
                a.DisplayDetails();
                i++;
            }
            break;

        default:
            break;
        }
    }while(choice==1||choice==2||choice==3);
    cout<<"\n\nExiting System....";
    return 0;
}