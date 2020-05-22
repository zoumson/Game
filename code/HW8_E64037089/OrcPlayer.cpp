//  Xcode compiler
//  OrcPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//


#include <iostream>
#include <string>
#include <math.h>
#include "OrcPlayer.h"


using namespace std;
//1
OrcPlayer::OrcPlayer()//default constructor 
{
    
    setName("anonymous");
    setLevel(1) ;
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(0);
    setMP(0);
    setExp(0);
    
}
//2
OrcPlayer::OrcPlayer(int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(0);
    setMP(0);
    setExp(0);
}
//3
OrcPlayer::OrcPlayer(int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(0);
    setMP(0);
    setExp(0);
}
//4
OrcPlayer::OrcPlayer(const OrcPlayer& p)//copy constructor
{
    setLevel(p.getLevel());
    setName(p.getName());
}
//5
void OrcPlayer::setLevel(int l)//set level
{
    try{
        if(l<1){throw 4;}
        else {setAttr(l);}
        
    }
    catch (int x)
    {cout <<"Level should be equal or higher than 1. Error number "<<x<<endl;}
}
//6
void OrcPlayer::setAttr(int l)//set attributes
{
    level = l;
    max_hp = 200 + 20*level; // stores max. HP of the player
    max_mp = 50 + 5*level; // stores max. MP of the player
    attack = 50 + 12*level;
    defense = 30 + 10*level;
    lvup_exp = ceil( pow(10, log2(level +1)));
}
//7
void OrcPlayer::levelUp(void)//level upgrading 
{
    setLevel(++level);
    /*the following 2 attributes should be setted by user, this is just an initialisation
     in case of level upgrading but exp is kept*/
    setHP(0);
    setMP(0);
    
    
}
void OrcPlayer::playerStats()//display player features 

{
    cout<<"------------Welcome to Player Stats------------"<<endl<<endl;
    cout<<"\tPlayer Category--------------Orc Player"<<endl;
    cout<<"\tPlayer name------------------"<<getName()<<endl;
    cout<<"\tLevel------------------------"<<level<<endl;
    cout<<"\tHP---------------------------"<<getHP()<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<getMP()<<"/"<<max_mp<<endl;
    cout<<"\tExp--------------------------"<<getExp()<<"/"<<lvup_exp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
    cout<<endl<<"----------------------End----------------------"<<endl;
    
    
}
