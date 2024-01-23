/**
 * @author Clayton Moeck
 * @brief assign7
 */

#include <iostream>
#include "postNetFunctions.h"
#include <fstream>
#include <string>

int main()
{
  std::ifstream inputFile("input.txt");

  if (!inputFile.is_open())
  {
    std::cout << "Error: Unable to open input file.";
    return 1;
  }

  std::ofstream outputFile("output.txt");
  if (!outputFile.is_open())
  {
    std::cout << "Error: Unable to open output file.";
    return 1;
  }

  std::string line;
  while (std::getline(inputFile, line))
  {
    std::string result = printCity(line);
    outputFile << result << "\n" << std::endl;
  }
  inputFile.close();
  outputFile.close();

  return 0;
}