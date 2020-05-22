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
    
    GoblinMonster(string n, int a, int d , int e, int h, int m);
    ~GoblinMonster();
    void attackTo(GeneralPlayer*);
    void monsterStats();
   

};

#endif /* GoblinMonster_h */
