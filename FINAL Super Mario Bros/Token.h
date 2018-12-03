#ifndef TOKEN_H
#define TOKEN_H
#include "SDL_Plotter.h"
#include <algorithm>

class Token {
private:
    int mPosX=  50;
    int mPosY= 0;
   int WIDTH = 50;
   int HEIGHT = 50;

    int mVelX = 0;
    int mVelY = 0;



public:
    void setPosX(int x)
    {
       mPosX= x;
    }

    void setPosY(int y)
    {
        mPosY = y;
    }

    int getPosX()
    {
        return mPosX;
    }

    int getPosY()
    {
        return mPosY;
    }

    void move(int xOffset, int yOffset)
     {
        mPosX = min(max(mPosX + xOffset, 0), windowWidth - WIDTH);
        mPosY = min(max(mPosY + yOffset, 0), windowHeight - HEIGHT);
        mVelX = xOffset + 1;
        mVelY = yOffset - 10;
}

    void draw1(SDL_Plotter & g)
    {
        for (int col = mPosX; col < WIDTH + mPosX; col++)   // goes through all columns
        {
            for (int row = mPosY; row < HEIGHT + mPosY; ++row)
            {
                g.plotPixel(col,row, 255, 204, 0);
            }
        }
    }

};

#endif //TOKEN_H
