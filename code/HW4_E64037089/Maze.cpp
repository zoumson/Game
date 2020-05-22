//Xcode compiler
//  Maze.cpp
//  today
//
//  Created by ZOUMA Adama on 4/12/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include "Maze.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include<cstdlib>




using namespace std;

void Maze::readPrintMaze ()


{
    string filename;
    cout << "Input filename :";
    cin >> filename;
    ifstream myFile;
    myFile.open(filename);//read input file
    stringstream convert;
    string word;
    
    
    int note = 0;
    getline(myFile, word, ',');//get maze column
    convert << word;
    convert >> col;
    word.clear();
    convert.clear();
    getline(myFile, word, '\n');//get maze row
    convert << word;
    convert >> row;
    word.clear();
    convert.clear();
    int** data = new int*[row];
    for(int i = 0; i < row; i++)
    { data[i] = new int[col];}
    
    int l = 0;
    
    
    
    while (myFile.good()){
        
        for (int j = 0; j < col-1; j++){//store maze map in data array
            getline(myFile, word, ',');
            convert << word;
            convert >> note;
            data[l][j] = note;
            word.clear();
            convert.clear();
            
        }
        getline(myFile, word, '\n');//storing the last column
        convert << word;
        convert >> note;
        
        data[l][col-1] = note;
        word.clear();
        convert.clear();
        l++;
        if(l == row){break;}//file reading stop right in the end of last row
        
    }
    
    myFile.close();
    
 
   
   for (int i = 0; i < row; i++)//Print maze
    {
        for (int j = 0; j < col; j++)
        { if(j==col-1)
            
        {
            if (data[i][j] > 201){cout <<BONUS <<endl;}
            else if (data[i][j] == 0){cout <<FREE <<endl;}
            else if (data[i][j] == 1){cout <<WALL <<endl;}
            
            else if (data[i][j] == 200){ cout <<START <<endl;startX = i; startY = j;}
            else if (data[i][j] == 201){ cout <<DESTINATION <<endl; endX = i; endY = j;}
        }
            
            
        else
        {
            if (data[i][j] > 201){cout <<BONUS ;}
            else if (data[i][j] == 0){cout <<FREE ;}
            else if (data[i][j] == 1){ cout <<WALL;}
            else if (data[i][j] == 200){ cout <<START;startX = i; startY = j;}
            else if (data[i][j] == 201){ cout <<DESTINATION;endX = i; endY = j;}
            
        }
            
        }
    }
 
    
    
   
}


     






