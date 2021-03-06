//  Xcode compiler
//  KnightPlayer.h
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef KnightPlayer_h
#define KnightPlayer_h
#include "GeneralPlayer.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class KnightPlayer : public GeneralPlayer
{
public:
        KnightPlayer();
        KnightPlayer(int);
        KnightPlayer(int, string);
        KnightPlayer(const KnightPlayer&);
        void setLevel(int);
        void setAttr(int);
        void levelUp(void);
        void heal(void);
        void increaseExp(int);
        void specialSkill();//specialSkill is heal in KnightPlayer
};



#endif /* KnightPlayer_h */
