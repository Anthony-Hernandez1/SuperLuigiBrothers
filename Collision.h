
#include "player.h"
#include "floor.h"
#include "Token.h"

using namespace std;
//checks the four corners of Mario and Enemy to see if they are touching
class Collision
{
public:
    Floor en;
    Player ma;
    Token en1;
    Floor ma1;

    bool collisionPlayer(Floor en, Player ma)
    {
        bool collision = false;
        if(((en.getPosX() == ma.getPosX()) && (en.getPosX() == (ma.getPosX() + ma.getWidth()))) ||
           ((en.getPosX() + en.getWidth() == ma.getPosX()) && (en.getPosX() + en.getWidth()) == (ma.getPosX() + ma.getWidth())))
        {

            if((en.getPosY() == (ma.getPosY()) && en.getPosY() == (ma.getPosY() + ma.getHeight()) ||
                (en.getPosY() + en.getHeight()) == ma.getPosY() && (en.getPosY() + en.getHeight()) == ma.getPosY() + ma.getHeight()))
            {
                collision=true;
            }
        }
        else {
            collision = false;
        }
        return  collision;

    }

    bool collisionCoin(Token en1, Floor ma1)
    {
        bool collision = false;
        if(((en1.getPosx() == ma1.getPosX()) && (en1.getPosx() == (ma1.getPosX() + ma1.getWidth()))) ||
           ((en1.getPosx() + en1.getWidth() == ma1.getPosX()) && (en1.getPosx() + en1.getWidth()) == (ma1.getPosX() + ma1.getWidth())))
        {

            if((en1.getPosY() == (ma1.getPosY()) && en1.getPosY() == (ma1.getPosY() + ma1.getHeight()) ||
                (en1.getPosY() + en1.getHeight()) == ma1.getPosY() && (en1.getPosY() + en1.getHeight()) == ma1.getPosY() + ma1.getHeight()))
            {
                collision=true;
            }
        }
        else {
            collision = false;
        }
        return  collision;

    }


    int getCollisionPlayer(Floor en, Player ma)
    {
        return collisionPlayer( en, ma);
    }


    int getCollisionCoin(Token en1, Floor ma1 ){


        return collisionCoin(en1,ma1);
    }
    /*void displayCollision()
    {
        if(getCollision() == true)
        {
            cout << "Enemy dead";
        }
    }*/


    bool collidesWith( Token t1, Floor &p)
    {
        bool flag;
        if(t1.getPosx() + p.getWidth() < p.getPosX()){
            flag = false;
        } else if(t1.getPosx() + p.getHeight() < p.getPosY()){
            flag = false;
        } else if(t1.getPosx() > p.getPosX() + p.getWidth()){
            flag = false;
        } else if(t1.getPosx() > p.getPosY() + p.getHeight()){
            flag =  false;
        } else {
            flag =  true;
        }
        return flag;
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



    bool collidedFloor(Token x, Floor p  )
    {
        bool collided = false;

            if(x.collidesWith(p))
            {
                collided = true;
            }
        return collided;
    }


};
