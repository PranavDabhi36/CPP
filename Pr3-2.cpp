/*
A software development company was tasked with conducting a performance analysis of recursive algorithms versus 
their iterative counterparts. The specific focus was on calculating the Sum of integers in an array, where the 
array's size and elements were to be provided dynamically by the user. To facilitate memory management and enable 
dynamic resizing of the array, the team decided to use a flexible container for storing the array elements.
The system was designed to first prompt users for the array's size and then request the input of individual elements. 
A recursive function was to be implemented to compute the Sum by dividing the problem into smaller sub-problems, 
recursively summing subsets of the array until reaching the base case. In addition to the recursive implementation, 
an iterative version of the function would be created for comparison.
The main objective of the study was to assess and compare the computational performance and implementation complexity 
of both recursive and non-recursive approaches. By evaluating execution times, memory usage, and code complexity, 
the team hoped to gain insights into the trade-offs between recursion and iteration, particularly in terms of efficiency 
and applicability to real-world problems.

recursive vs iterative
Sum of int array elements
size and elements by user
??compare code complexity, execution time, memory usage, etc.
*/

#include<iostream>
using namespace std;

int SumRecursive(int a[], int n){
    if(n<=0) //base condition in recursive function
    return 0;
    return (a[n-1] + SumRecursive(a, n-1)); //recursive condition
}

int SumIterative(int a[], int n){
    int Sum=0;
    for(int i=0; i<n; i++){
        Sum+=a[i];
    }
    return Sum;
}
 
int main()
{
    int n;
    cout<<"\n\nEnter number of elements of integer array: ";
    cin>>n;
    int intArr[n];

    cout<<"Enter elements in array: \n";
    for(int i=0; i<n; i++){
        cin>>intArr[i];
    }

    cout<<"\nSum of all elements by recursive function: "<<SumRecursive(intArr, n); //compare both outputs
    cout<<"\nSum of all elements by iterative function: "<<SumIterative(intArr, n);
    
    return 0;
}