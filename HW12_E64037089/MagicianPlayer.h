//  Xcode compiler
//  MagicianPlayer.h
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef MagicianPlayer_h
#define MagicianPlayer_h
#include "GeneralPlayer.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class MagicianPlayer:  public GeneralPlayer
{
public:
    
    MagicianPlayer();
    MagicianPlayer(int);
    MagicianPlayer(int, string);
    MagicianPlayer(const MagicianPlayer&);
    void setLevel(int);
    void setAttr(int);
    void levelUp(void);
    void pray(void);
    void increaseExp(int);
    void specialSkill();// specialSkill is pray in MagicianPlayer
};

#endif /* MagicianPlayer_h */
