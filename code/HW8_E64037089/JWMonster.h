//
//  JWMonster.h
//  game
//
//  Created by ZOUMA Adama on 5/3/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef JWMonster_h
#define JWMonster_h
#include "AbstractMonster.h"




class JWMonster:public  AbstractMonster

{
public :


JWMonster(string n, int a, int d , int e, int h, int m);
~JWMonster();
    void attackTo(GeneralPlayer*);
    void monsterStats();
};

#endif /* JWMonster_h */
