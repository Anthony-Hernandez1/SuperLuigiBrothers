#ifndef ACTUALFLOOR_H
#define ACTUALFLOOR_H
#include <iostream>
#include <algorithm>
#include "SDL_Plotter.h"
using namespace std;


class actualFloor
{
private:
// what makes object up
    int width = 1000;
    int height = 40;
    int posX;
    int posY;

public:
// what object does

    void draw(SDL_Plotter & g, int posX,int posY)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 0,255,0);
            }
        }
    }


};
#endif // SDL_PLOTTER_H_

