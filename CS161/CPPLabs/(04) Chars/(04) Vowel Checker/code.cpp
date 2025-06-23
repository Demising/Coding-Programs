#include <iostream>
using namespace std;

int main()
{
    char inputChar;

    cin >> inputChar;

    inputChar = tolower(inputChar);

    if (inputChar == 'a' || inputChar == 'e' || inputChar == 'i' || inputChar == 'o' || inputChar == 'u')
        cout << "vowel";
    else if (isalpha(inputChar))
        cout << "consonant";
    else
        cout << "Invalid input. Please enter a letter.";
    

    return 0;
}