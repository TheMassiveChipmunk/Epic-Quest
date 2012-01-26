#ifndef _UTIL_HPP
#define _UTIL_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include <cctype>

const bool FILE_MODE = false;
const std::string LOG = "Log.txt";
const std::string ERRORS = "Errors.txt";

//Default mask color
#define TRANS_COLOR sf::Color (255 , 0 , 255)

typedef std::vector<std::string>::size_type size_type;

//Logs error
void logMessage (const std::string& , std::string Path = "NO_FILE");

//Sfml bliting function
void sfBlit (sf::Sprite& , sf::RenderWindow& , float , float);
void sfBlit (const sf::Texture& , sf::RenderWindow& , float , float);

//Load textures
bool loadTexture (sf::Texture& , const std::string&);

//Check if a string is a digit
bool isDigit (const std::string&);

//Make a string lowercase
std::string toUpper (std::string);

//Get info from file
std::string getFile (const std::string&);

//String Split class based off
//http://www.daniweb.com/software-development/cpp/threads/117408
 
class Splitter 
{
    std::vector <std::string> Tokens;
public:
    //Contructor
    Splitter (const std::string& , const std::string&);
    
    //Overload index operator
    std::string operator[] (size_type);
    
    //Get size
    size_type getSize ();
    
    //Split string
    void split (const std::string& , const std::string&);
};

#endif
