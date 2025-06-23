#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double pi;
	pi = 3.14159;
	
	double angle;
	double adjacent;
	cin >> angle >> adjacent;
	
	double radians;
	radians = angle * (pi/180);
	
	double hypotenuse;
	hypotenuse = adjacent / cos(radians);
	

	cout << hypotenuse;
}