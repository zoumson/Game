// Maze.h

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>

using namespace std;

class Maze {
public:

	vector<vector<int> > getMap();//maze map building
    Maze(const string&);
    int getColumn();
    void printMaze();//maze display
    void mazePath();//path from start to end

private:
	string filename;//maze map filename
	vector<vector<int> > Map;// maze map
	int row, column;//maze dimension
	void setMap();
};

#endif
