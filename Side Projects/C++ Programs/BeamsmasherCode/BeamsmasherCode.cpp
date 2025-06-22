/**
 * @file BeamsmasherCode.cpp
 * @author Clayton 'Demising'
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 */

#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    cout << "Please enter in the following numbers" << endl;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Z: ";
    cin >> z;

    cout << "-------------------" << endl;
    cout << "First number is: " << (2 * x) + 11 << endl;
    cout << "Second number is: " << ((2 * z) + y) - 5 << endl;
    cout << "Third number is: " << abs((y + z) - x) << endl;
}

