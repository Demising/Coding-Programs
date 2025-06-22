#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <ctime>

#include "Address.h"
#include "ArrayList.h"
#include "AddressArrayList.h"
#include "AddressLinkedList.h"

using namespace std;

//==========================================================
//Test Case Group 1: Creating ArrayLists
//==========================================================

TEST_CASE("1. Testing AddressArrayList") {
  int size = 8;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }

  CHECK(testListA.listSize() == 4);
  CHECK(testListB.listSize() == 4);

  testListA.combine(testListB);

  CHECK(testListA.listSize() == 8);
  CHECK(testListB.listSize() == 0);
}

//==========================================================
//Test Case Group 2: State Extracting (ArrayList)
//==========================================================

TEST_CASE("2a. Testing State Extracting (Size: 20)") {
  int size = 20;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }

  CHECK(testListA.listSize() == 10);
  CHECK(testListB.listSize() == 10);

  testListA.combine(testListB);

  CHECK(testListA.listSize() == 20);
  CHECK(testListB.listSize() == 0);

  ArrayList<Address> testListC;
  int arrayIndex = 0;
  for (int i = 0; i < testListA.listSize(); i++) {
    if (testListA.retrieveAt(i).state == "OH") {
        break;
    }
    arrayIndex++;
  } 

  if (testListA.retrieveAt(arrayIndex).state == "OH") {
    testListC = testListA.extractAllMatches(testListA.retrieveAt(arrayIndex));
  }
  for (int i = 0; i < testListA.listSize(); i++) {
    CHECK(testListA.retrieveAt(i).state != "OH");
  }
  for (int i = 0; i < testListC.listSize(); i++) {
    CHECK(testListC.retrieveAt(i).state == "OH");
  }

  CHECK(testListA.listSize() == 19);
  CHECK(testListC.listSize() == 1);
} TEST_CASE("2b. Testing State Extracting (Size: 50)") {
  int size = 50;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }

  CHECK(testListA.listSize() == 25);
  CHECK(testListB.listSize() == 25);

  testListA.combine(testListB);

  CHECK(testListA.listSize() == 50);
  CHECK(testListB.listSize() == 0);

  ArrayList<Address> testListC;
  int arrayIndex = 0;
  for (int i = 0; i < testListA.listSize(); i++) {
    if (testListA.retrieveAt(i).state == "OH") {
        break;
    }
    arrayIndex++;
  } 

  if (testListA.retrieveAt(arrayIndex).state == "OH") {
    testListC = testListA.extractAllMatches(testListA.retrieveAt(arrayIndex));
  }
  for (int i = 0; i < testListA.listSize(); i++) {
    CHECK(testListA.retrieveAt(i).state != "OH");
  }
  for (int i = 0; i < testListC.listSize(); i++) {
    CHECK(testListC.retrieveAt(i).state == "OH");
  }

  CHECK(testListA.listSize() == 48);
  CHECK(testListC.listSize() == 2);
} TEST_CASE("2c. Testing State Extracting (Size: 25000)") {
  int size = 50000;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }

  CHECK(testListA.listSize() == 25000);
  CHECK(testListB.listSize() == 25000);

  testListA.combine(testListB);

  CHECK(testListA.listSize() == 50000);
  CHECK(testListB.listSize() == 0);

  ArrayList<Address> testListC;
  int arrayIndex = 0;
  for (int i = 0; i < testListA.listSize(); i++) {
    if (testListA.retrieveAt(i).state == "OR") {
        break;
    }
    arrayIndex++;
  } 

  if (testListA.retrieveAt(arrayIndex).state == "OR") {
    testListC = testListA.extractAllMatches(testListA.retrieveAt(arrayIndex));
  }
  for (int i = 0; i < testListA.listSize(); i++) {
    CHECK(testListA.retrieveAt(i).state != "OR");
  }
  for (int i = 0; i < testListC.listSize(); i++) {
    CHECK(testListC.retrieveAt(i).state == "OR");
  }

  CHECK(testListA.listSize() == 49155);
  CHECK(testListC.listSize() == 845);
}

//==========================================================
//Test Case Group 3: LinkedList Creation
//==========================================================

TEST_CASE("3. Testing If AddressLinkedList Works") {
  int size = 50;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }
  CHECK(testListA.listSize() == 25);
  CHECK(testListB.listSize() == 25);

  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 25);
  CHECK(testlinkedListB.listSize() == 25);

  for (int i = 0; i < size/2; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
    CHECK(testListB.retrieveAt(i) == testlinkedListB.retrieveAt(i));
  }
}

//==========================================================
//Test Case Group 4: Combining LinkedLists
//==========================================================

