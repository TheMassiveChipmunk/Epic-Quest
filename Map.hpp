#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Util.hpp"
#include "TileSet.hpp"

const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 100;

class Map
{
    TileSet Set;
    int MapWidth;
    int MapHeight;
    std::vector <int> TileMap;
public:
    Map ();
    Map (std::string , std::string);

    bool loadSet (std::string);
    bool loadMap (std::string);

    void printMap ();
    void drawMap (sf::RenderWindow*);
};
