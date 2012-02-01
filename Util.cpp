#include "Util.hpp"

/*    Splitter class    */

/*
  @Params : None
  @Type : Constructor
  @Return Value : None 
*/

Util::Splitter::Splitter ()
{
    //Not much to implement we will leave it empty for now
}


/*
  @Params : String to be split and delimeter
  @Type : Overloaded Constructor
  @Return Value : None 
*/

Util::Splitter::Splitter (const std::string& String , 
				 const std::string& Delim)
{
    //Just call the split function with the passed arguments
    this->split (String , Delim);
}

/*
  @Params : None
  @Type : Class Method
  @Return Value : unsigned integer
*/

unsigned int Util::Splitter::size ()
{
    //Return the vector size
    return this->Tokens.size ();
}

/*
  @Params : Index
  @Type : Class Method
  @Return Type : std::string
 */

std::string Util::Splitter::at (unsigned int Index)
{
    //Return the token
    return this->Tokens.at (Index);
}

/*
  @Params : String to be split and delimeter
  @Type : Class Method
  @Return Type : void
*/

void Util::Splitter::split (const std::string& String , 
				   const std::string& Delim)
{
    //Clear the tokens
    this->Tokens.clear ();
    
    //Start of the string
    unsigned int Start = 0;

    //End of the string
    unsigned int End = 0;
    
    //Iterate through string
    while (End != std::string::npos)
    {
	//Find delimiter
	End = String.find (Delim , Start);
	
	//Get sub string of delimiter and it to the tokens
	this->Tokens.push_back (String.substr (Start , End - Start));
	
	//Check next part of the string
	Start = End + Delim.size();
    }
    
}

/*
  @Params : Index
  @Type : Class overloaded index operator
  @Return Type : std::string
*/

std::string Util::Splitter::operator[] (unsigned int Index)
{
    //Return the tokens
    return this->Tokens.at (Index);
}


/*    Debugging functions    */


/*
  @Params : Message
  @Type : Namespace function
  @Return Type : void
 */

void Util::logMessage (const std::string& Message)
{
    //Check if we are writing to a file
    if (FILE_MODE)
    {
	//Stream to write to
	std::ofstream Stream (LOG_FILE.c_str () , std::ios::app);
	
	//Check if the file was loaded
	if (!Stream)
	{
	    return;
	}	
	
	//Write message
	Stream << "MESSAGE : " << Message << "." << std::endl;
	
	//Close the stream
	Stream.close ();
    }
    //We are writing to the console
    else
    {
	std::cerr << "MESSAGE : " << Message << "." << std::endl;
    }
}

/*    Graphics functions    */

/*
  @Params : Texture , Window , X and Y
  @Type : Namespace function
  @Return Type : void
*/

void Util::sfBlit (const sf::Texture& Texture , 
	     sf::RenderWindow& Window , 
	     float X , float Y)
{
    //Temp sprite
    sf::Sprite Sprite (Texture);

    //Set sprite position
    Sprite.SetPosition (X , Y);

    //Finally draw it to the window
    Window.Draw (Sprite);
}

/*
  @Params : Texture and Texture path
  @Type : Namespace functions
  @Return Type : boolean
*/

bool Util::loadTexture (sf::Texture& Texture ,
		  const std::string& Path)
{
    //Create an image
    sf::Image Image;

    //Check if the image was loaded properly
    if (!Image.LoadFromFile (Path))
    {
	//Log a message
	Util::logMessage ("Could not load " + Path);

	//Image was not loaded
	return false;
    }

    //Create a mask for image
    Image.CreateMaskFromColor (MASK_COLOR);
    
    //Check if texture was loaded properly
    if (!Texture.LoadFromImage (Image))
    {
	//Log a message
	Util::logMessage ("Could not make a texture from " + Path);

	//Texture was not loaded
	return false;
    }

    //Everything is okay
    return true;
}

/*    String manipulation    */


/*
  @Params : String to be changed
  @Type : Namespace function
  @Return Type : std::string&
*/

std::string& Util::toUpper (std::string& String)
{
    //Iterator
    unsigned int i = 0;

    //Go though entire string
    for (i = 0 ; i < String.length () ; i++)
    {
	//Make the current character uppercase
	String [i] = toupper (String [i]);
    }

    //Return the new string
    return String;
}

/*
  @Params : String to be checked
  @Type : Namespace function
  @Return Type : boolean
*/

bool Util::isDigit (const std::string& String)
{
    //Iterator
    unsigned int i = 0;
    
    //Check the entire string
    for (i = 0 ; i < String.length () ; i++)
    {
	//Check if the current character is not a number
	if (!isdigit (String [i]))
	{
	    //The character is a letter
	    return false;
	}
    }

    //All of the characters were numbers
    return true;
}
