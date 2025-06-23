#include <iostream>

using namespace std;

int main() {
  cout << "Enter the number of inches you have: ";
  double inches;
  cin >> inches;

  int remainingInches = static_cast<int>(inches);

  int miles = remainingInches / 63360;
  remainingInches %= 63360;

  int yards = remainingInches / 36;
  remainingInches %= 36;

  int feet = remainingInches / 12;
  remainingInches %= 12;

  cout << "From the" << inches << " inches, you have:\n";
  cout << miles << " miles\n";
  cout << yards << " yards\n";
  cout << feet << " feet and\n";
  cout << remainingInches << " inches\n";
}
