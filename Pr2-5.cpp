/*
A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.
To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.
EMI = P * R * (1 + R)^T / ((1 + R)^T - 1)
As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed
to include a feature to display comprehensive loan details, including the calculated EMI, in a 
customerfriendly format. This functionality was intended to aid both customers and bank staff in managing
loan-related queries effectively.

loan management:
emi
loan summary()
emi()
loan id
name
total amount
interest rate
tenure(months)



correct and efficient code///
output formatting///
indentation///
naming///
comments///
*/


#include<iostream>
#include<math.h>
using namespace std;
    
class LoanMaster
{
    int LoanID, Time;//all time in months
    string Name;
    float Principle, IRate, EMI, Amount, Interest;
    
    void CalculateDetails() //utility method for calculations
    {
        float temp = (float)pow(1+IRate, Time);

        EMI = Principle*IRate*temp/(temp - 1);
        Amount = EMI*Time;
        Interest = Amount - Principle;
    }

    public:
    
    void AddData(string N = "Name", int ID = 0, float P = 0, float IR = 0, int T = 0)
    {
        Name = N;
        LoanID = ID;
        Principle = P;
        IRate = IR/100;
        Time = T;

        CalculateDetails(); //calling utility method from access method
    }

    void LoanSummary()
    {
        cout<<"\n\nLoan ID : "<<LoanID;
        cout<<"\nName : "<<Name;
        cout<<"\nPrinciple : "<<Principle;
        cout<<"\nInterest Rate (%) : "<<IRate*100;
        cout<<"\nTime (Months) : "<<Time;
        cout<<"\nEMI : "<<EMI;
        cout<<"\nTotal Interest : "<<Interest;
        cout<<"\nTotal Amount to Pay : "<<Amount;
    }
};
    
int main()
{
    LoanMaster Loan[20];
    
    int LoanID, Time, choice=0, Count=0;
    string Name;
    float Principle, IRate;

    do
    {
        cout<<"\n\nLoan Management System\nChoices:"; //choice based system
        cout<<"\n1. Add New Loan Details\n2. All Loans Summary\n0. Exit System\n\nEnter choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"\nEnter details for Loan "<<Count+1;
            cout<<"\nLoan ID : ";
            cin>>LoanID;
            cout<<"Name : ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Principle : ";
            cin>>Principle;
            cout<<"Interest Rate (%) : ";
            cin>>IRate;
            cout<<"Time (Months) : ";
            cin>>Time;
            Loan[Count].AddData(Name, LoanID, Principle, IRate, Time);
            cout<<"\nNew Loan Added!!";
            cout<<"\n\nLoan Details are:";
            Loan[Count].LoanSummary();
            Count++;
        }
        else if(choice==2){
            if(Count<1)
            cout<<"\nNO Loans in System!"; //error handling
            else
            {
                for(int i=0; i<Count;i++) //all loans summary
                {
                    cout<<"\nLoan "<<i+1<<" Details:";
                    Loan[i].LoanSummary();
                }
            }
        }
        else
        break;
    }while(choice==1||choice==2);
    cout<<"\nExiting System!";
    
    return 0;
}