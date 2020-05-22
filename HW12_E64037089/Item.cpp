//
//  Item.cpp
//  myRpg
//
//  Created by ZOUMA Adama on 6/27/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"Item.h"

using namespace std;

Item::Item()
{
    name = "No name";
    effects = "No effects";
}

Item::Item(string n,string e ,string d,int l ,int w ,char t)
{
    name = n;
    effects = e;
    description = d;
    level_required = l;
    weight = w;
    type = t;
}
