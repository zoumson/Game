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


//1
void GeneralPlayer::setAttr(int l) // automatically calculate attributes for a given level
{

    level =  l;
    max_hp = 100 + 10*level; // stores max. HP of the player
    max_mp = 40 + 5*level; // stores max. MP of the player
    attack = 20 + 5*level;
    defense = 20 + 5*level;
    lvup_exp = ceil( pow(10, log2(level +1)));//exp threshold for a given level
}
//2
void GeneralPlayer::setLevel(int l){//check if level is greater or equal to 1
    try{                           //before setting attributes
        if(l<1){throw 4;}
        else {setAttr(l);}
    }
    catch (int x)
    {cout <<"Level should be equal or higher than 1."<<endl;}
}
//3
GeneralPlayer::GeneralPlayer()//default constructor
{
    setName("anonymous");
    setLevel(1) ;
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    hp = 100;
    mp = 50;
    money = 0;
    exp = 0;
    
}
//4
GeneralPlayer::GeneralPlayer (int l)//constructor that let user set level
{
    setName("anonymous");
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    hp = 100;
    mp = 50;
    money = 0;
    exp = 0;
}
//5
GeneralPlayer::GeneralPlayer (int l, string n)//constructor that let user set level and name
{
    setName(n);
    setLevel(l);
    /*the following 3 attributes should be setted by user, this is just an initialisation */
    hp = 100;
    mp = 50;
    money = 0;
    exp = 0;
}
//6
GeneralPlayer::GeneralPlayer(const GeneralPlayer& p)//copy constructor
{
    setLevel(p.level);
    setName(p.name);
    setHP(p.hp);
    setMP(p.mp);
    setExp(p.exp);
    setMoney(p.money);
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
    setLevel(++level);
    hp = 100;
    mp = 50;
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
     exp += e; ;//exp can only be increased, reuction is not allowed
    /* level is upgraded each time exp surpasses
    a given threshold for the actual level
     */
     while (exp > lvup_exp){ levelUp();}
}
//21
void GeneralPlayer::setExp(int e)
{
    
    try
    {
        if( e<0 ) { throw 3;}
        else
        {exp =e;
            /* level is upgraded each time exp surpasses
             a given threshold for the actual level
             */
        while (exp > lvup_exp){levelUp();}
        }
    }
    catch(int x) {
        cout <<"Exp cannot be a negative number."<<endl;
    }
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
    try
    {
        if( h<0 || h > max_hp) { throw 1;}
        else {hp = h;}
    }
    catch(int x) {
        cout <<"Wrong value of HP[0~"<<max_hp<<"]"<<endl;
    }
}
//25
int GeneralPlayer::getMP() const //return MP
{
    return mp ;
}
//26
void GeneralPlayer::setMP(int m)//set MP, reject all negative values or values higher than max MP
{
    try
    {
        if( m < 0 || m > max_mp) { throw 2;}
        else {mp = m;}
    }
    catch(int x) {
        cout <<"Wrong value of MP[0~"<<max_mp<<"]"<<x<<endl;
    }
}

 void GeneralPlayer::playerStats()//display player features

{
    cout<<"------------Welcome to Player Stats------------"<<endl<<endl;
    cout<<"\tPlayer Category--------------General Player"<<endl;
    cout<<"\tPlayer name------------------"<<name<<endl;
    cout<<"\tLevel------------------------"<<level<<endl;
    cout<<"\tHP---------------------------"<<hp<<"/"<<max_hp<<endl;
    cout<<"\tMP---------------------------"<<mp<<"/"<<max_mp<<endl;
    cout<<"\tExp--------------------------"<<exp<<"/"<<lvup_exp<<endl;
    cout<<"\tAttack-----------------------"<<attack<<endl;
    cout<<"\tDefense----------------------"<<defense<<endl;
   cout<<endl<<"-----------------------End---------------------"<<endl;

    
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
        --ab->count;//when a monster died the number of monster is reduced
        
    }
 

}


void GeneralPlayer::setMoney(int m)

{
    
    try
    {
        if( m < 0) { throw 7;}
        else { money = m;}
    }
    catch(int x) {
        cout <<"Wrong value of Money"<<endl;
    }

}
int GeneralPlayer::getMoney() const
{
    return money;
}
string GeneralPlayer::serialize() const
{
    ofstream saveFile ("File.txt", ios::out);
    
    if (saveFile)
    {
        //We only save values that can be setted
        //Automically generated values are not concerned (attack, defense...etc)
        saveFile << level << "$" << hp << "$" << mp << "$" << exp << "$" <<money<<endl;
    }
    else
        cout << "File could not be opened" << endl;
    string word;
    ifstream readFile("File.txt", ios::in);
    getline(readFile, word);
    return word;
}


void GeneralPlayer::unserialize(string openFile)
{
    int count = 0;
    for (int i = 0; i < openFile.size(); i++)
    {
        if (i == 0)//first word contains level
        {
            istringstream convert(&openFile[0]);
            convert >> level;
            setLevel(level);
            count++;
        }
        else if (openFile[i] == '$'&&count == 1)
        {
            int wordToNumber;
            istringstream readHP(&openFile[i + 1]);
            readHP >> wordToNumber;
            setHP(wordToNumber);
            count++;
        }
        else if (openFile[i] == '$'&&count == 2)
        {
            int wordToNumber;
            istringstream readMP(&openFile[i + 1]);
            readMP >> wordToNumber;
            setMP(wordToNumber);
            count++;
        }
        else if (openFile[i] == '$'&&count == 3)
        {
            int wordToNumber;
            istringstream readEXP(&openFile[i + 1]);
            readEXP >> wordToNumber;
            setExp(wordToNumber);
            count++;
        }
        else if (openFile[i] == '$'&&count == 4)
        {
            int wordToNumber;
            istringstream readMONEY(&openFile[i + 1]);
            readMONEY >> wordToNumber;
            setMoney(wordToNumber);
        }
        
        
    
        
    }
    
}







