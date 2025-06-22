/**
 * @author Demising
 * @brief Riemann Sum
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;
// double yFinderRework(string equation, double i) {

// }

double yFinder(string equation, double i) {
  double y = 0;
  for (int j = 0; j < equation.size(); j++) {
    if (equation[j] == 'x') {
      if (equation[j + 1] == '^') {
        double power = stod(equation.substr(j + 2, 1));
        y = pow(i, power);
      }
      if (equation[j + 1] == '+') {
        y = i + stod(equation.substr(j + 2, 1));
      }
      if (equation[j + 1] == '/') {
        y = i / stod(equation.substr(j + 2, 1));
      }
      if (equation[j - 1] == '/') {
        y = stod(equation.substr(j - 2, 1)) / i;
      }
    }
  }
  return y;
}

void riemannMidpoint (string equation, vector<double> midPoints, double changeX) {
  double sum = 0;
  for (int i = 0; i < midPoints.size() - 1; i++) {
    double y = yFinder(equation, midPoints[i]);
    sum += changeX * y;
  }
  cout << sum;
}

void riemannRight (string equation, vector<double> gridPoints, double changeX) {
  double sum = 0;
  for (int i = 1; i < gridPoints.size() - 1; i++) {
    double y = yFinder(equation, gridPoints[i]);
    sum += changeX * y;
  }
  cout << sum;
}

void riemannLeft (string equation, vector<double> gridPoints, double changeX) {
  double sum = 0;
  for (int i = 0; i < gridPoints.size() - 2; i++) {
    double y = yFinder(equation, gridPoints[i]);
    sum += changeX * y;
  }
  cout << sum;

}

vector<double> midPointFinders (vector<double> gridPoints, double changeX) {
  vector<double> midPoints;
  for (int i = 0; i < gridPoints.size() - 1; i++) {
    midPoints.push_back(gridPoints[i] + (changeX / 2));
  }

  return midPoints;
}

int main() { 
  double a, b, n;
  double changeX;
  string equation = "x^3";
  puts("Specify your equation");
  cout << "f(x) = ";
  cin >> equation;
  puts("Specify your interval");
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;
  puts("Specify the number of subintervals");
  cout << "n: ";
  cin >> n;

  changeX = (b - a) / n;

  vector<double> gridPoints;
  gridPoints.push_back(a);

  for (int i = 0; i < n; i++) {
    gridPoints.push_back(gridPoints[i] + changeX);
  }

  gridPoints.push_back(b);

  vector<double> midPoints = midPointFinders(gridPoints, changeX);

  riemannLeft(equation, gridPoints, changeX);
  cout << endl;
  riemannRight(equation, gridPoints, changeX);
  cout << endl;
  riemannMidpoint(equation, midPoints, changeX);

}