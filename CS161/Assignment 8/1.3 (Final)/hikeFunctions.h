//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef HIKEFUNCTIONS_H
#define HIKEFUNCTIONS_H

#include <iostream>

/**
 * @brief Calculates and returns the highest point along a segment of the
 *  hike that starts at startMile and ends at endMile.
 * @param heights array of elevations
 * @param startMile First mile marker to consider - inclusive
 * @param endMile Last mile marker to consider - inclusive
 * @return Highest elevation found
 *
 * The start and end are both inclusive - the highest point might be one
 * of them.
 *
 * Given this array: 1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200
 *
 * The highestPointBetween 0 and 2 is 3450
 */
int highestPointBetween(const int heights[], int startMile, int endMile);

/**
 * @brief Find the average elevation for a range of mile markers.
 *
 * Given this array: 1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200
 *
 * The average from 5 to 8 is 1410.0
 *
 * @param heights array of elevations
 * @param startMile First mile marker to include - inclusive
 * @param endMile Last mile marker to include - inclusive
 * @return mean of heights
 */
double average(const int heights[], int startMile, int endMile);

/**
 * @brief Determines if given location is a **peak**.
 * @param heights array of elevations
 * @param arrSize number of elements in heights
 * @param mile location to check
 * @return true if it is a peak, false otherwise
 *
 * A **peak** is higher than the elevations directly before and after it.
 * Mile 0 and the last mile marker in a hike are never considered to be a **peak**.
 *
 * Given this array: 1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200
 *
 * mile 4 (2900) is a peak as it is higher than both 2800 and 1650
 */
bool isPeak(const int heights[], int arrSize, int mile);

/**
 * @brief Find an ideal spot to take a break on this hike and enjoy the view.
 * @param heights array of elevations
 * @param arrSize number of elements in heights
 * @return the mile marker or the ideal resting spot.
 *
 * The location of the ideal rest spot is: the first peak in the middle third
 * of the hike. Since hikes won't always divide perfectly into three segments,
 * determine the length of the first third and last third as the length / 3 rounded
 * to the nearest whole number. The "middle third" will be everything between
 * them.
 *
 * Given this array: 1000 1500 1600 1400 1800 1000 1000
 *
 * The arrSize is 7, so the first and last thirds are 7/3 or 2.333 miles which
 * rounds down to 2. So the middle third excludes the first and last two items and
 * consists of 1600 1400 1800. The first peak in that range is 1600 which is at
 * index 2, so we would return that.
 *
 * If there is no peak in the middle third, the ideal resting spot should just
 * be the middle mile marker (size / 2).
 */
int restingSpot(const int heights[], int arrSize);

/**
 * @brief Return the number of **segments** that climb or descend 1000 or more feet.
 * @param heights array of elevations
 * @param arrSize number of elements in heights
 * @return number of steep segments
 *
 * A **segment** is the part of a hike between two consecutive mile markers.
 * (From 0 to 1 or 4 to 5). A **steep segment** is one that goes up or down by 1000
 * or more feet in that mile.
 *
 * Given this array: 1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200
 *
 * There are 2 steep segments (1650->3450 and 2900->1650)
 */
int numSteepSegments(const int heights[], int arrSize);

/**
 * @brief The total elevation change along the given part of a hike
 * @param heights array of elevations
 * @param startMile First mile marker to include - inclusive
 * @param endMile Last mile marker to include - inclusive
 * @return Total amount of up and down distance traveled
 *
 * Given this array: 1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200
 *
 * From mile 1 to mile 3, we climb up by 1800 (from 1650 to 3450), then down
 * by 650 (to 2800), for a total change of 2450.
 */
int totalElevationChange(const int heights[], int startMile, int endMile);

/**
 * @brief Read arrSize pieces of data from the **inputSource** into the array
 * @param inputSource
 * @param heights array of elevations
 * @param arrSize number of elements in heights
 *
 * Fills the heights array by reading arrSize number of integers from the inputSource.
 * The inputSource could be a file, or a stringstream, or cin.
 *
 * Hint: just read from inputSource like it was a file or cin using >> but make sure
 * to refer to it as inputSource, not "cin".
 */
void getData(std::istream& inputSource, int heights[], int arrSize);

/**
 * @brief The most common elevation of the mile markers
 * @param heights array of elevations
 * @param arrSize number of elements in heights
 * @return The elevation that is most common among the mile markers.
 *
 * Given this array: 1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200
 *
 * 1650 appears 3 times which is more than any of the other elevations. So
 * it is the value that should be returned.
 *
 * If there are two equally common elevations, return the one that appears
 * first in the array. (In the above example, if there were only two 1650's
 * you should return 1200 as it appears before 1650).
 *
 * If everything is equally common, returns the starting elevation of the hike.
 * (First of the equally common.)
 */
int mostCommonElevation(const int heights[], int arrSize);

#endif // HIKEFUNCTIONS_H
