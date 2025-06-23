/**
 * @brief assign3
 * @author Clayton Moeck
 */

#include <iostream>
#include <cmath>

using namespace std;

const double g = 32.17405;
const double π = 3.14159265359;
const double wallHeight = 75.0;
const double targetDistance = 150.0;
const double targetWidth = 50.0;

int main() 
{ 
  double u, θ, distanceToWall;

  cout << "Enter the distance from the wall the catapult is at (in feet): ";
  cin >> distanceToWall;

  cout << "Enter the initial velocity of the rock (in feet per second): ";
  cin >> u;

  cout << "Enter the launch angle (in degrees): ";
  cin >> θ;

  double angleToRadians = θ * (π / 180.0);
  double range = (pow(u,2) * 2 * (sin(angleToRadians) * (cos(angleToRadians)))) / g;
  double height = tan(angleToRadians) * distanceToWall - (g / (2 * pow(u,2) * pow(cos(angleToRadians),2))) * pow(distanceToWall,2);

  if (height <= 75.0 && height > 0)
  {
    cout << "Hits the wall " << height << " feet up." << endl;
    return 0;
  }
  
  if (range < targetDistance + distanceToWall)
    cout << "Too short!" << endl << "Rock traveled " << range << " feet" << endl;
  else if (range > targetDistance + targetWidth + distanceToWall)
    cout << "Too far!" << endl << "Rock traveled " << range << " feet." << endl;
  else
    cout << "Hit!" << endl << "Rock traveled " << range << " feet." << endl;
  
  return 0;
}