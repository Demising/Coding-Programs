/**
 * @author Clayton Moeck
 * @brief hikeFunctions
 */

#include <iostream>
#include "hikeFunctions.h"
#include <fstream>
#include <string>

using namespace std;

int highestPointBetween(const int heights[], int startMile, int endMile)
{
    int highestPoint = 0;
    for (int i = startMile; i <= endMile; i++)
    {
        if (heights[i] > highestPoint)
        {
            highestPoint = heights[i];
        }
    }

    return highestPoint;
}

//double average(const int heights[], int startMile, int endMile);
//{
//    int totalSum = 0;
//    int mileTotal = endMile - startMile;
//    for (int i = startMile; i <= endMile; i++)
//    {
//        totalSum += heights[i];
//    }

//    double finalAverage = totalSum / mileTotal;

//    return finalAverage;
//}

//bool isPeak(const int heights[], int arrSize, int mile);
//{
//    int peak = heights[mile];
//    if (peak > heights[mile-1] && peak > heights[mile+1])
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }

//}

//int restingSpot(const int heights[], int arrSize);
//{
//    int firstThird = arrSize / 3;
//    int lastThird = 2 * firstThird;

//    for (int i = firstThird; i < lastThird; i++)
//    {
//        if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) {
//            return i;
//        }
//    }
//
//    return arrSize / 2;
//}

//int numSteepSegments(const int heights[], int arrSize);
//{
//    int steepSegments = 0;

//    for (int i = 0; i < arrSize; ++i)
//    {
//        int elevationDifference = abs(heights[i] - heights[i - 1]);

//        if (elevationDifference >= 1000)
//        {
//            steepSegments++;
//        }
//    }

//    return steepSegments;
//}

//int totalElevationChange(const int heights[], int startMile, int endMile);
//{
//    int elevationChange = 0;

//    for (int i = startMile; i < endMile; i++)
//    {
//        for (int j = startMile + 1; j <= endMile; j++)
//        {
//            elevationChange += abs(heights[i]-heights[j])
//        }
//    }

//    return elevationChange;

//}

//void getData(std::istream& inputSource, int heights[], int arrSize);
//{
//    for (int i = 0; i < arrSize; ++i)
//    {
//        inputSource >> heights[i];
//    }
//}

//int mostCommonElevation(const int heights[], int arrSize);
//{
//    std::unordered_map<int, int> elevationCounts;
//
//    for (int i = 0; i < arrSize; ++i) {
//        elevationCounts[heights[i]]++;
//    }

//    int mostCommonElevation = heights[0];
//    int maxCount = elevationCounts[mostCommonElevation];

//    for (const auto& entry : elevationCounts) {
//        if (entry.second > maxCount || (entry.second == maxCount && entry.first < mostCommonElevation)) {
//            mostCommonElevation = entry.first;
//            maxCount = entry.second;
//        }
//    }

//    return mostCommonElevation;
//}
