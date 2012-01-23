#include "TileSet.hpp"

//Default constructor
TileSet::TileSet ()
{
}

//String constructor
TileSet::TileSet (const std::string& SetPath)
{
    this->loadSet (SetPath);
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
	    int i = 0;
	    TileProp Temp;
	    sf::Texture Texture;
	    
	    //Get tile name
	    In >> Temp.Name;
	    
	    //Check if tile is open
	    In >> i;
	    
	    //0 means open
	    if (i == 0)
	    {
		Temp.Open = true;
	    }
	    //1 means open
	    else if (i == 1)
	    {
		Temp.Open = false;
	    }
	    //Default is closed
	    else
	    {
		Temp.Open = false;
	    }
	    
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
