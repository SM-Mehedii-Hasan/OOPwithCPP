// 🔹 What are Static Member Functions?
// In C++, a static member function is a class function that is not tied to any specific object.
// Declared with the keyword 'static' inside the class.
// Can only access static data members or other static member functions directly.
// Cannot access non-static members (since it has no 'this' pointer).
// Useful when you want a function that logically belongs to the class, not to individual objects.

// 🔹 Key Points:
// No 'this' pointer – cannot access instance variables directly.
// Belongs to the class – can be called using ClassName::functionName().
// Can be called using objects too, but recommended way is through class name.
// Mainly used to work with static data members or perform class-level operations.


#include <iostream>
using namespace std;

class Customer {
    string name;
    long long account_no; 
    int balance;
    static int total_customer;
    static int total_balance;

public:
   

    Customer(string name, long long account_no, int balance) {
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        total_customer++;
        total_balance+=balance;
    }

    void display_user_info() {
        cout << "User Name: " << name 
             << ", Account Number: " << account_no 
             << ", Balance: " << balance 
             << ", Total Customers: " << total_customer << endl;
    }

    static void display_totalAmount() {
        cout << "Total Customers = " << total_customer << endl;
         cout << "Total Balance = " << total_balance << endl;
    }
    void  deposit(long long amount){
        balance+=amount;
        total_balance+=amount;
    }
    void withdraw(long long amount){
        balance-=amount;
        total_balance-=amount;
    }
};

int Customer::total_customer = 0;
int Customer::total_balance = 0;

int main() {
    Customer c1("Mehedi", 14678997645678, 500);
    Customer c2("Adil", 2456789098765, 300);
    Customer c3("Sakib", 456789987653, 400);
    Customer c4("Abid", 56789043, 399);
        cout<<"\nbefore transaction:\n";
    c1.display_user_info();
    c2.display_user_info();
    c3.display_user_info();
    c4.display_user_info();
    Customer::display_totalAmount();
    c1.deposit(1000);
    c2.withdraw(200);
      cout<<"\n after transaction:\n";
    c1.display_user_info();
    c2.display_user_info();
    c3.display_user_info();
    c4.display_user_info();
    Customer::display_totalAmount();




    return 0;
}
// 👉 Summary:
// Static Data Member → Shared variable across all objects.
// Static Member Function → Shared function across all objects; can only work with static members.
// | Feature                            | **Static Data Member**                                | **Static Member Function**                                                  |
// | ---------------------------------- | ----------------------------------------------------- | --------------------------------------------------------------------------- |
// | **Definition**                     | A class variable shared by all objects.               | A class function shared by all objects.                                     |
// | **Keyword**                        | Declared with `static` inside the class.              | Declared with `static` inside the class.                                    |
// | **Storage**                        | Only one copy exists (at class level).                | Only one function exists (at class level).                                  |
// | **Access**                         | Accessed using `ClassName::variable` or object.       | Accessed using `ClassName::function()` or object.                           |
// | **Object Requirement**             | No object needed (can be accessed via class name).    | No object needed (can be called via class name).                            |
// | **Can Access Non-Static Members?** | ❌ No (only through object reference).                 | ❌ No (cannot access non-static data/functions directly, no `this` pointer). |
// | **Purpose**                        | To store class-level information (e.g., total count). | To operate on class-level data (mainly static members).                     |
// | **Lifetime**                       | Exists for the entire program duration.               | Exists for the entire program duration.                                     |
// | **Example**                        | `static int total_customer;`                          | `static void display_totalCustomer();`                                      |


// ⚡ Quick Mnemonic:
// Static Data Member = Shared Variable
// Static Member Function = Shared Function
