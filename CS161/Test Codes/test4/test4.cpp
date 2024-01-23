/**
 * @author Demising
 * @brief test4
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fullName;
    cout << "Enter a full name: ";
    getline(cin, fullName);

    // Find the last space in the full name to separate first and last names
    size_t lastSpace = fullName.find_first_of(" ");
    
    if (lastSpace != string::npos) {
        // Extract the last name and the first initial
        string lastName = fullName.substr(lastSpace + 1);
        string firstInitial = fullName.substr(0, 1);
        
        // Print the result in the desired format
        cout << lastName << ", " << firstInitial << "." << endl;
    } else {
        cout << "Invalid input. Please enter a full name in the format 'First Last'." << endl;
    }

    return 0;
}