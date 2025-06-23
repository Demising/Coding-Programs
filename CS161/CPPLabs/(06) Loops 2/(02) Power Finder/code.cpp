#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double x;
  double answer;
  cin >> x;

  for(double power = 0; answer < 1000; power++) {
    answer = pow(x, power);
    if(answer <= 1000) {
      cout << answer << " ";
    }
  }
}