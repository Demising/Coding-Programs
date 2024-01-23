/**
 * @author CM
 * @brief test3
 */

#include <iostream>
#include <string>

std::string betweenBars(const std::string& inputString) {
    // Find the first occurrence of "|"
    size_t firstBarIndex = inputString.find("|");

    size_t secondBarIndex = inputString.find("|", firstBarIndex + 1);

        // Check if the second "|" exists
    if (secondBarIndex != std::string::npos) {
            // Extract and return the text between the two "|"
        return inputString.substr(firstBarIndex + 1, secondBarIndex - firstBarIndex - 1);
    }

    // Return an empty string if the conditions are not met
    return "";
}

int main() {
    // Example usage:
    std::string inputStr = "This is |between| bars";
    std::string result = betweenBars(inputStr);
    std::cout << result << std::endl;

    return 0;
}