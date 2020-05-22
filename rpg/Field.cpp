//
//  Field.cpp
//  try
//
//  Created by ZOUMA Adama on 5/23/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>
#include"Field.h"
#include"Battle.h"
#include"AbstractMonster.h"
#include"GeneralPlayer.h"
#include"GoblinMonster.h"
#include"JWMonster.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
#include"OrcPlayer.h"
#include"ZombieMonster.h"
#include"Game.h"

using namespace std;


Field::Field(const string n_maze, int x, int y, int w, int h)
{
    
    string str;
    int c = 0;
    
    ifstream insert(n_maze);
    insert >> words[0][0];
    insert.get();
    insert >> words[0][1];
    
    map_data = new int *[words[0][0]];                                            //∞ ∫AARRAY
    
    for (int i = 0; i<words[0][0]; i++)
    {
        map_data[i] = new int[words[0][0]];
    }
    while (getline(insert, str)) {                                              //≈™¿…
        for (int j = 0; j < words[0][0]; j++) {
            insert >> map_data[c][j];
            if (j != words[0][0] - 1)
                insert.get();
        }
        c++;
    }
    vision_width=w;
    vision_height=h;
    setPosition(x, y);
    generateMonster();
}

Field::~Field()
{
    delete [] map_data;
}
bool Field::move(char m)
{
    if (m == 'w')
    {
        d = 'w';
        temp = map_data[getCurrentPositionY()-1][getCurrentPositionX()];                //©π§W≤æ∞
        moveUp();
    }
    if (m == 's')
    {
        d = 's';
        temp = map_data[getCurrentPositionY()+1][getCurrentPositionX()];                //©π§U≤æ∞
        moveDown();
    }
    if (m == 'a')
    {
        d = 'a';
        temp = map_data[getCurrentPositionY()][getCurrentPositionX()-1];                //©π•™≤æ∞
        moveLeft();
    }
    if (m == 'd')
    {
        d = 'd';
        temp = map_data[getCurrentPositionY()][getCurrentPositionX()+1];                //©π•k≤æ∞
        moveRight();
    }
    else
    { }
    map_data[getCurrentPositionY()][getCurrentPositionX()] = 2;                        //•N™Ì™±Æa¶Ï∏m
    return true;
    
}
bool Field::moveUp(void)
{
    if (map_data[getCurrentPositionY() - 1][getCurrentPositionX()] == 1)
    {
        return false;
    }
    else if (map_data[getCurrentPositionY() - 1][getCurrentPositionX()] == 201 && door_key != 1)                //®ÏπF•ÿ™∫¶a(∂«∞e¬I) •i¨O®S∆_∞Õ
    {
        cout << "ßA®S¶≥∆_∞Õ!!!!" << endl;
        system("pause");
        return false;
    }
    else if (map_data[getCurrentPositionY() - 1][getCurrentPositionX()] == 201 && door_key == 1 )                //®ÏπF•ÿ™∫¶a(∂«∞e¬I)
    {
        cout << "•Œ∆_∞Õ∂}§F™˘°A∂i®Ï§U§@±i¶aπœ!!" << endl;
        Game::map_count = 2;
        system("pause");
        return true;
    }
    else
    {
        current_position_y--;
        map_data[getCurrentPositionY() + 1][getCurrentPositionX()] = temp;
        return true;
    }
}

