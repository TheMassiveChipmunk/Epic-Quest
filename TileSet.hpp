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
const int BLOCK_MAX = 5;

//Enumeration containing tile properties
enum BlockType
{
    BLOCK_OPEN,
    BLOCK_CLOSED,
    BLOCK_HIDE,
    BLOCK_EVENT,
    BLOCK_ENEMY
};

//Array containing all blocks
const BlockType BLOCK_ARRAY [BLOCK_MAX] = 
{
    BLOCK_OPEN,
    BLOCK_CLOSED,
    BLOCK_HIDE,
    BLOCK_EVENT,
    BLOCK_ENEMY
};

//String name of all blocks
const std::string BLOCK_STRING_ARRAY [BLOCK_MAX] =
{
    "BLOCK_OPEN",
    "BLOCK_CLOSED",
    "BLOCK_HIDE",
    "BLOCK_EVENT",
    "BLOCK_ENEMY"
};

//Tile properties
typedef struct
{
    BlockType Block;
    int X , Y;
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

    BlockType getOptions (std::string&);

    bool loadSet (const std::string&);
    
    TileProp getTile (unsigned int);

    sf::Texture& getTexture (unsigned int);
};

#endif
