#ifndef _MAP_HPP
#define _MAP_HPP

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Util.hpp"
#include "TileSet.hpp"

class Map
{
    TileSet Set;
    int MapWidth;
    int MapHeight;
    std::vector <int> TileMap;
public:
    Map ();
    Map (const std::string& , const std::string&);

    bool loadSet (const std::string&);
    bool loadMap (const std::string&);

    void printMap ();
    void drawMap (sf::RenderWindow&);
};

#endif
