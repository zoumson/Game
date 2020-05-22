//  Xcode compiler
//  MagicianPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include"MagicianPlayer.h"
#include<iostream>
#include<string>
#include<math.h>



using namespace std;
//1
MagicianPlayer::MagicianPlayer()//default constructor
{
    
    setName("anonymous");
    setLevel(1) ;
    
}
//2
MagicianPlayer::MagicianPlayer(int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//3
MagicianPlayer::MagicianPlayer(int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//4
MagicianPlayer::MagicianPlayer(const MagicianPlayer& p)//copy constructor
{
    setLevel(p.getLevel());
    setName(p.getName());
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
    
}
//5
void MagicianPlayer::setLevel(int l)//set level
{
    while(l<1){cout<<"Reset level again"<<endl;}
    
    setAttr(l);
    if(getExp() > getLvupExp()){ setExp(getLvupExp());}
}

void MagicianPlayer::levelUp(void)//level upgrading
{
    setHP(getMaxHP());
    setMP(getMP());
    setLevel(++level);
    
    //exp is unchanged
    
    
}


void MagicianPlayer::increaseExp(int e)
{
    setExp(getExp()+e); ;//exp can only be increased, reduction is not allowed
    /* level is upgraded each time exp surpasses
     a given threshold for the actual level
     */
    if (getExp() < 0) {setExp(0);}
    while (getExp() > getLvupExp()){ levelUp();}
}

void MagicianPlayer::pray(void)//additional function to GeneralPlayer
{
    if (getHP() >= 5 * level)
    {
    increaseMP (level*10);
    increaseHP (level*(-5));
    }
    else
    {
         cout << "hp too low!" << endl;
    }
    
}

void MagicianPlayer::setAttr(int l)//set attributes
{
    level = l;
    max_hp = 120 + 15*level; // stores max. HP of the player
    max_mp = 100 + 15*level; // stores max. MP of the player
    attack = 30 + 8*level;
    defense = 20 + 7*level;
    lvup_exp = ceil( pow(10, log2(level +1)));
    setHP(getMaxHP());
    setMP(getMP());
    setExp(getExp());
    setMoney(getMoney());
}

void MagicianPlayer::specialSkill()
{
    pray();
}
