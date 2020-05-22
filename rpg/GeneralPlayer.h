//  Xcode compiler
//  GeneralPlayer.h
//  game
//
//  Created by ZOUMA Adama on 4/29/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef GeneralPlayer_h
#define GeneralPlayer_h

#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include <math.h>
#include "Item.h"
#include "WeaponItem.h"
#include "ArmorItem.h"
#include "ConsumableItem.h"
using namespace std;
class AbstractMonster;
class  GeneralPlayer
{


private:
    
string name; // Stores the name of the player
int hp; // Stores the HP of the player, >= 0
int mp; // Stores the MP of the player, >= 0
int exp = 0; /* Stores the experience of the player, >= 0
           Will not reset to zero after level-up
              Experience is zero in the beginning */


protected :
    
    int level; // Stores the level of the player, >= 1
    int attack; // stores attack of the player
    int defense; // stores defense of the player
    int max_hp; // stores max. HP of the player
    int max_mp; // stores max. MP of the player
    int lvup_exp; // stores needed exp. to level-up
    int money = 0;// represents the number of money, >=0

    
public:
    
    GeneralPlayer(); // default constructor
    GeneralPlayer(int); // normal constructor
    GeneralPlayer(int, string); // normal constructor
    ~GeneralPlayer()//destructor
    {
        GeneralPlayer::count--;
    }
    GeneralPlayer(const GeneralPlayer&);
    
    
    void setName(string);
    string getName(void) const;
    void setLevel(int); // need to call setAttr() inside
    int getLevel(void) const;
    int getAttack(void) const;
    int getDefense(void) const;
    int getMaxHP(void) const;
    int getMaxMP(void) const;
    int getLvupExp(void) const;
    virtual void setAttr(int); // parameter is level
    
    
    void levelUp(void); // level++
    void increaseHP(int);
    void increaseMP(int);
    void increaseExp(int);
    void recoverHP(void); // hp = max_hp;
    void recoverMP(void); // mp = max_mp;
    
    
    void setExp(int);
    int getExp(void) const;
    int getHP()const;
    void setHP(int);
    int getMP () const;
    void setMP(int);
    
    
    void attackTo(AbstractMonster*);//attack monster
    virtual  void specialSkill() = 0;//specialSkill does nothing in GeneralPlayer
    void setMoney(int);
    int getMoney() const;
    static int count;
    
    string serialize() const;
    void unserialize(string);
    static GeneralPlayer* pptr[10];
    
    
    static Item*backpack[20];
    WeaponItem* weapon;
    ArmorItem* armor;
    //    ConsumableItem* potion;
    bool useWeapon(WeaponItem*);
    bool useArmor(ArmorItem*);
    void useConsumable(ConsumableItem*);
    bool putItem(Item*);
    Item* takeItem(int);
    
    
};

#endif /* GeneralPlayer_h */
