#include "Map.hpp"

Map::Map ()
{
}

Map::Map (const std::string& Set , const std::string& Map)
{
    //Load set
    if (!this->loadSet (Set))
    {
	logError ("Could not load " + Set + " from constructor" , ERRORS);
    }
    else
    {
	logError ("Loaded " + Set + " correctly" , LOG);
    }
    //Load map
    if (!this->loadMap (Map))
    {
	logError ("Could not load " + Map + " from constructor" , ERRORS);
    }
    else
    {
	logError ("Loaded " + Set + " correctly" , LOG);
    }
}

bool Map::loadSet (const std::string& Set)
{
    return (this->Set.loadSet (Set));
}

bool Map::loadMap (const std::string& Map)
{
    //Read file
    std::ifstream In (Map.c_str ());

    //Check if file exist
    if (!In)
    {
	//Log
	logError ("Could not load " + Map , ERRORS);
	return false;
    }
    else
    {
	//Log
	logError ("Loaded " + Map + " correctly" , LOG);
	
	//Temp variables
	int i = 0;
	float X = 0.0f;
	float Y = 0.0f;
	Point Temp;
	
	//Get map width and height
	In >> this->MapWidth >> this->MapHeight;
	
	//While In is good
	while (In.good ())
	{   
	    //Check if X is still in range
	    if (X == this->MapWidth)
	    {
		X = 0;
		Y++;
	    }

	    //Check if Y is still in range
	    if (Y == this->MapHeight)
	    {
		break;
	    }

	    //Get tile type
	    In >> Temp.i;
	    
	    //Set X and Y
	    Temp.X = X * TILE_WIDTH;
	    Temp.Y = Y * TILE_HEIGHT;
	    
	    //Increment
	    X++;
	    i++;

	    //Add to vector
	    this->Points.push_back (Temp);
	}

	//Close the file
	In.close ();
	
	//Everything is okay
	return true;
    }
}

void Map::draw (sf::RenderWindow& Window)
{
    //Iterate
    std::vector <Point>::iterator it;
    
    for (it = this->Points.begin () ; it < this->Points.end () ; it++)
    {
	//Draw sprite
	sfBlit (this->Set [it->i].Texture , Window , it->X , it->Y);
    }
}

Point Map::operator[] (unsigned int Index)
{
    return this->Points.at (Index);
}
