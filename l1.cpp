#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract Base Class: Account
class account {
public:
    virtual void displayinfo() = 0;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual ~account() {}  // virtual destructor
};

// Derived Class: SavingAccount
class savingaccount : public account {
private:
    string accountholder;
    int accountid;
    double balance;
    double interestrate;

public:
    savingaccount(string holder, int id, double initbalance)
        : accountholder(holder), accountid(id), balance(initbalance), interestrate(0.05) {}

    // Getter methods
    string getholder() const { return accountholder; }
    int getid() const { return accountid; }
    double getbalance() const { return balance; }
    double getinterestrate() const { return interestrate; }

    // Override methods
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accountid << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from account " << accountid << endl;
        } else {
            cout << "Invalid amount or insufficient balance" << endl;
        }
    }

    void displayinfo() override {
        cout << "Saving Account - ID: " << accountid
             << ", Holder: " << accountholder
             << ", Balance: " << balance
             << ", Interest Rate: " << interestrate << endl;
    }
};

// Derived Class: CurrentAccount
class currentaccount : public account {
private:
    string accountholder;
    int accountid;
    double balance;
    double overdraftlimit;

public:
    currentaccount(string holder, int id, double initbalance)
        : accountholder(holder), accountid(id), balance(initbalance), overdraftlimit(1000) {}

    // Getter methods
    string getHolder() const { return accountholder; }
    int getid() const { return accountid; }
    double getbalance() const { return balance; }

    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accountid << endl;
        } else {
            cout << "Invalid amount to be deposited" << endl;
        }
    }

    void withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftlimit >= amount)) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from account " << accountid << endl;
        } else {
            cout << "Invalid amount or exceeds overdraft limit!" << endl;
        }
    }

    void displayinfo() override {
        cout << "Current Account - ID: " << accountid
             << ", Holder: " << accountholder
             << ", Balance: " << balance
             << ", Overdraft Limit: " << overdraftlimit << endl;
    }
};

// Bank class to manage multiple accounts
class bank {
private:
    vector<account*> accounts;  // Polymorphic collection

public:
    void addaccount(account* acc) {
        accounts.push_back(acc);
    }

    void displayallaccounts() {
        cout << "\nAll Bank Accounts:\n";
        for (auto acc : accounts) {
            acc->displayinfo();
        }
    }

    ~bank() {
        for (auto acc : accounts) {
            delete acc;
        }
    }
};

// Demonstration
int main() {
    bank mybank;

    // Creating accounts
    savingaccount* s1 = new savingaccount("Alice", 101, 5000.0);
    currentaccount* c1 = new currentaccount("Bob", 202, 3000.0);

    // Adding to bank
    mybank.addaccount(s1);
    mybank.addaccount(c1);

    // Performing operations
    s1->deposit(1000);
    s1->withdraw(700);
    c1->deposit(500);
    c1->withdraw(3500); // Uses overdraft

    // Display info of all accounts
    mybank.displayallaccounts();

    return 0;
}
