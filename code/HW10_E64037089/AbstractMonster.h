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
    
    AbstractMonster(string n, int a, int d, int e, int h, int m);
    virtual ~AbstractMonster();
    void setHP(int);
    int getHP() const;
    void setMP(int);
    int getMP() const;
    virtual void attackTo(GeneralPlayer*) = 0;
    const string name;
    const int attack;
    const int defense;
    const int exp;
    const int max_hp;
    const int max_mp;
    static int count; // stores the number of alive monsters
    static int getCount();
    virtual void monsterStats()=0;//display player features
    bool canAttack(GeneralPlayer*);

    
private:
    
    int hp;
    int mp;
    
};




#endif /* AbstractMonster_h */
