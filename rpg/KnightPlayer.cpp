//  Xcode compiler
//  KnightPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include"KnightPlayer.h"

using namespace std;
//1
KnightPlayer::KnightPlayer()//default constructor
{
    
    setName("anonymous");
    setLevel(1) ;
    
}
//2
KnightPlayer::KnightPlayer(int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//3
KnightPlayer::KnightPlayer(int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//4
KnightPlayer::KnightPlayer(const KnightPlayer& p)//copy constructor
{
    setLevel(p.getLevel());
    setName(p.getName());
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
    
}
//5
void KnightPlayer::setLevel(int l)//set level
{
    while(l<1){cout<<"Reset level again"<<endl;}
    
    setAttr(l);
    if(getExp() > getLvupExp()){ setExp(getLvupExp());}
}

void KnightPlayer::levelUp(void)//level upgrading
{
    setHP(getMaxHP());
    setMP(getMP());
    setLevel(++level);
    
    //exp is unchanged
    
    
}


void KnightPlayer::increaseExp(int e)
{
    setExp(getExp()+e); ;//exp can only be increased, reduction is not allowed
    /* level is upgraded each time exp surpasses
     a given threshold for the actual level
     */
    if (getExp() < 0) {setExp(0);}
    while (getExp() > getLvupExp()){ levelUp();}
}


void KnightPlayer::setAttr(int l)//set attributes
{
    
    
    level = l;
    setExp(0);
    max_hp = 150 + 25*level; // stores max. HP of the player
    max_mp = 70 + 10*level; // stores max. MP of the player
    attack = 40 + 10*level;
    defense = 20 + 12*level;
    lvup_exp = ceil( pow(10, log2(level +1)));
    setHP(getMaxHP());
    setMP(getMP());
    setExp(getExp());
    setMoney(getMoney());
    
}
void KnightPlayer::heal(void)// additional function to GeneralPlayer
{
    
    if (getMP() >= 5*level)
    {
    increaseHP (level*10) ;
    increaseMP (level*(-5));
    }
    else
    {
        cout << "mp too low!" << endl;
    }
    
}


void KnightPlayer::specialSkill()
{
    heal();
}


