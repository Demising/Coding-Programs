/**
 * @author Clayton Moeck
 * @brief Unit tests for main.cpp
 */

//-----------------------------------------------------------------------------------
//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------

//Sample functions

// We do NOT want to define a main in this file, already have one in the
//  other tester. So comment out the define that says to create a main:
////#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include <iostream>
using namespace std;
#include "Person.h"
#include <string>
#include <fstream>
#include <sstream>

Person storePeople(string line) {
    Person p;
    string zipString;

    istringstream input(line);

    getline(input, p.kNum, ',');
    getline(input, p.last, ',');
    getline(input, p.first, ',');
    getline(input, zipString, ',');

    p.zipCode = stoi(zipString);

    return p;
}

bool compareByZipCode(const Person& a, const Person& b) {
    return a.zipCode < b.zipCode;
}

void arrayCopy(Person* people, Person* peopleCopy, int size) {
  for (int i = 0; i < size; i++) {
    peopleCopy[i] = people[i];
  }
}

Person* makeArray(int size) {
    string line;

    Person* peopleTest = new Person[size];

    ifstream file("tests.txt");
  
    for (int i = 0; i < size; i++) {
        getline(file, line);
        peopleTest[i] = storePeople(line);
    }

    return peopleTest;
}

TEST_CASE("1. Creating a Person") {
    string line = "K123456789,Smith,John,12345";
    Person p = storePeople(line);
    CHECK(p.kNum == "K123456789");
    CHECK(p.last == "Smith");
    CHECK(p.first == "John");
    CHECK(p.zipCode == 12345);
}

TEST_CASE("2. Creating Multiple People (Size 10).") {
    int size = 10;
    string line;

    Person* peopleTest2 = new Person[size];

    ifstream file("tests.txt");
  
    for (int i = 0; i < size; i++) {
        getline(file, line);
        peopleTest2[i] = storePeople(line);
    }

    CHECK(peopleTest2[0].kNum == "K1059298");
    CHECK(peopleTest2[0].last == "Wintheiser");
    CHECK(peopleTest2[0].first == "Claudie");
    CHECK(peopleTest2[0].zipCode == 97015);

    CHECK(peopleTest2[4].kNum == "K1067173");
    CHECK(peopleTest2[4].last == "Conroy");
    CHECK(peopleTest2[4].first == "Iliana");
    CHECK(peopleTest2[4].zipCode == 97019);

    CHECK(peopleTest2[9].kNum == "K1067994");
    CHECK(peopleTest2[9].last == "Carter");
    CHECK(peopleTest2[9].first == "Maddison");
    CHECK(peopleTest2[9].zipCode == 97621);

    delete[] peopleTest2;
}

TEST_CASE("3. Copying An Array.") {
    Person* peopleTest3 = makeArray(10);
    Person* peopleCopy3 = new Person[10];
    arrayCopy(peopleTest3, peopleCopy3, 10);
    for (int i = 0; i < 10; i++) {
        CHECK(peopleTest3[i].kNum == peopleCopy3[i].kNum);
        CHECK(peopleTest3[i].last == peopleCopy3[i].last);
        CHECK(peopleTest3[i].first == peopleCopy3[i].first);
        CHECK(peopleTest3[i].zipCode == peopleCopy3[i].zipCode);
    }
    delete[] peopleTest3;
    delete[] peopleCopy3;
}

TEST_CASE("4. Sorting People 2-7 by KNumber.") {
    Person* peopleTest4 = makeArray(10);
    Person* peopleCopy4 = new Person[10];
    arrayCopy(peopleTest4, peopleCopy4, 10);
    sortByID(peopleCopy4, 2, 8);
    CHECK(peopleCopy4[0].kNum == "K1059298");
    CHECK(peopleCopy4[1].kNum == "K1057424");
    CHECK(peopleCopy4[2].kNum == "K1067173");
    CHECK(peopleCopy4[3].kNum == "K1067632");
    CHECK(peopleCopy4[4].kNum == "K1079786");
    CHECK(peopleCopy4[5].kNum == "K1097919");
    CHECK(peopleCopy4[6].kNum == "K1097941");
    CHECK(peopleCopy4[7].kNum == "K1098858");
    CHECK(peopleCopy4[8].kNum == "K1012470");
    CHECK(peopleCopy4[9].kNum == "K1067994");
    delete[] peopleTest4;
    delete[] peopleCopy4;
}

