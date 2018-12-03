#ifndef LEVEL1_H
#define LEVEL1_H

class Level1
{
private:
//platforms
    int width;
    int height;
    int posX;
    int posY;

public:

    Level1()
    {
        width = 20;
        height = 50;
        posX = 0;
        posY = 0;
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
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 255, 255, 255);
            }
        }
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
};
#endif // LEVEL1_H