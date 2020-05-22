//
//  Item.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef Item_h
#define Item_h
#include <iostream>
using namespace std;

class GeneralPlayer;
class Item
{
private:
public:
    
    Item operator=(const Item & rhs)
    {
        return *this;
    }
    //const public Data members
    const int level_required; // level limit of equip/use this item
    const string name; // the name of this item
    //E.g., “JW’s Hand”
    const string effects; // a short description of its effect
    //E.g., “Attack+100, 20% of probability making opponents cannot act at the next turn”
    const string description; // a short description of this item
    /*E.g., “A silver-made hand-shaped weapon. There’s a folklore said that once upon a time, a blacksmith encountered and was beaten by the JWMaster. While fighting with JWM, he found that the shape of JWM’s hand is so beautiful. So he made a weapon that mimics the shape of JWM’s hand for increasing his ability in self-defense.”*/
    const int weight; // the weight of the item
    const char type;
    //Type of this item, “w” for weapons, “a” for armors, “c” for consumables

    
};


#endif /* Item_h */
