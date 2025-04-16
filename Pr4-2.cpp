/*
A growing organization wanted to develop a system to manage its hierarchy and 
represent its structure in a programmatic way. To achieve this, a multilevel 
approach was designed, reflecting the natural progression of roles within the 
organization. At the foundation, a class was created to represent a person, 
capturing the basic details such as name and age. Building on this, an 
intermediate level was introduced to represent employees, adding a unique 
identifier for each. Finally, at the topmost level, a class for managers was 
created, which included additional details such as the department they oversee.
The system needed to handle the initialization of all these attributes through 
constructors at each level, ensuring the proper propagation of information 
across the hierarchy. Additionally, the functionality to display details at 
every level was included to provide clear insights into the organization's 
structure. Two approaches were explored for managing multiple managers: one 
relied on an efficient method for retrieval and organization based on employee 
identifiers, while the other used a straightforward and static method for storage.
*/

#include<iostream>
#include<vector>
using namespace std;
 
class Person {
    string Name;
    int Age;
protected: //base variables protected for security

    Person(string n, int a) { //basse counstructor
        Name = n;
        Age = a;
    }

    void DisplayP() {
        cout<<"\nName: "<<Name;
        cout<<"\nAge: "<<Age;
    }
};

class Employee : private Person { //private inheritance for security
    float ID;
public:

    Employee(string n, int a, float id) : Person(n, a) {  //derived constructor
        ID = id;
    }

    void DisplayE() {
        DisplayP();
        cout<<"\nEmployee ID: "<<ID;
    }
};

class Manager : private Employee { //private inheritance for security
    string Department;
public:

    Manager(string n, int a, float id, string d) : Employee(n, a, id) { //grandchild clss constructor
        Department = d;
    }

    void DisplayM() {
        DisplayE();
        cout<<"\nDepartment: "<<Department;
    }
};

int main()
{
    vector<Manager> Mngr;
    vector<Employee> Emp;
    int Choice = 0, i = 0, age;
    float id; //temp variables
    string name, dept;

    do{
        cout<<"\n\nEmployee Record Management System\nChoices:-\n1. Enter New Employee\n2. Enter New Manager"
            <<"\n3. Display All Employees\n0. Exit System\n\nEnter your choice: "; //choice based system
        cin>>Choice;

        if(Choice==1){
            cout<<"\nEnter Employee Details:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Age: "; //input
            cin>>age;
            cout<<"Employee ID: ";
            cin>>id;

            Emp.push_back(Employee(name, age, id)); //new employee constructor called by vector
        }
        else if(Choice==2){
            cout<<"\nEnter Manager Details:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Age: ";
            cin>>age;
            cout<<"Employee ID: ";
            cin>>id;
            cout<<"Department: ";
            cin.ignore();
            getline(cin, dept);

            Mngr.push_back(Manager(name, age, id, dept));
        }
        else if(Choice==3){
            cout<<"\n\nDisplaying all Employees Details:-";
            for(Employee &E: Emp) { //for loop used for vectors
                cout<<"\n\nEmployee "<<++i;
                E.DisplayE();
            }
            i=0;
            cout<<"\n\nDisplaying all Managers Details:-";
            for(Manager &M: Mngr) {
                cout<<"\n\nManager "<<++i;
                M.DisplayM();
            }
        }
        else
        break;

    }while(Choice>0 && Choice<4);

    cout<<"\n\nExiting System....";
    
    return 0;
}