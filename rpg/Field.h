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
using namespace std;

class Field {
public:
    
    Field(const string , int, int, int, int);
    ~Field(void);
    bool move(char);
    bool moveUp(void);
    bool moveDown(void);
    bool moveLeft(void);
    bool moveRight(void);
    int getCurrentPositionX(void) const;
    int getCurrentPositionY(void) const;
    int getVisionWidth(void) const;
    int getVisionHeight(void) const;
    string getMapName(void) const;
    int getMapSymbol(int, int);
    void setPosition(int, int);
    void setMapSymbol(int, int, int);
    void setVisionSize(int, int);
    void display(void);
    void generateMonster(void);
    bool take_a_fight();
    
    int door_key = 0;
    int **board;
    int** map_data;
    int current_position_x;
    int current_position_y;
    string map_name;
    int vision_width;
    int vision_height;
    int words[2][2] = { 0,0,0,0 };
    int temp;
    char d;
    
};




#endif /* Field_h */
