#ifndef _TILESET_HPP
#define _TILESET_HPP

#include <iostream>
#include <fstream>

#include <map>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Util.hpp"

//Tile properties
typedef struct
{
    bool Open;
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
    TileSet (std::string);

    bool loadSet (std::string);
    
    TileProp getTile (unsigned int);

    sf::Texture& getTexture (unsigned int);
};

#endif