TEST_CASE("4a. Testing If AddressLinkedList Combine Works (Size: 50)") {
  int size = 50;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }
  CHECK(testListA.listSize() == 25);
  CHECK(testListB.listSize() == 25);

  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 25);
  CHECK(testlinkedListB.listSize() == 25);

  for (int i = 0; i < size/2; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
    CHECK(testListB.retrieveAt(i) == testlinkedListB.retrieveAt(i));
  }

  testListA.combine(testListB);
  testlinkedListA.combine(testlinkedListB);

  for (int i = 0; i < size; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
  }
} TEST_CASE("4b. Testing If AddressLinkedList Combine Works (Size: 500)") {
  int size = 500;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }
  CHECK(testListA.listSize() == 250);
  CHECK(testListB.listSize() == 250);

  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 250);
  CHECK(testlinkedListB.listSize() == 250);

  for (int i = 0; i < size/2; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
    CHECK(testListB.retrieveAt(i) == testlinkedListB.retrieveAt(i));
  }

  testListA.combine(testListB);
  testlinkedListA.combine(testlinkedListB);

  for (int i = 0; i < size; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
  }
} TEST_CASE("4d. Testing If AddressLinkedList Combine Works (Size: 5000)") {
  int size = 5000;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }
  CHECK(testListA.listSize() == 2500);
  CHECK(testListB.listSize() == 2500);

  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 2500);
  CHECK(testlinkedListB.listSize() == 2500);

  for (int i = 0; i < size/2; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
    CHECK(testListB.retrieveAt(i) == testlinkedListB.retrieveAt(i));
  }

  testListA.combine(testListB);
  testlinkedListA.combine(testlinkedListB);

  for (int i = 0; i < size; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
  }
} TEST_CASE("4e. Testing If AddressLinkedList Combine Works (Size: 50000)") {
  int size = 50000;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }
  CHECK(testListA.listSize() == 25000);
  CHECK(testListB.listSize() == 25000);

  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 25000);
  CHECK(testlinkedListB.listSize() == 25000);

  for (int i = 0; i < size/2; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
    CHECK(testListB.retrieveAt(i) == testlinkedListB.retrieveAt(i));
  }

  testListA.combine(testListB);
  testlinkedListA.combine(testlinkedListB);

  for (int i = 0; i < size; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
  }
}

//==========================================================
//Test Case Group 5: Extracting States
//==========================================================

TEST_CASE("5. Testing If AddressLinkedList Extract Works (Size: 50000 / State: OR)") {
  int size = 50000;
  ArrayList<Address> testListA;
  ArrayList<Address> testListB;

  AddressFactory testFactory("25000AddressesA.txt");
  AddressFactory testFactory2("25000AddressesB.txt");

  for(int i = 0; i < size / 2; i++) {
    Address testA = testFactory.getNext();
    testListA.insertEnd(testA);
    Address testB = testFactory2.getNext();
    testListB.insertEnd(testB);
  }
  CHECK(testListA.listSize() == 25000);
  CHECK(testListB.listSize() == 25000);

  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 25000);
  CHECK(testlinkedListB.listSize() == 25000);

  for (int i = 0; i < size/2; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
    CHECK(testListB.retrieveAt(i) == testlinkedListB.retrieveAt(i));
  }

  testListA.combine(testListB);
  testlinkedListA.combine(testlinkedListB);

  for (int i = 0; i < size; i++) {
    CHECK(testListA.retrieveAt(i) == testlinkedListA.retrieveAt(i));
  }

  ArrayList<Address> testListC;
  int arrayIndex = 0;
  for (int i = 0; i < testListA.listSize(); i++) {
    if (testListA.retrieveAt(i).state == "OR") {
        break;
    }
    arrayIndex++;
  } 

  if (testListA.retrieveAt(arrayIndex).state == "OR") {
    testListC = testListA.extractAllMatches(testListA.retrieveAt(arrayIndex));
  }
  for (int i = 0; i < testListA.listSize(); i++) {
    CHECK(testListA.retrieveAt(i).state != "OR");
  }
  for (int i = 0; i < testListC.listSize(); i++) {
    CHECK(testListC.retrieveAt(i).state == "OR");
  }

  CHECK(testListA.listSize() == 49155);
  CHECK(testListC.listSize() == 845);

  int firstOregonIndex = 0;
  while (firstOregonIndex < testlinkedListA.listSize()) {
    if (testlinkedListA.retrieveAt(firstOregonIndex).state == "OR") {
        break;
    }
    firstOregonIndex++;
  }
  AddressLinkedList testlinkedListC = testlinkedListA.extractAllMatches(testlinkedListA.retrieveAt(firstOregonIndex));
  for (int i = 0; i < testlinkedListA.listSize(); i++) {
    CHECK(testlinkedListA.retrieveAt(i).state != "OR");
  }
  for (int i = 0; i < testlinkedListC.listSize(); i++) {
    CHECK(testlinkedListC.retrieveAt(i).state == "OR");
  }

  CHECK(testlinkedListA.listSize() == 49155);
  CHECK(testlinkedListC.listSize() == 845);

  for (int i = 0; i < testlinkedListA.listSize(); i++) {
    CHECK(testlinkedListA.retrieveAt(i).state == testListA.retrieveAt(i).state);
  }
  for (int i = 0; i < testlinkedListC.listSize(); i++) {
    CHECK(testlinkedListC.retrieveAt(i).state == testListC.retrieveAt(i).state);
  }
}

