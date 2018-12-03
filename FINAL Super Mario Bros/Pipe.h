#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <algorithm>
#include "SDL_Plotter.h"
using namespace std;


class Pipe
{
private:
//pipes
    int width;
    int height;
    int posX;
    int posY;

public:
// what object does
//platforms
    Pipe()
    {
        width = 0;
        height = 0;
        posX = 0;
        posY = 0;
    }
//mutators
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
//accessors
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }

    void draw(SDL_Plotter & g, int posX,int posY)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 57, 230, 0);
            }
        }
    }

};
#endif // SDL_PLOTTER_H_

