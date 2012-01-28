#ifndef _TILESET_HPP
#define _TILESET_HPP

#include <iostream>

#include <vector>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "Util.hpp"
#include "Structs.hpp"

class TileSet
{
    //Vector containing all possible tiles
    std::vector <Tile> Types;
public:
    //Constructors
    TileSet ();
    TileSet (const std::string&);

    //How many tiles
    unsigned int size ();

    //Get a texture
    sf::Texture& getTexture (unsigned int);
    
    //Get tile
    Tile& operator[] (unsigned int);
    
    //Load tiles
    bool loadSet (const std::string&);

    //Get flags
    TileType getFlags (const std::string&);
};

#endif
