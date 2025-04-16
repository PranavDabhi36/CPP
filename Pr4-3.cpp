/*
A vehicle manufacturing company sought to create a robust system to organize 
and manage the details of various cars produced under its brand. To accomplish 
this, a hierarchical structure was conceptualized, reflecting the essential 
components of a vehicle. At the foundation, a class was designed to represent 
the type of fuel a vehicle uses. Another class was created to capture the brand 
name of the vehicle. These two foundational elements were then combined into a 
derived class specifically representing cars, integrating both fuel type and 
brand information.
Constructors were used at each level to ensure proper initialization of attributes, 
allowing seamless integration of all details. Additionally, the ability to display 
complete information about a car, including its fuel type and brand, was incorporated 
into the system. To simulate a real-world scenario such as a service queue, multiple 
cars were organized and processed sequentially using a structured approach. This not 
only streamlined handling of cars but also provided an opportunity to compare different 
methods of managing the collection and processing of vehicle data.
*/

#include<iostream>
#include<vector>
using namespace std;
    
class Fuel //bse 1 class
{
    string FuelType;
protected:
    
    Fuel(string f){
        FuelType = f;
    }

    void DisplayFuel(){
        cout<<"\nFuel Type: "<<FuelType;
    }
};

class Brand //base 2 class
{
    string BrandName;
protected:
    
    Brand(string b){
        BrandName = b;
    }

    void DisplayBrand(){
        cout<<"\nBrand Name: "<<BrandName;
    }
};

class Car : private Fuel, private Brand //derived class
{
public:
    
    Car(string f, string b): Fuel(f), Brand(b) {}

    void DisplayCar(){
        DisplayBrand();
        DisplayFuel();
    }
};
    
int main()
{
    vector<Car> Cars;
    int Choice=0, i=0;
    string brand, fuel;

    do{
        cout<<"\n\nCompany Car Database\nChoices:\n1. Enter New Car Information\n2. Display all Cars Information\n0. Exit System"
            <<"\n\nEnter your Choice: ";
        cin>>Choice;  
    

        if(Choice==1){
            cout<<"\nEnter Car Brand: ";
            cin.ignore();
            getline(cin, brand);
            cout<<"Enter Fuel Type: ";
            getline(cin, fuel);

            Cars.push_back(Car(fuel, brand));
            cout<<"\nNew Car Added!!";
        }
        else if(Choice==2){
            cout<<"\nDisplaying all cars information:";
            for(Car &c : Cars){
                cout<<"\n\nCar "<<++i;
                c.DisplayCar();
            }
        }
        else
        break;

    }while(Choice==1||Choice==2);

    cout<<"\n\nExiting System...";

    return 0;
}