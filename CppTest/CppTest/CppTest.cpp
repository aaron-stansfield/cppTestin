// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <cmath>
using namespace std;

int While = 0;
int money = 0;


int enemyx = 13;
int enemyy = 3;
int enemyxcheck;
int enemyycheck;

int Fvalue[4];
int lowestnum = 0;
int lowestnumcheck;

string input = "";
int playerxcheck;
int playerycheck;
int playerx = 0;
int playery = 0;

int arr[10][20] =
{
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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


double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool isvalid(int row,int col)
{
    if (arr[row][col] != 1 && col >= 0 && col <= 19 && row >= 0 && row <= 9)
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
    system("cls");
    cout << "player = 2, walls = 1, dudes = 4, mony = 8";
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << arr[i][j];
            this_thread::sleep_for(100ns);
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
    while (found = false)
    {
        int dist = distance(playerx, playery, enemyrow, enemycol);
        cout << dist;
        //if (something)
        /* {
            if (path[0] == 'U')
            {
                enemyycheck++;
                cout << "U";
            }
            else if (path[0] == 'D')
            {
                cout << "D";
                enemyycheck--;
            }

            if (path[0] == 'R')
            {
                enemyxcheck++;
                cout << "R";
            }
            else if (path[0] == 'L')
            {
                enemyxcheck--;
                cout << "L";
            }

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    patharr[i][j] = arr[i][j];
                }
            }
            return;
        }*/

        int upnodeH = distance(enemyrow + 1, enemycol, playerrow, playercol);
        int upnodeG = distance(enemyrow + 1, enemycol, enemyrow, enemycol);
        Fvalue[0] = upnodeG + upnodeH;

        int rightnodeH = distance(enemyrow, enemycol + 1, playerrow, playercol);
        int rightnodeG = distance(enemyrow, enemycol + 1, enemyrow, enemycol);
        Fvalue[1] = rightnodeG + rightnodeH;

        int downnodeH = distance(enemyrow - 1, enemycol, playerrow, playercol);
        int downnodeG = distance(enemyrow - 1, enemycol, enemyrow, enemycol);
        Fvalue[2] = downnodeG + downnodeH;

        int leftnodeH = distance(enemyrow, enemycol - 1, playerrow, playercol);
        int leftnodeG = distance(enemyrow, enemycol - 1, enemyrow, enemycol);
        Fvalue[3] = leftnodeG + leftnodeH;

        for (int i = 0; i < 3; i++)
        {
            if (lowestnumcheck > Fvalue[i])
            {
                lowestnumcheck = Fvalue[i];
                lowestnum = i;
            }
            int big = lowestnum;
        }

        for (int i = 0; i < 3; i++)
        {
            if(Fvalue[lowestnum] = Fvalue[i])

        }



        



    }

    


    /*if (row == playery && col == playerx)
    {
        dead();
    }*/
    //this_thread
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


int main()
 {

    printguy();
    while (While < 1)
    {

        inputfunc();
        enemymove(enemyy,enemyx,playery,playerx);
        this_thread::sleep_for(2000ms);
        printguy();
        
    }
 }




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
