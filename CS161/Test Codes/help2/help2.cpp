#include <iostream>
#include <string>
#include <algorithm>  // Added for remove function


using namespace std;

const int ROWS = 13;
const int COLUMNS = 4;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
int findSeatLetter(char letter);
void displaySeats(char seats[][ROWS]);
void markSeatAsOccupied(char seats[][ROWS], int rowIndex, int seatIndex);

int main(void) {
    char seats[COLUMNS][ROWS] = {

        {'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'},
        {'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C'},
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    };
while (true) {
        displaySeats(seats);


        cout << endl << "Enter a seat or Q to quit: ";
        string input;
        cin >> input;
        cout << endl;

        if (input == "Q" ||  input == "q") {
            break;
        }


        string num = input.substr(0, input.length() - 1);
        char letter = input[input.length() - 1];

        int rowIndex = findRowIndex(stoi(num));
        int seatIndex = findSeatIndex(letter);


        if (rowIndex == -1 || seatIndex == -1) {
            cout << "Sorry, no such seat exists on the CRJ 200" << endl;
}
        else {
            markSeatAsOccupied(seats, rowIndex, seatIndex);
        }
    }

    return 0;
}

void displaySeats(char seats[][ROWS]) {

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            cout << seats[i][j] << ' ';

        }
        cout << endl;
    }
    cout << "\n" << "                  1 1 1 1" << endl << "1 2 3 4 5 6 7 8 9 0 1 2 3" << "\n" << endl; 

    for (int k = 2; k < 4; ++k) {
        for (int l = 0; l < ROWS; ++l) {
            cout << seats[k][l] << ' ';

        }
        cout << endl;
    }

}

void markSeatAsOccupied(char seats[][ROWS], int rowIndex, int seatIndex) {


    seats[seatIndex][rowIndex] = 'X';
}

int findRowIndex(int thisRow) {
    if (thisRow > ROWS || thisRow < 1) {
        return -1;
    }
    else {
        return thisRow - 1;  // Adjusted to match the correct row index
    }
}

int findSeatLetter(char letter) {
    // Convert seat letter to corresponding index

    if (letter == 'A') return 3;
    if (letter == 'B') return 2;
    if (letter == 'C') return 1;
    if (letter == 'D') return 0;
    return -1;
}

int findSeatIndex(char thisSeat) {
    // Convert seat letter to corresponding index DO NOT CHANGE
    if (thisSeat == 'A') return 3;

    else if (thisSeat == 'B') return 2;
    else if (thisSeat == 'C') return 1;
    else if (thisSeat == 'D') return 0;
    else return -1;
}