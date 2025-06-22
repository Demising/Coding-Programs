#include <iostream>
using namespace std;

#include "StringHashTable.h"

void StringHashTable::insert(const std::string& key) {
  if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
    throw invalid_argument("Invalid key");

  // Grow if needed
  if(currentSize >= MAX_LOAD * tableCapacity)
    grow();

  int bucketNumber = getBucket(key);

  // Linear probing to find the first available location
  while(buckets[bucketNumber] != EMPTY_CELL &&
        buckets[bucketNumber] != PREVIOUS_USED_CELL) {
    if(buckets[bucketNumber] == key) {
      // The key is already in the table, no need to insert again
      return;
    }
    bucketNumber = (bucketNumber + 1) % tableCapacity;
  }

  // Insert the key and update size
  buckets[bucketNumber] = key;
  currentSize++;
}