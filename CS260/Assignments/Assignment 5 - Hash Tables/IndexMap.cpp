//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "IndexMap.h"
#include <iostream>

using namespace std;

IndexMap::IndexMap(int startingBuckets) {
    numBuckets = startingBuckets;
    keyCount = 0;
    buckets = new IndexRecord[numBuckets];
}

IndexMap::~IndexMap() {
    delete[] buckets;
}

IndexRecord IndexMap::get(const std::string& word) const {
    unsigned int location = getLocationFor(word);
    unsigned int originalLocation = location;
    while (buckets[location].word != "?" && buckets[location].word != word) {
        location = (location + 1) % numBuckets;
        if (location == originalLocation) {
            return IndexRecord();
        }
    }
    return buckets[location];
}

bool IndexMap::contains(const std::string& key) const {
    unsigned int location = getLocationFor(key);
    unsigned int originalLocation = location;
    while (buckets[location].word != "?" && buckets[location].word != key) {
        location = (location + 1) % numBuckets;
        if (location == originalLocation) {
            return false;
        }
    }
    return buckets[location].word == key;
}

int IndexMap::numKeys() const {
    return keyCount;
}

void IndexMap::print() const {
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].word != "?") {
            cout << buckets[i] << endl;
        }
    }
}

void IndexMap::grow() {
    IndexRecord* oldBuckets = buckets;
    int oldNumBuckets = numBuckets;

    numBuckets = 2 * oldNumBuckets + 1;
    buckets = new IndexRecord[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i].word = "?";
    }

    for (int i = 0; i < oldNumBuckets; i++) {
        if (oldBuckets[i].word != "?") {
            unsigned int location = getLocationFor(oldBuckets[i].word);
            while (buckets[location].word != "?") {
                location = (location + 1) % numBuckets;
            }
            buckets[location] = oldBuckets[i];
        }
    }

    delete[] oldBuckets;
}

unsigned int IndexMap::getLocationFor(const std::string& key) const {
    unsigned int hash = 0;
    for (unsigned int i = 0; i < key.size(); i++) {
        hash = hash * 31 + key[i];
    }
    return hash % numBuckets;
}

void IndexMap::findWordPairs(const std::string& key1, const std::string& key2) const {
    IndexRecord record1 = get(key1);
    IndexRecord record2 = get(key2);

    for (int i = 0; i < record1.locations.size(); i++) {
        for (int j = 0; j < record2.locations.size(); j++) {
            if (record1.locations[i].pageNum == record2.locations[j].pageNum && record1.locations[i].wordNum + 1 == record2.locations[j].wordNum) {
                cout << key1 << " at " << record1.locations[i] << " is followed by " << key2 << " at " << record2.locations[j] << endl;
            }
        }
    }
}

std::string IndexMap::firstWordOnPage(int pageNumber) const {
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].locations.size(); j++) {
            if (buckets[i].locations[j].pageNum == pageNumber) {
                if (buckets[i].locations[j].wordNum == 1) {
                    return buckets[i].word;
                }
            }
        }
    }
    return "Not found";
}

void IndexMap::add(const std::string& key, int pageNumber, int wordNumber) {
    if (keyCount >= numBuckets * 0.7) {
        grow();
    }

    unsigned int location = getLocationFor(key);
    while (buckets[location].word != "?" && buckets[location].word != key) {
        location = (location + 1) % numBuckets;
    }

    if (buckets[location].word == "?") {
        buckets[location].word = key;
        keyCount++;
    }

    buckets[location].addLocation(IndexLocation(pageNumber, wordNumber));
}