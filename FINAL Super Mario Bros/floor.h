#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include "SDL_Plotter.h"
#include <stdlib.h>
using namespace std;

struct Color
{

    int red,
        green,
        blue;

    Color()
    {
        red = 204;
        blue = 0;
        green = 204;
    }

};

class Floor
{
private:
//platforms
    int width;
    int height;
    int posX;
    int posY;

public:

    int wFloor = 1000;
    int hFloor = 40;
    Floor()
    {
        width = 0;
        height = 0;
        posX = 0;
        posY = 0;
        int wFloor = 1000;
    int hFloor = 40;
    }
    Floor(int w, int h, int pX, int pY)
    {
        width = w;
        h = height;
        pX = posX;
        pY = posY;
    }
/****************************
*       void setWidth(int)   *
* description: sets w from input
* return: void
* pre: width inputted
* post: returns void
******************************/
    void setWidth(int w)
    {
        width = w;
    }
/****************************
*       void setHeight(int)   *
* description: sets h from input
* return: void
* pre: height inputted
* post: returns void
******************************/
    void setHeight(int h)
    {
        height = h;
    }
/********************************
*       void setFloorWidth(int)   *
* description: sets w from input
* return: void
* pre: width inputted
* post: returns void
******************************/
    void setFloorWidth(int wF)
    {
        wFloor = wF;
    }
/****************************
*       void setFloorHeight(int)   *
* description: sets h from input
* return: void
* pre: height inputted
* post: returns void
******************************/
    void setFloorHeight(int hF)
    {
        hFloor = hF;
    }

//accessors
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
    int getFloorWidth()
    {
        return wFloor;
    }
/****************************
*       int getFloorHeight()   *
* description: retrieves height
* return: int
* pre: height read in
* post: returns int
******************************/
    int getFloorHeight()
    {
        return hFloor;
    }

/******************************************
*       int draw(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int draw(SDL_Plotter & g, int posX,int posY)
    {
        Color color;
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 11, 127, 229);
            }
        }
    }
/******************************************
*       int drawLevel2(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawLevel2(SDL_Plotter & g, int posX,int posY)
    {
        Color color;
        color.red = 0;
        color.blue = 255;
        color.green= 255;
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, color.red, color.green, color.blue);
            }
        }
    }
/******************************************
*       int drawLevel3(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawLevel3(SDL_Plotter & g, int posX,int posY)
    {
        Color color;
        color.red = 102;
        color.blue = 204;
        color.green= 0;
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, color.red, color.green, color.blue);
            }
        }
    }
/******************************************
*       int drawLevel4(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawLevel4(SDL_Plotter & g, int posX,int posY)
    {
        Color color;
        color.red = 0;
        color.blue = 102;
        color.green= 0;
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, color.red, color.green, color.blue);
            }
        }
    }
/******************************************
*       int drawLevel5(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawLevel5(SDL_Plotter & g, int posX,int posY)
    {
        Color color;
        color.red = rand() % 255 +1;
        color.blue = rand() % 255 +1;
        color.green= rand() % 255 +1;
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, color.red, color.green, color.blue);
            }
        }
    }
/******************************************
*       int drawLevel6(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawLevel6(SDL_Plotter & g, int posX,int posY)
    {
        Color color;
        color.red = 150;
        color.blue = 0;
        color.green= 0;
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, color.red, color.green, color.blue);
            }
        }
    }


/******************************************
*       int drawFloor(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
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
/******************************************
*       int drawPipe(SDL_Plotter,int,int)  *
* description: plots pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    void drawPipe(SDL_Plotter & g, int posX,int posY)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 42, 109, 31);
            }
        }
    }

};
#endif // SDL_PLOTTER_H_
