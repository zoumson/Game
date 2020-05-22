//
//  ConsumableItem.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef ConsumableItem_h
#define ConsumableItem_h
#include "Item.h"

class ConsumableItem: public Item
{
public:
    //We add a public member function here
    void use(GeneralPlayer* gp);
   // This function is responsible to adjust a player’s status such as HP, MP…
};

#endif /* ConsumableItem_h */
