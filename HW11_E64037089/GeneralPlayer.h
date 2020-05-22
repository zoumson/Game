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
int exp; /* Stores the experience of the player, >= 0
           Will not reset to zero after level-up*/


protected :
    
    int level; // Stores the level of the player, >= 1
    int attack; // stores attack of the player
    int defense; // stores defense of the player
    int max_hp; // stores max. HP of the player
    int max_mp; // stores max. MP of the player
    int lvup_exp; // stores needed exp. to level-up
    int money;// represents the number of money, >=0

    
public:
    
    GeneralPlayer(); // default constructor
    GeneralPlayer(int); // normal constructor
    GeneralPlayer(int, string); // normal constructor
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
    virtual void playerStats();//display player features
    void attackTo(AbstractMonster*);//attack monster
    virtual  void specialSkill() = 0;//specialSkill does nothing in GeneralPlayer
    void setMoney(int);
    int getMoney() const;
    string serialize() const;
    void unserialize(string);
    Item** backpack; // the “inventory” in many other games
    WeaponItem* weapon; // weapon item
    ArmorItem* armor; // armor item
    int backpack_weight; // current weight of player’s backpack
    int backpack_weight_limit; // limit on weight of backpack
    int backpack_slot_limit; // limit on number of backpack’s slots
    
    bool equipWeapon(WeaponItem*);
    bool equipArmor(ArmorItem*);
    /*
     Equipping a weapon/armor
    If there’s a weapon/armor already equipped, use the new one to replace the old one. Then put the old one to backpack (Don’t forget to check the slot & weight limit)
    The return value indicates this operation is successful or not
    True => successful
    False => failed, backpack weight limit exceed, level does not meet the requirement, etc
     */
    void useConsumable(ConsumableItem*);
    /*
     Using a consumable item
    Remembering that consumable items will vanished after using them
     */

    bool putItem(Item*);
    /*
     Put(add) an item into backpack
    The return value indicates this operation is successful or not
    True => successful
    False => failed, maybe there is no empty slots or weight limit exceeds
     */
    Item* takeItem(int);
    /*
    Take(remove) an item from backpack
    The parameter is the index of backpack
    The return value is a pointer that points to the item to be removed
    If the slot of that index value is empty, return a NULL pointer
     */

    
    
    
    
    
    
   
    






};

#endif /* GeneralPlayer_h */
