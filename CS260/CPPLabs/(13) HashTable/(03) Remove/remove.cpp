#include <iostream>
using namespace std;

#include "StringHashTable.h"

// YOUR CONTAINS HERE
bool StringHashTable::contains(const std::string& key) const {
  if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
    throw invalid_argument("Invalid key");

  int bucketNumber = getBucket(key);
  int initialBucket = bucketNumber;

  // Iterate through the table using linear probing
  while(buckets[bucketNumber] != EMPTY_CELL) {
    if(buckets[bucketNumber] == key) {
      return true;
    }
    bucketNumber = (bucketNumber + 1) % tableCapacity;
    if(bucketNumber == initialBucket) {
      // We've looped back to the initial bucket, the table is full and the key
      // isn't present
      return false;
    }
  }

  return false;
}

// YOUR INSERT HERE
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

void StringHashTable::remove(const std::string& key) {
  if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
    throw invalid_argument("Invalid value");

  int bucketNumber = getBucket(key);
  int initialBucket = bucketNumber;

  // Linear probing to find the key
  while(buckets[bucketNumber] != EMPTY_CELL) {
    if(buckets[bucketNumber] == key) {
      // Replace with tombstone and update size
      buckets[bucketNumber] = PREVIOUS_USED_CELL;
      currentSize--;
      return;
    }
    bucketNumber = (bucketNumber + 1) % tableCapacity;
    if(bucketNumber == initialBucket) {
      // We've looped back to the initial bucket, the table is full and the key
      // isn't present
      return;
    }
  }

  // Key not found, nothing to remove
}