#ifndef gameProj
#define gameProj

#include <string>

/**
 * @brief Holds the necessary information of a school team and their game title, school division, and scores.
 * @param school Stores the name of the school (first section of the line) as a string.
 * @param gameTitle Stores the name of the game (second section of the line) as a string.
 * @param division Stores the school's division (third section of the line) as a string. Division either means it's a highschool (HS), or middle school (MS).
 * @param scores An array that is used to store the 5 scores at the end of the line.
*/
struct Teams
{
    std::string school;
    std::string gameTitle;
    std::string division;
    int scores[5];
};

/**
 * @brief Function that uses the struct "Teams" and stores information from the line sent to it.
 * @param info is a variable for struct "Teams" and is used to easily separate the sections of the line to place them in their proper variables.
 * @param info. is used to store the sections of the line into the appropiate string (ex: "info.school" would put any section it takes into the school variable in the teams struct).
 * @param scoresNum is used in the for loop to quickly gather each of the scores at the end of the line, and is used in conjunction with "stoi(scoresNum)" to convert them from string to integer.
 *        They are then placed into an "info.scores[i]" array, with i being the position in the array they're stored into.
 * @return info is returned at the end, so that way the function that called to it can easily access the information in the struct depending on the variable name.
 *         (ex: if "Teams team2 = storeTeams(input)" was used to store the information into the struct, then that information is attached to "team2".
 *         Using, for example, "team2.school" would pull up the school's name).
*/
Teams storeTeam(const std::string&);

/**
 * @brief A series of if statements that depend on which category is returned.
 * @param teamCounts[] is the array of structs that is sent into the function.
 * @param value is the value of the highest score for a team.
 * @param team is the variable to determine which team is being looked at, based on what value is sent into the function.
 * @return Category is returned as one of the five strings, depending on which score value equaled to.
*/
std::string categoryListing(Teams teamCounts[], std::string, int);

/**
 * @brief Goes through each team's score and sees which one is the highest, then sends it to function "categoryListing" to get the category returned.
 * @param bestCategories is the 'new' array with string values being pointed.
 * @param highestValue is the highest score value. It is compared to the other scores per team, and if it is less than the score it's compared to, that comparing score becomes the new highest value.
 * @param category is the string that is returned from "categoryListing".
 * @return bestCategory is returned to whichever function called it, and now has an array of strings that can be called on.
*/
std::string* bestCategory(Teams teamCounts[], const int);

/**
 * @brief Holds the code together to be able to print for general team data, and for filter mode.
 * @param teamData, is an array created to hold the printable information.
 * @param category is the result of sending "teamCounts" array and "team_count" array size to "bestCategory".
 * @param totalScore is the sum of all category scores and is sent back from function "findTotalScore", and is turned into a string later.
 * @return teamData[] array is returned back to whichever function it called, with it being a string.
*/
std::string* teamDataPrint(Teams teamCounts[], const int);

/**
 * @brief Function used to find the highest scoring team within the middle school division.
 * @param topScoreMS A variable used to determine what the highest scoring category is.
 * @param totalScore Is the result of the value brought back from the function "findTotalScore", with the variable being an array.
 * @return topScoreMS is returned to the function that called it after a few checks and value replacements.
*/
int middleTopScoringTeam(Teams teamCounts[], const int);

/**
 * @brief Function used to find the highest scoring team within the high school division.
 * @param topScoreHS A variable used to determine what the highest scoring category is.
 * @param totalScore Is the result of the value brought back from the function "findTotalScore", with the variable being an array.
 * @return topScoreHS is returned to the function that called it after a few checks and value replacements.
*/
int highTopScoringTeam(Teams teamCounts[], const int);

/**
 * @brief Function used to find the amount of teams who are 5 points or less than that of the highest score in the middle school division.
 * @param topMSSCore A value gathered from the function "middleTopScoringTeam".
 * @param scores An array of the total point count of all the teams.
 * @param msCount Initial value of 0, it is incremented each time a team is found to be within the required range.
 * @return msCount is returned to the function it called it, after being incremented the certain number of times.
*/
int msTopScoringTeams(Teams teamCounts[], const int);

/**
 * @brief Function used to find the amount of teams who are 5 points or less than that of the highest score in the high school division.
 * @param topHSSCore A value gathered from the function "highTopScoringTeam".
 * @param scores An array of the total point count of all the teams.
 * @param hsCount Initial value of 0, it is incremented each time a team is found to be within the required range.
 * @return hsCount is returned to the function it called it, after being incremented the certain number of times.
*/
int hsTopScoringTeams(Teams teamCounts[], const int);

/**
 * @brief Function designed to store the average scores of each category into an array.
 * @param scoresSum An array with an array size of 5 that is meant to store the sum of the scores in each category.
 * @param scoresAve An array with an array size of 6 that is meant to store the averages of the sums of the scores from each category, with the 6th index being the sum of all the averages.
 * @return scoresAve is returned to whichever function that called it, now with the average scores of each category, and sum of the averages.
*/
double* scoreAveragesTeams(Teams teamCounts[], const int);

/**
 * @brief Function designed to find the total score of a team and store it into a separate array.
 * @param totalScore An array with an array size of the total team count, which is used to the grandTotal value of each team after it's been found.
 * @param grandTotal Initial value of 0, and is reset back to zero in a loop, it is summed together with variable "score" as a way to store the total score of a team.
 * @param score Is the value of whichever score it is of the currently team. It loops through the scores of a team first, before switching to the next team.
 * @return totalScore is returned to whichever function called it with all the total score values of each team.
*/
int* findTotalScore(Teams teamCounts[], const int);

/**
 * @brief Takes in a string and based on the string, returns the title heading for the string.
*/
std::string printTitles(std::string);

/**
 * @brief Void function designed to print out the different teams in the competition.
 * @param printTeams Is an array that is determined based on what is returned from the function "teamDataPrint".
*/
void printTeams(Teams teamCounts[], const int);

/**
 * @brief Void function designed to print out the average scores of all the different categories, and the overall average.
 * @param averages Is an array of the averages that is determined based on what is returned from the function "scoreAveragesTeams".
*/
void printAverages(Teams teamCounts[], const int);

/**
 * @brief Void function designed to print out the top scores and number of teams within a division.
 * @param msTopScore The top score of the middle school division.
 * @param msTopTeams The number of teams that achieved a score within 5 of msTopScore.
 * @param hsTopScore The top score of the high school division.
 * @param hsTopTeam The number of teams that achieved a score within 5 of the hsTopScore.
*/
void printTopScores(Teams teamCounts[], const int);

/**
 * @brief Void function designed to print out the top teams and scores of a filtered view.
 * @param printFilteredTeams Is an array that is determined based on what is returned from the function "teamDataPrint".
*/
void printFilterView(Teams teamCounts[], const int, const std::string&);

#endif