/**
 * @brief assign1p2
 * @author Clayton Moeck
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{ 
  // We want to begin by asking the user to input the values for velocity and gravity.

  cout << "Please enter the velocity of the object being thrown in m/s."
  << " Only include numbers. For example, 27: ";
  double velocity;
  cin >> velocity;

  cout << "And now please enter the gravity of the planet/body you're on in m/s."
  << " Only include numbers. For example, 9.8: ";
  double gravity;
  cin >> gravity;

  // Next, we'll run through the standard equation to get the max height of the object thrown.

  double height = (1.0 / 2) * (pow(velocity, 2.0) / gravity);

  // Lastly, we'll display our results, listing both velocity and gravity first,
  // and then finishing it with the height.

  cout << "With the object's velocity being "
  << velocity << " m/s, and the force of gravity being "
  << gravity << " m/s, the height the object will reach is "
  << height << " meters.";

  return 0;
}