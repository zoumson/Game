//  Xcode compiler
//  GeneralPlayer.cpp
//  game
//
//  Created by ZOUMA Adama on 4/29/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "GeneralPlayer.h"
#include "AbstractMonster.h"
#include<string>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include <vector>


GeneralPlayer* GeneralPlayer::pptr[] = {};
int  GeneralPlayer::count = 0;//Initialize the number of players to zero
Item* GeneralPlayer::backpack[] = {};//player backpack is empty in the beginning

//1
void GeneralPlayer::setAttr(int l) // automatically calculate attributes for a given level
{

    level =  l;
    max_hp = 100 + 10*level; // stores max. HP of the player
    max_mp = 40 + 5*level; // stores max. MP of the player
    attack = 20 + 5*level;
    defense = 20 + 5*level;
    lvup_exp = ceil( pow(10, log2(level +1)));//exp threshold for a given level
    setHP(max_hp);
    setMP(max_mp);
    setExp(exp);
    setMoney(money);
   
}
//2
void GeneralPlayer::setLevel(int l){//check if level is greater or equal to 1
                              //before setting attributes
    while(l<1){cout<<"Reset level again"<<endl;}
    
        setAttr(l);
    if(exp > lvup_exp){ exp = lvup_exp;}
  
}
//3
GeneralPlayer::GeneralPlayer()//default constructor
{
    setName("anonymous");
    setLevel(1) ;
    weapon = NULL;
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//4
GeneralPlayer::GeneralPlayer (int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    weapon = NULL;
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//5
GeneralPlayer::GeneralPlayer (int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    weapon = NULL;
    GeneralPlayer::count++;
    GeneralPlayer::pptr[count] = this;
}
//6
GeneralPlayer::GeneralPlayer(const GeneralPlayer& p)//copy constructor
{
    setLevel(p.level);
    setName(p.name);
}

//7
void GeneralPlayer::setName(string s)// set name
{
    name = s;
}
//8
string GeneralPlayer::getName(void) const//return name
{
    return name;
}
//9
int GeneralPlayer::getLevel(void) const//return level
{
    return level;
}
//10
int GeneralPlayer::getAttack(void) const//return attack
{
    return attack;
}
//11
int GeneralPlayer::getDefense(void) const//return defense
{
    return defense;
}
//12
int GeneralPlayer::getMaxHP(void) const//return max HP
{
    return max_hp;
}
//13
int GeneralPlayer::getMaxMP(void) const//return max MP
{
    return max_mp;
    
}
//14
int GeneralPlayer::getLvupExp(void) const// return exp threshold for given level
{
    return lvup_exp;
}
//15
void GeneralPlayer::levelUp(void)//upgrade level to next level and set next level attributes
{
    hp = max_hp;
    mp = max_mp;
    setLevel(++level);
 
    //exp is unchanged

}
//16
void GeneralPlayer::recoverHP(void) // hp = max_hp
{
     setHP(max_hp);
}
//17
void GeneralPlayer::recoverMP(void) // mp = max_mp
{
    setMP(max_hp);
}
//18
void GeneralPlayer::increaseHP(int h)
{
    
    hp += h;
    /* -after increase if final HP is greater than max HP, set it back to max HP
       -after decrease if HP is less than 0, set it to 0
     */
    if(hp > max_hp){mp = max_hp;}
    if(hp < 0){hp = 0;}
}
//19
void GeneralPlayer::increaseMP(int m)
{       mp += m ;
    /* -after increase if final MP is greater than max MP, set it back to max MP
     -after decrease if MP is less than 0,set it to zero
     */
    if(mp > max_mp){mp = max_mp;}
    if(mp < 0){mp = 0;}
}
//20
void GeneralPlayer::increaseExp(int e)
{
     exp += e; ;//exp can only be increased, reduction is not allowed
    /* level is upgraded each time exp surpasses
    a given threshold for the actual level
     */
    if (exp < 0) {exp= 0;}
     while (exp > lvup_exp){ levelUp();}
}
//21
void GeneralPlayer::setExp(int e)
{
    
   
        if( e<0 ) {exp = 0;}
        else
        {
            exp =e;
            /* level is upgraded each time exp surpasses
             a given threshold for the actual level
             */
        while (exp > lvup_exp){levelUp();}//end of while
            
        }//end of else
   
}
//22
int GeneralPlayer::getExp() const//return exp
{
    return exp;
}
//23
int GeneralPlayer::getHP()const //return HP
{
    return hp;
}
//24
void GeneralPlayer::setHP(int h)//set HP, reject all negative values or values higher than max HP
{
    if (h > max_hp) {
        hp = max_hp;
    }
    else if (h < 0)
        hp = 0;
    else
        hp = h;
}
//25
int GeneralPlayer::getMP() const //return MP
{
    return mp ;
}
//26
void GeneralPlayer::setMP(int m)//set MP, reject all negative values or values higher than max MP
{
    if (m >= max_mp) {
        mp = max_mp;
    }
    else if (m < 0)
        mp = 0;
    else
        mp = m;
}


void GeneralPlayer::attackTo(AbstractMonster* ab)
{
    
    int damage =0;
    damage =  this->attack - ab->defense;//player attack minus monster defense
    int damagePer = damage*0.1;//10% of damage
    switch(rand()%2)
    {
        case 0:
            damage += rand()% damagePer;//damage +10% of damage
        case 1:
            damage -= rand()% damagePer;//damage -10% of damage
    }
    ab->setHP(ab->getHP() - damage);//monster hp update, its hp is automatically max hp before fight start
    
    if(ab->getHP()== 0 )// when monster hp is zero monster died
    {
        
        this->increaseExp(ab->exp);//player exp is increased to the threshold of the actual level
                                        //and player is ready to get into the next level
        money += ab->money;
        
        --ab->count;//when a monster died the number of monster is reduced
        
    }
 

}


void GeneralPlayer::setMoney(int m)

{
   
        if( m < 0) { money = 0;}
        else { money = m;}
    
}
int GeneralPlayer::getMoney() const
{
    return money;
}
string GeneralPlayer::serialize() const
{
    stringstream ss;
    
    ss <<level<<"|"<<hp<<"|"<<mp<<"|"<<exp<<"|"<<money;
    
    string s;
    ss >> s;
    return s;
}


void GeneralPlayer::unserialize(string s)
{
    int ls, hs, ms, es, mos;
    stringstream ss(s);
    
    ss >> ls;
    getline(ss, s, '|');
    ss >> hs;
    getline(ss, s, '|');
    ss >> ms;
    getline(ss, s, '|');
    ss >> es;
    getline(ss, s, '|');
    ss >> mos;
    if (!ss) cout << "error type" << endl; //check is convert successfully
    //else cout <<ls << endl;
    
    cout << "str type:" << s << endl;
    cout << "convert to num:" << ls << " " << hs << " " << ms << " " << es << " " << mos << endl;
        
    
        
}
    








