//Maze.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Maze.h"

using namespace std;

void Maze::printMaze()
//2D maze display
{
    
    int k = 0;
    while(k < row)
    {
        int j = 0;
        while (j < column)
        {
            cout << setw(3) << Map[k][j];
            j++;
        }
        
        cout <<"\n";
        k++;
    }
    
    cout <<"\n";
}

void Maze::setMap() {

    /* maze row and column */
    string word;
    stringstream convert;
	//file opened
	fstream myFile(filename, ios::in);

	if (!myFile) {
		cerr << "File could not be opened" << endl;
		system("pause");
		exit(1);
	}
	

	getline(myFile, word, ',');	//get maze column
	convert << word;
	convert >> column;
	word.clear();
	convert.clear();

	getline(myFile, word);	//get maze row
	convert << word;
	convert >> row;
	word.clear();
	convert.clear();

	//Maze data Processed
	while (getline(myFile, word))
    {	// read end of line
		stringstream tmpWord(word);
		string a;
		vector<int> tmpNum;

		while (getline(tmpWord, a, ','))
        {	//Read character separated by comma
            int tmp;
			stringstream tmpA(a);
			

			tmpA >> tmp;
			tmpNum.push_back(tmp);
		}
		Map.push_back(tmpNum);
	}//end of while
	word.clear();

	myFile.close();
}


Maze::Maze(const string &myFile)
{
    filename = myFile;
    setMap();
    
}


vector<vector<int> > Maze::getMap()
{
    return Map;
}

void Maze::mazePath()
{

	//Current position (x,y)
	int x, y;
    //right path
    vector<int> solution;
    
    //bonus
    int bonus = 0;


	//Initialization before right path finding
	vector<vector<int> > path(Map);
	for (int i = 0; i < row; i++)
    {	//Initial the path
		for (int j = 0; j < column; j++)
        {
			if (Map[i][j] != 1)
            {
				if (Map[i][j] == 200)
                {	// start point
					x = i;
					y = j;
					path[i][j] = -1;
				}
				else
                    {
					path[i][j] = 0;
                    }
				
			}
		}
	}

	

	//Start to find next movement one by one
	while (Map[x][y] != 201) //continue if not end of maze
    {

		
		cout <<"\nWow a new path is found\n\n";
         
		for (int i = 0; i < row; i++)
        {
			for (int j = 0; j < column; j++)
            {
				if (path[i][j] == -1)
                {
					cout << setw(2) << 'X';
				}
				else 
                {
					cout << setw(2) << path[i][j];
				}
			}
			cout << endl;
		}
		
		//west
		if (Map[x][y + 1] != 1) {
			if (path[x][y + 1] != -1) {
				path[x][y + 1] = -1;
				y = y + 1;
				solution.push_back(1);
				if (Map[x][y] > 201) {
					bonus++;
				}
				continue;
			}
		}

		//south
		if (Map[x + 1][y] != 1) {
			if (path[x + 1][y] != -1) {
				path[x + 1][y] = -1;
				x = x+ 1;
				solution.push_back(2);
				if (Map[x][y] > 201) {
					bonus++;
				}
				continue;
			}
		}

		//east
		if (Map[x][y - 1] != 1) {
			if (path[x][y - 1] != -1) {
				path[x][y - 1] = -1;
				y = y - 1;
				solution.push_back(3);
				if (Map[x][y] > 201) {
					bonus++;
				}
				continue;
			}
		}

		//north
		if (Map[x - 1][y] != 1) {
			if (path[x - 1][y] != -1) {
				path[x - 1][y] = -1;
				x = x - 1;
				solution.push_back(4);
				if (Map[x][y] > 201) {
					bonus++;
				}
				continue;
			}
			
		}

		//Not the right one, start over
		
                if(solution.back()==1)
                {
                    y = y - 1;
                    solution.pop_back();
                    
                }
		
                  if(solution.back()==2)
                  {
                      x = x - 1;
                      solution.pop_back();
                  }
			
                if(solution.back()==3)
                {
                    y = y + 1;
                    solution.pop_back();
                }
			
                if(solution.back()==3)
                {
                    x = x + 1;
                    solution.pop_back();
                    
                }
    }// end of while, end reached
			
//final path 

	cout << "\nPath from start to end found\n\n";
	for (int i = 0; i < row; i++)
    {
		for (int j = 0; j < column; j++)
        {
			if (path[i][j] == -1)
            {
				cout << setw(2) << 'X';//right path
			}
			else {
				cout << setw(2) << path[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;

	//bonus
	cout << "\n\tTotal bonus: " << bonus <<"\n\n";
}

    


