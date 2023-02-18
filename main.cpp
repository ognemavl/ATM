#include<conio.h> // We are using this header to get a function from it
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
	// The rage of long int is longer than the normal Int
	long int account_No;
	string name;
	int PIN;
	double balance;
	string mobile_No;

public:
	void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
		account_No = account_No_a;
		name = name_a;
		PIN = PIN_a;
		balance = balance_a;
		mobile_No = mobile_No_a;
	}

	long int getAccountNo() {
		return account_No;
	}

	string getName() {
		return name;
	}

	int getPIN() {
		return PIN;
	}

	double getBalance() {
		return balance;
	}

	string getMobileNo() {
		return mobile_No;
	}

	void setMobile(string mob_prev, string mob_new) {
		if (mob_prev == mobile_No) {
			mobile_No = mob_new;
			cout << endl << "Successfully Updated Mobile NO.";
			_getch(); // getch is to hold the screen (untill the user presses any key)
		}
	}

	void cashWithDraw(int amount_a) {
		if (amount_a > 0 && amount_a < balance) {
			balance -= amount_a;
			cout << endl << "Please Collect your cash";
			cout << endl << "Available Balance: " << balance;
			_getch();
		}
		else {
			cout << endl << "Invalid Input or Insufficient Balance";
			_getch();
		}
	}
};

int main()
{
	int choice = 0, enterPin;
	long int enterAccountNo;

	system("cls"); // this sistem function is used to clear the screen

	ATM user1;

	user1.setData(1234567, "Ognema", 1111, 40000.692, "9087654321");

	do {
		system("cls");

		cout << endl << "****Welcome to ATM****";
		cout << endl << "Enter Your Account No ";
		cin >> enterAccountNo;

		cout << endl << "Enter PIN";

		cin >> enterPin;

		if ((enterAccountNo == user1.getAccountNo()) && (enterPin == user1.getPIN())) {
			
				int amount = 0;
				string oldMobileNo, newMobileNo;

				system("cls");
				// User Interface

				cout << endl << "**** Welcome to ATM****";
				cout << endl << "Select Options";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash Withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile No";
				cout << endl << "5. Exit";
				cin >> choice;

				switch (choice) {
				case 1:
					cout << endl << "Your Bank balance is: " << user1.getBalance();

					_getch();
					break;
				case 2:
					cout << endl << "Enter the amount: ";
					cin >> amount;
					user1.cashWithDraw(amount);

					break;
				case 3:
					cout << endl << "*** User Details are:- ";
					cout << endl << "-> Account no ";
					cout << endl << "-> Name ";
					cout << endl << "-> Balance ";
					cout << endl << "-> Mobile No. ";

					_getch();
					break;

				case 4:
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldMobileNo;

					cout << endl << "Enter New Mobile No. ";
					cin >> newMobileNo;

					user1.setMobile(oldMobileNo, newMobileNo);
					break;

				case 5:
					exit(0); // Exit Application

				default:
					cout << endl <<"Enter valid data !!!";
				}
		}
	} while (1);
}