// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <Windows.h>
using namespace std;
int While = 0;
int money = 0;


int enemyx = 13;
int enemyy = 3;
int enemyrowcheck;
int enemycolcheck;

bool check;
int bloop = 0;
int firstdir;
int moveorder[4];
bool validdir = false;
int lastposx;
int lastposy;


int Fvalue[4];
int Hvalue[4];
int Gvalue[4];

int n = sizeof(Fvalue) / sizeof(Fvalue[0]);

int lowestnum = 0;
int lowestnumcheck = 3000;
int dir;

string input = "";
int playerxcheck;
int playerycheck;
int playerx = 4;
int playery = 9;

int arr[10][20] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,1,0,0,0,0,0,4,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,8,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

};

void insertionsort(int blam[], int output[]) {
    for (int i = 1; i < n; ++i) {
        int key = blam[i];
        int j = i - 1;

        while (j >= 0 && blam[j] > key) {
            blam[j + 1] = blam[j];
            --j;
        }
        output[j + 1] = key;
        output[j + 2] = i;
    }
}

double distance(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
}

void setValues(int erow,int ecol, int j)
{
    Hvalue[j] = distance(erow, ecol, playery, playerx);
    Gvalue[j] = distance(erow, ecol, enemyy, enemyx);
    Fvalue[j] = Gvalue[j] + Hvalue[j];
}

bool isvalid(int row,int col)
{
    if (arr[row][col] != 1 && (col > 0 && col < 19) && (row > 0 && row < 9) && row != lastposy && col != lastposx)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printguy()
{
    system("color 0a");
    system("cls");
    cout << "player = 2, walls = 1, dudes = 4, mony = 8";
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << arr[i][j];
            Beep(rand(), 100);
        }

        
        cout << "\n";
    }
    cout << money << "\n";
}

void dead()
{
    system("cls");
    cout << "ur died \n" << "money == " << money;
    _getch();
    exit(0);
}


void enemymove(int enemyrow, int enemycol, int playerrow, int playercol)
{
    enemyrowcheck = enemyrow;
    enemycolcheck = enemycol;
    cout << "\n rowcolChecker" << enemyrow << enemycol;
    //this_thread::sleep_for(1s);
    arr[enemyy][enemyx] = 0;

    setValues(enemyrow + 1, enemycol, 0);
    setValues(enemyrow, enemycol + 1, 1);
    setValues(enemyrow - 1, enemycol, 2);
    setValues(enemyrow, enemycol - 1, 3);
   
    insertionsort(Fvalue, moveorder);
    cout << "\n ";
    for (int i = 0; i < 4; i++)
    {
        cout << Fvalue[i];
    }
    
    //this_thread::sleep_for(3s);
    int dist = distance(enemyrow, enemycol, playerrow, playercol);
    cout << "\n" << dist << "wow";
    
    for (int i = 0; i < 4; i++)
    {

        //cout << "\n lowestnumcheck & Fvalue[i]" << lowestnumcheck << "  " << Fvalue[i] << i;
        //cout << "\n lowestnum & Hvalue[i]" << lowestnum << "  " << Hvalue[i] << i;
        //this_thread::sleep_for(2s);
        //cout << "\n" << i << " " << Fvalue[i] << " " << Fvalue[lowestnum];
        if ((Fvalue[i] < Fvalue[lowestnum]) || (Fvalue[i] == lowestnumcheck && Hvalue[i] < Hvalue[lowestnum]))
        {
            //cout << "\n lowestnumcheck & Fvalue[i]" << lowestnumcheck << "  " << Fvalue[i] << i;
            cout << "\n if passed" << i;
            //this_thread::sleep_for(2s);
            switch (i)
            {
            case 0 :
                cout << "woooo0";
                lowestnumcheck = Fvalue[0];
                lowestnum = 0;
                dir = lowestnum;
                
                break;
            case 2:
                cout << "woooo2";
                lowestnumcheck = Fvalue[2];
                lowestnum = 2;
                dir = lowestnum;
                break;
            case 1:
                cout << "woooo1";
                lowestnumcheck = Fvalue[1];
                lowestnum = 1;
                dir = lowestnum;
                break;
            case 3:
                cout << "woooo3";
                lowestnumcheck = Fvalue[3];
                lowestnum = 3;
                dir = lowestnum;
                break;
            }
            
        }
        //0 isvalid(enemyrow + 1, enemycol)
        //1 isvalid(enemyrow, enemycol + 1)
        //2 isvalid(enemyrow - 1, enemycol)
        //3 isvalid(enemyrow, enemycol - 1)
    }

    cout << "\n ";
    for (int i = 0; i < 4; i++)
    {
        cout << moveorder[i];
    }
    
    //this_thread::sleep_for(5s);


    lastposx = enemyx;
    lastposy = enemyy;

    switch (dir) 
    {
    case 0:
        enemyy++;
        cout << "U";
        break;
    case 2:
        enemyy--;
        cout << "D";
        break;
    case 1:
        enemyx++;
        cout << "R";
        break;
    case 3:
        enemyx--;
        cout << "L";
        break;
    }

    system("color 4");
    arr[enemyy][enemyx] = 4;
    system("color 7");

    /*if (bloop == 1)
    {
        firstdir = dir;
        bloop++;
    }*/

    
    //this_thread::sleep_for(1s);
    for (int i = 0; i < 4; i++)
    {
        moveorder[i] = 0;
    }
    


    //this_thread::sleep_for(10s);
    //enemymove(enemyrowcheck, enemycolcheck, playery, playerx);
    
}




void inputfunc() 
{
    arr[playery][playerx] = 0;
    input = _getch();
    playerxcheck = playerx;
    playerycheck = playery;
    if (input == "w" && playery > 0)
    {
        playerycheck--;
    }
    else if (input == "s" && playery < 9)
    {
        playerycheck++;
    }
    else if (input == "a" && playerx > 0)
    {
        playerxcheck--;
    }
    else if (input == "d" && playerx < 19)
    {
        playerxcheck++;
    }
    else
    {
        //cout << "poopy";
    }

    if (arr[playerycheck][playerxcheck] != 1)
    {
        if (arr[playerycheck][playerxcheck] == 4)
        {
            dead();
        }
        else if (arr[playerycheck][playerxcheck] == 8)
        {
            money++;
        }

        playerx = playerxcheck;
        playery = playerycheck;
    }
    else
    {

    }
    arr[playery][playerx] = 2;
}

void Update()
{
    while (While < 1)
    {
        inputfunc();
        enemymove(enemyy, enemyx, playery, playerx);
        lowestnumcheck = 3000;
        validdir = false;
        //cout << "WOO)OOO";
        //this_thread::sleep_for(1s);
        printguy();
    }
}

int main()
 {
    printguy();
    Update();

 }




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
