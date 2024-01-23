#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main() 
{ 
    const int arrSize = 6;
    const int heights[arrSize] = {970, 974, 974, 970, 975, 976};

    int maxCount = 0;
    int mostCommon = heights[0];
    for (int i = 0; i < arrSize; i++) {
        int heightCount = 0;
        // cout << heights[i] << ", ";
        for (int j = 0; j < arrSize; j++) {
            // cout << heights[i] << ", " << heights[j] << " | ";
            if (heights[j] == heights[i]) {
                heightCount++;
            }
        }
        if (heightCount > maxCount) {
            maxCount = heightCount;
            mostCommon = heights[i];
        }
    }

    cout << mostCommon;

}