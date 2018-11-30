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



    void setWidth(int w)
    {
        width = w;
    }

    int getWidth()
    {
        return width;
    }

    void setHeight(int h)
    {
        height = h;
    }

    int getHeight()
    {
        return height;
    }
};
#endif // LEVEL1_H
