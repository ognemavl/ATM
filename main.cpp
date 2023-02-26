#include <iostream>
#include <string>

using namespace std;

/* Mini ATM Project
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    -> Update Mobile No
*/

class ATM {
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a);
    long int getAccountNo();
    string getName();
    int getPIN();
    double getBalance();
    string getMobileNo();
    void setMobile(string mob_prev, string mob_new);
    void cashWithDraw(int amount_a);
};

void ATM::setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
    account_No = account_No_a;
    name = name_a;
    PIN = PIN_a;
    balance = balance_a;
    mobile_No = mobile_No_a;
}

long int ATM::getAccountNo() {
    return account_No;
}

string ATM::getName() {
    return name;
}

int ATM::getPIN() {
    return PIN;
}

double ATM::getBalance() {
    return balance;
}

string ATM::getMobileNo() {
    return mobile_No;
}

void ATM::setMobile(string mob_prev, string mob_new) {
    if (mob_prev == mobile_No) {
        mobile_No = mob_new;
        cout << endl << "Successfully Updated Mobile NO.";
        cin.get(); // cin.get is to hold the screen (until the user presses Enter)
    }
}

void ATM::cashWithDraw(int amount_a) {
    if (amount_a > 0 && amount_a < balance) {
        balance -= amount_a;
        cout << endl << "Please Collect your cash";
        cout << endl << "Available Balance: " << balance;
        cin.get();
    }
    else {
        cout << endl << "Invalid Input or Insufficient Balance";
        cin.get();
    }
}

int main()
{
    int choice = 0;
    long int enterAccountNo;
    int enterPin;

    system("cls"); // clear the screen

    // Create a new ATM object and set initial data
    ATM user1;
    user1.setData(1234567, "Ognema", 1111, 40000.692, "9087654321");

    do {
        system("cls"); // clear the screen

        cout << endl << "**** Welcome to ATM ****";
        cout << endl << "Enter Your Account No: ";
        cin >> enterAccountNo;

        cout << endl << "Enter PIN: ";
        cin >> enterPin;

        // Check if account number and PIN match
        if (enterAccountNo == user1.getAccountNo() && enterPin == user1.getPIN()) {

            int amount = 0;
            string oldMobileNo, newMobileNo;

            system("cls"); // clear the screen

            // User Interface
            cout << endl << "**** Welcome to ATM ****";
            cout << endl << "Select Options:";
            cout << endl << "1. Check Balance";
            cout << endl << "2. Cash Withdraw";
            cout << endl << "3. Show User Details";
            cout << endl << "4. Update Mobile No";
            cout << endl << "5. Exit";
            cout << endl << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << endl << "Your Bank balance is: " << user1.getBalance() << endl;
                system("pause"); // wait for user input
                break;
            case 2:
                cout << endl << "Enter the amount: ";
                cin >> amount;
                user1.cashWithDraw(amount);
                break;
            case 3:
                cout << endl << "*** User Details are:- ";
                cout << endl << "-> Account no: " << user1.getAccountNo();
                cout << endl << "-> Name: " << user1.getName();
                cout << endl << "-> Balance: " << user1.getBalance();
                cout << endl << "-> Mobile No: " << user1.getMobileNo() << endl;
                system("pause"); // wait for user input
                break;
            case 4:
                cout << endl << "Enter Old Mobile No.: ";
                cin >> oldMobileNo;
                cout << endl << "Enter New Mobile No.: ";
                cin >> newMobileNo;
                user1.setMobile(oldMobileNo, newMobileNo);
                break;
            case 5:
                exit(0); // Exit Application
            default:
                cout << endl << "Invalid choice. Please enter a valid option." << endl;
                system("pause"); // wait for user input
            }
        }
        else {
            cout << endl << "Invalid account number or PIN. Please try again." << endl;
            system("pause"); // wait for user input
        }
    } while (true);

    return 0;
}
