/**
 * @author Clayton Moeck
 * @brief assign9
 */

#include <iostream>
#include "gameProject.h"

using namespace std;

int main() {
  string school = "North Salem,Rascal Roundup,HS,12,14,13,8,16";
  string t = storeTeam(school);
  cout << t;
}