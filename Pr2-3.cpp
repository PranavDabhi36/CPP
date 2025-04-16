/*
In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer Accounts. The management envisioned a system where each
Account would store details about the Account holder, their unique Account number, and the current
Balance. To ensure flexibility and Accounturacy, they required functionalities for creating Accounts with
varying initial Balances, Depositing Money, Withdrawing funds (with checks for sufficient Balance), and
generating detailed Account summaries.
The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new Accounts could be created in two
ways: one with no initial Balance, and another with specified Account details and a starting Amount.
Additionally, they recognized the need for reliable mechanisms to handle Deposits and Withdrawals,
ensuring proper validation to prevent overdrafts. Displaying Account details in a clear format was also
prioritized for customer communication.
To ensure scalability, the team decided to simulate the system by creating multiple Accounts using the
proposed methods. They tested various scenarios, such as Depositing and Withdrawing Amounterent
Amounts, handling edge cases like insufficient funds, and verifying that the Account summaries were
Accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.

AccountNum
Name
Balance
CreateAccount(initialBalance) //with default parameters
Deposit()
Withdraw() //without overdraft
AccountSummary() //viewData() list of accounts and details
minimum balance only for Withdraw not create
account search
ERRORS - MIN BAL, NO ACCount FOUND

psuedocode per fn and class diagram
coding convention - spaces comments camelcase, even in class diagram
*/

#include<iostream>
using namespace std;

int AN = 69420;
    
class BankAccount
{
    int AccountNum;
    float Bal;
    string Name;       //class variables
    static int MinBal, Count;
    
public:

    int ReturnAccountNum()
    {return AccountNum;}
    
    int CreateAccount(string N = "Test", float B = 0)
    {
        Count++;
        Name = N;
        Bal = B;
        AccountNum = AN+Count;

        return AccountNum;
    }

    void Deposit(float B)
    {
        Bal+=B;
    }
    
    int Withdraw(float B)
    {
        if(Bal-B>=MinBal)
        { //check if withdrawal leaves minimum balance
            Bal-=B;
            return 0;
        }
        else
        return 1;
    }

    void AccountSummary()
    {
        cout<<"\nName: "<<Name;
        cout<<"\nAccount Number: "<<AccountNum;
        cout<<"\nCurrent Balance: "<<Bal;
    }
};

int BankAccount :: MinBal = 1000;
int BankAccount :: Count = 0;
    
int main()
{
    BankAccount Account[10];
    int Choice=0, Count=0, AccountNum=0;
    float Amount=0, Bal=0;
    string Name;
    
    do{
        int i=0;
        cout<<"\n\nChoices:\n1.Create Account\n2.Deposit Money\n3.Withdraw Money\n4.Accounts List\n0.Exit System";
        cout<<"\n\nPlease Select your Choice: ";
        cin>>Choice;
        
        switch (Choice)
        {
        case 1:
            cout<<"\nPlease enter your Details to Create New Account:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Initial Balance to Deposit: ";
            cin>>Bal;                                                          //input from user
            cout<<"\nYour New Account is Created!!\nYour Account Number is: "<<Account[Count].CreateAccount(Name, Bal);
            Count++;
            break;

        case 2:
            cout<<"\nEnter your Account number to Deposit Money: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {   
                if(Account[i].ReturnAccountNum()==AccountNum) //searching all acounts
                {
                    cout<<"\nEnter the Amount of Money you want to Deposit: ";
                    cin>>Amount;
                    Account[i].Deposit(Amount);
                    cout<<endl<<Amount<<" Rs. Deposited in Account Number "<<Account[i].ReturnAccountNum();
                    break;
                }
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break;
        
        case 3:
            cout<<"\nEnter your Account number to Withdraw Money: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {   
                if(Account[i].ReturnAccountNum()==AccountNum)
                {
                    cout<<"\nEnter the Amount of Money you want to Withdraw: ";
                    cin>>Amount;
                    if(Account[i].Withdraw(Amount))
                    cout<<"\nInvalid Amount! Please Withdraw such Amount as to leave your Account at Minimum Balance of Rs. 1000";
                    else
                    cout<<endl<<Amount<<" Rs. Withdrawn from Account Number "<<Account[i].ReturnAccountNum();
                    break;
                }
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break;
            
            case 4:
            for(i=0;i<Count;i++) //listing all accounts in system
            {
                cout<<"\nAccount Number "<<i+1<<endl;
                Account[i].AccountSummary();
            }
            break;
        
        default:
            break;
        }

    }while(Choice>=1&&Choice<=4);
    cout<<"\nExiting System....\n\n";

    return 0;
}