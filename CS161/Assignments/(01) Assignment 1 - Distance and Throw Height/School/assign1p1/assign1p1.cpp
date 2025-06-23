/**
 * @brief assign1p1
 * @author Clayton Moeck
 */

#include <iostream>

using namespace std;

int main()
{ 
  // We want to take a certain number in the measurement of inches,
  // and convert it across Miles, Yards, Foot/Feet, and Inches (Remainder).

  // We'll begin by asking for the number of inches

  cout << "Enter the number of inches you have."
  << " Please leave the word inches out of the input. For example, 76536: ";
  double inches;
  cin >> inches;

  // We'll convert amount to remainingInches, and making it a int integer.

  int remainingInches = static_cast<int>(inches);

  // After receiving the input for inches (as assigned the variable "inches"),
  // we'll go over a series of divisions and remainder operators.

  // First, we'll find the amount of Miles with remainingInches through division.
  // Then we'll take our remainingInches value, and replace it with a remainder equation of the
  // initial remainingInches value and 63360 (amount of Inches in a Mile).

  int numberOfMiles = remainingInches / 63360;
  remainingInches = remainingInches % 63360;

  // Second, we'll find the amount of Yards with remainingInches through division.
  // Then, we'll take the remainingInches value from the previous section,
  // and replace it with a remainder equation of itself and 36 (amount of Inches in a Yard).

  int numberOfYards = remainingInches / 36;
  remainingInches = remainingInches % 36;

  // Third, we'll find the amount in Feet with remainingInches through division.
  // Then, we'll take the remainingInches value from the previous section,
  // and replace it with a remainder equation of itself and 12 (amount of Inches in a foot).

  int numberOfFeet = remainingInches / 12;
  remainingInches = remainingInches % 12;

  // Fourth, we'll find the number of inches in remainingInches and give it the variable number "inches"

  int numberOfInches = remainingInches;

  // Finally, we'll display our results.
  
  cout << inches << " inches directly translates to " << numberOfMiles 
  << " Miles, " << numberOfYards << " Yards, " << numberOfFeet 
  << " Foot/Feet, " << " and " << numberOfInches << " inches.";

  cout << " For a conversion to metric, that is: ";

  double millimeters = static_cast<double>(inches * 25.4);

  int remainingMillimeters = static_cast<int>(millimeters);

  int numberOfKilometers = remainingMillimeters / 1000000;
  remainingMillimeters = remainingMillimeters % 1000000;

  int numberOfMeters = remainingMillimeters / 1000;
  remainingMillimeters = remainingMillimeters % 1000;

  int numberOfCentimeters = remainingMillimeters / 10;
  remainingMillimeters = remainingMillimeters % 10;

  int numberOfMillimeters = remainingMillimeters;

  cout << millimeters << " millimeters, which directly translates to "  << numberOfKilometers << " Kilometers, " << numberOfMeters << " Meters, " << numberOfCentimeters 
  << " Centimeters," << " and " << numberOfMillimeters << " Millimeters.";

  return 0;
}