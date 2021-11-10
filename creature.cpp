//
// Assignment 3  CSS 342 Mashadi Section 3
// 10/30/2021
// Created by Yusuf Pisan: https://github.com/ajahanba/ass3-maze-starter
// Finished by Omar Shaban
//

#include "creature.h"

//prints location of creature
std::ostream & operator << (std::ostream & Out,
  const Creature & Creature) {
  Out << "C(" << Creature.Row << "," << Creature.Col << ")" << endl;
  return Out;
}

//constructor
Creature::Creature(int Row, int Col): Row(Row), Col(Col) {}

//returns a boolean if the creature is at the exit
bool Creature::atExit(const Maze & Maze) const {
  return Row == Maze.getExitRow() && Col == Maze.getExitColumn();
}

//initiates the Path string and walk method and returns the solution path
string Creature::solve(Maze & Maze) {
  string Path;
  Path = walk(Maze, Path);
  return Path;
}

//recursive method that chooses which cell the creature moves to
string Creature::walk(Maze & Maze, string Path) {
  //skips if list if the creature is at exit
  if (!atExit(Maze)) {
    //next 4 if statements check surroundings for a clear. Has priority E, S, N, then W
    if (Maze.isClear(Row, Col + 1)) {
      Path = Path + goEast(Maze);
      return walk(Maze, Path);
    }
    if (Maze.isClear(Row + 1, Col)) {
      Path = Path + goSouth(Maze);
      return walk(Maze, Path);
    }
    if (Maze.isClear(Row - 1, Col)) {
      Path = Path + goNorth(Maze);
      return walk(Maze, Path);
    }
    if (Maze.isClear(Row, Col - 1)) {
      Path = Path + goWest(Maze);
      return walk(Maze, Path);
    }
    //next 4 if statements check surroundings for a path when there are no clears. Has opposite priority of previous if's to make backtracking correct.
    if (Maze.getCell(Row, Col - 1) == '*') {
      goWest(Maze);
      Path.pop_back();
      return walk(Maze, Path);
    }
    if (Maze.getCell(Row - 1, Col) == '*') {
      goNorth(Maze);
      Path.pop_back();
      return walk(Maze, Path);
    }
    if (Maze.getCell(Row + 1, Col) == '*') {
      goSouth(Maze);
      Path.pop_back();
      return walk(Maze, Path);
    }
    if (Maze.getCell(Row, Col + 1) == '*') {
      goEast(Maze);
      Path.pop_back();
      return walk(Maze, Path);
    }
  }
  Maze.markAsPath(Row, Col);
  return Path;
}

//moves the creature up one cell
string Creature::goNorth(Maze & Maze) {
  //If the cell it is moving to is clear, it changes the current cell to path. the cell it is moving to is path, it changes the current to +
  if (Maze.getCell(Row - 1, Col) == '*') {
    Maze.markAsVisited(Row, Col);
  } else {
    Maze.markAsPath(Row, Col);
  }
  Row--;
  return "N";
}

//moves the creature left on cell
string Creature::goWest(Maze & Maze) {
  //If the cell it is moving to is clear, it changes the current cell to path. the cell it is moving to is path, it changes the current to +
  if (Maze.getCell(Row, Col - 1) == '*') {
    Maze.markAsVisited(Row, Col);
  } else {
    Maze.markAsPath(Row, Col);
  }
  Col--;
  return "W";
}

//moves the creature right one cell
string Creature::goEast(Maze & Maze) {
  //If the cell it is moving to is clear, it changes the current cell to path. the cell it is moving to is path, it changes the current to +
  if (Maze.getCell(Row, Col + 1) == '*') {
    Maze.markAsVisited(Row, Col);
  } else {
    Maze.markAsPath(Row, Col);
  }
  Col++;
  return "E";
}

//moves the creature left one cell
string Creature::goSouth(Maze & Maze) {
  //If the cell it is moving to is clear, it changes the current cell to path. the cell it is moving to is path, it changes the current to +
  if (Maze.getCell(Row + 1, Col) == '*') {
    Maze.markAsVisited(Row, Col);
  } else {
    Maze.markAsPath(Row, Col);
  }
  Row++;
  return "S";
}