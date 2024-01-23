/**
 * @author CM
 * @brief test8
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int student_count = 5;
const int math_score_count = 10;

struct StudentInfo {
    string name;
    string mathCourse;
    int age;
    int mathScores[10];
};

double averageMath(StudentInfo studentCount[], const int math_scores) {
  StudentInfo student;
  double mathSum = 0;
  double mathAve = 0;
  for (int i = 0; i < math_scores; i++) {
    double mathScore = 0;
    mathScore = student.mathScores[i];
    mathSum += mathScore;
  }
  mathAve = mathSum / math_scores;
}

StudentInfo storeInfo(const string& line) {
  StudentInfo student;
  string ageString;
  string mathScore;
  stringstream input(line);
  getline(input, student.name, ',');
  getline(input, student.mathCourse, ',');
  getline(input, ageString, ',');
  student.age = stoi(ageString);

  for (int i = 0; i < math_score_count; i++) {
    getline(input, mathScore, ',');

    student.mathScores[i] = stoi(mathScore);
  }
}

int main() { 
  StudentInfo studentCount[student_count];
  string student;
  double averageMathScores;

  for (int i = 0; i < student_count; i++) {
    getline(cin, student);
    studentCount[i] = storeInfo(student);
  }

  for (int i = 0; i < student_count; i++) {
    averageMathScores = averageMath(studentCount, math_score_count);
    cout << averageMathScores << " ";
  }

}