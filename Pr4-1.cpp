/*
A team of engineers was tasked with developing a program to calculate 
and manage the areas of multiple circles for a design project. To 
achieve this, they devised a solution using a structured, object-oriented 
approach. At the foundation of their solution was a base class that 
represented a generic shape, responsible for storing and managing the 
radius of the circle. Building upon this, a specialized class for 
circles was created to extend functionality by introducing a method 
for calculating the area of a circle based on its radius. Using this 
framework, the team designed a system to handle multiple circles, 
ensuring that the process of storing, calculating, and displaying 
the areas was efficient and adaptable. They explored two different 
approaches for managing the collection of circles—one focusing on 
flexibility and dynamic handling, while the other used a more static 
structure. By implementing and comparing these methods, the engineers 
gained insights into the benefits of using efficient techniques for 
organizing and processing geometric data, enhancing their problem-solving 
capabilities.

areeas of multiple circles
base: shape: radius
derived: circle: calculateearea()
store calculate and display circlees
*/


#include<iostream>
#include<vector>
using namespace std;
    
class Shape{
private:
    float radius;//size(int)=4

protected:
    Shape(float r){ //constructor
        radius=r;
    }

    float GetRadius(){
        return radius; //to acccess pvt member after inheritance
    }
};

class Circle : private Shape{
private:
    float Area;

    void CalculateArea(){ //utility function
        Area = 3.14159265*GetRadius()*GetRadius();
    }
public:

    Circle(float r=0):Shape(r){
        CalculateArea(); //derived class constructor
    }

    void DisplayData(){
        cout<<"\nRadius: "<<GetRadius()<<" units";
        cout<<"\nArea: "<<Area<<" sq. units";
    }
};

int main(){

    vector<Circle> CircMang; //dynamic array
    int choice=1, i=0;
    float r=0;

    while(choice==1||choice==2){
        
        cout<<"\n\nCircle Management System Choices:\n1.Add Circle\n2.Display all Circles\n0.Exit System\n\nEnter Choice: ";
        cin>>choice; //choice based system

        if(choice==1){
            cout<<"\nEnter New Circle Radius: ";
            cin>>r;
            CircMang.push_back(Circle(r));
            cout<<"\nNew Circle added succesfully!!\n\nDisplaying its details:-";
            CircMang[i].DisplayData();
            i++;
        }
        else if (choice==2){
            cout<<"\nDisplaying "<<i<<" circles' details:-";
            int j=0;
            for(Circle &ref: CircMang){
                cout<<"\n\nCircle "<<j+1<<" details:-";
                ref.DisplayData();
                j++;
            }
        }
        else
        break;
    }
    cout<<"\n\nExiting System.....";

    return 0;
}