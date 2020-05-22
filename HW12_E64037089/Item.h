//
//  Item.h
//  try
//
//  Created by ZOUMA Adama on 5/28/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef Item_h
#define Item_h
#include<iostream>
#include<string>

using namespace std;
class Item
{
    
public:
    
    int level_required; // level limit of equip/use this item
    string name; // the name of this item
    string effects;// a short description of its effect
    string description; // a short description of this item
    int weight; // the weight of the item
    char type;
    
    Item();
    Item(string, string, string, int, int, char);
    
    
    void showoutinfo()
    {
        cout << "name" << name << endl;
        cout << "effects" << effects << endl;
    }
    
    
    
};


#endif /* Item_h */
