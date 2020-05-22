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
    ZombieMonster(string n, int a, int d , int e, int h, int m);
    
    
    
    ~ZombieMonster();
    void attackTo(GeneralPlayer*);
    void monsterStats();
    
};


#endif /* ZombieMonster_h */
