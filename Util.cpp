#include "Util.hpp"

//Log error function
void logError (const std::string& Error , std::string Path)
{
    //Check if we are writing to a file
    if (Path != "NO_FILE" || FILE_MODE)
    {
	//Out file
	std::ofstream Out (Path.c_str () , std::ios::app);
	
	//Print error
	Out << "Error : " << Error << std::endl;
	
	//Close file
	Out.close ();
    }
    //We are writing to the console
    else
    {
	//Print error
	std::cerr << "Error : " << Error << std::endl;
    }
}

//Sfml bliting function
void sfBlit (const sf::Texture& Texture , sf::RenderWindow& Window , float X , float Y)
{
    sf::Sprite Sprite (Texture);

    Sprite.SetPosition (X , Y);

    Window.Draw (Sprite);
}

//Sfml bliting function
void sfBlit (sf::Sprite& Sprite , sf::RenderWindow& Window , float X , float Y)
{
    Sprite.SetPosition (X , Y);

    Window.Draw (Sprite);
}

//Load texture function
bool loadTexture (sf::Texture& Texture , const std::string& ImagePath)
{
    //Image to create mask and texture
    sf::Image Image;
    
    //Check if we can load the image
    if (!Image.LoadFromFile (ImagePath))
    {
	logError ("Could not load " + ImagePath);
	return false;
    }
    //Image exists
    else
    {
	//Create a mask
	Image.CreateMaskFromColor (TRANS_COLOR);
	
	//Load texture
	Texture.LoadFromImage (Image);	
	
	//Everything is okay
	return true;
    }

}

bool isDigit (const std::string& String)
{
    //Temp variable
    unsigned int i = 0;
    
    //Iterate through string and look for a non-numerical character
    for (i = 0 ; i < String.length () ; i++)
    {
	//Check we found a non-numerical character 
	if (!isdigit (String [i]))
	{
	    logError (String + " is not a number");
	    return false;
	}
    }

    //All the characters were numeric
    return true;
}

std::string getFile (const std::string& File)
{
    //Reader
    std::ifstream In (File.c_str ());
    
    //Check if file exists
    if (!In)
    {
	return "NO_FILE";
    }
    else
    {
	//File exists
	
	/*Create string that has all of the file 
	  and one that holds the current line
	 */
	std::string Total = "";
	std::string Temp = "";

	while (In.good ())
	{
	    //Read all of the file
	    
	    std::getline (In , Temp);
	    
	    //Add a new line character
	    Temp += "\n";
	    
	    //Add the line to temp
	    Total += Temp;
	}
	
	//Close the file
	In.close ();
	
	//Return total
	return Total;
    }
}

std::string toUpper (std::string String)
{
    //Temp variables
    unsigned int i = 0;

    //Make all of the string uppercase
    for (i = 0 ; i < String.size () ; i++)
    {
	String [i] = toupper (String [i]); 
    }
    
    return String;
}

/*
  Splitter class
  This is a little class that gets strings and then returns them
 */

//Splitter class
Splitter::Splitter (const std::string& String , const std::string& Delim)
{
    this->split (String , Delim);
}

//Index operator
std::string Splitter::operator[] (size_type Index)
{
    return this->Tokens.at (Index);
}

//Return the number of tokens
size_type Splitter::getSize ()
{
    return this->Tokens.size ();
}

//Split the string
void Splitter::split (const std::string& String , const std::string& Delim)
{
    //Size type variables
    std::string::size_type Start = 0;
    std::string::size_type End = 0;
    
    //Iterate through string
    while (End != std::string::npos)
    {
	//Find delimiter
	End = String.find (Delim , Start);
	
	//Get sub string of delimiter
	this->Tokens.push_back (String.substr (Start , End - Start));

	//Check next part of the string
	Start = End + Delim.size();
    }
}
