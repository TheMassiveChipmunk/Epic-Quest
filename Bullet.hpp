#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Graphics/Rect.hpp>

typedef struct
{
    sf::Sprite Sprite;
    sf::IntRect Position;
    float SpeedX , SpeedY;
}Bullet;

#endif
