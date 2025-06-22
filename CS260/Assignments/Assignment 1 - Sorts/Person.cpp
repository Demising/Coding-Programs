//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool operator==(const Person& p1, const Person& p2){
	if(p1.last == p2.last && p1.first == p2.first)
		return true;
	else
		return false;
}

bool operator<(const Person& p1, const Person& p2) {
	if(p1.last < p2.last || 
	   p1.last == p2.last && p1.first < p2.first)
		return true;
	else
		return false;
}

void sortByID(Person* array, int start, int end) {
	//TODO via quadratic sort algorithm - can add helper functions
	for (int i = start; i < end; ++i) {
		int minIndex = i;
		int minimum = stoi(array[i].kNum.substr(1));
		for (int j = i + 1; j < end; ++j) {
			int jNumber = stoi(array[j].kNum.substr(1));
			if (minimum > jNumber) {
				minIndex = j;
				minimum = jNumber;
			}
		}
		if (minIndex != i) {
			swap(array[i], array[minIndex]);
		}
	}
}

// bool compareNamesChars(const std::string& a, const std::string& b) {
// 	int i = 0;
	
// 	while (i < a.size() && i < b.size()) {
// 		if (a[i] < b[i]) {
// 			return true;
// 		} else if (a[i] > b[i]) {
// 			return false;
// 		}
// 		i++;
// 	}

// 	if (a.size() < b.size()) {
// 		return true;
// 	} else {
// 		return false;
// 	}
// }

int partitionFunction(Person* array, int low, int high) {
	Person pivot = array[low];

	int i = low + 1;
	int j = high;

	while (i <= j) {
		while ((i <= j) && ((array[i] < pivot) || ((array[i] == pivot) && (array[i] < pivot)))) { // || (array[i].last == pivot.last && array[i].first < pivot.first) operator<(array[i], pivot
			i++;
		}
		while ((i <= j) && (!(array[j] < pivot) || ((array[j] == pivot) && !(array[j] < pivot)))) { //|| (array[j].last == pivot.last && (pivot.first < array[j].first))
			j--;
		}
		if (i < j) {
			std::swap(array[i], array[j]);
			i++;
			j--;
		}
	}

	std::swap(array[low], array[j]);

	return j;
}

void nameSortInternal(Person* array, int low, int high) {
	if (low >= high) {
		return;
	}

	int pivotIndex = partitionFunction(array, low, high);

	nameSortInternal(array, low, pivotIndex - 1);

	nameSortInternal(array, pivotIndex + 1, high);
}

void nameSort(Person* array, int size)  {
	//TODO via quicksort algorithm - can add helper functions
	nameSortInternal(array, 0, size - 1);
}

void zipSortInternalSort(Person* array, int bucket[], int size) {
	Person* tempArray = new Person[size];
	for (int i = 0; i < size; i++) {
		tempArray[i] = array[i];
	}

	for (int i = size - 1; i >= 0; i--) {
		int index = array[i].zipCode % 97000;
		bucket[index]--;
		tempArray[bucket[index]] = array[i];
	}

	for (int i = 0; i < size; i++) {
		array[i] = tempArray[i];
	}
	delete[] tempArray;
}

void zipSortInternal(Person* array, int size) {
	int* bucketCount = new int[1000];
	for (int i = 0; i < 1000; i++) {
		bucketCount[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		int index = array[i].zipCode % 97000;
		bucketCount[index]++;
	}

	for (int i = 1; i < 1000; i++) {
		bucketCount[i] = bucketCount[i] + bucketCount[i - 1];
	}

	zipSortInternalSort(array, bucketCount, size);


	delete[] bucketCount;
}

void zipSort(Person* array, int size) {
	//TODO via bucketsort algorithm - can add helper functions
	zipSortInternal(array, size);
}