#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"Battle.h"
#include "GeneralPlayer.h"
#include "AbstractMonster.h"
using namespace std;









Battle::Battle(GeneralPlayer* gp[], AbstractMonster* ab[], int nPlyr, int nMon, int limTurn)
{
    deadPlayer = 0;
    deadMonster = 0;
    situation = 0;
    n_turn = 0;
    list_turn = 0;
    int i = 0;
    int j = 0;
    nP = nPlyr;
    nM = nMon;
    turn_limit = limTurn;
    ActionList = new Character[nPlyr + nMon];
    
     while (i < nPlyr) // all players fight first
    {
        GeneralPlayer *player;
        ActionList[i].instance = gp[i];
        player = static_cast<GeneralPlayer*>(ActionList[i].instance);
        ActionList[i].type = 'p';
        //player die once its HP is 0
        if (player->getHP()>0)
            ActionList[i].alive = 1;
        else
            ActionList[i].alive = 0;
        i++;
    }
    
   while ( j < nPlyr )//monster start fighting after  all players are done
    {
        AbstractMonster *monster;
        ActionList[j].instance = ab[j - nPlyr];
        monster = static_cast<AbstractMonster*>(ActionList[j].instance);
        ActionList[j].type = 'm';
        if (monster->getHP()>0)//player die once its HP is 0
            ActionList[j].alive = 1;
        else
            ActionList[j].alive = 0;
        j++;
    }
    
}
Battle::Battle(GeneralPlayer* gp[], AbstractMonster* ab[], int nPlyr, int nMon)
{
    deadPlayer = 0;
    deadMonster = 0;
    situation = 0;
    n_turn = 0;
    list_turn = 0;
    int i = 0;
    int j = 0;
    nP = nPlyr;
    nM = nMon;
    turn_limit = 99;
    ActionList = new Character[nPlyr + nMon];
    while (i < nPlyr) // all players fight first
    {
        GeneralPlayer *player;
        ActionList[i].instance = gp[i];
        player = static_cast<GeneralPlayer*>(ActionList[i].instance);
        ActionList[i].type = 'p';
        //player die once its HP is 0
        if (player->getHP()>0)
            ActionList[i].alive = 1;
        else
            ActionList[i].alive = 0;
        i++;
    }
    
    while ( j < nPlyr )//monster start fighting after  all players are done
    {
        AbstractMonster *monster;
        ActionList[j].instance = ab[j - nPlyr];
        monster = static_cast<AbstractMonster*>(ActionList[j].instance);
        ActionList[j].type = 'm';
        if (monster->getHP()>0)//player die once its HP is 0
            ActionList[j].alive = 1;
        else
            ActionList[j].alive = 0;
        j++;
    }
}
void Battle::Turn()
{
    srand(time(0));
    n_turn++;
    if (n_turn > turn_limit&&turn_limit != 0)
        cout << "Turn limit exceeded !" << endl;
    else
    {
        for (int nTurn = 0; nTurn < nP + nM; nTurn++)
        {
            GeneralPlayer *player;
            AbstractMonster *monster;
            if (ActionList[nTurn].type == 'p'&&ActionList[nTurn].alive == 1)
            {
                if (deadMonster == nM)
                {
                    situation = 1;
                    cout << "Players win !" << endl;
                    break;
                }//if monsters are all dead print "Players win !" and break the for loop
                else
                {
                    int m;
                    player = static_cast<GeneralPlayer*>(ActionList[nTurn].instance);
                    do
                    {
                        m = rand() % nM + nP;
                    } while (ActionList[m].alive == 0);//randomly choose a monster which is alive
                    monster = static_cast<AbstractMonster*>(ActionList[m].instance);
                    player->attackTo(monster);
                    cout << "------" << player->getName() << "  Attack  " << monster->name << "------" << endl;
                    displayData();
                    if (monster->getHP() == 0)
                    {
                        
                        cout << monster->name << " Dead !" << endl;
                        ActionList[m].alive = 0;
                        player->setExp(player->getExp() + monster->exp);
                        deadMonster++;
                    }
                }
            }
            else if (ActionList[nTurn].type == 'm'&&ActionList[nTurn].alive == 1)
            {
                if (deadPlayer == nP)
                {
                    situation = 2;
                    cout << "Monsters win !" << endl;
                    break;
                }//if players are all dead print "Monsters win !" and break the for loop
                else
                {
                    int p;
                    monster = static_cast<AbstractMonster*>(ActionList[nTurn].instance);
                    do
                    {
                        p = rand() % nP;
                    } while (ActionList[p].alive == 0);//randomly choose a player which is alive
                    player = static_cast<GeneralPlayer*>(ActionList[p].instance);
                    monster->attackTo(player);
                    cout << "-----" << monster->name << "  Attack  " << player->getName() << "---" << endl;
                    displayData();
                    if (player->getHP() <= 0)
                    {
                        cout << player->getName() << " Dead !" << endl;
                        ActionList[p].alive = 0;
                        deadPlayer++;
                    }
                }
            }
        }
        if (deadMonster == nM && situation == 0)
        {
            situation = 1;
            cout << "Players win !" << endl;
        }
        if (deadPlayer == nP && situation == 0)
        {
            situation = 2;
            cout << "Monsters win !" << endl;
        }
    }
}
void Battle::Move(int nTurn)
{
    GeneralPlayer *tmp_player;
    AbstractMonster *tmp_monster;
    if (ActionList[nTurn].type == 'p'&&ActionList[nTurn].alive == 1)
    {
        if (deadMonster == nM)
        {
            situation = 1;
            cout << "Players win !" << endl;
        }//if monsters are all dead print "Players win !" and break the for loop
        else
        {
            int m;
            tmp_player = static_cast<GeneralPlayer*>(ActionList[nTurn].instance);
            do
            {
                m = rand() % nM + nP;
            } while (ActionList[m].alive == 0);//randomly choose a monster which is alive
            tmp_monster = static_cast<AbstractMonster*>(ActionList[m].instance);
            tmp_player->attackTo(tmp_monster);
            cout << tmp_player->getName() << "  Attack  " << tmp_monster->name << endl;
            displayData();
            if (tmp_monster->getHP() <= 0)
            {
                cout << tmp_monster->name << " Dead !" << endl;
                ActionList[m].alive = 0;
                //tmp_player->setMoney(tmp_player->getMoney() + tmp_monster->money);
                tmp_player->setExp(tmp_player->getExp() + tmp_monster->exp);
                deadMonster++;
            }
        }
    }
    else if (ActionList[nTurn].type == 'm'&&ActionList[nTurn].alive == 1)
    {
        if (deadPlayer == nP)
        {
            situation = 2;
            cout << "Monsters win !" << endl;
        }//if players are all dead print "Monsters win !" and break the for loop
        else
        {
            int p;
            tmp_monster = static_cast<AbstractMonster*>(ActionList[nTurn].instance);
            do
            {
                p = rand() % nP;
            } while (ActionList[p].alive == 0);//randomly choose a player which is alive
            tmp_player = static_cast<GeneralPlayer*>(ActionList[p].instance);
            tmp_monster->attackTo(tmp_player);
            cout << tmp_monster->name << "  Attack  " << tmp_player->getName() << endl;
           displayData();
            if (tmp_player->getHP() <= 0)
            {
                cout << tmp_player->getName() << " Dead !" << endl;
                ActionList[p].alive = 0;
                deadPlayer++;
            }
        }
    }
    if (deadMonster == nM && situation == 0)
    {
        situation = 1;
        cout << "Players win !" << endl;
    }
    if (deadPlayer == nP && situation == 0)
    {
        situation = 2;
        cout << "Monsters win !" << endl;
    }
}
void Battle::battleTturn()
{
    int count = 1;
    if (turn_limit == 0)
    {
        do
        {
            n_turn = count;
            cout << "<<Turn " << count << ">>" << endl;
            Turn();
            count++;
        } while (situation == 0);
    }
    else
    {
        for (int i = 0; i < turn_limit; i++)
        {
            n_turn = count;
            cout << "<<Turn " << count << ">>" << endl;
            Turn();
            count++;
            if (situation != 0)
                break;
        }
    }
}
void Battle::displayData()
{
    cout << "Player : " << endl;
    cout << setw(5);
    cout << "Name" << setw(5) << "Level" << setw(5) << "HP" << setw(5) << "MP" << setw(5);
    cout <<"Money"<<setw(5)<<"Attack"<<setw(5)<<"Defense"<<setw(5)<<endl<< setw(5);
    for (int i = 0; i < nP; i++)
    {
        GeneralPlayer *player;
        player = static_cast<GeneralPlayer*>(ActionList[i].instance);
        cout << player->getName() << setw(5);
        cout << player->getLevel() << setw(5) << player->getHP() << "/" << player->getMaxHP() << setw(5);
        cout << player->getMP() << "/" << player->getMaxMP() << setw(5);
        cout <<player->getMoney()<<setw(5)<<player->getAttack()<<setw(5)<<player->getDefense()<<setw(5)<<endl;
    }
    cout << "Monster : " << endl;
    cout << setw(5);
    cout << "Name" << setw(5) << "HP" << setw(5) << "MP" << setw(5) ;
    cout <<"Attack"<<setw(5)<<"Defense"<<setw(5)<<endl<< setw(5);

    for (int i = nP; i < nP + nM; i++)
    {
        AbstractMonster *monster;
        monster = static_cast<AbstractMonster*>(ActionList[i].instance);
        cout << monster->name << setw(5);
        cout << monster->getHP() << "/" << monster->max_hp << setw(5);
        cout << monster->getMP() << "/" << monster->max_mp << setw(5) << endl;
        cout <<monster->attack<<setw(5)<<monster->defense<<setw(5)<<endl;
    }
    cout << endl;
}


