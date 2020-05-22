//
//  GoblinMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "GoblinMonster.h"



GoblinMonster::GoblinMonster(const string n, const int a, const int d, const int e, const int m_h, const int m_m, int m)
:AbstractMonster(n,a,d,e,m_h,m_m,m)   //constructor
{
    setHP(getMaxHP());
    setMP(getMaxMP());
    count++;
}

GoblinMonster::~GoblinMonster(){--count;};

void GoblinMonster::attackTo(GeneralPlayer* gp)
{
    if(this->attack - gp->getDefense()>=0)
    {
    int damage =0;
    damage = this->attack - gp->getDefense();//monster attack minus player defense
    int damagePer = damage*0.1;//10% of damage
    srand(time(0));
    switch(rand()%2)
    {
        case 0:
            damage += rand()% damagePer;//damage +10% of damage
        case 1:
            damage -= rand()% damagePer;//damage -10% of damage
    }
    gp->increaseHP(damage);
    }
    else
    {
        cout<<"Attack too low"<<endl;
    }
    
}

