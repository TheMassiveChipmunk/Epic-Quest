#ifndef _CHARACTER_BASE_H
#define _CHARACTER_BASE_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "Bullet.hpp"

const int BULLET_MAX = 60;

enum GameState
{
    STATE_PLAYING , STATE_END
};

class CharacterBase
{
protected:

    friend class PowerUpManager;

    float CharacterSpeedX , CharacterSpeedY;

    float Gravity;
    
    int iBulletCounter;
    int iBulletLimit;
    
    int iLives;

    bool Touchable;
    
    Bullet Bullets [BULLET_MAX];
    sf::IntRect Position;
    
    sf::Image BulletImage;
    sf::Texture BulletTexture;
    sf::Sprite BulletSprite;

    sf::Image CharacterImage;
    sf::Texture CharacterTexture;
    sf::Sprite CharacterSprite;

    sf::RenderWindow* Window;

    virtual bool isTouchable ();
    
    virtual sf::IntRect* getCharacter ();
    virtual sf::IntRect* getBullet (int);

    virtual void draw () = 0;
    virtual void attack () = 0;
    virtual GameState update () = 0;
};

#endif
