#include "Map.hpp"

//Default constructor
Map::Map ()
{
    this->MapWidth = 0;
    this->MapHeight = 0;
}

//Loads map and tile set
Map::Map (std::string Set , std::string Map)
{
    this->loadSet (Set);
    this->loadMap (Map);
}

//Loads set
bool Map::loadSet (std::string Set)
{
    return this->Set.loadSet (Set);
}

//Loads map
bool Map::loadMap (std::string Map)
{
    //Map reader
    std::ifstream In (Map.c_str ());
    
    //Check if file exist
    if (!In)
    {
	//File does not exist return an error
	logError ("Map " + Map + " does not exist");
	return false;
    }
    else
    {
	//File does exist

	//Get map width and height
	In >> this->MapWidth;
	In >> this->MapHeight;

	std::cerr << this->MapWidth << " X " << this->MapHeight << std::endl;
	
	//Fill tile map
	while (In.good ())
	{
	    //Temp variable
	    int i = 0;
	    
	    In >> i;
	    
	    //Add it to the vector
	    this->TileMap.push_back (i);
	}
	
	//Close file
	In.close ();

	//Everything is okay
	return true;
    }
}

//Prints map
void Map::printMap ()
{
    //Iterator variables
    int i = 0;
    std::vector <int>::iterator it;

    //Print Width and Height
    std::cerr << this->MapWidth << " X "  
	      << this->MapHeight << std::endl;
    
    for (it = this->TileMap.begin () ; it < this->TileMap.end () ; it++)
    {
	//Display current
	std::cerr << *it << " ";
	
	//Add a new line
	if (i == this->MapWidth)
	{
	    i = 0;
	    std::cerr << std::endl;
	}
	
	i++;
    }
}

void Map::drawMap (sf::RenderWindow* Window)
{    
    //Iterators
    std::vector <int>::iterator it;
    int X = 0;
    int Y = 0;

    //Iterate through vector
    for (it = this->TileMap.begin () ; it < this->TileMap.end () ; it++)
    {	
	//Draw the sprite
	sfBlit (this->Set.getTexture (*it) , Window , X * TILE_WIDTH , Y * TILE_HEIGHT);
	X++;
	
        //Check if we drew a row
	if (X == this->MapWidth)
	{
	    X = 0;
	    Y++;
	}
	//Check if we drew everything
	if (Y == this->MapHeight)
	{
	    return;
	}

    }
}
