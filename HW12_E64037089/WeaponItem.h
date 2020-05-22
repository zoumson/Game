//
//  WeaponItem.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef WeaponItem_h
#define WeaponItem_h
#include"Item.h"

class WeaponItem : public Item
{
public:
    int attack_increment; //the number of increment on attack after equipping this item
    
    
    
    WeaponItem();
    WeaponItem(string, string, string,int , int, int, char);
    
};

#endif /* WeaponItem_h */
