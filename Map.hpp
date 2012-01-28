#ifndef _MAP_HPP
#define _MAP_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

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
    //Constructors
    Map ();
    Map (const std::string& , const std::string&);
 
    //Load map and tile set
    bool loadMap (const std::string&);
    bool loadSet (const std::string&);
    
    //Check for any collisions
    bool isCollision (sf::IntRect&);

    //Draw to the screen
    void draw (sf::RenderWindow&);

    //Show all of the flags
    void showFlags ();

    //Show all types
    void showTypes ();

    //Check for any tiles out of the map
    void inMap (const sf::RenderWindow&);

    //Update all closed and movable
    void update ();
    void update (sf::IntRect&);

    //Get a point
    Point operator[] (unsigned int);
};

#endif
