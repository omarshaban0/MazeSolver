//
// Assignment 3  CSS 342 Mashadi Section 3
// 10/30/2021
// Created by Yusuf Pisan: https://github.com/ajahanba/ass3-maze-starter
// Finished by Omar Shaban
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL {
  CLEAR,
  WALL,
  PATH,
  VISITED
};

class Maze {
  //outputs maze
  friend ostream & operator << (ostream & Out,
    const Maze & Maze);
  private:
    const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;
  public:
    //constructor
    explicit Maze(const string & FileName);
  //returns bool on if cell is clear or not
  bool isClear(int Row, int Col) const;
  //marks cell as '*' aka path
  void markAsPath(int Row, int Col);
  //marks cell as '+' aka visited
  void markAsVisited(int Row, int Col);
  //returns exit row
  int getExitRow() const;
  //returns exit column
  int getExitColumn() const;
  // returns cell status(X, ' ', *, or +)
  char getCell(int Row, int Col) const;
};

#endif //ASS3_MAZE_H