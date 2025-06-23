#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char char1, char2, char3;

    cin >> char1 >> char2 >> char3;

    bool hasDigit = (isdigit(char1) || isdigit(char2) || isdigit(char3));
    bool hasNonAlnum = (!isalnum(char1) || !isalnum(char2) || !isalnum(char3));

    if (hasDigit && hasNonAlnum)
        cout << "YES";
    else
        cout << "NO";
    

    return 0;
}