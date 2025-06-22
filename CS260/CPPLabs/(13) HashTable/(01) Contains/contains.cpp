#include <iostream>
using namespace std;

#include "StringHashTable.h"

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