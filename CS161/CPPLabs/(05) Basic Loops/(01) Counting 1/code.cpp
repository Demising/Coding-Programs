#include <iostream>
using namespace std;

int main() {
    int number;
    
    cin >> number;
    
    if (number <= 0) {
        cout << "Please enter a positive number." << std::endl;
        return 1; // Exit with an error code
    }
    
    for (int i = 1; i <= number; ++i) {
        cout << i;
    }
    
    cout << endl;
    
    return 0;
}