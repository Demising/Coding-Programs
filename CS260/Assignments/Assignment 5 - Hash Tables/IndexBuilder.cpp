#include "IndexMap.h"
#include "IndexRecord.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("GreatExpectations.txt");
  IndexMap GE(10);

  cout << "-----------------Section 3-----------------" << endl;
  string word;

  int pageNumber = 1;
  int totalNumberOfWords = 0;
  int wordNumber = 1;

  clock_t start = clock();

  while (file >> word) {
    if (word == "----------------------------------------") {
      pageNumber++;
      wordNumber = 1;
    } else {
      for (int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);
      }
      GE.add(word, pageNumber, wordNumber);
      wordNumber++;
      totalNumberOfWords++;
    }
  }

  clock_t end = clock();
  
  cout << "Indexing took " << (end - start) / (double)CLOCKS_PER_SEC << " seconds" << endl;
  cout << "Great Expectations has " << GE.numKeys() << " unique words" << endl;
  cout << "Great Expectations has " << totalNumberOfWords << " total words" << endl;

  IndexRecord fathers = GE.get("fathers");
  cout << fathers << endl;

  cout << "-----------------Section 4-----------------" << endl;
  GE.findWordPairs("great", "expectations");
  // GE.findWordPairs("my", "father");

  cout << "-----------------Section 5-----------------" << endl;
  string firstWord = GE.firstWordOnPage(100);
  cout << "The first word on page 100 is " << firstWord << endl;
  // string firstWord2 = GE.firstWordOnPage(50);
  // cout << "The first word on page 100 is " << firstWord2 << endl;
  // string firstWord3 = GE.firstWordOnPage(1);
  // cout << "The first word on page 100 is " << firstWord3 << endl;
  // string firstWord4 = GE.firstWordOnPage(3);
  // cout << "The first word on page 100 is " << firstWord4 << endl;
}