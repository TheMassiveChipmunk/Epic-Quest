#include "TileSet.hpp"

TileSet::TileSet ()
{
}

TileSet::TileSet (const std::string& Path)
{
    //Check if we can load the path
    if (!this->loadSet (Path))
    {
	//Log errors
	logError ("Could not load " + Path + ", from constructor!!" , ERRORS);
    }
    //Write log
    else
    {
	logError ("Loaded " + Path + ", correctly." , LOG);
    }
    
}

TileType TileSet::getFlags (const std::string& Flags)
{
    //Tokens
    Splitter Split (Flags , "|");
    
    //Temp variable
    TileType Temp = TYPE_NONE;
    
    //Iterate through tokens
    unsigned int i = 0;
    
    for (i = 0 ; i < Split.getSize () ; i++)
    {
	//Check token type
	if (toUpper (Split [i]) == "TYPE_OPEN")
	{
	    Temp =  (TileType) (Temp | TYPE_OPEN);
	}
	if (toUpper (Split [i]) == "TYPE_CLOSED")
	{
	    Temp = (TileType) (Temp | TYPE_CLOSED);
	}
	if (toUpper (Split [i]) == "TYPE_HIDE")
	{
	    Temp = (TileType) (Temp | TYPE_HIDE);
	}
	if (toUpper (Split [i]) == "TYPE_EVENT")
	{
	    Temp = (TileType) (Temp | TYPE_EVENT);
	}
	if (toUpper (Split [i]) == "TYPE_MOVABLE")
	{
	    Temp = (TileType) (Temp | TYPE_MOVABLE);
	}
	if (toUpper (Split [i]) == "DEFAULT")
	{
	    Temp = (TileType) (Temp | TYPE_OPEN);
	}
    }

    //Return token
    return Temp;
}

/*
  Default format
  Path Type Speed
 */

bool TileSet::loadSet (const std::string& Path)
{
    std::ifstream In (Path.c_str ());
    
    //Check if file exists
    if (!In)
    {
        //Log error
	logError ("Could not load " + Path + "!!" , ERRORS);
	
        //Return false
	return false;
    }
    //Read from file
    else
    {
	//While file good
	while (In.good ())
	{
	    //Temp tile
	    Tile Block;
	    
            //Texture Path and Flag string
	    std::string TexturePath;
	    std::string Flags;
	    
	    //Loading the image

	    //Get image path
	    In >> TexturePath;
	    
	    //Load texture
	    if (!loadTexture (Block.Texture , TexturePath))
	    {
		logError ("Could not load " + TexturePath , ERRORS);
	    }
	    
	    //Get next flags
	    In >> Flags; 
	    
	    //Load flags
	    Block.Type = this->getFlags (Flags);
	
	    //Check if block has movable flag turned on
	    if (Block.Type & TYPE_MOVABLE)
	    {
		//Get speed X and Y
		In >> Block.SpeedX;
		In >> Block.SpeedY;
	    }
	    
	    //Add to vector
	    this->Types.push_back (Block);
	}
	
	//Close file
	In.close ();

	//Log
	logError ("Loaded " + Path + ", correctly" , LOG);

	//Everything is okay
	return true;
    }
}

unsigned int TileSet::size ()
{
    //Get how many tiles there are
    return this->Types.size ();
}

Tile TileSet::operator[] (unsigned int Index)
{
    //Return tile
    return this->Types.at (Index);
}
