/*#ifndef COLLISION_H
#define COLLISION_H
#include "Enemy.h"
#include "Player.h"

class Collision
{
    public:
    Enemy en;
    Player ma;
    bool collision(Enemy &en, Player &ma)
    {
        bool collision = false;
        if(((en.getPosX() == ma.getPosX()) && (en.getPosX() == (ma.getPosX() + ma.getWidth()))) ||
       ((en.getPosX() + en.getWidth() == ma.getPosX()) && (en.getPosX() + en.getWidth()) == (ma.getPosX() + ma.getWidth())))
        {

    if((en.getPosY() == (ma.getPosY()) && en.getPosY() == (ma.getPosY() + ma.getHeight()) ||
       (en.getPosY() + en.getHeight()) == ma.getPosY() && (en.getPosY() + en.getHeight()) == ma.getPosY() + ma.getHeight()))
        {
            return true;
        }
    }
      else
            return false;

    }

    int getCollision()
    {
        return collision( en, ma);
    }
    void displayCollision()
    {
        if(getCollision() == true)
        {
            cout << "Enemy dead";
        }
    }
};
#endif // COLLISION_H*/
