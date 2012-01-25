#ifndef _MAP_HPP
#define _MAP_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Util.hpp"
#include "TileSet.hpp"

#include "Structs.hpp"

const int TILE_WIDTH = 50;
const int TILE_HEIGHT = 50;

class Map
{
    //Map width and height
    int MapWidth;
    int MapHeight;
    
    //Tile set
    TileSet Set;

    //All of the sets
    std::vector <Point> Points;
public:
    Map ();
    Map (const std::string& , const std::string&);
 
    //Load map and tile set
    bool loadMap (const std::string&);
    bool loadSet (const std::string&);

    //Draw to the screen
    void draw (sf::RenderWindow&);

    //Get a point
    Point operator[] (unsigned int);
};

#endif
