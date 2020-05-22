//
//  ConsumableItem.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef ConsumableItem_h
#define ConsumableItem_h
#include"Item.h"

class ConsumableItem :public Item
{
public:
    int hp;
    int mp;
    int count = 0;
    //    void use(GeneralPlayer*);
    
    ConsumableItem(void);
    ConsumableItem(string, string, string, int, int, int, char);
    
    int recoverhp=50;
    int recovermp=30;
};
#endif /* ConsumableItem_h */
