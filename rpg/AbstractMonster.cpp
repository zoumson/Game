//
//  AbstractMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "AbstractMonster.h"

int AbstractMonster::count = 0;

AbstractMonster::AbstractMonster(const string n, const int a, const int d, const int e, const int m_h, const int m_m,int m)
:name(n),attack(a),defense(d),exp(e),max_hp(m_h),max_mp(m_m),money(m)
{
    setHP(getMaxHP());
    setMP(getMaxMP());
    count++;
}
void AbstractMonster::setHP(int h) {
    if (h > max_hp) {
        hp = max_hp;
    }
    else if (h < 0)
        hp = 0;
    else
        hp = h;
}
int AbstractMonster::getHP() const {
    return hp;
}
void AbstractMonster::setMP(int m) {
    if (m > max_mp) {
        mp = max_mp;
    }
    else if (m < 0)
        mp = 0;
    else
        mp = m;
}
int AbstractMonster::getMP() const {
    return mp;
}
int AbstractMonster::getAttack()const {
    return attack;
}
int AbstractMonster::getDefense()const {
    return defense;
}
int AbstractMonster::getMaxHP()const {
    return max_hp;
}
int AbstractMonster::getMaxMP()const {
    return max_mp;
}
int AbstractMonster::getmaxExp()const {
    return exp;
}
string AbstractMonster::setName()const {
    return name;
}
AbstractMonster::~AbstractMonster() {
    count--;
}
void AbstractMonster::attackTo(GeneralPlayer*g) {}


