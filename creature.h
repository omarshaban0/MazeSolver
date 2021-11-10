//
// Assignment 3  CSS 342 Mashadi Section 3
// 10/30/2021
// Created by Yusuf Pisan: https://github.com/ajahanba/ass3-maze-starter
// Finished by Omar Shaban
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"

#include <ostream>

class Creature {
  public:
    //prints location of creature
    friend ostream & operator << (ostream & Out,
      const Creature & Creature);

  private:
    int Row;
  int Col;

  public:
    //constructor
    Creature(int Row, int Col);
  //initiates the Path string and walk method and returns the solution path
  string solve(Maze & Maze);
  //returns a boolean if the creature is at the exit
  bool atExit(const Maze & Maze) const;
  //recursive method that chooses which cell the creature moves to
  string walk(Maze & Maze, string Path);
  //moves the creature up one cell
  string goNorth(Maze & Maze);
  //moves the creature down one cell
  string goSouth(Maze & Maze);
  //moves the creature right one cell
  string goEast(Maze & Maze);
  //moves the creature left one cell
  string goWest(Maze & Maze);
};

#endif //ASS3_CREATURE_H