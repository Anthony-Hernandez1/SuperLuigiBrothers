#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <algorithm>
#include "SDL_Plotter.h"
using namespace std;


const int windowHeight = 600;
const int windowWidth = 1000;

class Player
{
private:
// what makes object up

    // velocity of dot
    int velX,
        velY;
    int width = 74;
    int height = 22;
    int posX = 200;
    int posY = 200;
    int hp;


public:
    SDL_Rect positionRect;

// what object does

    void movePlayer(int xOffset, int yOffset)   // allows you to move
    {
        //posX = min(max(posX + xOffset, 0), windowWidth - width);   // allows object to move, max width, does not allow player to go off screen
        //posY = min(max(posY + yOffset, 0), windowHeight - height);
        posX = min(max(posX + xOffset, 0), windowWidth - width );
        posY = min(max(posY + yOffset, 0), windowHeight - height - 40);//allows object to move, max height changes to account for the floor
        velX = posX -5;
    }


    // draws dot on screen
    void draw(SDL_Plotter & g)
    {
        for (int col = posX; col < width + posX; col++)   // goes through all columns
        {
            for (int row = posY; row < height + posY; ++row)
            {
                g.plotPixel(col,row, 23,10,204);
            }
        }
    }
//sets health of player (MUTATORS)
    void setHealth(int h)
    {
        hp = h;
    }

    void setPosX(int x)
    {
        posX = x;
    }

    void setPosY(int y)
    {
        posY = y;
    }
//MUTATORS
    int getPosX()
    {
        return posX;
    }

    int getPosY()
    {
        return posY;
    }
    
    int getWidth()
    {
        return width;
    }
    
    int getHeight()
    {
        return height;
    }

    void jump()
    {

    }
    
    void createPlayer(string a)
    {
        ifstream pFile;
        
        pFile.open("Mario.txt");
        
        row = 50;
        col = 50;
        
        for(int r = 0; r < row; r++)
        {
            for(int c = 0; c < col; c++)
            {
                pFile >> player[r][c].R;
                pFile >> player[r][c].G;
                pFile >> player[r][c].B;
            }
        }
        pFile.close();
    }

};
#endif // SDL_PLOTTER_H_
