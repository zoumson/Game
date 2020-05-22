//
//  AbstractMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "AbstractMonster.h"

int AbstractMonster::count = 0;


AbstractMonster::AbstractMonster(string n, int a, int d , int e, int h, int m):name(n),attack(a),defense(d), exp(e), max_hp(h), max_mp(m)
{
    //abstract is not a real monster so we don't count the number of monster created here
    setHP(max_hp);
    setMP(max_mp);
};

AbstractMonster::~AbstractMonster(){}
void AbstractMonster::setHP(int h)
{
    if(h < 0){hp = 0;} //monster hp is updated automatically after attack, so we cannot control the incoming argument
    else               //if argument h is negative, just set hp to zero, meaning monster died
    {hp = h;}
}
int AbstractMonster::getHP() const
{
    return hp;
}
void AbstractMonster::setMP(int m)
{
    if(m < 0){mp = 0;} //monster mp is updated automatically after attack, so we cannot control the incoming argument
    else               //if argument n is negative, just set mp to zero, meaning monster loses ability to attack
    {mp = m;}
}
int AbstractMonster::getMP() const
{
    return mp;
}
int AbstractMonster::getCount()
{return count;}

bool AbstractMonster::canAttack(GeneralPlayer* gp)
{
    return this->getMP()!=0 && this->getHP()!=0 && this->attack >= gp->getDefense();
}
