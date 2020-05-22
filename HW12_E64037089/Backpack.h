//
//  Backpack.h
//  myRpg
//
//  Created by ZOUMA Adama on 6/27/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef Backpack_h
#define Backpack_h

#include<iostream>
#include"Item.h"
#include"ArmorItem.h"
#include"WeaponItem.h"

using namespace std;

class Backpack
{
public:
    Backpack(int);
    ~Backpack()
    {
        delete[] backpack;
    }
    Item** backpack; // the °ßinventory°® in many other games
    WeaponItem* weapon; // weapon item
    ArmorItem* armor; // armor item
    int backpack_weight; // current weight of player°¶s backpack
    int backpack_weight_limit; // limit on weight of backpack
    int backpack_slot_limit; // limit on number of backpack°¶s slots
    void showout_backpack();
    
    
};


#endif /* Backpack_h */
