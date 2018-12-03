#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "SDL_Plotter.h"
using namespace std;


const int windowHeight = 600;
const int windowWidth = 1000;

class Player
{
private:
// what makes object up

    // velocity of dot
    int velX,
        velY;
    int width;
    int height;
    int posX;
    int posY;



public:
 int hp;
// what object does
    Player()
    {
        velX =0;
        velY =0;
        width = 74;
        height = 22;
        posX = 350;
        posY = 525;
    }
/***************************************
*          void movePlayer(int)          *
* description: moves mario, gravity
* return: void
* pre: key == up,down,left,right arrows
* post: returns void
**************************************/
    void movePlayer(int xOffset, int yOffset)   // allows you to move
    {
        //posX = min(max(posX + xOffset, 0), windowWidth - width);   // allows object to move, max width, does not allow player to go off screen
        //posY = min(max(posY + yOffset, 0), windowHeight - height);
        //posX = min(max(posX + xOffset, 0), windowWidth - width );
        posY = min(max(posY + yOffset, 0), windowHeight - height - 40);//allows object to move, max height changes to account for the floor
        velX = posX -1;
        velY = posY +1;
    }
/***************************************
*          void moveLuigi(int)          *
* description: moves Luigi, floats
* return: void
* pre: key == WASD
* post: returns void
**************************************/
    void moveLuigi(int xOffset, int yOffset)
    {
        posX = min(max(posX + xOffset, 0), windowWidth - width);   // allows object to move, max width, does not allow player to go off screen
        posY = min(max(posY + yOffset, 0), windowHeight - height -40);
    }
/***************************************
*          void moveLeft(int)          *
* description: subtracts from x-coordinate
* return: void
* pre: key == left arrow
* post: returns void
**************************************/
    void moveLeft(int xOffset)
    {
        posX-=1;
    }
/***************************************
*          void moveRight(int)          *
* description: adds to player's x-coordinate
* return: void
* pre: key == right arrow                *
* post: returns void
**************************************/
    void moveRight(int xOffset)
    {
        posX+=1;
    }
/***************************************
*           void gravity(int)          *
* description: pulls player to ground
* return: void
* pre: jumping == true                 *
* post: returns void
**************************************/
    void gravity(int yOffset)
    {
        while (posY!= windowHeight-height-40){
        posY+=1;
        }
    }
/******************************************
*       int draw(SDL_Plotter)  *
* description: plots pixels on screen
* return: void
* pre: x/y coordinates specified
* post: returns void
******************************************/
    void draw(SDL_Plotter & g)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 244,66,66);
            }
        }
    }
/******************************************
*       int draw2(SDL_Plotter)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
        void draw2(SDL_Plotter & g)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 104,244,66);
            }
        }
    }
//sets health of player (MUTATORS)
/****************************
*       void setHealth(int)   *
* description: sets hp of player
* return: void
* pre: player exists
* post: returns void
******************************/
    void setHealth(int h)
    {
        hp = h;
    }
/****************************
*       void setPosX(int)   *
* description: reads in posX
* return: void
* pre: x coordinate exists
* post: returns void
******************************/
    void setPosX(int x)
    {
        posX = x;
    }
/****************************
*       void setPosY(int)   *
* description: reads in posY
* return: void
* pre: y coordinate exists
* post: returns void
******************************/
    void setPosY(int y)
    {
        posY = y;
    }
/****************************
*       int getPosX()   *
* description: retrieves xPos
* return: int
* pre: x position read in
* post: returns int
******************************/
    int getPosX()
    {
        return posX;
    }
/****************************
*       int getPosY()   *
* description: retrieves yPos
* return: int
* pre: y position read in
* post: returns int
******************************/
    int getPosY()
    {
        return posY;
    }

    int getWidth()
    {
        return width;
    }
/****************************
*       int getHeight()   *
* description: retrieves height
* return: int
* pre: height read in
* post: returns int
******************************/
    int getHeight()
    {
        return height;
    }

};
#endif // SDL_PLOTTER_H_
