//  Xcode compiler
//  OrcPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//


#include <iostream>
#include <string>
#include <math.h>
#include "OrcPlayer.h"


using namespace std;
//1
OrcPlayer::OrcPlayer()//default constructor 
{
    
    setName("anonymous");
    setLevel(1) ;
    
}
//2
OrcPlayer::OrcPlayer(int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//3
OrcPlayer::OrcPlayer(int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//4
OrcPlayer::OrcPlayer(const OrcPlayer& p)//copy constructor
{
    setLevel(p.getLevel());
    setName(p.getName());
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;

}
//5
void OrcPlayer::setLevel(int l)//set level
{
    while(l<1){cout<<"Reset level again"<<endl;}
    
    setAttr(l);
    if(getExp() > getLvupExp()){ setExp(getLvupExp());}
}
//6
void OrcPlayer::setAttr(int l)//set attributes
{
    level = l;
    max_hp = 200 + 20*level; // stores max. HP of the player
    max_mp = 50 + 5*level; // stores max. MP of the player
    attack = 50 + 12*level;
    defense = 30 + 10*level;
    lvup_exp = ceil( pow(10, log2(level +1)));
    setHP(getMaxHP());
    setMP(getMP());
    setExp(getExp());
    setMoney(getMoney());
}
//7
void OrcPlayer::levelUp(void)//level upgrading 
{
    setHP(getMaxHP());
    setMP(getMP());
    setLevel(++level);
    
    //exp is unchanged

    
}


void OrcPlayer::increaseExp(int e)
{
    setExp(getExp()+e); ;//exp can only be increased, reduction is not allowed
    /* level is upgraded each time exp surpasses
     a given threshold for the actual level
     */
    if (getExp() < 0) {setExp(0);}
    while (getExp() > getLvupExp()){ levelUp();}
}

void OrcPlayer::specialSkill(){}
