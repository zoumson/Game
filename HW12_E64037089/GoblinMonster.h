//
//  GoblinMonster.h
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef GoblinMonster_h
#define GoblinMonster_h
#include "AbstractMonster.h"
#include <stdlib.h>

class GoblinMonster : public AbstractMonster
{
    public :
    
    GoblinMonster(string="goblin", int=60, int=40, int=12, int=100, int=50,int=20);
    ~GoblinMonster();
    void attackTo(GeneralPlayer*);
};

#endif /* GoblinMonster_h */
