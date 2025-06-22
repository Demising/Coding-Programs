//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "DataStream.h"
#include "PriorityQueue.h"
#include <ctime>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
  // Set up source of fake random packets. Seed with 0.
  DataStream d(0);

  PriorityQueue<Packet> queue;

  // Read in a script in the form: "g 16000 r 16000 q";
  string jobScript;
  getline(cin, jobScript);

  // Use stringstream to parse the script
  stringstream scriptedInput(jobScript);

  clock_t start = clock();

  char jobType;
  scriptedInput >> jobType;

  while (jobType != 'q') {
    if (jobType == 'p') {
      // Print the highest priority packet. Do not remove it.
      Packet p = queue.getMax();
      cout << p.priority << " " << p.data << endl;
    } else {
      // Getting or removing packets
      int copies;
      scriptedInput >> copies;
      if (jobType == 'g') {
        for (int i = 0; i < copies; i++) {
          // Get a packet
          Packet p = d.getPacket();

          // Insert packet at that location
          queue.add(p);
        }
      } else if (jobType == 'r') {
        for (int i = 0; i < copies; i++) {
          // Remove highest priority packet
          queue.removeMax();
        }
      }
    }
    scriptedInput >> jobType;
  }


  clock_t end = clock();
  cout << "Run performed in "
       << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds"
       << endl;
}
