//
//  ZombieMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "ZombieMonster.h"




ZombieMonster::ZombieMonster(string n, int a, int d , int e, int h, int m):AbstractMonster("Zombie", 50, 65, 17, 150, 30)

{
    ++count;
    setHP(max_hp);
    setMP(max_mp);
};
ZombieMonster::~ZombieMonster(){--count;};

void ZombieMonster::attackTo(GeneralPlayer* gp)
{
  
    
    if(this->getMP()!=0 && this->getHP()!=0 && this->attack >= gp->getDefense())//monster attack condition
        
    {
        switch(rand() % 2)
        {
            case 0://normal attack
            {
                
                double damage =0;
                damage = (double)(this->attack - gp->getDefense());//monster attack minus player defense
                damage *= 1.1;//damage is increased by 10%
                gp->setHP(gp->getHP() - (int)damage);//player hp update
                
                if(gp->getHP()== 0)// when player hp is zero player died
                {
                    cout<<"ZOMBIE TOO STRONG"<<endl;
                    cout<<"ZOMBIE has killed Player"<<endl;
                }
                else
                {
                    cout<<"ZOMBIE WEAK"<<endl;
                    cout<<"Player Survives After ZOMBIE Attack"<<endl;
                }
                break;
            }
                
                
            case 1://super attack
                
            {
                double dmg =0;//damage
                int imp = 0;//impact
                
                dmg = 2.0*this->attack - gp->getDefense();// monster attack power is doubled before fighting player
                dmg *= 1.1;
                imp = gp->getHP()-(int)dmg;
                gp->setHP(imp);
                //starting value of mp is max mp
                int static mpr = this->max_mp;//make mpr static, so that for next attack mp is last attack mp after the fight
                mpr -= 10;//super attack reduced mp always by 10
                this->setMP(mpr);
                if(this->getMP()==0){cout<<"No more Super Attack for JW!!"<<endl;}
                if(gp->getHP()== 0)// when monster hp is zero monster died
                {
                    cout<<"ZOMBIE TOO STRONG"<<endl;
                    cout<<"ZOMBIE has killed Player"<<endl;
                }
                else
                {
                    cout<<"ZOMBIE WEAK"<<endl;
                    cout<<"Player Survives After ZOMBIE Attack"<<endl;
                }
                break;
            }
                
        }
    }
    
    else
    {
        cout<<"Attack Impossible"<<endl<<"ZOMBIE TOO WEAK"<<endl;
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













