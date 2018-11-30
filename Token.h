//
// Created by rozinskas on 11/19/2018.
//

#ifndef GROUP_PROJECT_MARIO_TOKEN_H
#define GROUP_PROJECT_MARIO_TOKEN_H
#include "SDL_Plotter.h"
#include <algorithm>

class Token {
private:
    int mPosX=150;
    int mPosY=150;
   int WIDTH = 50;
   int HEIGHT = 50;

    int mVelX = 0;
    int mVelY = 0;



public:
    
    int setPosX(int x)
    {
        mPosX=x;
    }

    int setPosY(int y ){
        mPosY=y;

    }
    int getPosx(){
        return mPosX;
    }

    int getPosY()
    {
        return mPosY;
    }
    int getWidth()
    {
        return WIDTH;
    }

    int getHeight()
    {
        return HEIGHT;
    }

    void move(int xOffset, int yOffset) {
        mPosX = min(max(mPosX + xOffset, 0), windowWidth - WIDTH);
        mPosY = min(max(mPosY + yOffset, 0), windowHeight - HEIGHT);
        mVelX = xOffset + 1;
        mVelY = yOffset - 25;
    }

    void draw1(SDL_Plotter & g)
    {
        for (int col = mPosX; col < WIDTH + mPosX; col++)   // goes through all columns
        {
            for (int row = mPosY; row < HEIGHT + mPosY; ++row)
            {
                g.plotPixel(col,row, 0,0,0);
            }
        }
    }
    
    bool collidesWith(Floor  &p)
    {
        bool flag = true;
        if((p.getPosX()+p.getHeight() < p.getPosX())|| (p.getPosY()+p.getHeight()<p.getPosY())
           || (p.getPosX() >p.getPosX()+p.getWidth()) || (p.getPosY() > p.getPosY()+p.getHeight())){
            flag = false;
        }
        return flag;
    }

    //reads from file and sets it in array
    /*void createToken()
    {
    ifstream tFile;
    tFile.open("Token.txt");
    row = 50;
    col = 50;
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            tFile >> token[r][c].R;
            tFile >> token[r][c].G;
            tFile >> token[r][c].B;
        }
    }
    tFile.close();
}*/
    

















#endif //GROUP_PROJECT_MARIO_TOKEN_H
