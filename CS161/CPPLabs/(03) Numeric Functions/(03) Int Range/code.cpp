#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double decimalValue;
	cin >> decimalValue;
	
	double value1;
	double value2;
	
	value1 = ceil(decimalValue);
	value2 = floor(decimalValue);
	
	cout << value2 << " " << value1;
}