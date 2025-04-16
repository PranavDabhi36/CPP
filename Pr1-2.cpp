/*
A small retail store is facing challenges in managing its inventory effectively. The store sells a
variety of Items, each identified by a unique Item ID, a name, the available quantity in
stock, and the Rate per unit. To streamline their operations, the store needs a basic system to
manage this inventory efficiently.
The system must provide the ability to add new Items to the inventory, ensuring that each
Item has its ID, name, quantity, and Rate properly recorded. Additionally, the system should
allow the store staff to update the quantity of any existing Item, such as when new stock
arrives or when items are sold.
Another essential feature of the system is the calculation of the total value of all Items in
the inventory, which is determined by multiplying the quantity of each Item by its Rate and
summing these values for all Items.
The store management is exploring two approaches for this system: a procedural approach and
an object-oriented approach. The goal is to evaluate these approaches by comparing their ease
of implementation, code reusability, and overall complexity.
The system's design and implementation should consider these requirements and provide an
effective solution (either procedural approach or an object-oriented approach) to the store's
inventory management problems.

Item id
prod name
quantity
Rate

main:
count
id
quantity
rate
name

add new prod()
update quantity of prod()
genBill()
*/

#include<iostream>
#include<iomanip>
using namespace std;

class Item
{
    int Quantity, ID;
    float Rate, Total;
    static float BillAmount; //class variables
    string Name;
    
public:

    int ReturnID()
    {return ID;}
    
    int ReturnTotal()
    {return Total;}

    void NewItem(string N, float R, int I)
    {
        Quantity = 1;
        Name = N;
        Rate = R;    //initialising variables of new object from user
        ID = I;  
        Total = (float)Rate;
    }

    void IncreaseItemQuantity()
    {
        Quantity++;
        Total = (float)(Rate*Quantity);
    }

    void friend GenerateBill(Item Item[], int Count);
};

float Item :: BillAmount = 0;

void GenerateBill(Item Item[], int Count)
{
    cout<<endl<<endl<<left<<setw(7)<<"ID";
    cout<<left<<setw(15)<<"Name";
    cout<<right<<setw(8)<<"Quantity";
    cout<<right<<setw(8)<<"Rate";
    cout<<right<<setw(8)<<"Total";

    for(int i=0; i<Count;i++)
    {
        cout<<fixed<<setprecision(0); //using manipulators to output formatted data
        cout<<endl<<left<<setw(7)<<Item[i].ID;
        cout<<left<<setw(15)<<Item[i].Name;
        cout<<fixed<<setprecision(2);  //friend function accessing object variables 
        cout<<right<<setw(8)<<Item[i].Quantity;  //from outside the object
        cout<<right<<setw(8)<<Item[i].Rate;
        cout<<right<<setw(8)<<Item[i].Total;
    }

    for(int i=0; i<Count;i++)
    Item::BillAmount+=(float)Item[i].Total;
    cout<<fixed<<setprecision(2);          //calculating total bill amount
    cout<<endl<<endl<<right<<setw(38)<<"TOTAL Price Amount:"<<right<<setw(8)<<Item::BillAmount<<endl<<endl;
}

int main()
{
    Item Item[10];
    int Count=0, Choice=1, ID, Quantity;
    string Name;  //temporary variables in main()
    float Rate;
    
    cout<<"\n\nAdd First Item:";
    do{
        int i=0;
        cout<<"\nItem ID: ";
        cin>>ID;
        
        for(i=0;i<Count;i++)
        {   
            if(Item[i].ReturnID()==ID) //searching based in item id
            {
                Item[i].IncreaseItemQuantity();  //if item already exists, quantity increased
                cout<<"\nItem Quantity Increased by 1!\n"; 
                break;
            }
        }
        if(i>=Count)
        {              //when item not found, new item created
            cout<<"Name: ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Rate: ";
            cin>>Rate;       
            Item[Count].NewItem(Name, Rate, ID);
            Count++;
            cout<<endl<<"New Item Added!";
        }
        
        cout<<"\n\nChoices:\n1.Add Item\n0.Generate Bill";
        cout<<"\n\nPlease Select your Choice: "; //choice based system
        cin>>Choice;

    }while(Choice==1);

    GenerateBill(Item, Count);

    return 0;
}