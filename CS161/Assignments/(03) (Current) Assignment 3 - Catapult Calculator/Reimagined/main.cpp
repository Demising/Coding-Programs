#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;
const double degreesToRadians = pi / 180.0;
const double gravity = -9.8;
const double wallHeight = 75;
const double wallToVillage = 150;
const double villageDiameter = 2000;
double timeToWall;

int main() {
  cout << "What is the distance of the catapult from the wall? (in meters): ";
  double distance;
  cin >> distance;

  cout << "What is the angle that the rock is launched at? (in degrees): ";
  double angle;
  cin >> angle;

  cout << "What is the initial velocity of the rock? (in meters per second): ";
  double velocity;
  cin >> velocity;

  double angleInRadians = angle * degreesToRadians;
  double initialXVelocity = velocity * cos(angleInRadians);
  double initialYVelocity = velocity * sin(angleInRadians);
  
  double totalTimeInAir = -initialYVelocity / gravity;
  cout << "Time in air: " << totalTimeInAir << " seconds" << endl;
  double xPosition = initialXVelocity * totalTimeInAir;

  if (xPosition < distance) {
    cout << "The rock didn't reach the wall." << endl;
    cout << "The rock hit the ground at: " << xPosition << " meters" << endl;
  } else {
    timeToWall = distance / initialXVelocity;
    cout << "Time to wall: " << timeToWall << " seconds" << endl;
  }

  double yPosition = initialYVelocity * timeToWall + 0.5 * gravity * timeToWall * timeToWall;
  cout << "Y position at wall: " << yPosition << " meters" << endl;

  if (yPosition < wallHeight) {
    cout << "The rock hit the wall." << endl;
  }

  

}
