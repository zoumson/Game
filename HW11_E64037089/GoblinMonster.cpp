//
//  GoblinMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "GoblinMonster.h"




GoblinMonster::GoblinMonster():AbstractMonster("Goblin", 60, 40, 12, 100, 50)

{
    setHP(max_hp);
    setMP(max_mp);
    ++count;
    
};
GoblinMonster::~GoblinMonster(){--count;};

void GoblinMonster::attackTo(GeneralPlayer* gp)
{
    if(this->attack - gp->getDefense()>0)
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
    
}

void GoblinMonster::monsterStats()

{
    cout<<"------------Welcome to Monster Stats------------"<<endl<<endl;
    cout<<"\tMonster Category-------------Goblin Monster"<<endl;
    cout<<"\tMonster name-----------------"<<name<<endl;
    cout<<"\tHP---------------------------"<<getHP()<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<getMP()<<"/"<<max_mp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
    if(getHP()>0)
    {
        cout<<"\t------------Goblin ALIVE-------"<<endl;
        if(getMP()==0)
        {
        cout<<"\t------------Goblin Cannot Attack-------"<<endl;

        }
        
    }
    else
    {
        cout<<"\t\t-----------Goblin DIED-------"<<endl;

    }
    cout<<endl<<"-----------------------End---------------------"<<endl;

    
}













