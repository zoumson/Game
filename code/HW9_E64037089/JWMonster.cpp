//
//  JWMonster.cpp
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "JWMonster.h"





JWMonster::JWMonster():AbstractMonster("JWHuang", 120, 100, 42, 250, 100)
{
    ++count;
    setHP(max_hp);
    setMP(max_mp);
};
JWMonster::~JWMonster(){--count;};

void JWMonster::attackTo(GeneralPlayer* gp)
{
    this->setHP(  (int) 1.1*getHP());//monster hp increases by 10% before fight
    this->setMP((int) 1.05*getMP());//monster mp increases by 5% before fight
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

void JWMonster::monsterStats()


{
    cout<<"------------Welcome to Monster Stats------------"<<endl<<endl;
    cout<<"\tMonster Category--------------JW Monster"<<endl;
    cout<<"\tMonster name------------------"<<name<<endl;
    cout<<"\tHP---------------------------"<<getHP()<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<getMP()<<"/"<<max_mp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
    if(getHP()>0)
    {
        cout<<"\t-----------------JW ALIVE-------------"<<endl;
        if(getMP()==0)
        {
            cout<<"\t----------JW Cannot Attack--------"<<endl;
            
        }
        
    }
    else
    {
        cout<<"\t----------------JW DIED-----------------"<<endl;
        
    }
    cout<<endl<<"-----------------------End---------------------"<<endl;
    
    
}

























