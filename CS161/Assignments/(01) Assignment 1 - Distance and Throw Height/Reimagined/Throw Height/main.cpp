#include <iostream>
#include <cmath>

using namespace std;

double height(double velocity, double gravity) {
  double height;
  height = ((velocity)*(-velocity/-gravity)) + ((-0.5)*(gravity)*(pow((-velocity/-gravity), 2)));
  return height;
}

int main() {
  cout << "Please enter the velocity of the object being thrown (in m/s): ";
  double velocity;
  cin >> velocity;

  cout << "Now enter the gravity of the planet you are on (in m/s^2): ";
  double gravity;
  cin >> gravity;

  double result = height(velocity, gravity);
  cout << "The height of the object is: " << result << " meters.";
}
