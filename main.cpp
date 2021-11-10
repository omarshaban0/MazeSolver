#include <iostream>

#include "creature.h"

#include "maze.h"


void test() {
  Maze M("maze.txt");
  Maze M1("maze1.txt");
  Maze M2("maze2.txt");
  Maze M3("maze3.txt");
  // cout << m << endl;
  Creature C(4, 4);
  cout << "Path: " << C.solve(M) << endl;
  cout << M << endl;
  Creature C1(1, 7);
  cout << "Path: " << C1.solve(M1) << endl;
  cout << M1 << endl;
  Creature C2(3, 57);
  cout << "Path: " << C2.solve(M2) << endl;
  cout << M2 << endl;
  Creature C3(3, 57);
  cout << "Path: " << C3.solve(M3) << endl;
  cout << M3 << endl;
}
int main() {
  test();
  cout << "Done!" << std::endl;
  return 0;
}