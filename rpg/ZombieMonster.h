//
//  ZombieMonster.h
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef ZombieMonster_h
#define ZombieMonster_h
#include "AbstractMonster.h"






class  ZombieMonster : public  AbstractMonster
{
    public :
   ZombieMonster(string="zombie", int=50, int=65, int=17, int=150, int=30,int=30);
    ~ZombieMonster();
    void attackTo(GeneralPlayer*);
    
    
};


#endif /* ZombieMonster_h */
