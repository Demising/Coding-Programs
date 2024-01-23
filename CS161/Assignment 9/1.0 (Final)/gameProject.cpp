#include <iostream>
#include "gameProject.h"
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int* findTotalScore(Teams teamCounts[], const int team_count) {
    int* totalScore = new int[team_count];

    for (int i = 0; i < team_count; i++) {
        int grandTotal = 0;
        for (int j = 0; j < 5; j++) {
            int score = teamCounts[i].scores[j];
            grandTotal += score;
        }
        totalScore[i] = grandTotal;
    }
    return totalScore;
}

int middleTopScoringTeam(Teams teamCounts[], const int team_count) {
    int topScoreMS = 0;
    int* totalScore = findTotalScore(teamCounts, team_count);
    for (int i = 0; i < team_count; i++) {
        if (teamCounts[i].division == "MS") {
            int score = totalScore[i];
            if (score > topScoreMS) {
                topScoreMS = score;
            }
        }
    }
    return topScoreMS;
}

int msTopScoringTeams(Teams teamCounts[], const int team_count) {
    int topMSScore = middleTopScoringTeam(teamCounts, team_count);
    int* scores = findTotalScore(teamCounts, team_count);
    int msCount = 0;

    for (int i = 0; i < team_count; i++) {
        if (teamCounts[i].division == "MS") {
            if (scores[i] >= topMSScore - 5) {
                msCount++;
            }
        }
    }
    return msCount;
}

int highTopScoringTeam(Teams teamCounts[], const int team_count) {
    int topScoreHS = 0;
    int* totalScore = findTotalScore(teamCounts, team_count);
    for (int i = 0; i < team_count; i++) {
        if (teamCounts[i].division == "HS") {
            int score = totalScore[i];
            if (score > topScoreHS) {
                topScoreHS = score;
            }
        }
    }
    return topScoreHS;
}

int hsTopScoringTeams(Teams teamCounts[], const int team_count) {
    int topHSScore = highTopScoringTeam(teamCounts, team_count);
    int* scores = findTotalScore(teamCounts, team_count);
    int hsCount = 0;

    for (int i = 0; i < team_count; i++) {
        if (teamCounts[i].division == "HS") {
            if (scores[i] >= topHSScore - 5) {
                hsCount++;
            }
        }
    }
    return hsCount;
}

string categoryListing(Teams teamCounts[], int value, int team) {
    string category;
    if (value == teamCounts[team].scores[0]) {
        category = "Programming";
    }
    else if (value == teamCounts[team].scores[1]) {
        category = "Art";
    }
    else if (value == teamCounts[team].scores[2]) {
        category = "Game Design";
    }
    else if (value == teamCounts[team].scores[3]) {
        category = "Project Management";
    }
    else {
        category = "Use of Themes";
    }
    return category;
}

string* bestCategory(Teams teamCounts[], const int team_count) {
    string* bestCategories = new string[team_count];
    string category;

    for (int i = 0; i < team_count; i++) {
        int highestValue = teamCounts[i].scores[0];
        for (int j = 0; j < 5; j++) {
            if (teamCounts[i].scores[j] > highestValue) {
                highestValue = teamCounts[i].scores[j];
            }
        }
        category = categoryListing(teamCounts, highestValue, i);
        
        bestCategories[i] = category;
    }
    return bestCategories;

    delete [] bestCategories;
}

double* scoreAveragesTeams(Teams teamCounts[], const int team_count) {
    double* scoresSum = new double[5];
    double* scoresAve = new double[6];
    for (int i = 0; i < 5; i++) {
        scoresSum[i] = 0;
        for (int j = 0; j < team_count; j++) {
            scoresSum[i] += teamCounts[j].scores[i];
        }
        scoresAve[i] = scoresSum[i] / team_count;
        scoresAve[5] += scoresAve[i];
    }
    return scoresAve;

    delete [] scoresSum;
    delete [] scoresAve;
}

string printTitles(string title) {
    string td = "Team Data\n===================================================\n";
    string average = "Average Scores\n===================================================\n";
    string top = "Top Scores and Teams\n===================================================\n";
    string filtered = "Filtered View\n===================================================\n";
    if (title == "Team Data") {
        return td;
    }
    else if (title == "Average Scores") {
        return average;
    }
    else if (title == "Top Scores and Teams") {
        return top;
    }
    else if (title == "Filter") {
        return filtered;
    }
    else {
        return "False Title";
    }
}

string* teamDataPrint(Teams teamCounts[], const int team_count) {
    string* teamData = new string[team_count];
    string* category = bestCategory(teamCounts, team_count);
    int* totalScore = findTotalScore(teamCounts, team_count);
    for (int i = 0; i < team_count; i++) {
        teamData[i] = teamCounts[i].gameTitle + " from " + teamCounts[i].school + "\n   "
        + "Total Score: " + to_string(totalScore[i]) + "\n   "
        + "Best Category: " + category[i];
    }
    return teamData;

    delete [] teamData;
    delete [] category;
}

Teams storeTeam(const string& line) {
    Teams info;
    istringstream input(line);
    getline(input, info.school, ',');
    getline(input, info.gameTitle, ',');
    getline(input, info.division, ',');

    for (int i = 0; i < 5; i++)
    {
        string scoresNum;
        getline(input, scoresNum, ',');

        info.scores[i] = stoi(scoresNum);
    }
    return info;
}

void printTeams(Teams teamCounts[], const int team_count) {
    string* printTeams = teamDataPrint(teamCounts, team_count);

    for (int i = 0; i < team_count; i++) {
        cout << printTeams[i] << endl;
    }
    
    cout << endl;

    delete [] printTeams;
}

void printAverages(Teams teamCounts[], const int team_count) {
    double* averages = scoreAveragesTeams(teamCounts, team_count);
  
    cout << "Category:" << setw(30) << "Average Score:\n";
    cout << fixed << setprecision(2);
    cout << "Programming" << setw(18) << averages[0] << endl <<
    "Art" << setw(26) << averages[1] << endl <<
    "Game Design" << setw(18) << averages[2] << endl <<
    "Project Management" << setw(11) << averages[3] << endl <<
    "Use of Theme" << setw(17) << averages[4] << endl;
    cout << "-----------------------------------\n";
    cout << "Average Total:" << setw(15) << averages[5] << endl << endl;

    delete [] averages;
}

void printTopScores(Teams teamCounts[], const int team_count) {
    int msTopScore = middleTopScoringTeam(teamCounts, team_count);
    int msTopTeams = msTopScoringTeams(teamCounts, team_count);
    int hsTopScore = highTopScoringTeam(teamCounts, team_count);
    int hsTopTeams = hsTopScoringTeams(teamCounts, team_count);;
    cout << "MS Top Score: " << msTopScore <<
    "\nNumber of MS Teams Scoring " << (msTopScore - 5) << " or Above: " << msTopTeams << endl << endl;
    cout << "HS Top Score: " << hsTopScore <<
    "\nNumber of HS Teams Scoring " << (hsTopScore - 5) << " or Above: " << hsTopTeams << endl << endl;;
}

void printFilterView(Teams teamCounts[], const int team_count, const string& userInput) {
    string* printFilteredTeams = teamDataPrint(teamCounts, team_count);

    cout << "---------------------------------------------------\n";

    for (int i = 0; i < team_count; i++) {
        if (teamCounts[i].school.find(userInput) != string::npos) {
            cout << printFilteredTeams[i];
            cout << "\n---------------------------------------------------\n";
        }
    }

    delete [] printFilteredTeams;
}