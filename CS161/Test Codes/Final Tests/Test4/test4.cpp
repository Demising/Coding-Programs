/**
 * @author CM
 * @brief test4
 */

#include <iostream>
#include <cstring>
#include <String>
#include <sstream>
#include "test4.h"

using namespace std;

bool checkContains(Point lowerLeft, Point upperRight, Point pointFind) {
  bool withinX = (pointFind.x >= lowerLeft.x && pointFind.x <= upperRight.x);
  bool withinY = (pointFind.y >= lowerLeft.y && pointFind.y <= upperRight.y);

  return withinX && withinY;
}

int main() { 
  Point p1 = {5, 6};
  Point p2 = {15, 16};
  Point p3 = {10, 10};
  Point p4 = {0, 10};

  bool result1 = checkContains(p1, p2, p3);
  bool result2 = checkContains(p1, p2, p4);
  bool result3 = checkContains(p1, p2, p1);

  cout << result1 << " " << result2 << " " << result3 << endl;
  return 0;
}