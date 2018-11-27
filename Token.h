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
};


       /* while (true) {
            mPosX += mVelX;
            mCollider.x = mPosX;

//If the dot collided or went too far to the left or right
            if ((mPosX < 0) || (mPosX + DOT_WIDTH > windowWidth)) {
//Move back
                mPosX -= mVelX;
                mCollider.x = mPosX;
            }

//Move the dot up or down
            mPosY += mVelY;
            mCollider.y = mPosY;

//If the dot collided or went too far up or down
            if ((mPosY < 0) || (mPosY + DOT_HEIGHT > windowHeight)) {
//Move back
                mPosY -= mVelY;
                mCollider.y = mPosY;
            }
        }
    }
};

/*class Dot
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 10;

    //Initializes the variables
    Dot();

    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //Moves the dot and checks collision
    void move( SDL_Rect& wall );

    //Shows the dot on the screen
    void render();

private:
    //The X and Y offsets of the dot
    int mPosX, mPosY;

    //The velocity of the dot
    int mVelX, mVelY;

    //Dot's collision box
    SDL_Rect mCollider;
};*/

















#endif //GROUP_PROJECT_MARIO_TOKEN_H
