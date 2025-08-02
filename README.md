
📘 Banking System in C++
A simple OOP-based banking system implemented in C++ to demonstrate the four pillars of Object-Oriented Programming (OOP):

Abstraction

Encapsulation

Inheritance

Polymorphism

📌 Features
Two types of bank accounts:

Saving Account

Current Account

Deposit and withdrawal functionalities

Overdraft support for current accounts

Polymorphic account storage in a Bank class

Demonstrates full usage of OOP principles

🧠 Four Pillars of OOP in this Project
1. Abstraction
Done using a pure virtual class account with virtual methods:

cpp
Copy
Edit
class account {
public:
    virtual void displayinfo() = 0;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual ~account() {}
};
This hides the implementation and lets users interact via a simple interface.

2. Encapsulation
Each class (like savingaccount and currentaccount) has:

Private data members

Public getters and methods to access or modify them

private:
    string accountholder;
    int accountid;
    double balance;
3. Inheritance
savingaccount and currentaccount inherit from the account base class:

cpp
Copy
Edit
class savingaccount : public account { ... };
class currentaccount : public account { ... };
4. Polymorphism
Uses virtual functions and base class pointers to handle both account types generically:


vector<account*> accounts;
accounts.push_back(new savingaccount(...));
accounts.push_back(new currentaccount(...));

for (auto acc : accounts) {
    acc->displayinfo();  // Calls correct derived class method at runtime
}
📂 File Structure

bankingsystem/
│
├── main.cpp         # Main logic for the project
├── README.md        # This documentation
🚀 How to Run
✅ Step 1: Compile
bash

g++ main.cpp -o bank
✅ Step 2: Run
bash

./bank
Or on Windows:

bash

bank.exe
💡 Sample Output
yaml

Deposited 1000 to account 101
Withdrawn 700 from account 101
Deposited 500 to account 202
Withdrawn 3500 from account 202

All Bank Accounts:
Saving Account - ID: 101, Holder: Alice, Balance: 5300, Interest Rate: 0.05
Current Account - ID: 202, Holder: Bob, Balance: 0, Overdraft Limit: 1000
🧪 Concepts Practiced
Concept	Usage Example
Abstraction	account class hides implementation
Encapsulation	Private members and public getters/setters
Inheritance	savingaccount, currentaccount from account
Polymorphism	displayinfo(), deposit(), withdraw() dynamically dispatched

🧑‍💻 Author
Saurabh Singh Rajput

Second-year CSE student at IIIT Bhagalpur
Self-taught programmer passionate about building real-world OOP projects.

✅ Git Usage Notes
If you're getting this error when pushing:


error: src refspec main does not match any
Try this:

git branch        # Check your branch
git push -u origin master    # Use the correct branch name
If you want to rename your branch to main:
git branch -m main
git push -u origin main
