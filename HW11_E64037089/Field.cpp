//
//  Field.cpp
//  try
//
//  Created by ZOUMA Adama on 5/23/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//
#include"OrcPlayer.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
#include"GoblinMonster.h"
#include"ZombieMonster.h"
#include"JWMonster.h"
#include"GeneralPlayer.h"
#include"AbstractMonster.h"
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<fstream>
#include <iomanip>
#include<ctime>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include <string>
#include"Field.h"
#include"Battle.h"


bool Field::move(char move)
{
    if (move == 'w')
    {
        if (moveUp())
            return 1;
        else
            return 0;
    }
    else if (move == 'a')
    {
        if (moveLeft())
            return 1;
        else
            return 0;
    }
    else if (move == 's')
    {
        if (moveDown())
            return 1;
        else
            return 0;
    }
    else if (move == 'd')
    {
        if (moveRight())
            return 1;
        else
            return 0;
    }
    else return 0;
}
bool Field::moveUp(void)
{
    int x = currentPositionX, y = currentPositionY;
    y--;
    setPosition(x, y);
    if (currentPositionX != x || currentPositionY != y)
        return 1;
    else
        return 0;
}
bool Field::moveDown(void)
{
    int x = currentPositionX, y = currentPositionY;
    y++;
    setPosition(x, y);
    if (currentPositionX != x || currentPositionY != y)
        return 1;
    else
        return 0;
}
bool Field::moveLeft(void)
{
    int x = currentPositionX, y = currentPositionY;
    x--;
    setPosition(x, y);
    if (currentPositionX != x || currentPositionY != y)
        return 1;
    else
        return 0;
}
bool Field::moveRight(void)
{
    int x = currentPositionX, y = currentPositionY;
    x++;
    setPosition(x, y);
    if (currentPositionX != x || currentPositionY != y)
        return 1;
    else
        return 0;
}
int Field::getCurrentPositionX(void) const
{
    return currentPositionX;
}
int Field::getCurrentPositionY(void) const
{
    return currentPositionY;
}
int Field::getVisionWidth(void) const
{
    return visionWidth;
}
int Field::getVisionHeight(void) const
{
    return visionHeight;
}
string Field::getMapName(void) const
{
    return mapName;
}
int Field::getMapSymbol(int x, int y) const
{
    if (x >= 0 && y >= 0 && x < mapWidth && y < mapHeight)
    {
        return mapData[y][x];
    }
    else
        return -1;
}
Field::Field(int**map, int a, int b, int x, int y, int w, int h)
{

    mapWidth = a;
    mapHeight = b;
    setVisionSize(w, h);
    mapData = new int*[mapHeight];
    for (int i = 0; i < mapHeight; i++)
        mapData[i] = new int[mapWidth];
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
            mapData[i][j] = map[i][j];
    }
    setPosition(x, y);
}
Field::Field(const char* mapName, int x, int y, int w, int h)
{
    srand(time(0));
    setVisionSize(w, h);
    ifstream readFile(mapName, ios::in);
    string word;
    getline(readFile, word);
    istringstream mWidth(&word[0]);
    mWidth >> mapWidth;
    istringstream mHeight(&word[digital(mapWidth) + 1]);
    mHeight >> mapHeight;
    mapData = new int*[mapHeight];
    for (int i = 0; i < mapHeight; i++)
        mapData[i] = new int[mapWidth];
    for (int i = 0; i < mapHeight; i++)
    {
        getline(readFile, word);
        int k = 0;
        for (int j = 0; j < mapWidth; j++)
        {
            istringstream n(&word[k]);
            n >> mapData[i][j];
            k += digital(mapData[i][j]) + 1;
            if (mapData[i][j] == 0)
            {
                int m;
                m = rand() % 10;
                if (m == 0)
                    mapData[i][j] = 11;
                if (m == 1)
                    mapData[i][j] = 11;
                if (m == 2)
                    mapData[i][j] = 11;
                if (m == 3)
                    mapData[i][j] = 301;
                if (m == 4)
                    mapData[i][j] = 301;
            }
        }
    }
    setPosition(x, y);
}

