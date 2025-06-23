#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;

    for (int row = 1; row <= size; row++) {
        int stars = 2 * row - 1;

        for (int i = 0; i < stars; i++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}