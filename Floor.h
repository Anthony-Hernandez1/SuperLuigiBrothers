/***********************************
*       square with classes         *
*   does not work as of yet         *
************************************/

#include <iostream>
#include <cmath>
#include <fstream>
#include "SDL_Plotter.h"
#include "Player.h"
#include "floor.h"
#include "Enemy.h"
#include "background.h"
//#include "Sprite.h"
#include "Collisions.h"
//#include "Score.h"
using namespace std;

int main(int argc, char ** argv)
{
    ifstream input;
    const int windowHeight = 600;
    const int windowWidth = 1000;
    SDL_Plotter g(windowHeight,windowWidth);   // makes width and height of play window
    Player mario;
    Player luigi;
    Floor plat1,    //bottom left
          plat2,    // bottom right
          plat3,    // top left
          plat4,    // top right platform
          f;
    Enemy turtle;
    int count = 0;
// player initialized
    Background background;  // initialize background


    g.initSound("music.wav");       // initialize sound

    g.playSound("music.wav");

    bool stopped = false;
    int jumpPosition = 0;

    //background.setBackground("logo.txt"); //The background's dimensions and RGB values are stored in background.txt
    //background.drawBackground(g); //Draw the background
    while (!g.getQuit())
    {
        // draw background
         for (int col = 0; col < windowWidth; ++col)
        {
            for (int row = 0; row < windowHeight; row++)
            {
                g.plotPixel(col,row, 255,0,00);
            }
        }
       // background.drawBackground(g);

        //input
        if(g.getKey() == DOWN_ARROW)    // allows you to move
        {
            mario.movePlayer(0,1);   // moves character down 1 (y access positive)

        }
        else if (g.getKey() == UP_ARROW)
        {
            mario.movePlayer(0,-1);
            g.initSound("jumps.wav");
            g.playSound("jumps.wav");
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            mario.movePlayer(1,0);

        }
        else if (g.getKey() == LEFT_ARROW)
        {
            mario.movePlayer(-1,0);
        }

        if(g.getKey() == 'S')    // allows you to move
        {
            luigi.movePlayer(0,2);   // moves character down 1 (y access positive)
        }
        else if (g.getKey() == 'W')
        {
            luigi.movePlayer(0,-2);
        }
        else if (g.getKey() == 'D')
        {
            luigi.movePlayer(2,0);
        }
        else if (g.getKey() == 'A')
        {
            luigi.movePlayer(-2,0);
        }
        turtle.move(1,0);


        g.clear();
        mario.draw(g);
        luigi.draw(g);
        turtle.drawEnemy(g);
  //  if(isCollision(turtle,mario))
    //   {
      //     turtle.hp-=1;
       //}
/****************************
*       platforms     *
****************************/

//platform1
        int pX = 0;
        int pY = 300;
        plat1.setWidth(400);    // bottom left platform
        plat1.setHeight(40);
        plat1.draw(g,pX,pY);

        plat2.setWidth(450);    // bottom right platform
        plat2.setHeight(40);
        pX = 600;
        pY = 300;
        plat2.draw(g,pX,pY);

        plat3.setWidth(400);    // top left platform
        plat3.setHeight(40);
        pX = 0;
        pY = 150;
        plat3.draw(g,pX,pY);

        plat4.setWidth(450);    // top right
        plat4.setHeight(40);
        pX = 600;
        pY = 150;
        plat4.draw(g,pX,pY);

        pX = 0;
        pY = 560;
        f.drawFloor(g,pX,pY);
        g.update();


    }
}
