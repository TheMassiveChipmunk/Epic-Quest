#ifndef _TILESET_HPP
#define _TILESET_HPP

#include <iostream>
#include <fstream>

#include <map>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Util.hpp"

//Enumeration containing tile properties
enum BlockType
{
    BLOCK_OPEN = 1 , 
    BLOCK_CLOSED = 2 ,
    BLOCK_DRAWABLE = 4 ,
    BLOCK_EVENT = 8 ,
    BLOCK_ENEMY = 16 ,
    BLOCK_BACKGROUND = 32
};

//Tile properties
typedef struct
{
    BlockType Tile;
    std::string Name;
    sf::Sprite Sprite;
    std::string TexturePath;
}TileProp;

//Tile width and height
const int TILE_WIDTH = 50;
const int TILE_HEIGHT = 50;

/*
  Default tile set format 

  Name   Open?   Image_Path

 */

//Tile set class
class TileSet
{
    std::vector <TileProp> Tiles;
    std::vector <sf::Texture> TextureMap;
    std::map <std::string , TileProp> TileMap;
public:
    TileSet ();
    TileSet (const std::string&);

    bool loadSet (const std::string&);
    
    TileProp getTile (unsigned int);

    sf::Texture& getTexture (unsigned int);
};

#endif
