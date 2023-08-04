#ifndef INITIAL_SAVINGS_H
#define INITIAL_SAVINGS_H

/*
 * this is the header file for the InitialSavings class which will allow
 * the app to create an object for an initial investment setting and allow the user
 * to enter the numbers they would like to use, then create the object with those settings.
 *
 */

using namespace std;

// Here is the class definition along with the member and function declarations.
class InitialSavings {

// This is the public declarations which anyone in the program could use.
public:
	InitialSavings();                                      // Class constructor.
	void setInitialInvestment(double t_initialInvestment); // Function declaration for setting the initial investment.
	void setMonthlyDeposit(double t_monthlyDeposit);       // Function declaration for setting the monthly deposit.
	void setAnnualInterest(double t_annualRate);           // Function declaration for setting the annual interest rate.
	void setNumberOfYears(int t_years);                    // Function declaration for setting the number of years.
	double getInitialInvestment();                         // Function declaration for getting the initial investment.
	double getMonthlyDeposit();                            // Function declaration for getting the monthly deposit.
	double getAnnualInterest();                            // Function declaration for getting the annual interest rate.
	int getNumberOfYears();                                // Function declaration for getting the number of years.
	void printSettings();                                  // Function declaration for printing all numbers entered.

// This is the private declarations which only the class can use.
private:
	// Declaring all varaiables the class will use.
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualRate;
	int m_years;

};

#endif