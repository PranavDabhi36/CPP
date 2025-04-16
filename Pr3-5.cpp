/*
A data analytics company was tasked with developing a unique digital 
signature system based on the concept of "super digits." The system 
required finding a single-digit representation of a given number 
through recursive digit summation. The algorithm was defined as follows:
If the number has only one digit, it is its super digit. Otherwise, 
the super digit is the super digit of the sum of its digits, repeated 
recursively until a single digit is obtained.
The challenge involved an additional complexity—constructing the number 
by concatenating a given string representation of an integer multiple 
times. For example, if the number n was represented as a string and 
concatenated k times, the super digit of the resulting number needed 
to be calculated.
For instance:
Given n = 9875 and k = 4, the number is represented as 9875987598759875.
The sum of digits in this number is calculated recursively until a 
single digit remains:
9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 = 116
1 + 1 + 6 = 8
The super digit is 8.
The system was required to handle large numbers efficiently by leveraging 
mathematical insights rather than explicitly constructing large concatenated 
strings. This case study called for implementing a recursive solution to 
calculate the super digit, supported by a mathematical approach to optimize 
the handling of repeated sums.


find super digit
recursive sum function
given: string form of number and number of times it is repeated
large numbers
*/


#include<iostream>
#include<string>
using namespace std;

int SuperDigit(long long Number, int z){//max number = 9223372036854775807, so 19 digits
    if(z==1) //base case for recursive function
    return Number;
    else{
        long long Super =0;
        int y=0;
        
        while(Number>=1){
            Super+= Number%10; //adding each digit
            Number/=10;
            y++;
        }

        return SuperDigit(Super, y); //recursion
    }
}

int main()
{
    string Number, N;
    int k;

    cout<<"\n\nEnter the Number: ";cin>>N;
    cout<<"Enter the number of concatenations of this number: ";cin>>k;

    for(int i=0; i<k; i++){
        Number+=N;
    }

    cout<<"\nThe Super Digit of "<<Number<<" is "<<SuperDigit(stoll(Number), Number.size()); //string to number function
    
    return 0;
}