bool Field::moveDown(void)
{
    if (map_data[getCurrentPositionY()+1][getCurrentPositionX()] == 1)
    {
        return false;
    }
    
    else if (map_data[getCurrentPositionY() + 1][getCurrentPositionX()] == 201 && door_key != 3)                //®ÏπF•ÿ™∫¶a(∂«∞e¬I) ≥”ßQ¬I •i¨O®S∆_∞Õ
    {
        cout << "ßA®S¶≥∆_∞Õ!!!!" << endl;
        system("pause");
    }
    else if (map_data[getCurrentPositionY() + 1][getCurrentPositionX()] == 201 && door_key == 3)               //®ÏπF•ÿ™∫¶a(∂«∞e¬I)   ≥”ßQ¬I
    {
        cout << "ßA®˙±o§F§T¡˚ƒ_•€ °A ¶]¶πßA¶®•\¨@±œ§F≥o≠”∞ÍÆa!!!!!" << endl;
        cout << "±q¶π§ß´·°A≥o≠”∞ÍÆa¶A§]®S•X≤{≥s¶~ßÚ®a™∫™¨™p§F!!" << endl;
        system("pause");
        exit(1);
        return true;
    }
    else
    {
        current_position_y++;
        map_data[getCurrentPositionY()-1][getCurrentPositionX()] = temp;
    }
    return true;
}
bool Field::moveLeft(void)
{
    if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 1)
    {
        return false;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 201 && door_key != 2)               //®ÏπF•ÿ™∫¶a(∂«∞e¬I) •i¨O®S∆_∞Õ
    {
        cout << "ßA®S¶≥∆_∞Õ!!!!!!" << endl;
        cout << door_key;
        system("pause");
        return false;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 201 && door_key == 2)               //®ÏπF•ÿ™∫¶a(∂«∞e¬I)
    {
        cout << "•Œ∆_∞Õ∂}§F™˘°A∂i®Ï§U§@±i¶aπœ!!" << endl;
        Game::map_count = 3;
        system("pause");
        return true;
    }
    else
    {
        current_position_x--;
        map_data[getCurrentPositionY()][getCurrentPositionX() + 1] = temp;
        return true;
    }
}
bool Field::moveRight(void)
{
    if (map_data[getCurrentPositionY()][getCurrentPositionX()+1] == 1)
    {
        return false;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX()+1] == 201 && door_key != 3)                        //®ÏπF•ÿ™∫¶a(∂«∞e¬I) ≥”ßQ¬I •i¨O®S¶≥∆_∞Õ
    {
        cout << "ßA®S¶≥∆_∞Õ!!!!!!" << endl;
        system("pause");
        return true;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() + 1] == 201 && door_key == 3)                        //®ÏπF•ÿ™∫¶a(∂«∞e¬I) ≥”ßQ¬I
    {
        cout << "ßA®˙±o§F§T¡˚ƒ_•€ °A ¶]¶πßA¶®•\¨@±œ§F≥o≠”∞ÍÆa!!!!!" << endl;
        cout << "±q¶π§ß´·°A≥o≠”∞ÍÆa¶A§]®S•X≤{≥s¶~ßÚ®a™∫™¨™p§F!!" << endl;
        system("pause");
        exit(1);
        return true;
    }
    else
    {
        current_position_x++;
        map_data[getCurrentPositionY()][getCurrentPositionX()-1 ] = temp;
        return true;
    }
}
int Field::getCurrentPositionX(void) const
{
    return current_position_x;
}
int Field::getCurrentPositionY(void) const
{
    return current_position_y;
}
int Field::getVisionWidth(void) const
{
    return vision_width;
}
int Field::getVisionHeight(void) const
{
    return vision_height;
}
string Field::getMapName(void) const
{
    return map_name;
}
int Field::getMapSymbol(int x, int y)
{
    int a;
    a = map_data[x][y];
    if (a == 1)
        cout << "°Ω";                                                    //≈„•‹πœÆ◊
    if (a == 0)
        cout << "  ";
    if (a == 200)
        cout << "ST";
    if (a == 201)
        cout << "DE";
    if (a == 2 )
        cout << "PP";
    return a;
}
void Field::setPosition(int x, int y)
{
    current_position_x = x;
    current_position_y = y;
}
void Field::setMapSymbol(int s , int x, int y)
{
    if(s==1)
        cout << "°Ω";
    if(s==0)
        cout << "  ";
    if (s == 200)
        cout << "ST";
    if (s == 201)
        cout << "DE";
    if (s == 2)
        cout << "PP";
    if (s == 202)
        cout << "§È";
    if (s == 203)
        cout << "§Î";
    if (s == 204)
        cout << "¨P";
    
    
}
void Field::setVisionSize(int x, int y)
{
    int v_s;
    v_s = x*y;
}
void Field::display(void)
{
    system("cls");
    //for (int i = 0; i <words[0][1]; i++) {
    //    for (int j =0; j < words[0][0]; j++) {
    //        if (i >= 0 && j >= 0)
    //        {
    //            if (map_data[i][j] == 1)
    //                cout << "°Ω";                                                    //≈„•‹πœÆ◊
    //            if (map_data[i][j] == 0)
    //                cout << "  ";
    //            if (map_data[i][j] == 200)
    //                cout << "ST";
    //            if (map_data[i][j] == 201)
    //                cout << "™˘";
    //            if (map_data[i][j] == 2)
    //                cout << "PP";
    //            if (map_data[i][j] == 87)
    //                cout << "MM";
    //            if (map_data[i][j] == 202)
    //                cout << "§È";
    //            if (map_data[i][j] == 203)
    //                cout << "§Î";
    //            if (map_data[i][j] == 204)
    //                cout << "¨P";
    //            if (map_data[i][j] == 205)
    //                cout << "¨P";
    //        }
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    
    for (int i = current_position_y-3; i <current_position_y+getVisionHeight(); i++) {
        for (int j = current_position_x-3; j < current_position_x+getVisionWidth(); j++) {
            if ((i >= 0 && j >= 0) && (i< words[0][1] && j< words[0][0]))
            {
                
                if (map_data[i][j] == 1)
                    cout << "°Ω";                                                    //≈„•‹πœÆ◊(§p¶aπœ)
                if (map_data[i][j] == 0)
                    cout << "  ";
                if (map_data[i][j] == 200)
                    cout << "ST";
                if (map_data[i][j] == 201)
                    cout << "™˘";
                if (map_data[i][j] == 2)
                    cout << "PP";
                if (map_data[i][j] == 87)
                    cout << "MM";
                if (map_data[i][j] == 202)
                    cout << "§È";
                if (map_data[i][j] == 203)
                    cout << "§Î";
                if (map_data[i][j] == 204)
                    cout << "¨P";
                if (map_data[i][j] == 205)
                    cout << "¨P";
            }
        }
        cout << endl;
    }
    cout <<"\n"<< "you are now at( " << current_position_x << " , " << current_position_y << " )" << endl;
}