void Field::setPosition(int x, int y)
{
    if (x >= 0 && y >= 0 && x < mapWidth && y < mapHeight && mapData[y][x] != 1)
    {
        currentPositionX = x;
        currentPositionY = y;
    }
}
void Field::setMapSymbol(int symbol, int x, int y)
{
    if (x >= 0 && y >= 0 && x <= mapWidth && y <= mapHeight)
    {
        mapData[y][x] = symbol;
    }
}
void Field::setVisionSize(int w, int h)
{
    if (w > 0 && h > 0 && w <= 30 && h <= 30)
    {
        visionWidth = w;
        visionHeight = h;
    }
    else
    {
        visionWidth = 15;
        visionHeight = 15;
    }
}



void Field::showVision(int visionOriginX, int visionOriginY)
{
    for (int i = 0; i < visionWidth; i++)
        cout << "==";
    cout << endl;
    cout << setw(2);
    for (int i = visionOriginY; i < visionOriginY + visionHeight; i++)
    {
        for (int j = visionOriginX; j < visionOriginX + visionWidth; j++)
        {
            if (i == currentPositionY&&j == currentPositionX)
            {
                cout << "*" << setw(2);
            }
            else if (getMapSymbol(j, i) == -1)
            {
                cout << "X" << setw(2);
            }
            else if (getMapSymbol(j, i) == 0)
            {
                cout << " " << setw(2);
            }
            else if (getMapSymbol(j, i) == 1)
            {
                cout << "°º" << setw(2);
            }
            else if (getMapSymbol(j, i) == 11)
            {
                cout << "M" << setw(2);
            }
            else if (getMapSymbol(j, i) == 10)
            {
                cout << "E" << setw(2);
            }
            else if (getMapSymbol(j, i) == 202 || getMapSymbol(j, i) == 203 || getMapSymbol(j, i) == 204)
            {
                cout << "D" << setw(2);
            }
            else if (getMapSymbol(j, i) == 100)
            {
                cout << "J" << setw(2);
            }
            else if (getMapSymbol(j, i) / 100 == 3)
            {
                cout << "B" << setw(2);
            }
            else
            {
                cout << " " << setw(2);
            }
        }
        cout << endl;
    }
    for (int i = 0; i < visionWidth; i++)
        cout << "==";
    cout << endl;
    cout << "DIALOG is shown as 'D'" << endl;
    cout << "MONSTER is shown as 'M'" << endl;
    cout << "END is shown as 'E'" << endl;
    cout << "BONUS is shown as 'B'" << endl;
    cout << "x position :" << currentPositionX << endl;
    cout << "y position :" << currentPositionY << endl;
    cout << "w : move up" << endl;
    cout << "a : move left" << endl;
    cout << "s : move down" << endl;
    cout << "d : move right" << endl;
    cout << "1 : Save game" << endl;
    cout << "2 : view backpack" << endl;
    cout << "3 : return to main menu" << endl;
}

char Field::display(void)
{
    system("cls");
    char word;
    int visionOriginX;
    int visionOriginY;
    visionOriginX = currentPositionX - 0.5*visionWidth ;
    visionOriginY = currentPositionY - 0.5*visionHeight ;
    showVision(visionOriginX, visionOriginY);
    int check = 0;
    while (check == 0)
    {
        cin >> word;
        if (word == 'w' || word == 'a' || word == 's' || word == 'd')
        {
            check = 1;
            move(word);
            return word;
        }
        else if (word == '1' || word == '2' || word == '3')
        {
            check = 1;
            return word;
        }
        else
        {
            check = 1;
            cout << "*****Wrong button !*****" << endl;
            
        }
    }
    
    return NULL;
}
int Field::digital(int number)
{
    if (number >= 0)
    {
        int x = 1, result = 0;
        do
        {
            x = x * 10;
            result++;
        } while (number / x >= 1);
        return result;
    }
    else
        return 0;
}
