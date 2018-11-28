
#include <iostream>
#include "Enemy.h"
#include "Player.h"

using namespace std;
//checks the four corners of Mario and Enemy to see if they are touching

bool isCollision(Enemy one, Player two)
{
    if(one.getPosX() >= (two.getPosX()) && one.getPosX() <= (two.getPosX() + two.getWidth) ||
       (one.getPosX() + one.getWidth()) >= two.getPosX() && (one.getPosX() + one.getWidth()) <= two.getPosX() + two.getWidth)
    {
    
    if((one.getPosY() >= (two.getPosY()) && one.getPosY() <= (two.getPosY() + two.getHeight) ||
       (one.getPosY() + one.getHeight()) >= two.getPosY() && (one.getPosY() + one.getHeight()) <= two.getPosY() + two.getHeight))
        {
        return true;
        }
    }
    return false;
}

