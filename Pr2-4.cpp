/*
A mID-sized retail store faced challenges in efficiently managing its inventory of Items. The store's
management sought to build a system that could keep track of indivIDual Items, including Details like
a unique Item ID, Item Name, Price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To Orderress this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of Item Details, either with default values or
specific attributes like ID, Name, Price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when Items were sold,
ensuring sufficient inventory was available for each transaction. Orderitionally, the system would
provIDe clear, detailed summaries of each Item's status, aIDing in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory Items
simultaneously. They planned to design an array of inventory Items and simulate common tasks such
as Ordering stock, processing sales transactions, and displaying the current inventory Details. Handling
edge cases, such as attempting to sell more Items than available in stock, became a critical part of the
implementation to ensure reliability.

indivIDual Items in a store: //array
ID       }
Name     }
Price    } default or custom
quantity }

newShipment()
nItemsSold() //no oversell
ItemStatus()
*/

#include<iostream>
using namespace std;

int IID = 420;
    
class ItemData
{
    int Quantity, ID;
    float Price;
    string Name;     //object variables
    static int Count;
    
public:

    int ReturnID()
    {return ID;}
    
    int NewItem(string N = "Test", float P = 0, int Q = 0)
    {
        Count++;
        Name = N;
        Price = P; 
        Quantity = Q;  //input from user
        ID = IID+Count;

        return ID;
    }

    void OrderItem(int Q)
    {
        Quantity+=Q;
    }
    
    int SellItem(int Q)
    {
        if(Quantity>=Q) //check if enough stock to sell
        {
            Quantity-=Q;
            return 0;
        }
        else
        return 1;
    }

    void ItemsSummary()
    {
        cout<<"\n\nID: "<<ID;
        cout<<"\nName: "<<Name;
        cout<<"\nPrice: "<<Price;
        cout<<"\nCurrent Quantity: "<<Quantity;
    }
};

int ItemData :: Count = 0;
    
int main()
{
    ItemData Item[10];
    int Choice=0;
    int Count=0;
    float Qtny=0;
    string Name;
    float Price=0;
    int ID=0, Quantity = 0;
    
    do{
        int i=0;
        cout<<"\n\nChoices:\n1.Order New Item\n2.Order More Stock\n3.Sell Stock\n4.Inventory Summary\n0.Exit System";
        cout<<"\n\nPlease Select your Choice: ";
        cin>>Choice;
        
        switch (Choice)
        {
        case 1:
            cout<<"\nPlease enter Item Details to Order it:";
            cout<<"\nName: ";
            cin.ignore();  //to ignore '\n' before input
            getline(cin, Name);
            cout<<"Initial Quantity: ";
            cin>>Quantity;
            cout<<"Price: ";
            cin>>Price;
            cout<<"\nNew Item Ordered!!\nItem ID is: "<<Item[Count].NewItem(Name, Price, Quantity);
            Count++;
            break;

        case 2:
            cout<<"\nEnter Item ID of which to order more stock: ";
            cin>>ID;
            for(i=0;i<Count;i++)
            {   
                if(Item[i].ReturnID()==ID) //search
                {
                    cout<<"\nEnter the quantity of Item you want to order: ";
                    cin>>Qtny;
                    Item[i].OrderItem(Qtny);
                    cout<<endl<<Qtny<<" Items of ID number "<<Item[i].ReturnID()<<" ordered!!";
                    break;
                }
            }
            if(i>=Count)
            cout<<"\nNo such Item found in the system";
            break;
        
        case 3:
            cout<<"\nEnter ID of Item to sell: ";
            cin>>ID;
            for(i=0;i<Count;i++)
            {   
                if(Item[i].ReturnID()==ID)
                {
                    cout<<"\nEnter the quantity of Items to sell: ";
                    cin>>Qtny;
                    if(Item[i].SellItem(Qtny))
                    cout<<"\nInvalid quantity! Please sell within quantity of Item in stock";
                    else
                    cout<<endl<<Qtny<<" Items of ID number "<<Item[i].ReturnID()<<" sold!!";
                    break;
                }
            }
            if(i>=Count)
            cout<<"\nNo such Item found in the system";
            break;
        
        case 4:
            for(i=0;i<Count;i++)
            Item[i].ItemsSummary();
            break;
        
        default:
            break;
        }

    }while(Choice>=1&&Choice<=4);
    cout<<"\nExiting System....\n\n";

    return 0;
}