/*
A technology firm aimed to develop a flexible and reusable solution 
for managing collections of various data types, including integers, 
floating-point numbers, and characters. The system was intended to 
perform fundamental operations on these collections, such as finding 
the maximum value, reversing the collection, and displaying all 
elements. To achieve versatility and avoid redundancy in code, the 
solution was designed to use function templates, allowing the same 
logic to be applied seamlessly to different data types.
The team recognized the importance of using dynamic Kollections to store 
the collections, enabling efficient management of varying collection 
sizes. The design emphasized scalability and flexibility, ensuring 
that the system could handle different data types and their associated 
operations with minimal changes to the core logic.
In practice, the system allowed for the creation of collections for 
various data types, such as integers, floating-point numbers, and 
characters. The operations on these collections included determining 
the maximum value, reversing the order of elements, and printing the 
collection contents.

collection of different data types:-
<template>class{
collectionId
Constructor()
enter()
display()
reverse()
findmax()
}
switch cases:
enter
-select data Type//int, float and char//
display
-select collection//based on id//
reverse
-select collection
find max
-select collection
*/

#include<iostream>
#include<vector>
using namespace std;
    
template<typename Type>
class Collection //template class
{
    int NumElements=0;
    Type* Kollection; //pointer to array(dynamic array)
public:

    void InputCollection(){
        if(NumElements!=0){
            cout<<"\nThis Collection already exists";
            return;
        }
        cout<<"\nEnter the number of elements in this Collection: ";
        cin>>NumElements;
        Kollection = new Type[NumElements]; //declaring array after entering NumElements
        cout<<"\nEnter all elements of this collection:\n\n";
        for(int i=0; i<NumElements; i++){
            cout<<"Element "<<i+1<<": ";
            cin>>Kollection[i]; //accessing arraay by pointer
        }
        cout<<"\nNew Collection Added Succesfully!";
    }
    
    void Display(){
        for(int i=0; i<NumElements; i++){
            cout<<"\nElement "<<i+1<<": "<<Kollection[i];
        }
    }

    void Reverse(){
        for(int j=0; j<NumElements/2; j++){
            Type temp;
            temp = Kollection[j]; //reversing array logic
            Kollection[j] = Kollection[NumElements-j-1];
            Kollection[NumElements-j-1] = temp;
        }
        cout<<"\nElements reversed succesfully!!\n\nDisplaying reversed collection:";
        for(int i=0; i<NumElements; i++){
            cout<<"\nElement "<<i+1<<": "<<Kollection[i];
        }
    }

    Type FindMax(){
        Type Max=Kollection[0];
        for(int i=0; i<NumElements; i++){
            if(Max<Kollection[i]){ //mae element logic
                Max=Kollection[i];
            }
        }
        return Max;
    }
};
    
int main()
{
    Collection<int> intCollect; //using template class
    Collection<float> floatCollect; 
    Collection<char> charCollect; //one collection for each data type
    int Choice, Type, ID, n;

    do{
        cout<<"\n\n~Data Type Collections~"
            <<"\nChoices:-\n1.Enter a New Collection\n2.Display all Collections\n3.Reverse a Collection\n4.Find Maximum value in a collection\n0.Exit System"
            <<"\n\nEnter your Choice: "; //choie based system
        cin>>Choice;

        switch(Choice){
        case 1:
            cout<<"\nChoose Data Type of collection to enter:-"
                <<"\n1. Integer (int)"
                <<"\n2. Float (float)"
                <<"\n3. Character (char)"
                <<"\n\nEnter Choice: ";
            cin>>Type;

            if(Type==1){
                intCollect.InputCollection();
            }
            else if(Type==2){
                floatCollect.InputCollection();
            }
            else if(Type==3){
                charCollect.InputCollection();
            }
            else
            cout<<"\nIncorrect Choice!";
            break;
        case 2:
            cout<<"\nDisplaying all elements of Integer collection:";
            intCollect.Display();
            cout<<"\n\nDisplaying all elements of Float collection:";
            floatCollect.Display();
            cout<<"\n\nDisplaying all elements of Character collection:";
            charCollect.Display();
            break;
        case 3:
            cout<<"\nChoose Collection Data Type to reverse:-"
                <<"\n1. Integer (int)"
                <<"\n2. Float (float)"
                <<"\n3. Character (char)"
                <<"\n\nEnter Choice: ";
            cin>>Type;

            if(Type==1){
                cout<<"\nReversing elements of Integer collection...";
                intCollect.Reverse();
            }
            else if(Type==2){
                cout<<"\nReversing elements of Float collection...";
                floatCollect.Reverse();            
            }
            else if(Type==3){
                cout<<"\nReversing elements of Character collection...";
                charCollect.Reverse();            
            }
            else
            cout<<"\nIncorrect Choice!";
            break;
        case 4:
            cout<<"\nMaximum value in Integer Collection: "<<intCollect.FindMax()
                <<"\nMaximum value in Float Collection: "<<floatCollect.FindMax()
                <<"\nMaximum value in Characer Collection: "<<charCollect.FindMax();
        default:
            break;
        }
    }while(Choice>0 && Choice<5);
    cout<<"\n\nExiting System....";
    
    return 0;
}