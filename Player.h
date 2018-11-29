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
    int row = 50;
    int col = 50;
    
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
    Color player[50][50];
    
    void createPlayer()
    {
        ifstream pFile;
        
        pFile.open("Mario.txt");
        
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
    
    /*
    need to update this draw to get the image from file to update
    void draw(SDL_Plotter& g)
    {
        erase(g);
        for(int y =0 ; y < row;y++)
        {
            for(int x = 0; x < col; x++)
            {

            if(player[y][x].R == 255 && player[y][x].G == 255 && player[y][x].B == 255)
            {
                player[y][x].R = background[loc.x+x][loc.y+y].R;
                player[y][x].G = background[loc.x+x][loc.y+y].G;
                player[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,player[y][x].R, player[y][x].G, player[y][x].B);
        }
    }
    }
    */

};
#endif // SDL_PLOTTER_H_