void Field::generateMonster()
{
    srand((unsigned)time(NULL));
    int m;
    for (int i = 0; i < words[0][1]; i++)                                               //≤£•Õ©«™´
    {
        for (int j = 0; j < words[0][0]; j++)
        {
            if (map_data[i][j] == 0)
            {
                m = rand() % 15;
                if (m == 0)
                {
                    map_data[i][j] = 87;
                }
            }
        }
    }
}

bool Field::take_a_fight()
{
    if (map_data[getCurrentPositionY() + 1][getCurrentPositionX()] == 202 && d=='w')
    {
        map_data[getCurrentPositionY() + 1][getCurrentPositionX()] = 0;                      //±o®Ï§È§ß•€
        cout << "ßA±o®Ï§F§È§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§È§È§È§È§È§È§È§È§È§È" << endl;
        cout << "        §È          " << endl;
        cout << "      §È            " << endl;
        cout << "    §È              " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        door_key = 1;
        system("pause");
        return true;
    }
    if (map_data[getCurrentPositionY() + 1][getCurrentPositionX()] == 203 && d == 'w')
    {
        map_data[getCurrentPositionY() + 1][getCurrentPositionX()] = 0;                      //±o®Ï§Î§ß•€
        cout << "ßA±o®Ï§F§Î§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§Î§Î§Î§Î§Î§Î§Î§Î§Î§Î" << endl;
        cout << "        §Î          " << endl;
        cout << "      §Î            " << endl;
        cout << "    §Î              " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        system("pause");
        return true;
    }
    if (map_data[getCurrentPositionY() + 1][getCurrentPositionX()] == 204)
    {
        map_data[getCurrentPositionY() + 1][getCurrentPositionX()] = 0;                      //±o®Ï¨P§ß•€
        cout << "ßA±o®Ï§F¨P§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "¨P¨P¨P¨P¨P¨P¨P¨P¨P¨P" << endl;
        cout << "        ¨P          " << endl;
        cout << "      ¨P            " << endl;
        cout << "    ¨P              " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        system("pause");
        return true;
    }
    if (map_data[getCurrentPositionY()+1][getCurrentPositionX() ] == 87 && d=='w')
    {
        map_data[getCurrentPositionY()+1][getCurrentPositionX()] = 0;
        return true;
    }
    if (map_data[getCurrentPositionY() - 1][getCurrentPositionX()] == 202 && d == 's')
    {
        map_data[getCurrentPositionY() - 1][getCurrentPositionX()] = 0;                      //±o®Ï§È§ß•€
        cout << "ßA±o®Ï§F§È§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§È§È§È§È§È§È§È§È§È§È" << endl;
        cout << "        §È          " << endl;
        cout << "      §È            " << endl;
        cout << "    §È              " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        door_key = 1;
        system("pause");
        return true;
    }
    else if (map_data[getCurrentPositionY() - 1][getCurrentPositionX()] == 203 && d == 's')
    {
        map_data[getCurrentPositionY() - 1][getCurrentPositionX()] = 0;                      //±o®Ï§Î§ß•€
        cout << "ßA±o®Ï§F§Î§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§Î§Î§Î§Î§Î§Î§Î§Î§Î§Î" << endl;
        cout << "        §Î          " << endl;
        cout << "      §Î            " << endl;
        cout << "    §Î              " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        door_key = 2;
        system("pause");
        
        return true;
    }
    else if (map_data[getCurrentPositionY() - 1][getCurrentPositionX()] == 204 && d == 's')
    {
        map_data[getCurrentPositionY() - 1][getCurrentPositionX()] = 0;                      //±o®Ï¨P§ß•€
        cout << "ßA±o®Ï§F¨P§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "¨P¨P¨P¨P¨P¨P¨P¨P¨P¨P" << endl;
        cout << "        ¨P          " << endl;
        cout << "      ¨P            " << endl;
        cout << "    ¨P              " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        system("pause");
        return true;
    }
    if (map_data[getCurrentPositionY()-1][getCurrentPositionX()] == 87 && d=='s')
    {
        map_data[getCurrentPositionY()-1][getCurrentPositionX()] = 0;
        return true;
    }
    if (map_data[getCurrentPositionY()][getCurrentPositionX() + 1] == 202 && d == 'a')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() + 1] = 0;                      //±o®Ï§È§ß•€
        cout << "ßA±o®Ï§F§È§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§È§È§È§È§È§È§È§È§È§È" << endl;
        cout << "        §È          " << endl;
        cout << "      §È            " << endl;
        cout << "    §È              " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        system("pause");
        door_key = 1;
        return true;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() + 1] == 203 && d == 'a')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() + 1] = 0;                      //±o®Ï§Î§ß•€
        cout << "ßA±o®Ï§F§Î§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§Î§Î§Î§Î§Î§Î§Î§Î§Î§Î" << endl;
        cout << "        §Î          " << endl;
        cout << "      §Î            " << endl;
        cout << "    §Î              " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        system("pause");
        door_key = 2;
        return true;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() + 1] == 204 && d == 'a')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() + 1] = 0;                      //±o®Ï¨P§ß•€
        cout << "ßA±o®Ï§F¨P§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "¨P¨P¨P¨P¨P¨P¨P¨P¨P¨P" << endl;
        cout << "        ¨P          " << endl;
        cout << "      ¨P            " << endl;
        cout << "    ¨P              " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        system("pause");
        return true;
    }
    if (map_data[getCurrentPositionY()][getCurrentPositionX() + 1] == 87&& d=='a')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() + 1] = 0;
        return true;
    }
    if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 202 && d == 'd')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() - 1] = 0;                      //±o®Ï§È§ß•€
        cout << "ßA±o®Ï§F§È§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§È§È§È§È§È§È§È§È§È§È" << endl;
        cout << "        §È          " << endl;
        cout << "      §È            " << endl;
        cout << "    §È              " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È              §È " << endl;
        cout << " §È§È§È§È§È§È§È§È§È " << endl;
        system("pause");
        door_key = 1;
        return true;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 203 && d == 'd')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() - 1] = 0;                      //±o®Ï§Î§ß•€
        cout << "ßA±o®Ï§F§Î§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "§Î§Î§Î§Î§Î§Î§Î§Î§Î§Î" << endl;
        cout << "        §Î          " << endl;
        cout << "      §Î            " << endl;
        cout << "    §Î              " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î              §Î " << endl;
        cout << " §Î§Î§Î§Î§Î§Î§Î§Î§Î " << endl;
        system("pause");
        door_key = 2;
        return true;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 204 && d == 'd')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() - 1] = 0;                      //±o®Ï¨P§ß•€
        cout << "ßA±o®Ï§F¨P§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "¨P¨P¨P¨P¨P¨P¨P¨P¨P¨P" << endl;
        cout << "        ¨P          " << endl;
        cout << "      ¨P            " << endl;
        cout << "    ¨P              " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P              ¨P " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        door_key = 3;
        system("pause");
        return true;
    }
    else if (map_data[getCurrentPositionY()][getCurrentPositionX() - 1] == 205 && d == 'd')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() - 1] = 0;                      //±o®Ï∞≤™∫¨P§ß•€
        cout << "ßA±o®Ï§F¨P§ß•€!!!!! " << endl;
        cout << "                    " << endl;
        cout << "¨P¨P¨P¨P¨P¨P¨P¨P¨P¨P" << endl;
        cout << "        ¨P          " << endl;
        cout << "      ¨P            " << endl;
        cout << "    ¨P              " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        cout << " ¨P      ¨P      ¨P " << endl;
        cout << " ¨P    ¨P¨P¨P    ¨P " << endl;
        cout << " ¨P      ¨P      ¨P " << endl;
        cout << " ¨P¨P¨P¨P¨P¨P¨P¨P¨P " << endl;
        system("pause");
        cout << "•i¨O¶nπ≥¨O∞≤™∫!? §W≠±¶≥∏H≤™¶b!!" << endl;
        cout << "¨›®”¡Ÿ¶≥Øu™∫¨P§ß•€¬√¶b¨Y≥B©O!!!" << endl;
        system("pause");
        return true;
    }
    if (map_data[getCurrentPositionY()][getCurrentPositionX()-1] == 87 && d=='d')
    {
        map_data[getCurrentPositionY()][getCurrentPositionX() - 1] = 0;
        return true;
    }
    else
        return false;
}

