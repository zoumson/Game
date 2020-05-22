//  Xcode compiler
//  GeneralPlayer.h
//  game
//
//  Created by ZOUMA Adama on 4/29/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef GeneralPlayer_h
#define GeneralPlayer_h
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class  GeneralPlayer
{


private:
    
string name; // Stores the name of the player
int hp; // Stores the HP of the player, >= 0
int mp; // Stores the MP of the player, >= 0
int exp; /* Stores the experience of the player, >= 0
           Will not reset to zero after level-up*/


protected :
    
    int level; // Stores the level of the player, >= 1
    int attack; // stores attack of the player
    int defense; // stores defense of the player
    int max_hp; // stores max. HP of the player
    int max_mp; // stores max. MP of the player
    int lvup_exp; // stores needed exp. to level-up
    
public:
    
    GeneralPlayer(); // default constructor
    GeneralPlayer(int); // normal constructor
    GeneralPlayer(int, string); // normal constructor
    GeneralPlayer(const GeneralPlayer&);
    void setName(string);
    string getName(void) const;
    void setLevel(int); // need to call setAttr() inside
    int getLevel(void) const;
    int getAttack(void) const;
    int getDefense(void) const;
    int getMaxHP(void) const;
    int getMaxMP(void) const;
    int getLvupExp(void) const;
    void setAttr(int); // parameter is level
    void levelUp(void); // level++
    void increaseHP(int);
    void increaseMP(int);
    void increaseExp(int);
    void recoverHP(void); // hp = max_hp;
    void recoverMP(void); // mp = max_mp;
    void setExp(int);
    int getExp(void);
    int getHP();
    void setHP(int);
    int getMP();
    void setMP(int);
    void playerStats();//display player features 
   
    






};

#endif /* GeneralPlayer_h */
