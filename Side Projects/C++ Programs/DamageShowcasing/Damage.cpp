/**
 * @author Demising
 * @brief Damage
 */

#include <iostream>

using namespace std;

void intDamageIntHealth() {
  int health = 150;
  int damage = 25;
  cout << "Health: " << health << endl;
  cout << "Damage: " << damage << endl;
  cout << "Health after damage: " << health - damage << endl;
  cout << "------------------------------------" << endl;
}

void DoubleDamageIntHealth() {
  int health = 150;
  double damage = 25.5;
  cout << "Health: " << health << endl;
  cout << "Damage: " << damage << endl;
  health -= damage;
  cout << "Health after damage: " << health << endl;
  cout << "Health after damage should be 124.5" << endl;
  cout << "------------------------------------" << endl;
}

void intDamageDoubleHealth() {
  double health = 145.5;
  int damage = 25.5;
  cout << "Health: " << health << endl;
  cout << "Damage: " << damage << endl;
  health -= damage;
  cout << "Health after damage: " << health << endl;
  cout << "Health after damage should be 120.5" << endl;
  cout << "------------------------------------" << endl;
}

void DoubleDamageDoubleHealth() {
  double health = 145.5;
  double damage = 25.5;
  cout << "Health: " << health << endl;
  cout << "Damage: " << damage << endl;
  health -= damage;
  cout << "Health after damage: " << health << endl;
  cout << "Health after damage should be 120" << endl;
  cout << "------------------------------------" << endl;
}

void issue() {
  int health = 150;
  double damage = 24.5;
  cout << "Health: " << health << endl;
  cout << "Damage: " << damage << endl;
  for (int i = 0; i < 6; i++) {
    health -= damage;
  }
  cout << "Health after damage: " << health << endl;
  cout << "Health after damage should be 3" << endl;
  cout << "------------------------------------" << endl;
}

void issueFixed() {
  double health = 150;
  double damage = 24.5;
  cout << "Health: " << health << endl;
  cout << "Damage: " << damage << endl;
  for (int i = 0; i < 6; i++) {
    health -= damage;
  }
  cout << "Health after damage: " << health << endl;
  cout << "Health after damage should be 3" << endl;
  cout << "------------------------------------" << endl;
}

int main() { 
  intDamageIntHealth();
  DoubleDamageIntHealth();
  intDamageDoubleHealth();
  DoubleDamageDoubleHealth();
  issue();
  issueFixed();
}