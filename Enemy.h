//
// Created by ADAMIK on 11/19/2018.
//

#ifndef GROUP_PROJECT_ENEMY_H
#define GROUP_PROJECT_ENEMY_H
#include <iostream>
#include <algorithm>
#include "SDL_Plotter.h"

class Enemy {
private:
    int width = 74;
    int height = 22;
    int posX = 100;
    int posY = 100;
    int velX = 0;
    int vely = 0;

public:
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

};


#endif //GROUP_PROJECT_ENEMY_H
