#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

//checks the four corners of Mario and Enemy to see if they are touching
bool isCollision(Enemy one, Player two)
{
    if(one.posX < two.posX + two.width && one.posX + one.width  > two.posX && one.posY < two.posY + two.height && 
       one.posY + one.height > two.posY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // COLLISION_H_INCLUDED
