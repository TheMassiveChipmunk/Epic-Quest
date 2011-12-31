#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "Bullet.hpp"
#include "CharacterBase.hpp"

class Player : protected CharacterBase
{
public:
    Player (sf::RenderWindow* Window , sf::Image , sf::Image , sf::IntRect , 
	    sf::IntRect , float , float , float , float , float);

    bool CanShoot;

    void draw ();
    void attack ();
    void reload ();
    GameState update ();
};

#endif