bool Battle::nextActor(char choose)
{
    
    
  
   
        if(choose =='1')
    {
        if (n_turn < turn_limit)
        {
            if (ActionList[list_turn].alive == 1)
                Move(list_turn);
            else
                cout << "Character dead !" << endl;
            list_turn++;
            if (list_turn >= nP + nM)
            {
                list_turn = 0;
                n_turn++;
            }
            return 1;
        }
        else
        {
            cout << "Turn Limit exceeded !" << endl;
            return 0;
        }
    }
    
            
        else
            
    {
        
        if (n_turn < turn_limit)
        {
            
            int choose;
            if (ActionList[list_turn].alive == 1)
            {
                cout << "Choose a consumable item to use !" << endl;
                cin >> choose;
            
            }
            else
                cout << "Character dead !" << endl;
            list_turn++;
            if (list_turn >= nP + nM)
            {
                list_turn = 0;
                n_turn++;
            }
            return 1;
        }
        else 
        {
            cout << "Turn limit exceeded!" << endl;
            return 0;
        }
    }
 
}


int Battle::getListTurn()
{
    return list_turn;
    
}
int Battle::getsituation(void)
{
    return situation;
}
int Battle::getTurnCount(void) const
{
    return n_turn + 1;
}
int Battle::getTurnLimit(void) const
{
    return turn_limit;
}
int Battle::getPlayerCount(void) const
{
    return nP;
}
int Battle::getPlayerCount(bool x) const
{
    if (x == 0)
        return deadPlayer;
    else
        return nP - deadPlayer;
}
int Battle::getMonsterCount(void) const
{
    return nM;
}
int Battle::getMonsterCount(bool x) const
{
    if (x == 0)
        return deadMonster;
    else
        return nM - deadMonster;
}