//==========================================================
//Test Case Group 6: Interleaving
//==========================================================

TEST_CASE("6a. Testing If AddressLinkedList Interleave Works (Size: 50)") {
  int size = 50;
  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 25);
  CHECK(testlinkedListB.listSize() == 25);

  AddressLinkedList testlinkedListC = testlinkedListA;
  AddressLinkedList testlinkedListD = testlinkedListB;

  for (int i = 0; i < size/2; i++) {
    CHECK(testlinkedListA.retrieveAt(i) == testlinkedListC.retrieveAt(i));
    CHECK(testlinkedListB.retrieveAt(i) == testlinkedListD.retrieveAt(i));
  }

  testlinkedListC.interleave(testlinkedListD);
  int checkACount = 0;
  int checkBCount = 0;
  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListA.retrieveAt(checkACount));
      checkACount++;
    } else {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListB.retrieveAt(checkBCount));
      checkBCount++;
    }
  }
} TEST_CASE("6b. Testing If AddressLinkedList Interleave Works (Size: 500)") {
  int size = 500;
  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 250);
  CHECK(testlinkedListB.listSize() == 250);

  AddressLinkedList testlinkedListC = testlinkedListA;
  AddressLinkedList testlinkedListD = testlinkedListB;

  for (int i = 0; i < size/2; i++) {
    CHECK(testlinkedListA.retrieveAt(i) == testlinkedListC.retrieveAt(i));
    CHECK(testlinkedListB.retrieveAt(i) == testlinkedListD.retrieveAt(i));
  }

  testlinkedListC.interleave(testlinkedListD);
  int checkACount = 0;
  int checkBCount = 0;
  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListA.retrieveAt(checkACount));
      checkACount++;
    } else {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListB.retrieveAt(checkBCount));
      checkBCount++;
    }
  }
} TEST_CASE("6c. Testing If AddressLinkedList Interleave Works (Size: 5000)") {
  int size = 5000;
  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 2500);
  CHECK(testlinkedListB.listSize() == 2500);

  AddressLinkedList testlinkedListC = testlinkedListA;
  AddressLinkedList testlinkedListD = testlinkedListB;

  for (int i = 0; i < size/2; i++) {
    CHECK(testlinkedListA.retrieveAt(i) == testlinkedListC.retrieveAt(i));
    CHECK(testlinkedListB.retrieveAt(i) == testlinkedListD.retrieveAt(i));
  }

  testlinkedListC.interleave(testlinkedListD);
  int checkACount = 0;
  int checkBCount = 0;
  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListA.retrieveAt(checkACount));
      checkACount++;
    } else {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListB.retrieveAt(checkBCount));
      checkBCount++;
    }
  }
} TEST_CASE("6d. Testing If AddressLinkedList Interleave Works (Size: 50000)") {
  int size = 50000;
  AddressFactory aTestLinkedFactory("25000AddressesA.txt");
  AddressFactory aTestLinkedFactory2("25000AddressesB.txt");
  AddressLinkedList testlinkedListA;
  AddressLinkedList testlinkedListB;

  for(int i = 0; i < size / 2; i++) {
    Address b = aTestLinkedFactory.getNext();
    testlinkedListA.insertEnd(b);
    Address b2 = aTestLinkedFactory2.getNext();
    testlinkedListB.insertEnd(b2);
  }

  CHECK(testlinkedListA.listSize() == 25000);
  CHECK(testlinkedListB.listSize() == 25000);

  AddressLinkedList testlinkedListC = testlinkedListA;
  AddressLinkedList testlinkedListD = testlinkedListB;

  for (int i = 0; i < size/2; i++) {
    CHECK(testlinkedListA.retrieveAt(i) == testlinkedListC.retrieveAt(i));
    CHECK(testlinkedListB.retrieveAt(i) == testlinkedListD.retrieveAt(i));
  }

  testlinkedListC.interleave(testlinkedListD);
  CHECK(testlinkedListC.listSize() == 50000);
  int checkACount = 0;
  int checkBCount = 0;
  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListA.retrieveAt(checkACount));
      checkACount++;
    } else {
      CHECK(testlinkedListC.retrieveAt(i) == testlinkedListB.retrieveAt(checkBCount));
      checkBCount++;
    }
  }
}