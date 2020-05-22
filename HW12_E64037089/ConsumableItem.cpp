//
//  ConsumableItem.cpp
//  myRpg
//
//  Created by ZOUMA Adama on 6/27/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"ConsumableItem.h"
#include<string>
using namespace std;

ConsumableItem::ConsumableItem()
{
    name = "potion";
    effects = "No effects";
    description = "No description";
    weight = 0;
    type = 'c';
    hp = 50;
    mp = 30;
}

ConsumableItem::ConsumableItem(string n, string e, string d, int h, int m, int w, char t)
{
    name = n;
    effects = e;
    description = d;
    weight = w;
    type = t;
    recoverhp = h;
    recovermp = m;
    count+=100;
}



//
//void ConsumableItem::use(GeneralPlayer*g)
//{
//    g->increaseHP(recoverhp);
//    g->increaseMP(recovermp);
//}

