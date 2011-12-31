#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics.hpp>

const int BULLET_SPEED = 4;

struct Bullet
{
    sf::IntRect Box;
    sf::Sprite Sprite;
};

#endif
