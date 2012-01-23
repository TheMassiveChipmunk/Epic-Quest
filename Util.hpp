#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <fstream>

#include <string>

#include <SFML/Graphics.hpp>

#include <cctype>

//Default mask color
#define TRANS_COLOR sf::Color (255 , 0 , 255)

//Logs error
void logError (std::string , std::string Path = "NO_FILE");

//Sfml bliting function
void sfBlit (sf::Texture& , sf::RenderWindow* , int , int);

//Load textures
bool loadTexture (sf::Texture& , std::string);

//Check if a string is a digit
bool isDigit (std::string);

//Get info from file
std::string getFile (std::string);

#endif
