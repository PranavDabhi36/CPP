/*
A growing organization sought to enhance its payroll process to improve accuracy
and efficiency in calculating employee salaries. The goal was to manage details 
such as the employee's Name, Basic salary, and Bonus amount. While most employees 
would receive a default Bonus, there was a need for flexibility to provide customized 
bonuses for exceptional performers or those in specialized roles. To ensure real-time 
computation of each employee's total salary, the system would dynamically calculate
the total salary by adding the Basic salary and the Bonus. An inline function was 
chosen for this task, allowing the system to compute the total salary instantly during 
processing. The system was designed to initialize employee records using a constructor, 
where the Bonus could either be set to a default value or adjusted according to specific 
employee criteria. As the organization expanded, managing employee records efficiently 
became a key consideration. The solution involved 
//storing employee details dynamically//, 
ensuring the system could handle a growing number of records while maintaining 
//scalability and flexibility//. 
Each employee record would include their personal details, Basic salary, and Bonus 
information, with the system displaying a breakdown of each employee’s details along 
with their total salary.

salary management:
personal details
salary - Basic, Bonus, total
default, parameterized constructor
inline calculateSalary()
custom Bonus feature
DisplayDetails()
??dynamic storage
*/

#include<iostream>
#include<vector>
using namespace std;
    
class EmployeeMaster
{   
    string Name;
    int Age;
    float BasicSalary, BonusAmount;

    inline float TotalSalary(){ //utility function
        return (BasicSalary + BonusAmount);
    }

public:

    EmployeeMaster(string N, int A, int Basic, int Bonus = 10000){
     //constructor with Bonus as default arguments
        Name = N;
        Age = A;
        this->BasicSalary = Basic; //this pointer to access class var
        this->BonusAmount = Bonus;
    }


    void DisplayDetails(){
        cout<<"\nName: "<<this->Name;
        cout<<"\nAge: "<<this->Age;
        cout<<"\nBasic Salary: "<<this->BasicSalary;
        cout<<"\nBonus Amount: "<<this->BonusAmount;
        cout<<"\nTotal Salary: "<<TotalSalary();
    }

public:
    
};
   
int main()
{
    vector<EmployeeMaster> Emp; //dynamic array to store multiple employees data
    char check='y';
    string Name;
    int Age; //temp variables
    float Basic;

    cout<<"\nEnter Employee details:";
    while(check=='y'||check=='Y'){
        cout<<"\nName: ";
        cin.ignore();
        getline(cin, Name);
        cout<<"Age: ";cin>>Age;
        cout<<"Basic Salary: ";cin>>Basic;
        cout<<"\nDo you want to enter custom Bonus? (Y/N): ";
        cin>>check;
        if(check=='y'||check=='Y'){
            float Bonus;
            cout<<"\nBonus Amount: ";cin>>Bonus;
            Emp.push_back(EmployeeMaster(Name, Age, Basic, Bonus)); //employee with custom Bonus
        }
        else
        Emp.push_back(EmployeeMaster(Name, Age, Basic)); //default bonus

        cout<<"\nDo you want to enter another employee? (Y/N): ";
        cin>>check;
    }

    int i=0;
    cout<<"\nTotal "<<Emp.size()<<" employees added! Displaying Details:";
    for (EmployeeMaster &E : Emp){ //for loop for vectors using reference variable
        cout<<"\n\nEmployee "<<++i;
        E.DisplayDetails(); 
    }    
    cout<<"\n\nEnd Of Program!\n";
    return 0;
}