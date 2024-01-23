/**
 * @author Clayton Moeck
 * @brief assign4
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{ 
  double balance,monthlyPayment,annualPercentRate;
  int month = 0;
  cout << "Enter in your balance on the loan: ";
  cin >> balance;
  cout << "Enter your monthly payment for the loan: ";
  cin >> monthlyPayment;
  cout << "Enter your APR rate as a percentage: ";
  cin >> annualPercentRate;

  cout << "Month\tInt.\tPay\tBalance" << endl;

  if (month == 0)
  {
    cout << fixed << setprecision(2);
    cout << month << "\t" << "\t" << "\t" << balance << endl;
    month++;
  }
  
  double interest;
  double remainingBalance = balance;
  double monthlyInterest = (annualPercentRate / 1200); // To make Monthly Interest into a decimal value already without complicating the code.;

  while (remainingBalance > monthlyPayment)
  {
    interest = remainingBalance * monthlyInterest;
    remainingBalance = (remainingBalance + interest) - monthlyPayment;
    cout << month << "\t" << interest << "\t" << monthlyPayment << "\t" << remainingBalance << endl;
    cout << fixed << setprecision(2);
    month++;
  }

  interest = remainingBalance * monthlyInterest;
  double finalPayment = remainingBalance + interest;
  cout << month << "\t" << interest << "\t" << finalPayment << "\t" << 0.00 << endl;

  return 0;
}