/**
 * @author Clayton Moeck
 * @brief Unit tests for assign9
 */

//-----------------------------------------------------------------------------------
//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this line
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "gameProject.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;
//-----------------------------------------------------------------------------------
//Tests

Teams team1 = storeTeam("North Salem,Rascal Roundup,HS,12,14,13,8,16");
Teams team2 = storeTeam("Sunset High School,Circuit Run,HS,15,12,7,15,12");
Teams team3 = storeTeam("Arleta K-8,Roped Together,MS,15,16,10,11,17");
Teams team4 = storeTeam("The Dalles Middle School,The Scavenger,MS,9,11,11,12,18");
Teams team5 = storeTeam("Marshfield Jr. High School,World Traveler,MS,13,7,11,11,11");
Teams team6 = storeTeam("Rex Putnam High School,Resergemus,HS,15,15,15,19,20");
Teams team7 = storeTeam("Harrison High School,Time Dilation,HS,15,17,15,19,16");
Teams team8 = storeTeam("Newport High School,Echoing Void,HS,16,17,18,15,16");
Teams team9 = storeTeam("Lincoln City High School,Reclamation,HS,16,20,19,17,16");
Teams teamCounts[] = { team1, team2 };
Teams teamCounts2[] = { team1, team4, team5 };
Teams teamCounts3[] = {team2, team3, team6};
Teams teamCounts4[] = {team7, team8, team9};
Teams teamCountsTotal[] = {team1, team2, team3, team4, team5, team6, team7, team8, team9};

double* scoreAverage = scoreAveragesTeams(teamCounts, 2);
double* scoreAverage2 = scoreAveragesTeams(teamCounts2, 3);
double* scoreAverage3 = scoreAveragesTeams(teamCounts3, 3);
double* scoreAverageTotal = scoreAveragesTeams(teamCountsTotal, 9);

std::string* teamData = teamDataPrint(teamCounts, 2);
std::string* teamData2 = teamDataPrint(teamCounts2, 3);
std::string* teamData3 = teamDataPrint(teamCounts3, 3);

int* totalScore = findTotalScore(teamCounts, 2);
int* totalScore2 = findTotalScore(teamCounts2, 3);
int* totalScore3 = findTotalScore(teamCounts3, 3);
int* totalScoreAll = findTotalScore(teamCountsTotal, 9);

std::string* category = bestCategory(teamCounts, 2);
std::string* category2 = bestCategory(teamCounts2, 3);
std::string* category3 = bestCategory(teamCounts3, 3);
std::string* category4 = bestCategory(teamCounts4, 3);

TEST_CASE( "Teams" ) {
    std::cout << "1a: Team 1 Info" << std::endl;
    CHECK( team1.school == "North Salem" );
    CHECK( team1.gameTitle == "Rascal Roundup" );
    CHECK( team1.division == "HS" );
    CHECK( team1.scores[0] == 12 );
    CHECK( team1.scores[1] == 14 );
    CHECK( team1.scores[2] == 13 );
    CHECK( team1.scores[3] == 8 );
    CHECK( team1.scores[4] == 16 );
}

TEST_CASE( "Teams" ) {
    std::cout << "1b: Team 1 Info" << std::endl;
    CHECK( team2.school == "Sunset High School" );
    CHECK( team2.gameTitle == "Circuit Run" );
    CHECK( team2.division == "HS" );
    CHECK( team2.scores[0] == 15 );
    CHECK( team2.scores[1] == 12 );
    CHECK( team2.scores[2] == 7 );
    CHECK( team2.scores[3] == 15 );
    CHECK( team2.scores[4] == 12 );
}

TEST_CASE( "Print Titles" ) {
    std::cout << "2: Printing Titles" << std::endl;
    CHECK( printTitles("Team Data") == "Team Data\n===================================================\n");
    CHECK( printTitles("Average Scores") == "Average Scores\n===================================================\n");
    CHECK( printTitles("Top Scores and Teams") == "Top Scores and Teams\n===================================================\n");
    CHECK( printTitles("Filter") == "Filtered View\n===================================================\n");
    CHECK( printTitles("Filtered View") == "False Title");
}


TEST_CASE( "Total Team Score" ) {
    std::cout << "3: Total Team Scores" << std::endl;
    CHECK( totalScore[0] == 63);
    CHECK( totalScore[1] == 61);
    CHECK( totalScore2[0] == 63);
    CHECK( totalScore2[2] == 53);
    CHECK( totalScore3[1] == 69);
    CHECK( totalScore3[2] == 84);
    CHECK( totalScoreAll[7] == 82);
    CHECK( totalScoreAll[8] == 88);
    CHECK( totalScoreAll[5] == 84);
}

