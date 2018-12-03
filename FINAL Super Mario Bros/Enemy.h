//
// Created by ADAMIK on 11/19/2018.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "SDL_Plotter.h"
#include "Player.h"
//#include "Collisions.h"
class Enemy {
public:

    int width;
    int height;
    int velX;
    int velY;
    //int hp;
    int posX;
    int posY;
    int hp;
    int posY2,
        posX2;

    Enemy()
    {
         width = 74;
        height = 22;
        velX = 0;
        velY = 0;
        posX2 = 900;
        posY2 = 5;
        posX = 900;
        posY = 5;
        hp = 1;
    }
/***************************************
*          void move(int)          *
* description: moves Luigi, floats
* return: void
* pre: x/y coordinates set
* post: returns void
**************************************/
    void move(int xOffset, int yOffset)   // allows you to move
    {
        posX = min(max(posX + xOffset, 0), windowWidth - width);
        posY = min(max(posY + yOffset, 0), windowHeight - height-40);
        velX = posX +1;
        velY = posY -10;
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
* description: pulls enemy to ground
* return: void
* pre: enemy exists
* post: returns void
**************************************/
    void gravity(int yOffset)
    {
        while (posY!= windowHeight-height-40){
        posY+=1;
        }
    }
    void drawEnemy(SDL_Plotter & g)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 230,10,204);
            }
        }
    }
    void drawEnemy2(SDL_Plotter & g)
    {
        for (int col = posX2; col < width + posX2; col++)   // goes through all columns
        {
            for (int row = posY2; row < height + posY2; ++row)
            {
                g.plotPixel(col,row, 255, 153, 204);
            }
        }
    }

    void gravity2(int yOffset)
    {
        while (posY2!= windowHeight-height-40){
        posY2+=1;
        }
    }
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
// accessors
    int getHealth()
    {
        return hp;
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
/****************************
*       int getWidth()   *
* description: retrieves width
* return: int
* pre: width read in
* post: returns int
******************************/
    int getWidth()
    {
        return width;
    }
/****************************
*       int getFloorHeight()   *
* description: retrieves height
* return: int
* pre: height read in
* post: returns int
******************************/
    int getHeight()
    {
        return height;
    }

// destroy
    void die()
    {
       // if(Collision(Enemy e,Player p))
        //{
         //   ~Enemy;
        //}
    }


};
#endif //ENEMY_H
