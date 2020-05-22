#ifndef BATTLE_H
#define BATTLE_H
#include<iostream>
#include "GeneralPlayer.h"
#include "AbstractMonster.h"
#include<vector>
using namespace std;

#include<vector>
struct Character {
    char type;
    bool alive;
    void *instance;
};


class Battle
{
private:
    Character *ActionList;
    int n_turn;
    int turn_limit;
    int nPlyr;
    int nMon;
public:
    Battle(vector<GeneralPlayer*>, vector<AbstractMonster*>,  int);
    
    
    void printInfo(vector<GeneralPlayer*> , vector<AbstractMonster*> , vector<bool>, int );
    
};



#endif

