#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;

    for (int row = 1; row <= size; row++) {
        int spaces = size - row;

        for (int i = 0; i < spaces; i++) {
            cout << " ";
        }

        int stars = row;

        for (int i = 0; i < stars; i++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}