#include <iostream>

using namespace std;

int main() {
    double loanAmount, annualIncome;

    // Ask for user input
    cout << "Enter the loan amount: ";
    while (!(cin >> loanAmount)) {  // Input validation for loanAmount
        cout << "Invalid input. Please enter a valid number for the loan amount: ";
        cin.clear();  // Clear the error flag
        cin.ignore(10000, '\n');  // Ignore invalid input
    }

    cout << "Enter your annual income: ";
    while (!(cin >> annualIncome) || annualIncome == 0) {  // Input validation for annualIncome (check for zero income)
        if (annualIncome == 0) {
            cout << "Annual income cannot be zero. Please enter a non-zero income: ";
        } else {
            cout << "Invalid input. Please enter a valid number for annual income: ";
        }
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Calculate loan-to-income ratio
    double ratio = loanAmount / annualIncome;

    // Display the result
    cout << "Your loan-to-income ratio is: " << ratio << endl;

    return 0;
}