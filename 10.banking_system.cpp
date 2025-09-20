#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Customer {
    string name;
    string account_no;
    int balance;
    string passcode; // each customer has a passcode
    static int total_customer;
    static int total_balance;

public:
    Customer(string name, string account_no, int balance, string passcode) {
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        this->passcode = passcode;
        total_customer++;
        total_balance += balance;
    }

    void display_user_info() const {


//🔹 Why the const here?
// The const after the function name means:
// 👉 This function cannot modify any data members of the class (except those marked mutable).
// So inside this function:
// balance = 999; // ❌ Error (cannot modify in const function)
// But reading values is fine:
// cout << balance; // ✅ Allowed
// 🔹 Benefits
// Safe for read-only operations
// Since this function is only displaying data, it makes sense to mark it const.
// Can be called on const objects
// const Customer c1("Mehedi", 12345, 500);
// c1.display_user_info();  // ✅ Works
// If you hadn’t added const at the end, the compiler would complain here.
// Good practice in OOP
// Use const for functions that don’t change the object’s state.
// Makes the code more reliable and self-documenting.
// ⚡ Rule of Thumb:
// Add const at the end of member functions if they only read data and don’t modify the object.


        cout << "User Name: " << name
             << ", Account Number: " << account_no
             << ", Balance: " << balance << endl;
    }

    static void display_totalAmount() {
        cout << "Total Customers = " << total_customer << endl;
        cout << "Total Bank Balance = " << total_balance << endl;
    }

    void deposit(int amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        balance += amount;
        total_balance += amount;
        cout << name << " deposited " << amount 
             << ". New balance: " << balance << endl;
    }

    void withdraw(int amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << name << " does not have enough balance!" << endl;
            return;
        }
        balance -= amount;
        total_balance -= amount;
        cout << name << " withdrew " << amount 
             << ". New balance: " << balance << endl;
    }

    string get_name() const { return name; }

    bool verify_passcode(string input) const {
        return input == passcode;
    }
};

int Customer::total_customer = 0;
int Customer::total_balance = 0;

string to_lowercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main() {
    vector<Customer> customers;
    customers.emplace_back("Mehedi", "14678997645678", 500, "1234");
    customers.emplace_back("Adil", "2456789098765", 300, "2345");
    customers.emplace_back("Sakib", "456789987653", 400, "3456");
    customers.emplace_back("Abid", "56789043", 399, "4567");

    const string ADMIN_PASSWORD = "admin123";

    int mainChoice;
    while (true) {
        cout << "\n==== Mini Banking System ====\n";
        cout << "1. Customer Section\n";
        cout << "2. Authority Section\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            string name, passcode;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your passcode: ";
            cin >> passcode;

            bool found = false;
            for (auto& c : customers) {
                if (to_lowercase(c.get_name()) == to_lowercase(name) && c.verify_passcode(passcode)) {
                    found = true;
                    int custChoice;
                    while (true) {
                        cout << "\n--- Customer Menu ---\n";
                        cout << "1. View Account Info\n";
                        cout << "2. Deposit Money\n";
                        cout << "3. Withdraw Money\n";
                        cout << "4. Logout\n";
                        cout << "Enter your choice: ";
                        cin >> custChoice;

                        if (custChoice == 1) {
                            c.display_user_info();
                        } else if (custChoice == 2) {
                            int amount;
                            cout << "Enter amount to deposit: ";
                            cin >> amount;
                            c.deposit(amount);
                        } else if (custChoice == 3) {
                            int amount;
                            cout << "Enter amount to withdraw: ";
                            cin >> amount;
                            c.withdraw(amount);
                        } else if (custChoice == 4) {
                            cout << "Logging out...\n";
                            break;
                        } else {
                            cout << "Invalid choice!\n";
                        }
                    }
                    break;
                }
            }
            if (!found) cout << "Incorrect name or passcode!\n";
        } 
        else if (mainChoice == 2) {
            string password;
            cout << "Enter authority password: ";
            cin >> password;
            if (password == ADMIN_PASSWORD) {
                cout << "\n--- Authority Section ---\n";
                for (const auto& c : customers) {
                    c.display_user_info();
                }
                Customer::display_totalAmount();
            } else {
                cout << "Incorrect authority password!\n";
            }
        } 
        else if (mainChoice == 3) {
            cout << "Exiting program...\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
