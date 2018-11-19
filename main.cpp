/***********************************
*       square with classes         *
*   does not work as of yet         *
************************************/

#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "Player.h"
#include "floor.h"
#include "Enemy.h"
using namespace std;


int main(int argc, char ** argv)
{
    const int windowHeight = 600;
    const int windowWidth = 1000;
    SDL_Plotter g(windowHeight,windowWidth);   // makes width and height of play window

    Player mario;
    Floor f;
    Enemy turtle;

    bool stopped = false;

    int jumpPosition = 0;
    while (!g.getQuit())
    {
        // draw background
        for (int col = 0; col < windowWidth; ++col)
        {
            for (int row = 0; row < windowHeight; row++)
            {
                g.plotPixel(col,row, 0,0,0);
            }
        }
        //input
        if(g.getKey() == DOWN_ARROW)    // allows you to move
        {
            mario.movePlayer(0,1);   // moves character down 1 (y access positive)
        }
        else if (g.getKey() == UP_ARROW)
        {
            mario.movePlayer(0,-1);
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            mario.movePlayer(1,0);
        }
        else if (g.getKey() == LEFT_ARROW)
        {
            mario.movePlayer(-1,0);
        }

        Player luigi;
        if(g.getKey() == 'S')    // allows you to move
        {
            luigi.movePlayer(10,20);   // moves character down 1 (y access positive)
        }
        else if (g.getKey() == 'W')
        {
            luigi.movePlayer(10,-20);
        }
        else if (g.getKey() == 'D')
        {
            luigi.movePlayer(20,10);
        }
        else if (g.getKey() == 'A')
        {
            luigi.movePlayer(-20,10);
        }
        if(g.kbhit()){
            turtle.move(1,1);
        }
        if(g.kbhit()){
            g.getKey();
        }
        g.clear();
        mario.draw(g);
        luigi.draw(g);
        turtle.drawEnemy(g);
/****************************
*       platforms     *
****************************/

//platform1
        int pX = 0;
        int pY = 300;
        f.draw(g,pX,pY);

        pX = 600;
        pY = 300;
        f.draw(g,pX,pY);

        pX = 0;
        pY = 150;
        f.draw(g,pX,pY);

        pX = 600;
        pY = 150;
        f.draw(g,pX,pY);
        g.update();
    }
}









