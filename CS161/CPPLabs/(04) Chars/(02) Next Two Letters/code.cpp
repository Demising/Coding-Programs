#include <iostream>
using namespace std;

int main()
{
    char inputChar;

    cin >> inputChar;

    char nextChar1 = inputChar + 1;
    char nextChar2 = inputChar + 2;
	
    if (nextChar1 > 'z')
    	nextChar1 = 'a' + (nextChar1 - 'z' - 1);
       
    if (nextChar2 > 'z')
    	nextChar2 = 'a' + (nextChar2 - 'z' - 1);


	cout << nextChar1 << nextChar2;


    return 0;
}