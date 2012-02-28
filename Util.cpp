#include "Util.hpp"

/*
  @brief : Convert a string to uppercase
  @String: : std::string to be converted
  @return : A reference to the String
 */

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

/*
  @brief : Copy a sf::IntRect to another sf::IntRect
  @Source : sf::IntRect to be copied
  @Buffer : sf::IntRect to receive data
 */

void Venom::copyRect (const sf::IntRect& Source , sf::IntRect& Buffer)
{
    Buffer.Left = Source.Left;
    Buffer.Top = Source.Top;
    Buffer.Width = Source.Width;
    Buffer.Height = Source.Height;
}

/*
  @brief : Load a texture safely and with a default mask
  @Path : Image path to be loaded
  @Texture : sf::Texture to loaded image data to
  @Return : Returns true on success and false on failure
 */

bool Venom::loadTexture (const std::string& Path , sf::Texture& Texture)
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
