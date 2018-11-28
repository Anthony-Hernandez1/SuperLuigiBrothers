#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <algorithm>
#include "SDL_Plotter.h"
using namespace std;


class Floor
{
private:
//platforms
    int width;
    int height;
    int posX;
    int posY;
//floor
    int wFloor = 1000;
    int hFloor = 40;

public:
// what object does
//platforms

    Floor()
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
    void setFloorWidth(int wF)
    {
        wFloor = wF;
    }
    void setFloorHeight(int hF)
    {
        hFloor = hF;
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
    int getFloorWidth()
    {
        return wFloor;
    }
    int getFloorHeight()
    {
        return hFloor;
    }



    void draw(SDL_Plotter & g, int posX,int posY)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 204, 204, 0);
            }
        }
    }
//floor
    void drawFloor(SDL_Plotter & g, int posX,int posY)
    {
        for (int col = posX; col < wFloor + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < hFloor + posY; ++row)
            {
                g.plotPixel(col,row, 102, 51, 0);
            }
        }
    }
};
#endif // SDL_PLOTTER_H_
