#ifndef _STRUCTS_HPP
#define _STRUCTS_HPP

/*
  This header contains all structures
 */

//Graphics
#include <SFML/Graphics.hpp>

//Structure containing all tile properties
enum TileType
{
    TYPE_OPEN = 1,
    TYPE_CLOSED = 2,
    TYPE_HIDE = 4,
    TYPE_EVENT = 8,
    TYPE_MOVABLE = 16,
    TYPE_NONE = 128
};

//Tile containing all tile properties
struct Tile
{
    TileType Type; 
    sf::Texture Texture;
    float SpeedX , SpeedY;
};

#endif
