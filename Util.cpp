#include "Util.hpp"

//Convert a string to upper case
std::string& Venom::toUpper (std::string& String)
{
    std::string::size_type i;

    //Iterate and convert each letter to uppercase
    for (i = 0 ; i < String.length () ; i++)
    {
	toupper (String [i]);
    }
    
    return String;
}


//Load a texture
bool Venom::loadTexture (const std::string& Path , 
			 sf::Texture& Texture)
{
    sf::Image Image;
    
    if (!Image.LoadFromFile (Path))
    {
	//Log a failure
	Venom::logMessage <std::string> ("Could not load : " , Path);

	return false;
    }
    else
    {
	//Log that load is correctly loaded
	Venom::logMessage <std::string> ("Loaded : " , Path);

	//Create mask
	Image.CreateMaskFromColor (Venom::MASK_COLOR);
	
	//Load texture
	if (!Texture.LoadFromImage (Image))
	{
	    //Log a failure
	    Venom::logMessage <std::string> ("Could not create an image from : " , Path);
	    
	    return false;
	}
	
	return true;
    }
}
