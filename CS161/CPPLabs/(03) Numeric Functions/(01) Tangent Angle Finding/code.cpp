#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double opposite;
	double adjacent;
    cin >> opposite >> adjacent;
	
	double angleX = atan(opposite/adjacent);
	
	cout << angleX;

}