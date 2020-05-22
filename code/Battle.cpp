//
//  Battle.cpp
//  try
//
//  Created by ZOUMA Adama on 5/15/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include "Battle.h"




Battle::Battle(int nPlyr, int nMon)

{
   // initialize players type
    MagicianPlayer p1;
    p1.setHP(130);
    p1.setMP(50);
    p1.setLevel(2);
    KnightPlayer p2;
    p2.setHP(130);
    p2.setMP(50);
    p2.setLevel(2);
    OrcPlayer p3;
    p3.setHP(130);
    p3.setMP(50);
    p3.setLevel(2);
    
   //all 3 players belong to general player
    GeneralPlayer *player [3] = {&p1, &p2, &p3};
    
    // initialize monsters type
    ZombieMonster m1("n", 2, 3, 3, 3, 5);
    JWMonster m2("n", 2, 3, 3, 3, 5);
    GoblinMonster m3("n", 2, 3, 3, 3, 5);
    
    //all 3 monsters belong to abstract monster
     AbstractMonster *monster [3] = {&m1, &m2, &m3};
    
    int* selPlayer = new int[nPlyr];//hold the index of player to be selected
    int* selMonster = new int[nMon];//hold the index of monster to be selected
   
    //randomly pick a player
    for( int i = 0; i < nPlyr; i++)
    {
       selPlayer[i] = rand()%3;
    }
    
    //randomly pick a monster
    for( int i = 0; i < nMon; i++)
    {
        selMonster[i] = rand()%3;
    }
    
    
    
    //tournament start here
    for(int i = 0; i < nPlyr; i++)
    {
        int j = 0;
        bool a = false;
        bool b = false;
        cout <<"Player "<<i+1<< ": "<<player[selPlayer[i]]->getName()<<endl<<"Enemies: "<<endl;
        
        
            do
            {
                cout <<"Enemy "<<j+1<<" : "<<monster[selMonster[j]]->name<<endl;
                for (int k = 0; k < 10; k++)
                {player[selPlayer[i]]->attackTo(monster[selMonster[j]]);}//player fight first, then monster reply
                
            monster[selMonster[j]]->attackTo(player[selPlayer[i]]);
               
                if (!player[selPlayer[i]]->canAttack(monster[selMonster[j]]))//player died
                    {
                        cout<<"Enemy "<< j+1<<" killed Player "<<i+1<<endl<<endl;
                         b = true;
                    }
                    if(!monster[selMonster[j]]->canAttack(player[selPlayer[i]]))//monster died
                    {
                         
                         a = true;
                        
                        cout <<"Player "<<i+1<<" killed Monster "<<j+1<<endl;
                        
                    }
                
                j++;
            }
                    
            while (j < nMon && !(a || b));
        
        
        
        
       
        if (a && (!b))//player win
        {
                        cout<<"Player "<<i+1<<" wins"<<endl<<endl;
        }
         else if ((!a) && b)
            
        {
            cout<<"Game over: Player "<<i+1<<" loses" <<endl<<endl;//player loses
        }
    }
    
   
    }



