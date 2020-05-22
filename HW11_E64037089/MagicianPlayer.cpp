//  Xcode compiler
//  MagicianPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include"MagicianPlayer.h"


//1
MagicianPlayer::MagicianPlayer()//default constructor
{
    setName("anonymous");
    setLevel(1) ;
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(100);
    setMP(50);
    setExp(0);
}
//2
MagicianPlayer::MagicianPlayer(int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(100);
    setMP(50);
    setExp(0);
}
//3
MagicianPlayer::MagicianPlayer(int l, string n)//constructor that let user set level and name
{
    
    setName(n);
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    setHP(100);
    setMP(50);
    setExp(0);

}
//4
MagicianPlayer::MagicianPlayer(const MagicianPlayer& p)//copy constructor
{
    setLevel(p.getLevel());
    setName(p.getName());

}
//5
void MagicianPlayer::setLevel(int l)//set level
{
    try{
        if(l<1){throw 4;}
        else {setAttr(l);}
        
    }
    catch (int x)
    {cout <<"Level should be equal or higher than 1."<<endl;}
}
//6
void MagicianPlayer::setAttr(int l)//set attributes
{
    level = l;
    max_hp = 120 + 15*level; // stores max. HP of the player
    max_mp = 100 + 15*level; // stores max. MP of the player
    attack = 30 + 8*level;
    defense = 20 + 7*level;
    lvup_exp = ceil( pow(10, log2(level +1)));
}
//7
void MagicianPlayer::levelUp(void)//level upgrading
{
     setLevel(++level);
    setHP(100);
    setMP(50);
}
//8
void MagicianPlayer::pray(void)//additional function to GeneralPlayer
{
    increaseMP (level*10);
    increaseHP (level*(-5));
    
}
void MagicianPlayer::playerStats()//display player features, function overrided

{
    cout<<"------------Welcome to Player Stats------------"<<endl<<endl;
    cout<<"\tPlayer Category--------------Magician Player"<<endl;
    cout<<"\tPlayer name------------------"<<getName()<<endl;
    cout<<"\tLevel------------------------"<<level<<endl;
    cout<<"\tHP---------------------------"<<getHP()<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<getMP()<<"/"<<max_mp<<endl;
    cout<<"\tExp--------------------------"<<getExp()<<"/"<<lvup_exp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
    cout<<endl<<"----------------------End----------------------"<<endl;
    
    
}

void MagicianPlayer::specialSkill()
{
    pray();
}
