// 🔹 What are Static Data Members?
// In C++, a static data member is a class variable that is shared among all objects of the class instead of being unique to each object.
// Declared with the keyword static inside the class.
// Memory is allocated only once (at class level, not per object).
// All objects of the class share the same copy of the static member.
// Must be defined outside the class (unless it is inline since C++17).
// 🔹 Key Points:
// Shared across objects – changes made by one object are reflected in all others.
// Lifetime – exists for the entire program duration (similar to global variables).
// Access – can be accessed using:
// Object name: obj.x
// Class name: ClassName::x (preferred way).
#include <iostream>
using namespace std;

class Customer {
    string name;
    long long account_no;  // changed to long long
    int balance;

public:
    static int total_customer;

    Customer(string name, long long account_no, int balance) {
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        total_customer++;
    }

    void display_user_info() {
        cout << "User Name: " << name 
             << ", Account Number: " << account_no 
             << ", Balance: " << balance 
             << ", Total Customers: " << total_customer << endl;
    }

    static void display_totalCustomer() {
        cout << "Total Customers = " << total_customer << endl;
    }
};

int Customer::total_customer = 0;

int main() {
    Customer c1("Mehedi", 14678997645678, 500);
    Customer c2("Adil", 2456789098765, 300);
    Customer c3("Sakib", 456789987653, 400);

    c1.display_user_info();
    c2.display_user_info();
    c3.display_user_info();

    Customer::display_totalCustomer();  // static function call

    Customer c4("Abid", 56789043, 399);
    c4.display_user_info();

    cout << "Total Customers (access via class): " << Customer::total_customer << endl;

    return 0;
}
