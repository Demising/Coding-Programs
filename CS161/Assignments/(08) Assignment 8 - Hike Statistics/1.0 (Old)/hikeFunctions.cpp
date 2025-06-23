/**
 * @author Clayton Moeck
 * @brief hikeFunctions
 */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

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

double average(const int heights[], int startMile, int endMile)
{
    double totalSum = 0;
    double mileTotal = 0;
    for (int i = startMile; i <= endMile; i++)
    {
        totalSum += heights[i];
        mileTotal++;
    }

    double finalAverage = totalSum / mileTotal;

    return finalAverage;
}

bool isPeak(const int heights[], int arrSize, int mile)
{
    if (mile <= 0 || mile >= arrSize -1)
    {
        return false;
    }

    return heights[mile] > heights[mile-1] && heights[mile] > heights[mile+1];

}

int restingSpot(const int heights[], int arrSize)
{
    int firstThird = arrSize / 3;
    int lastThird = 2 * firstThird;

    for (int i = firstThird; i < lastThird; i++)
    {
        if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1])
        {
            return i;
        }
    }

    return arrSize / 2;
}

int numSteepSegments(const int heights[], int arrSize)
{
    int steepSegments = 0;

    for (int i = 1; i < arrSize; ++i)
    {
        int elevationDifference = abs(heights[i] - heights[i - 1]);

        if (elevationDifference >= 1000)
        {
            steepSegments++;
        }
    }

    return steepSegments;
}

int totalElevationChange(const int heights[], int startMile, int endMile)
{
    int elevationChange = 0;

    for (int i = startMile; i < endMile; i++)
    {
        elevationChange += abs(heights[i]-heights[i+1]);
    }

    return elevationChange;

}

void getData(std::istream& inputSource, int heights[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
    {
        inputSource >> heights[i];
    }
}

int mostCommonElevation(const int heights[], int arrSize)
{
    int maxCount = 0;
    int mostCommon = heights[0];
    for (int i = 0; i < arrSize; i++) {
        int heightCount = 0;
        for (int j = 0; j < arrSize; j++) {
            if (heights[i] == heights[j]) {
                heightCount++;
            }
        }
        if (heightCount > maxCount) {
            maxCount = heightCount;
            mostCommon = heights[i];
        }
    }

    return mostCommon;
}