/*
A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods.


deposit()
withdraw()
balance()

name
acc num
balance
*/

#include<iostream>
using namespace std;

class BankAccount
{
    int AccountNum;
    float Bal;     //class variables
    string Name;
    
public:

    int ReturnAccountNum()
    {return AccountNum;}
    
    void CreateAccount(string N, int AN)
    {
        Name = N;
        Bal = 0;        //initialising variables of new object from user
        AccountNum = AN;
    }

    void Deposit(float B)
    {
        Bal+=B;
    }
    
    int Withdraw(float B)
    {
        if(Bal>=B)   //check to avoid negative balance
        {            
            Bal-=B;
            return 0;
        }
        else
        return 1;
    }

    void ViewBalance()
    {
        cout<<"\nCurrent Balance in your Account: "<<Bal;
    }
};
    
int main()
{
    BankAccount Account[10];
    int Choice=0, Count=0, AccountNum=0;
    float Amount=0, Bal=0;              //temporary variables in main()
    string Name;
    
    do{
        int i=0;
        cout<<"\n\nChoices:\n1.Create Account\n2.Deposit Money\n3.Withdraw Money\n4.Check Balance\n0.Exit System";
        cout<<"\n\nPlease Select your Choice: "; //choice based system
        cin>>Choice;
        
        switch (Choice)
        {
        case 1:
            cout<<"\nPlease enter your Details to Create New Account:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Account Number: ";
            cin>>AccountNum; //initialising details from user
            Account[Count].CreateAccount(Name, AccountNum);
            cout<<"\nYour New Account is Created!!";
            Count++;  //counter
            break;

        case 2:
            cout<<"\nEnter your Account number to Deposit Money: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {   
                if(Account[i].ReturnAccountNum()==AccountNum) //searching account based on acc num
                {
                    cout<<"\nEnter the Amount of Money you want to Deposit: ";
                    cin>>Amount;
                    Account[i].Deposit(Amount);
                    cout<<endl<<Amount<<" Rs. Deposited in Account Number "<<Account[i].ReturnAccountNum();
                    Account[i].ViewBalance();
                    break;
                }
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break; //when account not found
        
        case 3:
            cout<<"\nEnter your Account number to Withdraw Money: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {   
                if(Account[i].ReturnAccountNum()==AccountNum)
                { //searching account based on account number
                    cout<<"\nEnter the Amount of Money you want to Withdraw: ";
                    cin>>Amount;
                    if(Account[i].Withdraw(Amount))
                    cout<<"\nInvalid Amount! Please Withdraw Amount less than or equal to your Account Balannce";
                    else
                    cout<<endl<<Amount<<" Rs. Withdrawn from Account Number "<<Account[i].ReturnAccountNum();
                    Account[i].ViewBalance();
                    break;
                }
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break; //handling edge cases
            
        case 4:
            cout<<"\nEnter your Account number to see Balance: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {   
                if(Account[i].ReturnAccountNum()==AccountNum)
                Account[i].ViewBalance();
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break;
        
        default:
            break;
        }

    }while(Choice>=1&&Choice<=4);
    cout<<"\nExiting System....\n\n";

    return 0;
}