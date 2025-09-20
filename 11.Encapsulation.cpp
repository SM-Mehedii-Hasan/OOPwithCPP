

// Encapsulation is one of the four main pillars of Object-Oriented Programming (OOP) (along with inheritance, polymorphism, and abstraction).

// 🔹 Definition

// Encapsulation means binding data (variables) and methods (functions) that operate on that data into a single unit (class) and restricting direct access to some of the object's components.
// This protects the internal state of an object and ensures that it can only be changed in controlled ways.

// 🔹 Key Ideas

// Data Hiding – Class members (like variables) are kept private and accessed only through public methods (getters/setters).

// Controlled Access – Prevents accidental modification of data and enforces rules.

// Improved Security – Sensitive data stays safe inside the object.

// Modularity – Each class controls its own data and behavior.






#include <iostream>
using namespace std;

class BankAccount {
private:    // 🔒 Encapsulated Data
    string customer_name;
    string pin;
    double balance;

public:
    BankAccount(string customer_name, string pin, double balance) {
        this->customer_name = customer_name;
        this->pin = pin;
        this->balance = balance;
    }

    // ✅ PIN verification (returns true/false, doesn’t expose PIN)
    bool verify_pin(string entered_pin) const {
        return entered_pin == pin;
    }

    string get_name() const {
        return customer_name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "✅ Deposit successful!\n";
        } else {
            cout << "❌ Invalid amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "✅ Withdrawal successful!\n";
        } else {
            cout << "❌ Invalid withdrawal amount!\n";
        }
    }

    void display() const {
        cout << "Name: " << customer_name 
             << ", Balance: " << balance << " tk" << endl;
    }
};

int main() {
    BankAccount a1("mehedi", "12345", 10000);

    cout << "\n<----- Welcome to iBank ----->\n";
    string name, pin;
    cout << "Enter Your name to login: ";
    cin >> name;
    cout << "Enter Your 5-digit PIN: ";
    cin >> pin;

    if (name == a1.get_name() && a1.verify_pin(pin)) {
        int choice;
        do {
            cout << "\n1. Account Status\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            if (choice == 1) {
                cout << "\n--- Account Status ---\n";
                a1.display();
            } 
            else if (choice == 2) {
                double deposit_amount;
                cout << "Enter deposit amount: ";
                cin >> deposit_amount;
                a1.deposit(deposit_amount);
            } 
            else if (choice == 3) {
                double withdraw_amount;
                cout << "Enter withdraw amount: ";
                cin >> withdraw_amount;
                a1.withdraw(withdraw_amount);
            } 
            else if (choice == 4) {
                cout << "👋 Thank you for using iBank. Goodbye!\n";
            } 
            else {
                cout << "❌ Invalid choice. Try again.\n";
            }

        } while (choice != 4);
    } else {
        cout << "❌ Login failed! Wrong name or PIN.\n";
    }

    return 0;
}
