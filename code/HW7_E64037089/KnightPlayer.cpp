//  Xcode compiler
//  KnightPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include "KnightPlayer.h"
//1
KnightPlayer::KnightPlayer()//default constructor
{
    setName("anonymous");
    setLevel(1) ;
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(0);
    setMP(0);
    setExp(0);
}
//2
KnightPlayer::KnightPlayer(int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(0);
    setMP(0);
    setExp(0);
}
//3
KnightPlayer::KnightPlayer(int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(0);
    setMP(0);
    setExp(0);
}
//4
KnightPlayer::KnightPlayer(const KnightPlayer& p)//copy constructor
{
    setLevel(p.getLevel());
    setName(p.getName());
    
}
//5
void KnightPlayer::setLevel(int l)//set level
{
    try{
        if(l<1){throw 4;}
        else {setAttr(l);}
        
    }
    catch (int x)
    {cout <<"Level should be equal or higher than 1."<<endl;}}
//6
void KnightPlayer::setAttr(int l)//set attributes
{
   

    level = l;
    setExp(0);
    max_hp = 150 + 25*level; // stores max. HP of the player
    max_mp = 70 + 10*level; // stores max. MP of the player
    attack = 40 + 10*level;
    defense = 20 + 12*level;
    lvup_exp = ceil( pow(10, log2(level +1)));
    
}
//7
void KnightPlayer::levelUp(void)// upgrading level
{
     setLevel(++level);
    setHP(0);
    setMP(0);
}
//8
void KnightPlayer::heal(void)// additional function to GeneralPlayer
{
    increaseHP (level*10) ;
    increaseMP (level*(-5));

}

void KnightPlayer::playerStats()//display player features, function overrided 

{
    cout<<"------------Welcome to Player Stats------------"<<endl<<endl;
    cout<<"\tPlayer Category--------------Knight Player"<<endl;
    cout<<"\tPlayer name------------------"<<getName()<<endl;
    cout<<"\tLevel------------------------"<<level<<endl;
    cout<<"\tHP---------------------------"<<getHP()<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<getMP()<<"/"<<max_mp<<endl;
    cout<<"\tExp--------------------------"<<getExp()<<"/"<<lvup_exp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
    cout<<endl<<"----------------------End----------------------"<<endl;
    
    
}


