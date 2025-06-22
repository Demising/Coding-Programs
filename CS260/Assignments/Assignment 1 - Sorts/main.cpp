#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Person.h"

using namespace std;

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

void arrayCopy(Person* people, Person* peopleCopy, int size) {
  for (int i = 0; i < size; i++) {
    peopleCopy[i] = people[i];
  }
}



int main() {
  int size;
  string line;
  cout << "Please enter in the number of records you want: ";
  cin >> size;

  Person* people = new Person[size];

  ifstream file("people.txt");
  
  for (int i = 0; i < size; i++) {
    getline(file, line);
    people[i] = storePeople(line);
  }

  cout << "-----------------------------Section 1----------------------------" << endl;
  cout << "The last record read was: " <<
  people[size - 1].kNum << ", " <<
  people[size - 1].last << ", " <<
  people[size - 1].first << ", " <<
  people[size - 1].zipCode << endl;

  cout << "-----------------------------Section 2----------------------------" << endl;

  Person* peopleCopy1 = new Person[size];
  arrayCopy(people, peopleCopy1, size);

  sortByID(peopleCopy1, 2, 7);

  for (int i = 0; i < 10; i++) {
      cout << peopleCopy1[i].kNum << ", " << peopleCopy1[i].last << ", " << peopleCopy1[i].first << ", " << peopleCopy1[i].zipCode << endl;
  }

  cout << "-----------------------------Section 3----------------------------" << endl;
  Person* peopleCopy2 = new Person[size];
  arrayCopy(people, peopleCopy2, size);

  clock_t start = clock();
  nameSort(peopleCopy2, size);
  clock_t end = clock();

  cout << "Time taken to sort: " << (double)(end - start) * 1.000 / CLOCKS_PER_SEC << " seconds" << endl;
  for (int i = 0; i < 10; i++) {
    cout << peopleCopy2[i].kNum << ", " << peopleCopy2[i].last << ", " << peopleCopy2[i].first << ", " << peopleCopy2[i].zipCode << endl;
  }

  cout << "-----------------------------Section 4----------------------------" << endl;
  Person* peopleCopy3 = new Person[size];
  arrayCopy(people, peopleCopy3, size);

  clock_t start2 = clock();
  zipSort(peopleCopy3, size);
  clock_t end2 = clock();
  cout << "Time taken to sort: " << (double)(end2 - start2) * 1.000 / CLOCKS_PER_SEC << " seconds" << endl;
  for (int i = 0; i < 10; i++) {
    cout << peopleCopy3[i].kNum << ", " << peopleCopy3[i].last << ", " << peopleCopy3[i].first << ", " << peopleCopy3[i].zipCode << endl;
  } 

  delete[] people;
  delete[] peopleCopy1;
  delete[] peopleCopy2;
  delete[] peopleCopy3;

}