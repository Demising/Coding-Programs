//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef PERSON_H
#define PERSON_H

#include <string>


//OK to add code here


//--------------------------------------------------
//DO NOT MODIFY THIS BLOCK
//--------------------------------------------------

struct Person {
	std::string kNum;
	std::string last;
	std::string first;
	int zipCode;
};

//Two Persons are == if their first and last names are the same
bool operator==(const Person& p1, const Person& p2);

//Natural ordering of Persons will be alphabetical by first then last
//p1 is < p2 if p1.last < p2.last or they have the same last name and p1.first < p2.first
bool operator<(const Person& p1, const Person& p2);

//Sort a portion of array of Persons by ID (KNumber)
//  Range of elements to sort is [start-end) (inclusive or start, exclusive of end)
void sortByID(Person* array, int start, int end);

//Sort an array of Persons so that they are alphabetized by last name
//  Individuals with the same last name should be ordered by first name
void nameSort(Person* array, int size);

//Sort an array of Persons so that they are sorted by zip code
void zipSort(Person* array, int size);

//--------------------------------------------------
//END DO NOT MODIFY BLOCK
//--------------------------------------------------


//OK to add code here
int partitionFunction(Person* array, int low, int high);

void nameSortInternal(Person* array, int low, int high);

void zipSortInternalSort(Person* array, int bucket[], int size);

void zipSortInternal(Person* array, int size);



#endif // PERSON_H
