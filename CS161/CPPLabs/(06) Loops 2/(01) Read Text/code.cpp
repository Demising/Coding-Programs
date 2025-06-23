#include <iostream>
using namespace std;

int main()
{
    char input;
	
	while (cin >> input && input != '.')
	{
		cout << input;
	}
	
	return 0;
}