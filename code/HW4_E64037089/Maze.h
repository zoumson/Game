//
//  Maze.h
//  today
//
//  Created by ZOUMA Adama on 4/12/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef Maze_h
#define Maze_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>



using namespace std;
class Maze{
private :
    int **data;
    int col, row;
    int startX, startY;// Starting X and Y values of maze
    int endX, endY;   // Ending X and Y values of maze
    const char WALL = '#';//wall
    const char FREE = ' ';// free space
    const char BONUS = '$';
    const char START = 'S';
    const char DESTINATION = 'D';

    

public :

    void readPrintMaze ();
    
};



#endif /* Maze_h */
