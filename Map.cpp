#include "Map.hpp"

Map::Map ()
{
}

Map::Map (const std::string& Set , const std::string& Map)
{
    //Load set
    if (!this->loadSet (Set))
    {
	logMessage ("Could not load " + Set + " from constructor" , ERRORS);
    }
    else
    {
	logMessage ("Loaded " + Set + " correctly" , LOG);
    }
    //Load map
    if (!this->loadMap (Map))
    {
	logMessage ("Could not load " + Map + " from constructor" , ERRORS);
    }
    else
    {
	logMessage ("Loaded " + Set + " correctly" , LOG);
    }
}

bool Map::loadSet (const std::string& Set)
{
    //Load set
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
	logMessage ("Could not load " + Map , ERRORS);
	return false;
    }
    else
    {
	//Log
	logMessage ("Loaded " + Map + " correctly" , LOG);
	
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

bool Map::isCollision (sf::IntRect& Rect)
{
    //Iteration
    std::vector <Point>::iterator it;
    
    for (it = this->Points.begin () ; it < this->Points.end () ; it++)
    {
	//Check if the tile is in the map
	if (it->i >= 0)
	{
	    //Check tile type of the current point is closed
	    if ((this->Set [it->i]).Type & TYPE_CLOSED && !(this->Set[it->i].Type & TYPE_DEAD))
	    {
		//Temp rectangle
		sf::IntRect PointRect (it->X , it->Y , TILE_WIDTH , TILE_HEIGHT);


		//Check if it intersects
		if (PointRect.Intersects (Rect))
		{
		    //There was a collision
		    return true;
		}
	    }	
	}
    }
    
    return false;
}

void Map::inMap (const sf::RenderWindow& Window)
{
    //Iterate
    std::vector <Point>::iterator it;

    for (it = this->Points.begin () ; it < this->Points.end () ; it++)
    {
	if (it->i >= 0)
	{
	    //Check if X is in the map
	    if (it->X > Window.GetWidth () + TILE_WIDTH)
	    {
		it->i = -1;
	    } 
	    if (it->X < 0 - TILE_WIDTH)
	    {
		it->i = -1;
	    }

	    //Check if Y is in the map
	    if (it->Y < 0 - TILE_HEIGHT)
	    {
		it->i = -1;
	    }
	    if (it->Y > Window.GetHeight () + TILE_HEIGHT)
	    {
		it->i = -1;
	    }
	}
    }
}

void Map::showTypes ()
{
    //Iterate and print
    std::vector <Point>::iterator it;
    
    for (it = this->Points.begin (); it < this->Points.end () ; it++)
    {
	std::cerr << it->i << std::endl;
    }
}

void Map::draw (sf::RenderWindow& Window)
{
    //Check if we should draw the tiles
    this->inMap (Window);

    //Iterate
    std::vector <Point>::iterator it;

    for (it = this->Points.begin () ; it < this->Points.end () ; it++)
    {
	//Check if the point is in the map
	if (it->i >= 0)
	{
	    //Draw sprite
	    if (!(this->Set [it->i].Type & TYPE_HIDE) &&
		!(this->Set [it->i].Type & TYPE_DEAD))
	    {
		//Blit it to the screen
		sfBlit (this->Set.getTexture (it->i) , Window , it->X , it->Y);    
	    }
	}
    }
}

void Map::update ()
{
    //Iterate
    std::vector <Point>::iterator it;

    for (it = this->Points.begin () ; it < this->Points.end () ; it++)
    {	
	if (it->i >= 0)
	{
	    if (!(this->Set [it->i].Type & TYPE_DEAD))
	    {
		//Check if current point is moving
		if ((this->Set [it->i]).Type & TYPE_MOVABLE)
		{
		    //Moving X and Y
		    it->X += this->Set [it->i].SpeedX;
		    it->Y += this->Set [it->i].SpeedY;
		}
	    }
	}
    }
}

void Map::update (sf::IntRect& Rect , void (*Function) (sf::IntRect&))
{
    //Update movable
    this->update ();
    
    //Check for collision
    if (this->isCollision (Rect))
    {
	Function (Rect);
    }
}

Point Map::operator[] (unsigned int Index)
{
    //Return point
    return this->Points.at (Index);
}


void Map::showFlags ()
{
    //Iterator
    unsigned int i = 0;
    
    //Iterate through set
    for (i = 0 ; i < this->Set.size () ; i++)
    {
	std::cerr << i;
	if (this->Set [i].Type & TYPE_OPEN)
	{
	    std::cerr << " has the open flag on ";
	}
	if (this->Set [i].Type & TYPE_CLOSED)
	{
	    std::cerr << " has the closed flag on ";
	}
	if (this->Set [i].Type & TYPE_HIDE)
	{	    
	    std::cerr << " has the hide flag on ";
	}	
	if (this->Set [i].Type & TYPE_DEAD)
	{	    
	    std::cerr << " has the dead flag on ";
	}
	if (this->Set [i].Type & TYPE_MOVABLE)
	{
	    std::cerr << " has the movable flag on ";
	}
	
	//Print a newline
	std::cerr << std::endl;
    }
}