TEST_CASE( "High School Top Scoring Teams" ) {
    std::cout << "4: High School Top Scoring Teams" << std::endl;
    CHECK( hsTopScoringTeams(teamCounts, 2) == 2);
    CHECK( hsTopScoringTeams(teamCounts2, 3) == 1);
    CHECK( hsTopScoringTeams(teamCounts3, 3) == 1);
    CHECK( hsTopScoringTeams(teamCountsTotal, 9) == 2);
}

TEST_CASE( "Middle School Top Scoring Teams" ) {
    std::cout << "5: Middle School Top Scoring Teams" << std::endl;
    CHECK( msTopScoringTeams(teamCounts, 2) == 0);
    CHECK( msTopScoringTeams(teamCounts2, 3) == 1);
    CHECK( msTopScoringTeams(teamCounts3, 3) == 1);
    CHECK( msTopScoringTeams(teamCountsTotal, 9) == 1);
}

TEST_CASE( "High School Top Score" ) {
    std::cout << "6: High School Top Score" << std::endl;
    CHECK( highTopScoringTeam(teamCounts, 2) == 63);
    CHECK( highTopScoringTeam(teamCounts2, 3) == 63);
    CHECK( highTopScoringTeam(teamCounts3, 3) == 84);
    CHECK( highTopScoringTeam(teamCountsTotal, 9) == 88);
}

TEST_CASE( "Middle School Top Score" ) {
    std::cout << "7: Middle School Top Score" << std::endl;
    CHECK( middleTopScoringTeam(teamCounts, 2) == 0);
    CHECK( middleTopScoringTeam(teamCounts2, 3) == 61);
    CHECK( middleTopScoringTeam(teamCounts3, 3) == 69);
    CHECK( middleTopScoringTeam(teamCountsTotal, 9) == 69);
}

TEST_CASE( "Average Scores" ) {
    std::cout << "8: Average Scores" << std::endl;
    CHECK( scoreAverage[0] == 13.5);
    CHECK( scoreAverage[2] == 10);
    CHECK( scoreAverage[4] == 14);
    CHECK( scoreAverage2[0] == Approx(11.3333));
    CHECK( scoreAverage2[2] == Approx(11.6667));
    CHECK( scoreAverage2[4] == 15);
    CHECK( scoreAverage3[0] == 15);
    CHECK( scoreAverage3[2] == Approx(10.6667));
    CHECK( scoreAverage3[4] == Approx(16.3333));
    CHECK( scoreAverageTotal[0] == 14);
    CHECK( scoreAverageTotal[2] == Approx(13.2222));
    CHECK( scoreAverageTotal[4] == Approx(15.7778));
    CHECK( scoreAverageTotal[5] == Approx(71.4444));
}

TEST_CASE( "Best Category Prints" ) {
    std::cout << "9: Best Category" << std::endl;
    CHECK( category[0] == "Use of Themes");
    CHECK( category[1] == "Programming");
    CHECK( category2[0] == "Use of Themes");
    CHECK( category2[1] == "Use of Themes");
    CHECK( category2[2] == "Programming");
    CHECK( category3[0] == "Programming");
    CHECK( category3[1] == "Use of Themes");
    CHECK( category3[2] == "Use of Themes");
    CHECK( category4[0] == "Project Management");
    CHECK( category4[1] == "Game Design");
    CHECK( category4[2] == "Art");
}

TEST_CASE( "Team Data Prints" ) {
    std::cout << "10: Team Data Prints" << std::endl;
    CHECK( teamData[0] == "Rascal Roundup from North Salem\n   Total Score: 63\n   Best Category: Use of Themes");
    CHECK( teamData[1] == "Circuit Run from Sunset High School\n   Total Score: 61\n   Best Category: Programming");
    CHECK( teamData2[1] == "The Scavenger from The Dalles Middle School\n   Total Score: 61\n   Best Category: Use of Themes");
    CHECK( teamData2[2] == "World Traveler from Marshfield Jr. High School\n   Total Score: 53\n   Best Category: Programming");
    CHECK( teamData3[0] == "Circuit Run from Sunset High School\n   Total Score: 61\n   Best Category: Programming");
    CHECK( teamData3[2] == "Resergemus from Rex Putnam High School\n   Total Score: 84\n   Best Category: Use of Themes");
}
