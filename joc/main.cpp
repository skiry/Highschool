#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
char GameOver[50][50] = {"-------------------------",
                         "-                       -",
                         "-      GAME OVER        -",
                         "-                       -",
                         "-1)Apasati ESC(ExitGame)-",
                         "-2)Apasati F1(Repetare) -",
                         "-------------------------"};

char GameWinner[50][50] = {"@@@@@@@@@@@@@@@@@@@@@@@",
                           "@                     @",
                           "@                     @",
                           "@    Win this Game    @",
                           "@                     @",
                           "@     F1 - Repeat     @",
                           "@@@@@@@@@@@@@@@@@@@@@@@"};

char map[50][50] = {"################",
                    "#              #",
                    "#              #",
                    "#      @       #",
                    "#              #",
                    "#*             #",
                    "################"};
int game_speed = 90;
bool pause = false;

//----------PLAYER------------//
int score = 0;

bool IsDead = false;
int playerCount = 0;

int inc_score = 5;
int HP = 100;
int SP = 100;
//----------OTHER-------------//
int over = 0;
int enemy = 0;
int totalenemy = 0;
//----------------------------//

//---------DIRECTION----------//
bool LimitUpDown = false;
//----------------------------//
void MyGame();
void WinGame()
{
    while(pause==true)
    {
        system("cls");
        for(int x = 0; x < 20; x++)
        {
            cout<<GameWinner[x]<<endl;
        }
        if(GetAsyncKeyState(VK_F1)!=0)
        {
            pause = false;
            if(enemy==0)
            {
                map[2][2] = '*';
                map[2][3] = '@';
            }
            MyGame();
        }
        if(GetAsyncKeyState(VK_ESCAPE)!=0)
        {
            pause = false;
        }
    }
}
void MyGame()
{
    while((pause==false)&&(IsDead == false))
    {
        system("cls");

        for(int x = 0; x < 7; x++)
        {
            cout<<map[x]<<endl;
        }
        for(int x = 0; x < 17; x ++ )
        {
            for(int y = 0 ; y < 17 ; y ++ )
            {
                switch(map[y][x])
                {
                    case '*':
                    {
                        if(LimitUpDown==false)
                        {
                            int y2 = y - 1; //up
                            switch(map[y2][x])
                            {
                                case ' ':
                                {
                                    map[y][x] = ' ';
                                    y -= 1;
                                    map[y2][x] = '*';
                                }break;

                                case '@':
                                {
                                    map[y][x] = ' ';
                                    y -= 1;
                                    map[y2][x] = '*';
                                }break;

                                case '#':
                                {
                                    LimitUpDown = true;
                                }break;
                            }
                        }
                        else
                        {
                            //down
                            int y2 = y + 1;
                            switch(map[y2][x])
                            {
                                case ' ':
                                {
                                    map[y][x] = ' ';
                                    y += 1;
                                    map[y2][x] = '*';
                                }break;

                                case '@':
                                {
                                    map[y][x] = ' ';
                                    y += 1;
                                    map[y2][x] = '*';
                                }break;

                                case '#':
                                {
                                    LimitUpDown = false;
                                }break;
                            }
                        }
                    }break;
                    case '@':
                    {
                        if(GetAsyncKeyState(VK_UP)!=0)
                        {
                            int y2 = y - 1;
                            switch(map[y2][x])
                            {
                                case ' ':
                                {
                                    map[y][x] = ' ';
                                    y -= 1;
                                    map[y2][x] = '@';
                                }break;

                                case '*':
                                {
                                    score = score+inc_score;
                                    map[y][x] = ' ';
                                    y -= 1;
                                    map[y2][x] = '@';
                                }break;
                            }
                        }

                        if(GetAsyncKeyState(VK_DOWN)!=0)
                        {
                            int y2 = y + 1;
                            switch(map[y2][x])
                            {
                                case ' ':
                                {
                                    map[y][x] = ' ';
                                    y += 1;
                                    map[y2][x] = '@';
                                }break;
                                case '*':
                                {
                                    score = score+inc_score;
                                    map[y][x] = ' ';
                                    y += 1;
                                    map[y2][x] = '@';
                                }break;
                            }
                        }

                        if(GetAsyncKeyState(VK_RIGHT)!=0)
                        {
                            int x2 = x + 1;
                            switch(map[y][x2])
                            {
                                case ' ':
                                {
                                    map[y][x] = ' ';
                                    x += 1;
                                    map[y][x2] = '@';
                                }break;

                                case '*':
                                {
                                    score = score+inc_score;
                                    map[y][x] = ' ';
                                    x += 1;
                                    map[y][x2] = '@';
                                }break;
                            }
                        }

                        if(GetAsyncKeyState(VK_LEFT)!=0)
                        {
                            int x2 = x - 1;
                            switch(map[y][x2])
                            {
                                case ' ':
                                {
                                    map[y][x] = ' ';
                                    x -= 1;
                                    map[y][x2] = '@';
                                }break;

                                case '*':
                                {
                                    score = score+inc_score;
                                    map[y][x] = ' ';
                                    x -= 1;
                                    map[y][x2] = '@';
                                }break;
                            }
                        }

                    }break;
                }

                if(GetAsyncKeyState(VK_ESCAPE)!=0)
                {
                    pause = true;
                }
            }
        }
        for(int x = 0 ; x < 17; x ++ )
        {
            for(int y = 0; y < 17; y ++ )
            {
                if(map[y][x]=='@')
                {
                    playerCount ++;
                }
            }
        }
        if(playerCount==0)
        {
            IsDead = true;
            over += 1;
        }
        for(int x = 0 ; x < 17; x ++ )
        {
            for(int y = 0; y < 17 ; y++)
            {
                if(map[y][x]=='*')
                {
                    enemy ++;
                }
            }
        }
        if(totalenemy<=enemy)
        {
            totalenemy = enemy;
        }
        if(enemy==0)
        {
            pause = true;
            WinGame();
        }
        cout<<"----------------------------------"<<endl;
        cout<<"ENEMY: "<<enemy<<endl;
        cout<<"SCORE: "<<score<<endl;
        cout<<"GAME SPEED: "<<game_speed<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"Health: "<<HP<<endl;
        cout<<"----------------------------------"<<endl;
        Sleep(game_speed);
        enemy = 0;
        playerCount = 0;
    }
    while(IsDead == true)
    {
        system("cls");
        for(int x = 0; x < 15; x ++ )
        {
            cout<<GameOver[x]<<endl;
        }
        if(GetAsyncKeyState(VK_F1)!=0)
        {
            IsDead = false;
            pause = false;
            if(enemy == 0)
            {
                map[2][2] = '*';
            }
            map[2][3] = '@';
            MyGame();
        }
        if(GetAsyncKeyState(VK_ESCAPE)!=0)
        {
            IsDead = false;
        }
    }
}
int main()
{
    MyGame();
}
