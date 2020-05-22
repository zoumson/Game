#ifndef BATTLE_H
#define BATTLE_H
#include<iostream>
#include "GeneralPlayer.h"
#include "AbstractMonster.h"
using namespace std;
struct Character
{
    char type; // monster or player?
    bool alive; // alive or dead?
    void *instance; // pointer to instance
};
class Battle
{
public:
    
    Character* getPlayers(void)
    {
        Character* PlayerList = new Character[nP];
        for (int i = 0; i < nP; i++)
        {
            PlayerList[i].type = 'p';
            PlayerList[i].alive = ActionList[i].alive;
            PlayerList[i].instance = ActionList[i].instance;
        }
        return PlayerList;
    }
    Character* getMonsters(void)
    {
        Character* MonsterList = new Character[nP];
        for (int i = nP; i < nM; i++)
        {
            MonsterList[i].type = 'm';
            MonsterList[i].alive = ActionList[i].alive;
            MonsterList[i].instance = ActionList[i].instance;
        }
        return MonsterList;
    }
    
    Character getCurrentActor(void)
    {
        Character CarTer;
        CarTer.type = ActionList[list_turn].type;
        CarTer.alive = ActionList[list_turn].alive;
        CarTer.instance = ActionList[list_turn].instance;
        return CarTer;
    }
    Battle(GeneralPlayer**, AbstractMonster**, int, int, int);//constructor
    Battle(GeneralPlayer**, AbstractMonster**, int, int);
    void Turn();//Turn of battle
    void Move(int);// Move in battle
    void battleTturn();//Turn one after another until one of player or monster win
    void displayData();//display data
    bool nextActor(char);//
    int getListTurn(void);
    int getsituation(void);
    int getTurnCount(void) const;
    int getTurnLimit(void) const;
    int getPlayerCount(void) const;
    int getPlayerCount(bool x) const;
    int getMonsterCount(void) const;
    int getMonsterCount(bool x) const;

    
private:
    Character * ActionList;
    /*
     "0"  start of battle
     "1"  players win
     "2"  monsters win
     */
    int situation;
    int nP;//number of player
    int nM;//number of monster
    int deadPlayer;//number of dead player
    int deadMonster;//number of dead monster
    int turn_limit;//limit of turn
    int n_turn;//actual turn
    int list_turn;//actual turn list
};


#endif

