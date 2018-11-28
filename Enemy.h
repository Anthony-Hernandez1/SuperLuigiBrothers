//
// Created by ADAMIK on 11/19/2018.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <algorithm>
#include "SDL_Plotter.h"
#include "Player.h"
#include "Collisions.h"
class Enemy {
public:

    int width = 74;
    int height = 22;
    int velX = 0;
    int vely = 0;
    //int hp;
    int posX = 40;
    int posY = 530;
    int hp;

    void move(int xOffset, int yOffset)   // allows you to move
    {
        posX = min(max(posX + xOffset, 0), windowWidth - width);
        posY = min(max(posY + yOffset, 0), windowHeight - height);
        velX = xOffset + 1;
        vely = yOffset + 1;
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
// mutators
    void setHealth(int h)
    {
        hp = h;
    }

    void setPosX(int x)
    {
        posX = x;
    }

    void setPosY(int y)
    {
        posY = y;
    }
// accessors
    int getHealth()
    {
        return hp;
    }

    int getPosX()
    {
        return posX;
    }

    int getPosY()
    {
        return posY;
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

