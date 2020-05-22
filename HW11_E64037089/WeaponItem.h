//
//  WeaponItem.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef WeaponItem_h
#define WeaponItem_h
#include "Item.h"
class WeaponItem: public Item
{
public:
    //const public data member
    int attack_increment; //the number of increment on attack after equipping this item

};

#endif /* WeaponItem_h */