TEST_CASE("5. Sorting People By Name Via Quicksort (Size 10).") {
    Person* peopleTest5 = makeArray(10);
    Person* peopleCopy5 = new Person[10];
    arrayCopy(peopleTest5, peopleCopy5, 10);
    nameSort(peopleCopy5, 10);
    std::sort(peopleTest5, peopleTest5 + 10);
    for (int i = 0; i < 10; i++) {
        CHECK(peopleTest5[i].last == peopleCopy5[i].last);
    }


    for (int i = 0; i < 10; i++) {
        CHECK(peopleTest5[i].first == peopleCopy5[i].first);
    }
    delete[] peopleTest5;
    delete[] peopleCopy5;
}

TEST_CASE("5. Sorting People By Name Via Quicksort (Size 100).") {
    Person* peopleTest6 = makeArray(100);
    Person* peopleCopy6 = new Person[100];
    arrayCopy(peopleTest6, peopleCopy6, 100);
    nameSort(peopleCopy6, 100);
    std::sort(peopleTest6, peopleTest6 + 100);
    for (int i = 0; i < 100; i++) {
        CHECK(peopleTest6[i].last == peopleCopy6[i].last);
    }

    for (int i = 0; i < 100; i++) {
        CHECK(peopleTest6[i].first == peopleCopy6[i].first);
    }
    delete[] peopleTest6;
    delete[] peopleCopy6;
}

TEST_CASE("6. Sorting People By Name Via Quicksort (Size 10,000)") {
    Person* peopleTest6 = makeArray(10000);
    Person* peopleCopy6 = new Person[10000];
    arrayCopy(peopleTest6, peopleCopy6, 10000);
    nameSort(peopleCopy6, 10000);
    std::sort(peopleTest6, peopleTest6 + 10000);
    for (int i = 0; i < 10000; i++) {
        CHECK(peopleTest6[i].last == peopleCopy6[i].last);
    }

    for (int i = 0; i < 10000; i++) {
        CHECK(peopleTest6[i].first == peopleCopy6[i].first);
    }
    delete[] peopleTest6;
    delete[] peopleCopy6;
}

TEST_CASE("7. Sorting Zip Codes via Bucket Sort (Size 1,000)") {
    Person* peopleTest7 = makeArray(1000);
    Person* peopleCopy7 = new Person[1000];
    arrayCopy(peopleTest7, peopleCopy7, 1000);
    zipSort(peopleCopy7, 1000);
    std::stable_sort(peopleTest7, peopleTest7 + 1000, compareByZipCode);
    for (int i = 0; i < 1000; i++) {
        CHECK(peopleTest7[i].zipCode == peopleCopy7[i].zipCode);
    }
    delete[] peopleTest7;
    delete[] peopleCopy7;
}

TEST_CASE("8. Sorting Zip Codes via Bucket Sort (Size 10,000).") {
    Person* peopleTest8 = makeArray(10000);
    Person* peopleCopy8 = new Person[10000];
    arrayCopy(peopleTest8, peopleCopy8, 10000);
    zipSort(peopleCopy8, 10000);
    std::stable_sort(peopleTest8, peopleTest8 + 10000, compareByZipCode);
    for (int i = 0; i < 10000; i++) {
        CHECK(peopleTest8[i].zipCode == peopleCopy8[i].zipCode);
    }
    delete[] peopleTest8;
    delete[] peopleCopy8;
}