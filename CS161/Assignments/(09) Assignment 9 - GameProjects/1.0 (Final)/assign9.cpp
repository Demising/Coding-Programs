/**
 * @author Clayton Moeck
 * @brief assign9
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include "gameProject.h"

using namespace std;

int main() { 
  const int TEAM_COUNT = 20;
  Teams teamCounts[TEAM_COUNT];
  string team;
  string line;
  string userInput;

  ifstream inputFile("teamdata.txt");

  for (int i = 0; i < TEAM_COUNT; i++) {
    getline(inputFile, team);
    teamCounts[i] = storeTeam(team);
  }

  inputFile.close();

  cout << printTitles("Team Data");

  printTeams(teamCounts, TEAM_COUNT);

  cout << printTitles("Average Scores");

  printAverages(teamCounts, TEAM_COUNT);

  cout << printTitles("Top Scores and Teams");

  printTopScores(teamCounts, TEAM_COUNT);

  cout << printTitles("Filter");
  cout << "Enter a school name: ";
  cin >> userInput;

  printFilterView(teamCounts, TEAM_COUNT, userInput);
}