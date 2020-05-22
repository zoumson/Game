//
//  ZombieMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "ZombieMonster.h"




ZombieMonster::ZombieMonster(const string n, const int a, const int d, const int e, const int m_h, const int m_m,int m)
:AbstractMonster(n,a,d,e,m_h,m_m,m)                //constructor
{
    setHP(getMaxHP());
    setMP(getMaxMP());
    count++;
}
ZombieMonster::~ZombieMonster(){--count;};

void ZombieMonster::attackTo(GeneralPlayer* gp)
{
 
    srand(time(0));
        switch(rand() % 2)
        {
            case 0://normal attack
                 if( this->attack >= gp->getDefense())
                 {
            {
                
                int damage =0;
                damage = this->attack - gp->getDefense();//monster attack minus player defense
                int damagePer = damage*0.1;//10% of damage
                switch(rand()%2)
                {
                    case 0:
                        damage += rand()% damagePer;//damage +10% of damage
                    case 1:
                        damage -= rand()% damagePer;//damage -10% of damage
                }
                gp->increaseHP(damage);
                
            }
                 }
                else
                {
                    cout<<"Attack too low"<<endl;
                }
                
                break;
                
                
            case 1://super attack
                
            {
                if( this->attack >= gp->getDefense() && getMP()>=10)
                {
                
                int damage =0;
                damage = 2*this->attack - gp->getDefense();//monster attack minus player defense
                int damagePer = damage*0.1;//10% of damage
                switch(rand()%2)
                {
                    case 0:
                        damage += rand()% damagePer;//damage +10% of damage
                    case 1:
                        damage -= rand()% damagePer;//damage -10% of damage
                }
                gp->increaseHP(damage);
                //starting value of mp is max mp
                int static mpr = this->max_mp;//make mpr static, so that for next attack mp is last attack mp after the fight
                mpr -= 10;//super attack reduced mp always by 10
                this->setMP(mpr);
                }
                else if (this->attack >= gp->getDefense()&& !(getMP()>=10))// normal attack
                {
                    
                    int damage =0;
                    damage = this->attack - gp->getDefense();//monster attack minus player defense
                    int damagePer = damage*0.1;//10% of damage
                    switch(rand()%2)
                    {
                        case 0:
                            damage += rand()% damagePer;//damage +10% of damage
                        case 1:
                            damage -= rand()% damagePer;//damage -10% of damage
                    }
                    gp->increaseHP(damage);
                    
                }
                else//attack fail
                {
                    cout <<"Attack too low"<<endl;
                }
                break;
               
            }
                
        }


}


