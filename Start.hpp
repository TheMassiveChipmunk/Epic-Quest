#ifndef _START_SCREEN_H
#define _START_SCREEN_H

#include <iostream>
#include <string> 

#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

const int ROTATION_LIMIT = 5;
const int ROTATION_START = 4;
const int SCALE_LIMIT = 5;
const int SCALE_START = 1;

enum Option
{
    OPTION_START , OPTION_ABOUT , 
    OPTION_CREDITS , OPTION_HELP , OPTION_NONE
};

Option startScreen (sf::RenderWindow* , sf::SoundBuffer*);

bool type (int);

#endif
