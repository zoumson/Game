//
//  Field.h
//  try
//
//  Created by ZOUMA Adama on 5/23/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef Field_h
#define Field_h
#include<iostream>
#include<string>
#include"GeneralPlayer.h"
#include"AbstractMonster.h"
#include"OrcPlayer.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
using namespace std;
class Field
{
public:
    
    
     //first parameter is map data
     //second parameter is map width
     //third parameter is map height
     //forth and fifth parameters are current player position(x,y)
     //sixth parameter is vision width
     //seventh parameter is vision  height
    
    Field(int**, int, int, int, int, int, int);
    
    //first parameter is map file name
    //second and third parameters are current player position(x,y)
    //sixth parameter is vision width
    //seventh parameter is vision  height
    Field(const char*, int, int, int, int);
    string getMapName(void) const;
    int getCurrentPositionX(void) const;
    int getCurrentPositionY(void) const;
    bool move(char);
    bool moveUp(void);
    bool moveDown(void);
    bool moveLeft(void);
    bool moveRight(void);
    int getVisionWidth(void) const;
    int getVisionHeight(void) const;
    int getMapSymbol(int, int) const;
    void setPosition(int, int);//set player position of player (x, y)
    //Set symbol on a given position
    //first parameter is symbol
    //second and third  are position(x, y)
    void setMapSymbol(int, int, int);
    //set vision size
    //first parameter is width
    //second  parameter is heigth
    void setVisionSize(int, int);
    char display(void);//Displaying  map
    int digital(int);
    void showVision(int, int);//display vision
private:
    string mapName;
    int** mapData;
    int mapWidth;
    int mapHeight;
    int visionWidth;
    int visionHeight;
    int currentPositionX;
    int currentPositionY;
    
};



#endif /* Field_h */
