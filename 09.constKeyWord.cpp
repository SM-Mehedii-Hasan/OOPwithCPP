// ✅ Key Takeaways
// Const object → can only call const member functions.
// Const member function → guarantees no modification of object members.
// Static members → shared across all objects; track things like total customers or total balance.
// Static functions → cannot access non-static members directly.
#include<iostream>
using namespace std;
class Customer{
    string name;
    long long account_no;
    int balance;
    static int total_customer;
    static int total_balance;
    public:
    Customer(string name,long long account_no,int balance){
          this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        total_customer++;
        total_balance += balance;
    }
    
    // 🔹 Const Member Function
    void display_user_info() const {  // const means it cannot modify any member variables
        cout << "User Name: " << name 
             << ", Account Number: " << account_no 
             << ", Balance: " << balance 
             << ", Total Customers: " << total_customer << endl;
    }
    
    static void display_totalAmount() {
        cout << "Total Customers = " << total_customer << endl;
        cout << "Total Balance = " << total_balance << endl;
    }
       void deposit(int amount) {
        balance += amount;
        total_balance += amount;
    }
       void withdraw(int amount) {
        if (amount > balance) {
            cout << name << " does not have enough balance!" << endl;
            return;
        }
        balance -= amount;
        total_balance -= amount;
    }
};
// Initialize static members
int Customer::total_customer = 0;
int Customer::total_balance = 0;
int main(){
    const Customer c1("Mehedi", 14678997645678, 500); // const object
    Customer c2("Adil", 2456789098765, 300);
    cout<<"\nbefore transaction:\n";

    c1.display_user_info();// ✅ Can call const member function
    c2.display_user_info();
    Customer::display_totalAmount();
    cout<<"\n after transacton:1\n";
    // ❌ Cannot call non-const function on const object
    // c1.deposit(100); // Error
    c2.deposit(500);
      c1.display_user_info();// ✅ Can call const member function
    c2.display_user_info();
    Customer::display_totalAmount();
    cout<<"\n after transacton:2\n";
    // ❌ Cannot call non-const function on const object
    //c1.withdraw(500);//error
    c2.withdraw(100);
    c1.display_user_info();// ✅ Can call const member function
    c2.display_user_info();
    Customer::display_totalAmount();


}
