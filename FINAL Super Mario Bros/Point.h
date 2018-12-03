
#ifndef POINT_H
#define POINT_H


struct Point
{
    int x;
    int y;

    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void setX( int x1)
    {
        x = x1;
    }

    void setY( int y1)
    {
        y = y1;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    double distance( Point& other)
    {
        return sqrt(pow(this->x -  other.getX(),2) + pow(this->y - other.getY(),2));    // calculates distance
    }
};

#endif // POINT_H
