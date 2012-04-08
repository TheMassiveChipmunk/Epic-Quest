#include "../include/Util.hpp"

/*!
 * Draw text to a window.
 * @param Text Text to be drawn.
 * @param Window Window to draw to.
 */
void Venom::drawText (const std::string& Text , float Size , float X , float Y , sf::RenderWindow& Window)
{
    sf::String String (Text);
    sf::Text RenderText (String);

    RenderText.setPosition (X , Y);
    RenderText.setCharacterSize (Size);

    Window.draw (RenderText);
}


/*!
 * Sleep for X milli-seconds.
 * @param X milli-seconds to sleep.
 */
void Venom::sleep (float X)
{
    sf::Clock Clock;

    while (Clock.getElapsedTime ().asMilliseconds () < X)
    {
    }
}

/*
 * Convert a string to uppercase
 * @param String A std::string to be converted.
 * @return A reference to the String.
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

/*!
 * draw to a window.
 * @param Window Window to draw to.
 * @param Texture Texture to draw.
 * @param X X coordinate on the window.
 * @param Y Y coordinate on the window.     
 */
void Venom::blit (const sf::Texture& Texture , float X , float Y , sf::RenderWindow& Window)
{
    sf::Sprite Sprite (Texture);
    Sprite.setPosition (X , Y);
    Window.draw (Sprite);
}

/*!
 * Split an std::string by delimiters.
 * @param Vector Vector holding all of the strings.
 * @param String String to be split.
 * @param Delim Delimiters.
 */
void Venom::split (std::vector <std::string>& Vector , const std::string& String , const std::string& Delims)
{
    Vector.clear ();
    
    unsigned int Current = 0;
    unsigned int Next = -1;
    
    do
    {
	Next = String.find_first_not_of (Delims , Next + 1);

	if (Next == std::string::npos)
	{ 
	    break;
	}	   

	Next -= 1;
        Current = Next + 1;

	Next = String.find_first_of (Delims , Current);
	Vector.push_back (String.substr (Current , Next - Current));
    } 
    while (Next != std::string::npos);
}


/*
 * Load a texture safely and with a default mask.
 * @param Path Image path to be loaded.
 * @param Texture sf::Texture to loaded image data to.
 * @return Returns true on success and false on failure.
 */
bool Venom::loadTexture (const std::string& Path , sf::Texture& Texture)
{
    sf::Image Image;
    
    if (!Image.loadFromFile (Path))
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
	Image.createMaskFromColor (Venom::MASK_COLOR);
	
	//Load texture
	if (!Texture.loadFromImage (Image))
	{
	    //Log a failure
	    Venom::logMessage <std::string> ("Could not create an image from : " , Path);
	    
	    return false;
	}
	
	return true;
    }
}

/*
 * Checks for an out of bound object.
 * @param Source Box to be checked.
 * @param Width The Width of the bounds.
 * @param Height The Height of the bounds.
 * @return True if in bounds false otherwise.
 */
bool Venom::inBound (const Venom::Box& Source , float Width , float Height)
{    
    if (Source.getX () > Width - Source.getWidth ())
    {
	return false;
    }
    if (Source.getX () < 0)
    {
	return false;
    }

    if (Source.getY () > Height - Source.getHeight ())
    {
	return false;
    }
    if (Source.getY () < 0)
    {
	return false;
    }

    return true;
}

/*
 * Keep object in bounds.
 * @param Box The box to be checked.
 * @param Width The width to be checked.
 * @param Height The height to be checked.
 */
void Venom::keepBounds (Venom::Box& Box , unsigned int Width , unsigned int Height)
{
    //Variables for easy of use.
    float X = Box.getX ();
    float Y = Box.getY ();
    float BWidth = Box.getWidth ();
    float BHeight = Box.getHeight ();

    if (X >= Width - BWidth)
    {
	X = Width - BWidth;
    }
    if (X <= 0)
    {
	X = 0;
    }

    if (Y >= Height - BHeight)
    {
	Y = Height - BHeight;
    }
    if (Y <= 0)
    {
	Y = 0;
    }

    Box.set (X , Y);
}
