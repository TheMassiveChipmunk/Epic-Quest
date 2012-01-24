#include "TileSet.hpp"

//Default constructor
TileSet::TileSet ()
{
    this->initMap ();
    int i = 0;
 
    for (i = 0 ; i < BLOCK_MAX ; i++)
    {
	std::cerr << BLOCK_STRING_ARRAY [i] << " ";
    }
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

    for (i = 0 ; i < BLOCK_MAX ; i++)
    {
	this->BlockMap.insert (std::pair <std::string , BlockType> 
			       (BLOCK_STRING_ARRAY [i] , BLOCK_ARRAY [i]));
    }
}

//Load options
int TileSet::getOptions (std::string& Options)
{
    //Split the options
    Splitter Split (Options , "|");
    
    //Vector containing all options
    std::vector <BlockType> OptionVec;
    
    //Temp variables
    unsigned int i = 0;
    int Type;
    std::vector <BlockType>::iterator it;    

    //Get options
    for (i = 0 ; i < Split.getSize () ; i++)
    {
	OptionVec.push_back (this->BlockMap [Split [i]]);
    }

    //Add options
    for (it = OptionVec.begin () ; it < OptionVec.end () ; it++)
    {
	Type |= *it;
    }

    return Type;
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
