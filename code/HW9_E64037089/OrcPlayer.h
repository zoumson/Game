//  Xcode compiler
//  OrcPlayer.h
//  game
//
//  Created by ZOUMA Adama on 4/30/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef OrcPlayer_h
#define OrcPlayer_h
#include "GeneralPlayer.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class OrcPlayer: public GeneralPlayer
{
    
  
public:
        OrcPlayer();
        OrcPlayer(int);
        OrcPlayer(int, string);
        OrcPlayer(const OrcPlayer&);
        void setLevel(int);
        void setAttr(int);
        void levelUp(void);
        void playerStats();//display player features, function overrided 
        void specialSkill();//specialSkill does nothing in OrcPlayer
};




#endif /* OrcPlayer_h */
