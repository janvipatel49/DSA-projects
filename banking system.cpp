#include<iostream>
using namespace std;

// ----------- Base Class: Account -----------
class Account {
protected:
    long long number;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your account number: ";
        cin >> number;
        balance = 0;
        cout << endl;
    }

    void depositMoney() {
        double amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;

        if (amt > 0) {
            balance += amt;
            cout << "Amount added! Current balance: Rs. " << balance << endl;
        } else {
            cout << "Please enter a valid amount.\n";
        }
    }

    void withdrawMoney() {
        double amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if (amt > 0) {
            if (amt <= balance) {
                balance -= amt;
                cout << "You withdrew Rs. " << amt << ". Remaining: Rs. " << balance << endl;
            } else {
                cout << "Not enough balance.\n";
            }
        } else {
            cout << "Enter a valid amount.\n";
        }
    }

    void showBalance() {
        cout << "Current balance: Rs. " << balance << endl;
    }

    void showInfo() {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << number << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

// ---------- Saving Account (Derived Class) ----------
class Saving : public Account {
public:
    void addInterest() {
        double rate = 0.02; // 2%
        double interest = balance * rate;
        balance += interest;
        cout << "Interest Rs. " << interest << " added.\n";
        cout << "Updated Balance: Rs. " << balance << endl;
    }
};

// ---------- Fixed Deposit Account (Derived Class) ----------
class FixedDeposit : public Account {
public:
    void fdInterest() {
        double amount;
        int months;
        double rate = 0.06; // 6% yearly

        cout << "Enter amount to deposit in FD: ";
        cin >> amount;

        if (amount > 0) {
            cout << "Enter duration in months: ";
            cin >> months;

            double interest = amount * rate * (months / 12.0);
            amount += interest;

            cout << "Interest Rs. " << interest << " added.\n";
            cout << "Maturity amount: Rs. " << amount << endl;
        } else {
            cout << "Please enter valid amount.\n";
        }
    }
};

// --------------- Main Function ---------------
int main() {
    int type;

    cout << "\n===== Welcome to Simple Bank App =====\n\n";
    cout << "1. Saving Account\n";
    cout << "2. Fixed Deposit\n\n";
    cout << "Enter account type (1 or 2): ";
    cin >> type;
    cout << endl;

    if (type == 1) {
        Saving user;
        user.createAccount();

        int ch;
        do {
            cout << "\n--- Menu ---\n";
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Show Balance\n";
            cout << "4. Show Account Info\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> ch;

            switch (ch) {
                case 1: user.depositMoney(); break;
                case 2: user.withdrawMoney(); break;
                case 3: user.showBalance(); break;
                case 4: user.showInfo(); break;
                case 0: cout << "Exiting...\n"; break;
                default: cout << "Invalid option.\n";
            }
        } while (ch != 0);

        user.addInterest(); // Add 2% interest at the end
        cout << "Thanks for using Saving Account.\n";
    }
    else if (type == 2) {
        FixedDeposit fd;
        fd.createAccount();
        fd.fdInterest();
        cout << "Thanks for using Fixed Deposit.\n";
    }
    else {
        cout << "Invalid account type.\n";
    }

    return 0;
}

