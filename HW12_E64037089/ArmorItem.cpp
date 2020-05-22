//
//  ArmorItem.cpp
//  myRpg
//
//  Created by ZOUMA Adama on 6/27/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"ArmorItem.h"

using namespace std;

ArmorItem::ArmorItem()
{
    name = "armor";
    effects = "No effects";
    description = "No description";
    level_required = 0;
    weight = 0;
    type = 'a';
    
    
}

ArmorItem::ArmorItem(string n, string e, string de,int d, int l, int w, char t)
{
    name = n;
    effects = e;
    description = d;
    level_required = l;
    defense_increment = d;
    weight = w;
    type = t;
}
