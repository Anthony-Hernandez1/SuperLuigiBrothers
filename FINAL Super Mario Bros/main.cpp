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
#include "Score.h"
#include "Token.h"
#include "secretLevel.h"
#include "Level1.h"
using namespace std;
const int GRAVITY = -1;
int main(int argc, char ** argv)
{
    ifstream input;
    const int windowHeight = 600;
    const int windowWidth = 1000;
    SDL_Plotter g(windowHeight,windowWidth);   // makes width and height of play window

    Score score1;
// Player initialization
    Player mario;
    Player luigi;
    Floor plat1,    //bottom left
          plat2,    // bottom right
          plat3,    // top left
          plat4,    // top right platform
          middlePlat,
          f,
         leftPipe1, //top left
         vtPipe1,   // draws vertical pipe upwards
         vtPipe2,
         hzPipe1,
         hzPipe2,      // draws second pipe above first
         rightPipe1,    // top right
         leftPipe2, // bottom left
         rightPipe2,    // bottom right
         plat5;
    Enemy turtle,
          turtle2;
    Token token,
          token2;

    Level1 L,   // initialize to show change of levels
           L2,
           box1,
           box2,
           box3,
           box4,
           box5,
           box6;
    Secret snowflake,
            snow,
            hat;

    int tempScore = 0;
    //collide.collision(turtle, mario);
   // collide.getCollision();

// initializes the music

        g.initSound("theme.wav");
        g.initSound("level5theme.wav");
        g.initSound("level2theme.wav");
        g.initSound("christmas.wav");
    while((!g.getQuit()))
    {
        if (tempScore < 20000)
        {
            g.playSound("theme.wav");
        }
/***************************
*   "Collision" for Mario "*
****************************/
        //Middle Plat
        if((mario.getPosX() > 254 && mario.getPosX()<603)&&(mario.getPosY() > 280 && mario.getPosY() < 325))
        {
         mario.setPosX(254);
        }
        if((mario.getPosX() < 610 && mario.getPosX()>255)&&(mario.getPosY() > 280 && mario.getPosY() < 325))
        {
         mario.setPosX(610);

        }
        if((mario.getPosX() > 255 && mario.getPosX() < 610)&&(mario.getPosY() < 327&&mario.getPosY() >278 ))
        {
         mario.setPosY(326);
        }
        if((mario.getPosX() > 255 && mario.getPosX() < 610)&&(mario.getPosY() > 277&&mario.getPosY() < 326))
        {
         mario.setPosY(277);
        }

        //Bottom-Right Plat
        if((mario.getPosX() > 525)&&(mario.getPosY()>377&&mario.getPosY()<428))
        {
            mario.setPosX(525);
        }
        if((mario.getPosX() > 525)&&(mario.getPosY()>376&&mario.getPosY()<429))
        {
            mario.setPosY(376);
        }
        if((mario.getPosX() > 525)&&(mario.getPosY()>376&&mario.getPosY()<430))
        {
            mario.setPosY(430);
        }

        //Bottom Left Plat
        if((mario.getPosX() < 370)&&(mario.getPosY()>377&&mario.getPosY()<428))
        {
            mario.setPosX(370);
        }
        if((mario.getPosX() < 370)&&(mario.getPosY()>376&&mario.getPosY()<429))
        {
            mario.setPosY(376);
        }
        if((mario.getPosX() < 370)&&(mario.getPosY()>376&&mario.getPosY()<430))
        {
            mario.setPosY(430);
        }

        //Top Left Plat
        if((mario.getPosX() < 370)&&(mario.getPosY()>150&&mario.getPosY()<180))
        {
            mario.setPosX(370);
        }
        if((mario.getPosX() < 368)&&(mario.getPosY()>127&&mario.getPosY()<180))
        {
            mario.setPosY(127);
        }
        if((mario.getPosX() < 370)&&(mario.getPosY()>150&&mario.getPosY()<181))
        {
            mario.setPosY(181);
        }

        //Top Right Plat
        if((mario.getPosX() > 525)&&(mario.getPosY()>150&&mario.getPosY()<180))
        {
            mario.setPosX(525);
        }
        if((mario.getPosX() > 526)&&(mario.getPosY()>127&&mario.getPosY()<180))
        {
            mario.setPosY(127);
        }
        if((mario.getPosX() > 526)&&(mario.getPosY()>150&&mario.getPosY()<181))
        {
            mario.setPosY(181);
        }

/***************************
*   "Collision" for Luigi "*
****************************/
        //Middle Plat
        if((luigi.getPosX() > 254 && luigi.getPosX()<603)&&(luigi.getPosY() > 280 && luigi.getPosY() < 325))
        {
         luigi.setPosX(254);
        }
        if((luigi.getPosX() < 610 && luigi.getPosX()>255)&&(luigi.getPosY() > 280 && luigi.getPosY() < 325))
        {
         luigi.setPosX(610);

        }
        if((luigi.getPosX() > 255 && luigi.getPosX() < 610)&&(luigi.getPosY() < 327&&luigi.getPosY() >278 ))
        {
         luigi.setPosY(326);
        }
        if((luigi.getPosX() > 255 && luigi.getPosX() < 610)&&(luigi.getPosY() > 277&&luigi.getPosY() < 326))
        {
         luigi.setPosY(277);
        }

        //Bottom-Right Plat
        if((luigi.getPosX() > 525)&&(luigi.getPosY()>377&&luigi.getPosY()<428))
        {
            luigi.setPosX(525);
        }
        if((luigi.getPosX() > 525)&&(luigi.getPosY()>376&&luigi.getPosY()<429))
        {
            luigi.setPosY(376);
        }
        if((luigi.getPosX() > 525)&&(luigi.getPosY()>376&&luigi.getPosY()<430))
        {
            luigi.setPosY(430);
        }

        //Bottom Left Plat
        if((luigi.getPosX() < 370)&&(luigi.getPosY()>377&&luigi.getPosY()<428))
        {
            luigi.setPosX(370);
        }
        if((luigi.getPosX() < 370)&&(luigi.getPosY()>376&&luigi.getPosY()<429))
        {
            luigi.setPosY(376);
        }
        if((luigi.getPosX() < 370)&&(luigi.getPosY()>376&&luigi.getPosY()<430))
        {
            luigi.setPosY(430);
        }

        //Top Left Plat
        if((luigi.getPosX() < 370)&&(luigi.getPosY()>150&&luigi.getPosY()<180))
        {
            luigi.setPosX(370);
        }
        if((luigi.getPosX() < 368)&&(luigi.getPosY()>127&&luigi.getPosY()<180))
        {
            luigi.setPosY(127);
        }
        if((luigi.getPosX() < 370)&&(luigi.getPosY()>150&&luigi.getPosY()<181))
        {
            luigi.setPosY(181);
        }

        //Top Right Plat
        if((luigi.getPosX() > 525)&&(luigi.getPosY()>150&&luigi.getPosY()<180))
        {
            luigi.setPosX(525);
        }
        if((luigi.getPosX() > 526)&&(luigi.getPosY()>127&&luigi.getPosY()<180))
        {
            luigi.setPosY(127);
        }
        if((luigi.getPosX() > 526)&&(luigi.getPosY()>150&&luigi.getPosY()<181))
        {
            luigi.setPosY(181);
        }

/***************************
*   "Collision" for Token "*
****************************/
//        if(mario.getPosY()+5>=token.getPosY()&&mario.getPosY()-5<=token.getPosX()&&
//           mario.getPosX()-5<=token.getPosX()&&mario.getPosX()+5<=token.getPosX())
//        {
//            token.setPosX(5);
//            token.setPosY(5);
//        }

       //Middle Plat
        if((token.getPosX() > 254 && token.getPosX()<603)&&(token.getPosY() > 280 && token.getPosY() < 325))
        {
         token.setPosX(254);
        }
        if((token.getPosX() < 610 && token.getPosX()>255)&&(token.getPosY() > 280 && token.getPosY() < 325))
        {
         token.setPosX(610);

        }
        if((token.getPosX() > 255 && token.getPosX() < 610)&&(token.getPosY() < 327&&token.getPosY() >278 ))
        {
         token.setPosY(326);
        }
        if((token.getPosX() > 255 && token.getPosX() < 610)&&(token.getPosY() > 277&&token.getPosY() < 326))
        {
         token.setPosY(277);
        }

        //Bottom-Right Plat
        if((token.getPosX() > 525)&&(token.getPosY()>377&&token.getPosY()<428))
        {
            token.setPosX(525);
        }
        if((token.getPosX() > 525)&&(token.getPosY()>376&&token.getPosY()<429))
        {
            token.setPosY(376);
        }
        if((token.getPosX() > 525)&&(token.getPosY()>376&&token.getPosY()<430))
        {
            token.setPosY(430);
        }

        //Bottom Left Plat
        if((token.getPosX() < 370)&&(token.getPosY()>377&&token.getPosY()<428))
        {
            token.setPosX(370);
        }
        if((token.getPosX() < 370)&&(token.getPosY()>376&&token.getPosY()<429))
        {
            token.setPosY(376);
        }
        if((token.getPosX() < 370)&&(token.getPosY()>376&&token.getPosY()<430))
        {
            token.setPosY(430);
        }

        //Top Left Plat
        if((token.getPosX() < 370)&&(token.getPosY()>150&&token.getPosY()<180))
        {
            token.setPosX(370);
        }
        if((token.getPosX() < 368)&&(token.getPosY()>127&&token.getPosY()<180))
        {
            token.setPosY(127);
        }
        if((token.getPosX() < 370)&&(token.getPosY()>150&&token.getPosY()<181))
        {
            token.setPosY(181);
        }

        //Top Right Plat
        if((token.getPosX() > 525)&&(token.getPosY()>150&&token.getPosY()<180))
        {
            token.setPosX(525);
        }
        if((token.getPosX() > 526)&&(token.getPosY()>127&&token.getPosY()<180))
        {
            token.setPosY(127);
        }
        if((token.getPosX() > 526)&&(token.getPosY()>150&&token.getPosY()<181))
        {
            token.setPosY(181);
        }
        //Token End Movement
        if(token.getPosX()>930&&token.getPosY()<435)
        {
            token.setPosX(0);
        }
        if(token.getPosX()>930&&token.getPosY()>435)
        {
            token.setPosX(5);
            token.setPosY(5);
        }
/******************************
*       Token 2 Collision       *
**********************************/
 //Middle Plat
        if((turtle2.getPosX() > 254 && turtle2.getPosX()<603)&&(turtle2.getPosY() > 280 && turtle2.getPosY() < 325))
        {
         turtle2.setPosX(254);
        }
        if((token2.getPosX() < 610 && token2.getPosX()>255)&&(token2.getPosY() > 280 && token2.getPosY() < 325))
        {
         token2.setPosX(610);

        }
        if((token2.getPosX() > 255 && token2.getPosX() < 610)&&(token2.getPosY() < 327&&token2.getPosY() >278 ))
        {
         token2.setPosY(326);
        }
        if((token2.getPosX() > 255 && token2.getPosX() < 610)&&(token2.getPosY() > 277&&token2.getPosY() < 326))
        {
         token2.setPosY(277);
        }

        //Bottom-Right Plat
        if((token2.getPosX() > 525)&&(token2.getPosY()>377&&token2.getPosY()<428))
        {
            token2.setPosX(525);
        }
        if((token2.getPosX() > 525)&&(token2.getPosY()>376&&token2.getPosY()<429))
        {
            token2.setPosY(376);
        }
        if((token2.getPosX() > 525)&&(token2.getPosY()>376&&token2.getPosY()<430))
        {
            token2.setPosY(430);
        }

        //Bottom Left Plat
        if((token2.getPosX() < 370)&&(token2.getPosY()>377&&token2.getPosY()<428))
        {
            token2.setPosX(370);
        }
        if((token2.getPosX() < 370)&&(token2.getPosY()>376&&token2.getPosY()<429))
        {
            token2.setPosY(376);
        }
        if((token2.getPosX() < 370)&&(token2.getPosY()>376&&token2.getPosY()<430))
        {
            token2.setPosY(430);
        }

        //Top Left Plat
        if((token2.getPosX() < 370)&&(token2.getPosY()>150&&token2.getPosY()<180))
        {
            token2.setPosX(370);
        }
        if((token2.getPosX() < 368)&&(token2.getPosY()>127&&token2.getPosY()<180))
        {
            token2.setPosY(127);
        }
        if((token2.getPosX() < 370)&&(token2.getPosY()>150&&token2.getPosY()<181))
        {
            token2.setPosY(181);
        }

        //Top Right Plat
        if((token2.getPosX() > 525)&&(token2.getPosY()>150&&token2.getPosY()<180))
        {
            token2.setPosX(525);
        }
        if((token2.getPosX() > 526)&&(token2.getPosY()>127&&token2.getPosY()<180))
        {
            token2.setPosY(127);
        }
        if((token2.getPosX() > 526)&&(token2.getPosY()>150&&token2.getPosY()<181))
        {
            token2.setPosY(181);
        }
        //Token End Movement
        if(token2.getPosX()>930&&token2.getPosY()<435)
        {
            token2.setPosX(0);
        }
        if(token2.getPosX()>930&&token2.getPosY()>435)
        {
            token2.setPosX(5);
            token2.setPosY(5);
        }
/**********************
*       input           *
***********************/

        mario.gravity(-1);      // GRAVITY FOR PLAYER1
        //luigi.gravity(-1);      // GRAVITY FOR PLAYER2

        tempScore++;
        cout << tempScore<< endl;

        if (g.getKey() == UP_ARROW)
        {
            mario.movePlayer(0,-50);
            g.initSound("jumps.wav");
            g.playSound("jumps.wav");

        }
        else if (g.getKey() == DOWN_ARROW)
        {
            mario.movePlayer(0,1);

        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            mario.moveRight(1);
            //score1.changeScore();

        }
        else if (g.getKey() == LEFT_ARROW)
        {
            mario.moveLeft(-1);
        }
//LUIGI
        else if(g.getKey() == 'W') // allows you to move
        {
            luigi.moveLuigi(0,-1);
            g.initSound("jumps.wav");
            g.playSound("jumps.wav");
        }
        else if (g.getKey() == 'D')
        {
            luigi.moveLuigi(1,0);
        }
        else if (g.getKey() == 'A')
        {
            luigi.moveLuigi(-1,0);
        }
        else if (g.getKey() == 'S')
        {
            luigi.moveLuigi(0,1);
        }

        if(g.kbhit()){

            g.getKey();
        }
        g.clear();
    //drawing
        mario.draw(g);
        luigi.draw2(g);
/*******************
*       Enemy       *
********************/

        turtle.drawEnemy(g);
        turtle.move(-1,1);
        //Middle Plat
        if((turtle.getPosX() > 254 && turtle.getPosX()<603)&&(turtle.getPosY() > 280 && turtle.getPosY() < 325))
        {
         turtle.setPosX(254);
        }
        if((turtle.getPosX() < 610 && turtle.getPosX()>255)&&(turtle.getPosY() > 280 && turtle.getPosY() < 325))
        {
         turtle.setPosX(610);

        }
        if((turtle.getPosX() > 255 && turtle.getPosX() < 610)&&(turtle.getPosY() < 327&&turtle.getPosY() >278 ))
        {
         turtle.setPosY(326);
        }
        if((turtle.getPosX() > 255 && turtle.getPosX() < 610)&&(turtle.getPosY() > 277&&turtle.getPosY() < 326))
        {
         turtle.setPosY(277);
        }

        //Bottom-Right Plat
        if((turtle.getPosX() > 525)&&(turtle.getPosY()>377&&turtle.getPosY()<428))
        {
            turtle.setPosX(525);
        }
        if((turtle.getPosX() > 525)&&(turtle.getPosY()>376&&turtle.getPosY()<429))
        {
            turtle.setPosY(376);
        }
        if((turtle.getPosX() > 525)&&(turtle.getPosY()>376&&turtle.getPosY()<430))
        {
            turtle.setPosY(430);
        }

        //Bottom Left Plat
        if((turtle.getPosX() < 370)&&(turtle.getPosY()>377&&turtle.getPosY()<428))
        {
            turtle.setPosX(370);
        }
        if((turtle.getPosX() < 370)&&(turtle.getPosY()>376&&turtle.getPosY()<429))
        {
            turtle.setPosY(376);
        }
        if((turtle.getPosX() < 370)&&(turtle.getPosY()>376&&turtle.getPosY()<430))
        {
            turtle.setPosY(430);
        }

        //Top Left Plat
        if((turtle.getPosX() < 370)&&(turtle.getPosY()>150&&turtle.getPosY()<180))
        {
            turtle.setPosX(370);
        }
        if((turtle.getPosX() < 368)&&(turtle.getPosY()>127&&turtle.getPosY()<180))
        {
            turtle.setPosY(127);
        }
        if((turtle.getPosX() < 370)&&(turtle.getPosY()>150&&turtle.getPosY()<181))
        {
            turtle.setPosY(181);
        }

        //Top Right Plat
        if((turtle.getPosX() > 525)&&(turtle.getPosY()>150&&turtle.getPosY()<180))
        {
            turtle.setPosX(525);
        }
        if((turtle.getPosX() > 526)&&(turtle.getPosY()>127&&turtle.getPosY()<180))
        {
            turtle.setPosY(127);
        }
        if((turtle.getPosX() > 526)&&(turtle.getPosY()>150&&turtle.getPosY()<181))
        {
            turtle.setPosY(181);
        }
        //Enemy End Movement
        if(turtle.getPosX()<5&&turtle.getPosY()<435)
        {
            turtle.setPosX(900);
        }
        if(turtle.getPosX()<5&&turtle.getPosY()>435)
        {
            turtle.setPosX(900);
            turtle.setPosY(5);
        }


/********************
*    NPC Movement   *
*********************/
        token.draw1(g);
        token.move(1,1);
      //  turtle2.moveLeft2(-1);

/****************************
*      LEVEL1 platforms     *
****************************/
//color LEVEL header
        int pX = 300;
        int pY = 10;
        L.draw(g,pX,pY);
        pX = 300;
        pY = 50;
        L2.setWidth(50);
        L2.setHeight(20);
        L2.draw(g,pX,pY);

        pX = 370;
        pY = 10;
        box1.setWidth(10);
        box1.setHeight(60);
        box1.draw(g,pX,pY);

//platform1
        plat1.setWidth(370);    // bottom left platform
        plat1.setHeight(30);
        plat1.draw(g,0,400);
        while(mario.getPosX()== plat1.getHeight() && mario.getPosY() == plat1.getWidth())
        {
            mario.setPosX(!0);
            mario.setPosY(!400);
        }
        plat2.setWidth(400);    // bottom right platform
        plat2.setHeight(30);
        plat2.draw(g,600,400);

        plat3.setWidth(370);    // top left platform
        plat3.setHeight(30);
        plat3.draw(g,0,150);

        plat4.setWidth(400);    // top right
        plat4.setHeight(30);
        plat4.draw(g,600,150);

        middlePlat.setWidth(280);    // middle
        middlePlat.setHeight(25);
        middlePlat.draw(g,330,300);

        f.drawFloor(g,0,560);

/*********************
*   Pipes           *
*********************/
        leftPipe1.setWidth(70);    // bottom left
        leftPipe1.setHeight(25);
        leftPipe1.drawPipe(g,0,530);

        leftPipe2.setWidth(50);    // top left
        leftPipe2.setHeight(35);
        leftPipe2.drawPipe(g,0,100);
        vtPipe1.setWidth(35);
        vtPipe1.setHeight(90);
        vtPipe1.drawPipe(g,15,30);
        hzPipe1.setWidth(60);
        hzPipe1.setHeight(35);
        hzPipe1.drawPipe(g,15,30);

        rightPipe1.setWidth(70);    // bottom right
        rightPipe1.setHeight(25);
        rightPipe1.drawPipe(g,940,530);

        rightPipe2.setWidth(50);    // top right
        rightPipe2.setHeight(35);
        rightPipe2.drawPipe(g,950,100);
        vtPipe2.setWidth(35);
        vtPipe2.setHeight(90);
        vtPipe2.drawPipe(g,945,45);
        hzPipe2.setWidth(60);
        hzPipe2.setHeight(35);
        hzPipe2.drawPipe(g,920,30);


/***********************************
            LEVEL 2                 *
*************************************/
    if(tempScore >= 10000)
    {
    //redraw for second level
        token2.draw1(g);
        token2.move(1,1);
        plat1.drawLevel2(g,0,400);
        plat2.drawLevel2(g,600,400);
        plat3.drawLevel2(g,0,150);
        plat4.drawLevel2(g,600,150);
        middlePlat.drawLevel2(g,330,300);
        pX = 400;
        pY = 10;
        box2.setWidth(10);
        box2.setHeight(60);
        box2.draw(g,pX,pY);

    }
/****************************************
*           LEVEL 3                     *
*****************************************/
    if (tempScore >= 20000)
    {
        g.quitSound("theme.wav");
        g.playSound("level2theme.wav");
        plat1.drawLevel3(g,0,400);
        plat2.drawLevel3(g,600,400);
        plat3.drawLevel3(g,0,150);
        plat4.drawLevel3(g,600,150);
        middlePlat.drawLevel3(g,330,300);
        pX = 430;
        pY = 10;
        box3.setWidth(10);
        box3.setHeight(60);
        box3.draw(g,pX,pY);
    }

/******************************************
*               LEVEL 4                   *
*******************************************/

    if (tempScore >= 30000)
    {
        plat1.drawLevel4(g,0,400);
        plat2.drawLevel4(g,600,400);
        plat3.drawLevel4(g,0,150);
        plat4.drawLevel4(g,600,150);
        middlePlat.drawLevel4(g,330,300);

        pX = 460;
        pY = 10;
        box4.setWidth(10);
        box4.setHeight(60);
        box4.draw(g,pX,pY);
    }

/******************************************
*               LEVEL 5                   *
*******************************************/

    if (tempScore >= 40000)
    {
        g.quitSound("level2theme.wav");
        g.playSound("level5theme.wav");
        plat1.drawLevel5(g,0,400);
        plat2.drawLevel5(g,600,400);
        plat3.drawLevel5(g,0,150);
        plat4.drawLevel5(g,600,150);
        middlePlat.drawLevel5(g,330,300);
        pX = 490;
        pY = 10;
        box5.setWidth(10);
        box5.setHeight(60);
        box5.draw(g,pX,pY);
    }

/******************************************
*               SECRET LEVEL              *
*******************************************/
    if(g.getKey() == 'C' || tempScore >=55000)
    {
        g.quitSound("level2theme.wav");
        g.quitSound("level5theme.wav");
        g.quitSound("theme.wav");
        g.playSound("christmas.wav");
        plat1.drawLevel6(g,0,400);
        plat2.drawLevel6(g,600,400);
        plat3.drawLevel6(g,0,150);
        plat4.drawLevel6(g,600,150);
        middlePlat.drawLevel6(g,330,300);

    // draw snowflakes
        snowflake.draw(g,100,30);   // left side
        snowflake.draw(g,110,110);
        snowflake.draw(g,60,70);
        snowflake.draw(g,180,67);
        snowflake.draw(g,260,70);
    // right side
        snowflake.draw(g,600,90);
        snowflake.draw(g,550,34);
        snowflake.draw(g,800,110);
        snowflake.draw(g,880,55);
        snowflake.draw(g,740,80);
    // middle
        snowflake.draw(g,500,200);
        snowflake.draw(g,390,250);
        snowflake.draw(g,440,170);
    // middle right
        snowflake.draw(g,650,260);
        snowflake.draw(g,880,340);
        snowflake.draw(g,830,290);
    //middle left
        snowflake.draw(g,230, 355);
        snowflake.draw(g,120, 290);
        snowflake.draw(g,50, 366);
        snowflake.draw(g,180, 244);
    // very bottom
        snowflake.draw(g,70,490);   // left side
        snowflake.draw(g,120,520);
        snowflake.draw(g,700,500);
        snowflake.draw(g,550,450);
        snowflake.draw(g,260,470);
        snowflake.draw(g,800, 510);
        snowflake.draw(g,910, 480);
        snowflake.draw(g,470, 460);

// on pipes
        snow.setHeight(15); // top left pipe
        snow.setWidth(60);
        snow.drawSnow(g,15,18);
        snow.drawSnow(g,920,20); // top right pipe
        snow.setHeight(15); // bottom left pipe
        snow.setWidth(70);
        snow.drawSnow(g,0,520);
        snow.drawSnow(g,940,520);   // bottom right
// on platforms
        snow.setHeight(15);
        snow.setWidth(368);
        snow.drawSnow(g,0,400);      // bottom left platform
        snow.drawSnow(g,0,140);   // top left
        snow.setHeight(15);
        snow.setWidth(390);
        snow.drawSnow(g,602,398);       //bottom right
        snow.drawSnow(g,602,145);
        snow.setHeight(15);     // middle
        snow.setWidth(280);
        snow.drawSnow(g,330,290);

    // mario's christmas hat
        hat.setHeight(10);
        hat.setWidth(74);
        hat.drawHat(g,mario.getPosX(),mario.getPosY());
        hat.setHeight(20);
        hat.setWidth(60);
        hat.drawHat2(g,mario.getPosX() +8,mario.getPosY() - 20);

        hat.setHeight(15);  // last portion
        hat.setWidth(15);
        hat.drawHat(g,mario.getPosX() + 25,mario.getPosY() - 35);
    // luigi's christmas hat
        hat.setHeight(10);
        hat.setWidth(74);
        hat.drawHat(g,luigi.getPosX(),luigi.getPosY());
        hat.setHeight(20);
        hat.setWidth(60);
        hat.drawHat2(g,luigi.getPosX() +8,luigi.getPosY() - 20);

        hat.setHeight(15);  // last portion
        hat.setWidth(15);
        hat.drawHat(g,luigi.getPosX() + 25,luigi.getPosY() - 35);

    }
    g.update();
    }
}
