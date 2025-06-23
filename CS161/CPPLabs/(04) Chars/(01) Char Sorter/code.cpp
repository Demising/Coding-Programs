#include <iostream>
using namespace std;

int main()
{
	char myChar;
    cin >> myChar;

    if (myChar >= 'A' && myChar <= 'J')
        cout << "1";
    else if (myChar >= 'K' && myChar <= 'P')
        cout << "2";
    else if (myChar >= 'Q' && myChar <= 'Z')
        cout << "3";
    else
        cout << "Invalid input. Please enter an uppercase letter.";
    

    return 0;
}