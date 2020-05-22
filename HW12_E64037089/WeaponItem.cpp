//
//  WeaponItem.cpp
//  myRpg
//
//  Created by ZOUMA Adama on 6/27/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"WeaponItem.h"

using namespace std;

WeaponItem::WeaponItem()
{
    name = "sword";
    effects = "No effects";
    description = "No description";
    level_required = 0;
    weight = 0;
    type = 'w';
}

WeaponItem::WeaponItem(string n, string e, string d, int a ,int l, int w, char t)
{
    name = n;
    effects = e;
    description = d;
    level_required = l;
    attack_increment = a;
    weight = w;
    type = t;
    
}
