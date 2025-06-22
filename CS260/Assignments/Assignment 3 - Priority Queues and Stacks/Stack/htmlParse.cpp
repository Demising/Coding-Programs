//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <fstream>
#include <iostream>

#include "Stack.h"

using namespace std;

int main()
{

  cout << "-----------------------------Section 1-----------------------------" << endl;
  string word;
  ifstream inFile("Document.html");
  if (!inFile.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }
  cout << "Section 1 Done." << endl;

  cout << "-----------------------------Section 2-----------------------------" << endl;

  Stack<string> tagStack;

  while (inFile >> word) {
    if (word[0] == '<') {
      if (word[1] == '/') {
        string temp1 = word.substr(0, 1);
        string temp2 = word.substr(2, word.length() - 1);
        temp1.append(temp2);
        word = temp1;
        if (word == tagStack.peek()) {
          tagStack.pop();
        } else {
          cout << "Error: " << word << " does not match " << tagStack.peek() << endl;
          return 1;
        }
      } else {
        tagStack.push(word);
      }
    } else {
      tagStack.reversePrint();
      cout << word << endl;
    }
  }
  if (!tagStack.isEmpty()) {
    cout << "Error: " << tagStack.peek() << " is not closed" << endl;
    tagStack.print();
    return 1;
  }
}
