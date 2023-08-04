#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "InitialSavings.h"

/*
 * This program is to be used by Airgead Banking and will let the user see how much
 * their investment can grow based on the numbers they enter for the initial investment, 
 * how much they will deposit monthly, the annual interest rate, and how many years they 
 * plan on investing.
 * 
 * Author: Nik Johnston
 * Date:   8/1/2021
 * 
 */

using namespace std;

InitialSavings investmentObj; // Creates the object for the savings information.

// A function that will output questions to ask the user, and then have user input while also verifying correct numbers entered.
void askInitial() {

	// Declaring and initializing variables.
	double invest = 0.0;
	double monthly = 0.0;
	double interest = 0.0;
	int numYears = 0;

	// While loop to have user enter positive real numbers for initial savings, monthly deposit, interest rate, and years.
	while (true) {
		
		/* 
		 * Here is a try block of statements that will verify the numbers the user enters
		 * to verify that the numbers entered are real and positive. If the numbers are incorrect
		 * then an exception will be thrown and the program will loop to the beginning of the try
		 * block again until the user enters actual numbers.
		 *
		 */

		try {
			cout << endl;
			cout << "********************************" << endl; // Series of output statements for user to see.
			cout << "********** Data Input **********" << endl;
			cout << "Initial Investment Amount:  $";

			// The program will now ask the user to enter numbers for each setting, and if the numbers are not real, a break statement is used along
			// with an runtime error thrown.
			cin >> invest;
			if (invest < 0.0) {
				throw runtime_error("Invalid initial investment amount");
				break;
			}
			cout << "Monthly Deposit:  $";
			cin >> monthly;
			if (monthly < 0.0) {
				throw runtime_error("Invalid monthly deposit amount");
				break;
			}
			cout << "Annual Interest:  %";
			cin >> interest;
			if (interest < 0.0) {
				throw runtime_error("Invalid interest rate");
				break;
			}
			cout << "Number of years:  ";
			cin >> numYears;
			if (numYears < 0) {
				throw runtime_error("Invalid amount of years");
				break;
			}
			break;
		}

		// Catch statement that only outputs if one of the input's was bad.
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Please try again." << endl;
		}

	}
	
	// After user enters all correct numbers, will use the object call to set the initial settings to be used throughout.
	investmentObj.setInitialInvestment(invest);
	investmentObj.setMonthlyDeposit(monthly);
	investmentObj.setAnnualInterest(interest);
	investmentObj.setNumberOfYears(numYears);

	system("PAUSE"); // Waits for user to continue.
	cout << endl;
	cout << endl;

}

// A function that will calculate and output the savings without monthly deposits.
void withoutMonthlyDeposit() {
	// Declaring variables.
	double balance = investmentObj.getInitialInvestment();
	double interestEarned;
	int i;

	// Series of output statements.
	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "  Year        Year End Balance     Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// For loop that will calculate interest earned and total amount, then output in a table for the user.
	for (i = 1; i <= investmentObj.getNumberOfYears(); ++i) {
		interestEarned = (investmentObj.getAnnualInterest() * balance);
		balance = (balance + interestEarned);

		cout << "   " << i << setw(16) << "$" << fixed << setprecision(2) << balance;
		cout << setw(21) << right << "$" << interestEarned << "   " << endl;
		cout << endl;
	}

}

// A function that will calculate and output the savings with monthly deposits.
void withMonthlyDeposit() {
	// Declaring variables.
	double balance = investmentObj.getInitialInvestment();
	double interestEarned;
	double yearlyInterest;
	int i;
	int j;

	// A series of output statements.
	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "  Year        Year End Balance     Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// For loop that will calculate and output interest earned and total amount in a table for the user.
	for (i = 1; i <= investmentObj.getNumberOfYears(); ++i) {
		yearlyInterest = 0.0;

		// Nested for loop to calculate based off of months.
		for (j = 1; j <= 12; ++j) {
			interestEarned = (balance + investmentObj.getMonthlyDeposit()) * (investmentObj.getAnnualInterest() / 12);
			yearlyInterest = yearlyInterest + interestEarned;
			balance = balance + investmentObj.getMonthlyDeposit() + interestEarned;
		}
		
		// A series of output statements.
		cout << "   " << i << setw(16) << right << "$" << fixed << setprecision(2) << balance;
		cout << setw(21) << right << "$" << yearlyInterest << "   " << endl;
		cout << endl;

	}
}



int main() {
	// Declaring and initializing variable.
	char cmd = 'y';

	// A while loop that will allow the user to rerun program with different amounts until they enter the 'q' key.
	while (cmd != 'q') {
		askInitial(); // A function call.
		withoutMonthlyDeposit(); // A function call.
		withMonthlyDeposit(); // A function call.

		// Asks the user to enter a key if they want to continue, then inputs into the cmd variable.
		cout << "Push any key to try other amounts or type 'q' to quit: ";
		cin >> cmd;

		cout << endl;
	}

	// A series of output statements.
	cout << "Thanks for trying Airgead's investing app!" << endl;
	cout << "Have a wonderful day!" << endl;

   return 0;
}