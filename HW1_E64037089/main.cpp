//
//  main.cpp
//  maz
//
//  Created by ZOUMA Adama on 6/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

//HW4 Maze

#include <iostream>
#include <vector>
#include <string>
#include "Maze.h"

using namespace std;

int main() {
    
    //File name
    string filename;
    
    //file name
    cout << "\tYour file name Please: ";
    getline(cin, filename);
    cout<<"\n\n";
    
    //maze generation
    Maze maze(filename);
    
    //dispolay  maze
    maze.printMaze();
    
    //maze path
    maze.mazePath();
    
    return 0;
}
