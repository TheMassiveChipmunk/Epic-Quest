#include "TileSet.hpp"

//Default constructor
TileSet::TileSet ()
{
    this->initMap ();
}

//String constructor
TileSet::TileSet (const std::string& SetPath)
{
    this->initMap ();
    this->loadSet (SetPath);
}

//Initialize map
void TileSet::initMap ()
{
    //Iterator
    int i = 0;

    //Initialize block map
    for (i = 0 ; i < BLOCK_MAX ; i++)
    {
	this->BlockMap.insert (std::pair <std::string , BlockType> 
			       (BLOCK_STRING_ARRAY [i] , BLOCK_ARRAY [i]));
    }
}

//Load options
BlockType TileSet::getOptions (std::string& Options)
{
    //Make options uppercase
    toUpper (Options);
    
    //Return the block type
    return this->BlockMap [Options];
}

//Load tile set
bool TileSet::loadSet (const std::string& SetPath)
{
    //Input file
    std::ifstream In (SetPath.c_str ());
    
    //Check if file exists
    if (!In)
    {
	logError ("Could not load " + SetPath);
	return false;
    }
    //File exists
    else
    {
	while (In.good ())
	{
	    //Temp variables
	    TileProp Temp;
	    sf::Texture Texture;
	    std::string Options;
	    
	    //Get tile name
	    In >> Temp.Name;
	    
	    //Get tile properties 
	    In >> Options;
	    
	    //Add the options
	    Temp.Block = this->getOptions (Options);

	    //Get image path
	    In >> Temp.TexturePath;
	    
	    //Load texture
	    loadTexture (Texture , Temp.TexturePath);
	    
	    //Set texture
	    Temp.Sprite.SetTexture (Texture);
	    
	    //Add to tile vector
	    this->Tiles.push_back (Temp);

	    //Add to texture vector
	    this->TextureMap.push_back (Texture);
            
            //Add to map
            this->TileMap.insert (std::pair <std::string , TileProp> (Temp.Name , Temp));    
	}
	
        //Close file
	In.close ();
	
	//Everything is okay
	return true;
    }
    
}

//Get tile prop
TileProp TileSet::getTile (unsigned int Index)
{
    return this->Tiles.at (Index);
}

//Get texture
sf::Texture& TileSet::getTexture (unsigned int Index)
{
    return this->TextureMap.at (Index);
}
