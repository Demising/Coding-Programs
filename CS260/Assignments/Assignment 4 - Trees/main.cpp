//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "MySet.h"

using namespace std;

// Returns a vector containing all valid IP addresses starting with 192.168
vector<string> getLocalIPs()
{
  vector<string> localIPs;
  localIPs.reserve(256 * 256); // reserve space in advance to minimize grows

  char ip[] = "XXX.XXX.XXX.XXX";
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      sprintf(ip, "192.168.%03d.%03d", i, j);
      localIPs.push_back(ip);
    }
  }

  return localIPs;
}

int main()
{
  cout << "-----------------------------Section 1----------------------------" << endl;
  int size;
  cout << "Please enter the size of the set: ";
  cin >> size;

  clock_t start = clock();
  MySet<string> setA;
  ifstream file("IPListA.txt");

  for (int i = 0; i < size; i++) {
    string ip;
    getline(file, ip);
    setA.add(ip);
  }
  clock_t end = clock();

  cout << "Set A has " << setA.size() << " items." << endl;
  cout << "Set A has a depth of " << setA.depth() << "." << endl;
  cout << "Set A took " << (double)(end - start) / CLOCKS_PER_SEC << " seconds to finalize." << endl;
  
  // ================================================================
  // This check was designed to test smaller sets of IP addresses and
  // see if they were being stored properly.
  // ================================================================
  // cout << "IP Addresses Contained" << endl;
  // setA.print();

  cout << "-----------------------------Section 2----------------------------" << endl;
  cout << "Getting smallest item in set A: " << endl;
  cout << setA.getSmallest() << endl;


  // ================================================================
  // Code to time the average time for getting smallest.
  // ================================================================
  // string result;
  // const int TIMING_REPS = 90000000;  //tune this number so you get a fairly stable answer without waiting too long 
  // clock_t start1 = clock();
  // for(int i = 0; i < TIMING_REPS; i++) {
  //   result = setA.getSmallest();
  // }
  // clock_t end1 = clock();
  // cout << "Smallest: " << result << endl;
  // cout << "Took " << 1.0 * (end1 - start1) / CLOCKS_PER_SEC / TIMING_REPS << " seconds per getSmallest." << endl;

  cout << "-----------------------------Section 3----------------------------" << endl;
  MySet<string> setA2(setA);
  for (int i = 0; i < 10; i++) {
    cout << setA2.removeLargest() << endl;
  }
  cout << "The size in set A2 now is: " << setA2.size() << endl;

  cout << "-----------------------------Section 4----------------------------" << endl;
  MySet<string> setA3(setA);

  // Checking the size of set A3, for calculations.
  cout << "The size in set A3 is: " << setA3.size() << endl;

  vector<string> localIPs = getLocalIPs();

  // ================================================================
  // Checking the size of the localIPs vector, for calculations.
  // Will display a number larger than what set A3 holds, due to A3 not having
  // all 256x256 local IP combos.
  // ================================================================
  cout << "Local IPs: " << localIPs.size() << endl;

  // ================================================================
  // Print function to see how many items the set has in it.
  // ================================================================
  cout << "Set A3 has: " << setA3.localCount(localIPs) << " local IPs." << endl;

  for (int i = 0; i < localIPs.size(); i++) {
    setA3.remove(localIPs[i]);
  }
  cout << "The size in set A3 now is: " << setA3.size() << endl;

  cout << "-----------------------------Section 5----------------------------" << endl;
  clock_t start2 = clock();
  vector<string> range = setA.getRange("100.000.000.000", "110.000.000.000");
  clock_t end2 = clock();

  cout << "Time to find all values within the range: " << (double)(end2 - start2) / CLOCKS_PER_SEC << " seconds." << endl;
  cout << "Size of Range Vector: " << range.size() << endl;

  if (range.size() < 5) {
    for (int i = 0; i < range.size(); i++) {
      cout << range[i] << endl;
    }
  } else {
    for (int i = 0; i < 5; i++) {
      cout << range[i] << endl;
    }
  }

  cout << "-----------------------------Section 6----------------------------" << endl;
  MySet<string> setB;
  ifstream file2("IPListB.txt");

  for (int i = 0; i < size; i++) {
    string ip2;
    getline(file2, ip2);
    setB.add(ip2);
  }
  cout << "The size of Set B is: " << setB.size() << endl;
  cout << "The depth of Set B is: " << setB.depth() << endl << endl;

  clock_t start3 = clock();
  MySet<string> setAUB = setA.unionWith(setB);
  clock_t end3 = clock();
  cout << "The size of set AUB is: " << setAUB.size() << endl;
  cout << "The depth of set AUB is: " << setAUB.depth() << endl;
  cout << "The smallest item in set AUB is: " << setAUB.getSmallest() << endl;
  cout << "The time to find the union of set A and set B is: " << (double)(end3 - start3) / CLOCKS_PER_SEC << " seconds." << endl;

  cout << "-----------------------------Section 7-----s-----------------------" << endl;
  clock_t start4 = clock();
  MySet<string> setAIB = setA.intersectionWith(setB);
  clock_t end4 = clock();

  cout << "The time to intersect Set A and B: " << (double)(end4 - start4) / CLOCKS_PER_SEC << " seconds." << endl;
  cout << "The size of set AIB is: " << setAIB.size() << endl;
  cout << "The depth of set AIB is: " << setAIB.depth() << endl;
  cout << "The smallest item in set AIB is: " << setAIB.getSmallest() << endl;
}
