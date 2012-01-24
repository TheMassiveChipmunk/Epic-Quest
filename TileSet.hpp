#ifndef _TILESET_HPP
#define _TILESET_HPP

#include <iostream>
#include <fstream>

#include <map>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Util.hpp"

/*
  Default tile set format 

  Name   Type(s)   Image_Path

 */


//Number of possible blocks
const int BLOCK_MAX = 6;

//Enumeration containing tile properties
enum BlockType
{
    BLOCK_OPEN = 1, 
    BLOCK_CLOSED = 2,
    BLOCK_DRAWABLE = 4,
    BLOCK_EVENT = 8,
    BLOCK_ENEMY = 16,
    BLOCK_BACKGROUND = 32
};

//Array containing all blocks
const BlockType BLOCK_ARRAY [BLOCK_MAX] = 
{
    BLOCK_OPEN, 
    BLOCK_CLOSED,
    BLOCK_DRAWABLE,
    BLOCK_EVENT,
    BLOCK_ENEMY,
    BLOCK_BACKGROUND
};

//String name of all blocks
const std::string BLOCK_STRING_ARRAY [BLOCK_MAX] =
{
    "BLOCK_OPEN",
    "BLOCK_CLOSED",
    "BLOCK_DRAWABLE"
    "BLOCK_EVENT",
    "BLOCK_ENEMY",
    "BLOCK_BACKGROUND"
};

//Tile properties
typedef struct
{
    int Block;
    std::string Name;
    sf::Sprite Sprite;
    std::string TexturePath;
}TileProp;

//Tile width and height
const int TILE_WIDTH = 50;
const int TILE_HEIGHT = 50;

//Tile set class
class TileSet
{
    std::vector <TileProp> Tiles;
    std::vector <sf::Texture> TextureMap;
    std::map <std::string , TileProp> TileMap;
    std::map <std::string , BlockType> BlockMap;
public:
    TileSet ();
    TileSet (const std::string&);        

    void initMap ();
    void showFlags (int);

    int getOptions (std::string&);

    bool loadSet (const std::string&);
    
    TileProp getTile (unsigned int);

    sf::Texture& getTexture (unsigned int);
};

#endif
