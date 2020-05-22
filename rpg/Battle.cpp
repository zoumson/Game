#include<iostream>
#include"Battle.h"
#include"AbstractMonster.h"
#include"GeneralPlayer.h"
#include<vector>
#include<typeinfo>
#include<ctime>
#include<cstdlib>
#include<iomanip>

//GeneralPlayer *tmp_player;
//Abstractmonster *tmp_monster;
using namespace std;

int turn_num = 1;
void Battle::printInfo(vector<GeneralPlayer*> p, vector<AbstractMonster*> m,vector<bool> alive,int nt)
{
    system("cls");
    cout << "turn number : " << turn_num << endl;
    cout << "player:" << endl;
    for (int i = 0; i < p.size(); i++)
    {
        if (nt == i)
        {
            cout << "->" << "player " << i + 1 << "  " << p[i]->getName() << setw(5) <<" HP: "<< p[i]->getHP() << " / " << p[i]->getMaxHP() << setw(5) << " MP: " << p[i]->getMP() << " / " << p[i]->getMaxMP() << endl;
        }
        else
            cout << "  " << "player " << i + 1 << "  " << p[i]->getName() << setw(5) << " HP: " << p[i]->getHP() << " / " << p[i]->getMaxHP() << setw(5) <<" MP: "<< p[i]->getMP() << " / " << p[i]->getMaxMP() << endl;
    }
    cout << "monster:" << endl;
    for (int i = 0; i < m.size(); i++)
    {
        if (nt - p.size() == i)
        {
            if (i == 1)
                turn_num++;
            cout << "->" << "monster " << i + 1 << "  " << m[i]->name << setw(5) << m[i]->getHP() << " / " << m[i]->getMaxHP() << endl;
        }
        else
            cout << "  " << "monster " << i + 1 << "  " << m[i]->name << setw(5) << m[i]->getHP() << " / " << m[i]->getMaxHP() << endl;
    }
}

Battle::Battle(vector<GeneralPlayer*> p, vector<AbstractMonster*> m, int nt)
{
    int win_or_not = 1;
    srand(time(NULL));
    int choose;
    int a;
    vector<bool> alive(p.size() + m.size());
    
    for (int i = 0; i < p.size() + m.size(); i++)//at the beginning all players and monsters are alive
    {
        alive[i] = 1;
    }
    do
    {
        for (int p_Turn = 0; p_Turn < p.size(); p_Turn++)
        {
            int temp_alive_m = 0;
            if (alive[p_Turn] == 1 && win_or_not == 1)
            {
                printInfo(p, m, alive, p_Turn);
                cout << "please enter 1 or 2" << endl;
                cout << "1 is normal attack , 2 is specialskill , 3 is flee , other choice are doing nothing !!" << endl;
                cin >> choose;
                
                if (choose == 1)
                {
                    printInfo(p, m, alive, p_Turn);
                    cout << "which monster do you want to attack?" << endl;
                    while (1)
                    {
                        cin >> a;
                        if (a <= 0 || a > m.size())
                        {
                            cout << " you can not choose the monster , please choose another one!!" << endl;
                            continue;
                        }
                        else if (alive[p.size() + a - 1] == 0)
                        {
                            cout << "the monster is already dead!!" << endl;
                            cout << "please choose another one!" << endl;
                            
                        }
                        else if (alive[p.size() + a - 1] == 1)
                        {
                            p[p_Turn]->attackTo(m[a - 1]);
                            if (m[a - 1]->getHP() <= 0)
                            {
                                alive[p.size() + a - 1] = 0;
                                printInfo(p, m, alive, p_Turn);
                                cout << "moster " << a << " is dead!" << endl;
                                system("pause");
                            }
                            for (int i = 0; i < m.size(); i++)
                            {
                                if (alive[i + p.size()] == 1)
                                    temp_alive_m++;
                            }
                            if (temp_alive_m == 0)
                            {
                                cout << "all monsters are dead!!" << endl;                   //©“¶≥©«™´¶∫•˙ ¿Ú≥”
                                cout << "you win!!" << endl;
                                win_or_not = 0;
                                break;
                            }
                            break;
                        }
                    }
                }
                else if (choose == 2)
                {
                    printInfo(p, m, alive, p_Turn);
                    p[p_Turn]->specialSkill();
                    system("pause");
                }
                else if (choose == 3)
                    win_or_not = 0;
            }
            else
                continue;
        }
        for (int m_Turn = p.size(); m_Turn < m.size()+p.size(); m_Turn++)
        {
            int temp_alive_p = 0;
            if (alive[m_Turn] == 1 && win_or_not == 1)                           //≥]©w©«™´ß¿ª±¯•Û
            {
                int rand_attack;
                printInfo(p, m, alive, m_Turn);
                while (1)
                {
                    rand_attack = (rand() % p.size());
                    if (alive[rand_attack] == 1 && win_or_not == 1)
                    {
                        m[m_Turn - p.size()]->attackTo(p[rand_attack]);
                        break;
                    }
                    else
                        continue;
                }
                if (p[rand_attack]->getHP() <= 0)
                {
                    alive[rand_attack] = 0;
                    printInfo(p, m, alive, m_Turn);
                    turn_num--;
                    cout << "player " << rand_attack + 1 << " is dead!";
                    system("pause");
                }
                for (int i = 0; i < p.size(); i++)
                {
                    if (alive[i] == 1)
                        temp_alive_p++;
                }
                if (temp_alive_p == 0)
                {
                    turn_num--;
                    cout << "you lose!!" << endl;
                    win_or_not = 0;
                    break;
                }
            }
        }
    } while (win_or_not);
}


