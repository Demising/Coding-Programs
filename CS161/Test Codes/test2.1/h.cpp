/**
 * @author h
 * @brief h
 */

#include <iostream>

using namespace std;

int main()
{ 
  int steepSegments = 0;
  const int TEST_ARR1_SIZE = 9;
  const int TEST_ARR1[TEST_ARR1_SIZE] = {1200, 1650, 3450, 2800, 2900, 1650, 1140, 1650, 1200}; 


    for (int i = 1; i < TEST_ARR1_SIZE; ++i)
    {
        int elevationDifference = abs(TEST_ARR1[i] - TEST_ARR1[i - 1]);
        cout << elevationDifference << " ";

        if (elevationDifference >= 1000)
        {
            steepSegments++;
        }
    }

    return steepSegments;

}