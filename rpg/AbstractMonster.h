//
//  AbstractMonster.h
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef AbstractMonster_h
#define AbstractMonster_h
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "GeneralPlayer.h"

using namespace std;

class AbstractMonster
{
    
public:
    
    AbstractMonster(string, int, int, int, int, int,int);
    ~AbstractMonster();
    string name;
    int attack;
    int defense;
    int exp;
    int max_hp;
    int max_mp;
    int money;
    static int count;
    void setHP(int);
    int getHP() const;
    void setMP(int);
    int getMP() const;
    int getAttack(void) const;
    int getDefense(void) const;
    int getMaxHP(void) const;
    int getMaxMP(void) const;
    int getmaxExp(void) const;
    string setName(void) const;
    virtual void attackTo(GeneralPlayer*)=0;

    
private:
    
    int hp;
    int mp;
    
};




#endif /* AbstractMonster_h */
