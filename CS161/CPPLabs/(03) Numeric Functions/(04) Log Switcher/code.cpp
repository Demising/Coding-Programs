#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    double number;
	cin >> number;
	
	double power;
	power = log(number) / log(2);
	
	cout << power;
}