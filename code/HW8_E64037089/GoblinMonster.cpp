//
//  GoblinMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "GoblinMonster.h"




GoblinMonster::GoblinMonster(string n, int a, int d , int e, int h, int m):AbstractMonster("Goblin", 60, 40, 12, 100, 50)
{
    setHP(max_hp);
    setMP(max_mp);
    ++count;
    
};
GoblinMonster::~GoblinMonster(){--count;};

void GoblinMonster::attackTo(GeneralPlayer* gp)
{
    
    if(this->getMP()!=0 && this->getHP()!=0 && this->attack >= gp->getDefense())//monster attack condition 
    {
    double damage =0;
    damage = (double)(this->attack - gp->getDefense());//monster attack minus player defense
    damage *= 1.1;//damage is increased by 10%
    gp->setHP(gp->getHP() - (int)damage);//player hp update, hp is set up manually before fight
   
    if(gp->getHP() ==0 )// when player hp is zero player died
    {
        cout<<"Goblin TOO STRONG"<<endl;
        cout<<"Goblin has killed Player"<<endl;
    }
        
    }
    
    else
    {
        cout<<"Attack Impossible"<<endl<<"Monster TOO WEAK"<<endl;
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







