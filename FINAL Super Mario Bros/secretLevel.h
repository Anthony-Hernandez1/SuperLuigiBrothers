#ifndef SECRETLEVEL_H
#define SECRETLEVEL_H
#include <iostream>
#include "SDL_Plotter.h"
#include <stdlib.h>
using namespace std;

class Secret
{
private:
//platforms
    int width;
    int height;
    int posX;
    int posY;

public:
// what object does
//platforms

    Secret()    // constructor
    {
        width = 10;
        height = 10;
        posX = 0;
        posY = 0;
    }
    Secret(int w, int h, int pX, int pY)
    {
        width = w;
        h = height;
        pX = posX;
        pY = posY;
    }
////////******************************MUTATORS****************
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
////////////////********************** ACCESSORS***********************
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
/******************************************
*       int draw(SDL_Plotter,int,int)  *
* description: plots snowflakes pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int draw(SDL_Plotter & g, int posX,int posY)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 255, 255, 255);
            }
        }
    }
/******************************************
*       int drawSnow(SDL_Plotter,int,int)  *
* description: plots snow's pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawSnow(SDL_Plotter & g, int posX,int posY)
    {

        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 255, 255, 255);
            }
        }
    }
/******************************************
*       int drawHat(SDL_Plotter,int,int)  *
* description: plots white hat on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawHat(SDL_Plotter & g, int posX,int posY)
    {

        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 255, 255, 255);
            }
        }
    }
/******************************************
*       int drawHat2(SDL_Plotter,int,int)  *
* description: plots red hat's pixels on screen
* return: int
* pre: x/y coordinates specified
* post: returns int
******************************************/
    int drawHat2(SDL_Plotter & g, int posX,int posY)
    {

        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 255, 0, 0);
            }
        }
    }



};
#endif // SDL_PLOTTER_H_

