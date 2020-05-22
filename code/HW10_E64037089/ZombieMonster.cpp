//
//  ZombieMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "ZombieMonster.h"




ZombieMonster::ZombieMonster():AbstractMonster("Zombie", 50, 65, 17, 150, 30)

{
    ++count;
    setHP(max_hp);
    setMP(max_mp);
};
ZombieMonster::~ZombieMonster(){--count;};

void ZombieMonster::attackTo(GeneralPlayer* gp)
{
 
    srand(time(0));
    if( 2*this->attack >= gp->getDefense())//monster attack condition
    {
        
    {
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
                break;
            }
                 }
                
                
            case 1://super attack
                
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
                break;
            }
                
        }
    }
    }
    

}


void ZombieMonster::monsterStats()


{
    cout<<"------------Welcome to Monster Stats------------"<<endl<<endl;
    cout<<"\tMonster Category--------------Zombie Monster"<<endl;
    cout<<"\tMonster name------------------"<<name<<endl;
    cout<<"\tHP---------------------------"<<getHP()<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<getMP()<<"/"<<max_mp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
    if(getHP()>0)
    {
        cout<<"\t---------Zombie ALIVE--------"<<endl;
        if(getMP()==0)
        {
            cout<<"\t--------Zombie Cannot Attack---------"<<endl;
            
        }
        
    }
    else
    {
        cout<<"\t--------Zombie DIED---------"<<endl;
        
    }
    cout<<endl<<"-----------------------End---------------------"<<endl;
    
    
}













