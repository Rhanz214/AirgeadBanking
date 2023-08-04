#include <iostream>
#include <iomanip>
#include "InitialSavings.h"

// Here we will define all the member functions that were in the header file.

using namespace std;

// This is the default constructor for when an object is initially created.
InitialSavings::InitialSavings() {
	m_initialInvestment = -1.0;
	m_monthlyDeposit = -1.0;
	m_annualRate = -1.0;
	m_years = -1;
}

// All of the object's setters.
void InitialSavings::setInitialInvestment(double t_initialInvestment) { // Sets initial investment.
	m_initialInvestment = t_initialInvestment;
}
void InitialSavings::setMonthlyDeposit(double t_monthlyDeposit) {       // Sets how much to deposit each month.
	m_monthlyDeposit = t_monthlyDeposit;
}
void InitialSavings::setAnnualInterest(double t_annualRate) {           // Sets how much the annual interest rate is.
	m_annualRate = t_annualRate / 100;
}
void InitialSavings::setNumberOfYears(int t_years) {                    // Sets the number of years the user will be saving.
	m_years = t_years;
}

// All of the object's getters.
double InitialSavings::getInitialInvestment() { return m_initialInvestment; } // Gets initial investment.
double InitialSavings::getMonthlyDeposit() { return m_monthlyDeposit; }       // Gets the monthly deposit.
double InitialSavings::getAnnualInterest() { return m_annualRate; }           // Gets the annual interest rate.
int InitialSavings::getNumberOfYears() { return m_years; }                    // Gets the number of years.

// Used to output the initial settings if need be.
void InitialSavings::printSettings() {
	cout << "Initial Investment is: " << fixed << setprecision(2) << m_initialInvestment << endl;
	cout << "Monthly Deposit is: " << setprecision(2) << m_monthlyDeposit << endl;
	cout << "Annual Rate is: " << setprecision(2) << m_annualRate << endl;
	cout << "Number of years is: " << setprecision(2) << m_years << endl;
}