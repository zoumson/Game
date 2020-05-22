//
//  ArmorItem.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef ArmorItem_h
#define ArmorItem_h
#include"Item.h"

class ArmorItem : public Item
{
public:
    int defense_increment; //the number of increment on defense after equipping this item
    
    ArmorItem();
    ArmorItem(string, string, string,int, int, int, char);
    
    
};

#endif /* ArmorItem_h */
