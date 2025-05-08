#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string* transactionLog;
    int logSize;
    int logCapacity;

    void resizeLog() {
        logCapacity *= 2;
        string* newLog = new string[logCapacity];
        for (int i = 0; i < logSize; ++i) {
            newLog[i] = transactionLog[i];
        }
        delete[] transactionLog;
        transactionLog = newLog;
    }

    void logTransaction(const string& message) {
        if (logSize >= logCapacity) {
            resizeLog();
        }
        transactionLog[logSize++] = message;
    }

public:
    BankAccount(string name, double initialBalance = 0.0)
        : accountHolder(name), balance(initialBalance), logSize(0), logCapacity(10) {
        transactionLog = new string[logCapacity];
        logTransaction("Account created with balance: " + to_string(balance));
    }

    ~BankAccount() {
        delete[] transactionLog;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Invalid deposit attempt: " + to_string(amount));
            cout << "Error: Deposit amount must be positive." << endl;
            return;
        }
        balance += amount;
        logTransaction("Deposited: " + to_string(amount) + ", New balance: " + to_string(balance));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Invalid withdrawal attempt: " + to_string(amount));
            cout << "Error: Withdrawal amount must be positive." << endl;
            return;
        }
        if (amount > balance) {
            logTransaction("Failed withdrawal (Insufficient funds): " + to_string(amount));
            cout << "Error: Insufficient balance." << endl;
            return;
        }
        balance -= amount;
        logTransaction("Withdrew: " + to_string(amount) + ", New balance: " + to_string(balance));
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << ", Balance: " << balance << endl;
    }

    void showLog() const {
        cout << "\nTransaction Log for " << accountHolder << ":\n";
        for (int i = 0; i < logSize; ++i) {
            cout << "- " << transactionLog[i] << endl;
        }
    }
};

int main() {
    string name;
    double initial;
    cout << "Enter account holder name: ";
    cin >> name;
    cout << "Enter initial balance: ";
    cin >> initial;

    BankAccount account(name, initial);

    int choice;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Show Log\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            double amt;
            cout << "Enter deposit amount: ";
            cin >> amt;
            account.deposit(amt);
        } else if (choice == 2) {
            double amt;
            cout << "Enter withdrawal amount: ";
            cin >> amt;
            account.withdraw(amt);
        } else if (choice == 3) {
            account.displayBalance();
        } else if (choice == 4) {
            account.showLog();
        }

    } while (choice != 5);

    return 0;
}