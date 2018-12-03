
#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "SDL_Plotter.h"
#include <algorithm>
#include <vector>
#include <fstream>

struct Point
{
    int x,y;
    int r,g,b;
    Point(int a = 0, int b = 0) // location for pixels
    {
        x = a;
        y = b;
    }
};

struct Color
{
    int r, g, b;

    Color()
    {
        r = g = b = 0;
    }
};

class Background
{
    private:

    public:
        vector <vector<Point> > objectBackground;
        void drawBackground(SDL_Plotter& g);
        void setBackground(string a);
};

/*
Description: This function sets vector background size and colors
Return:void
Precondition: File with correct data exists.
Postcondition: Background vector set with color and size.
*/
void Background::setBackground(string a)
{
    objectBackground.resize(1000, vector <Point>(1000));
    ifstream backgroundImage;
    backgroundImage.open(a.c_str());

    for(int i = 0; i < windowWidth; i++)
    {
        for(int j = 0; j < windowHeight; j++)
        {
            backgroundImage >> objectBackground[i][j].r >> objectBackground[i][j].g >> objectBackground[i][j].b;
            objectBackground[i][j].x = i;
            objectBackground[i][j].y = j;
        }
    }
    backgroundImage.close();
}

 /*
Description: This function uses Plotter to draw background
Return:void
Precondition: G object and SDL plotter exist
Postcondition:G object background array modified with colors.
        */
void Background::drawBackground(SDL_Plotter& g)
{
    for(int col = 0; col < windowWidth; col++)
    {
        for(int row = 0; row < windowHeight; row++)
        {
            g.plotPixel(objectBackground[row][col].y,objectBackground[row][col].x,objectBackground[row][col].r,objectBackground[row][col].g,objectBackground[row][col].b);
        }
    }
}



#endif // BACKGROUND_H_INCLUDED
