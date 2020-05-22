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


JWMonster(string="jwww", int=120, int=100, int=42, int= 250, int= 100,int=50);
~JWMonster();
    void attackTo(GeneralPlayer*);
    
};

#endif /* JWMonster_h */
