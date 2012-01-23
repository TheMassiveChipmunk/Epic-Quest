#include "Util.hpp"

//Log error function
void logError (std::string Error , std::string Path)
{
    //Check if we are writing to a file
    if (Path == "NO_FILE")
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
void sfBlit (sf::Texture& Texture , sf::RenderWindow* Window , int X , int Y)
{
    sf::Sprite Sprite (Texture);

    Sprite.SetPosition (X , Y);

    Window->Draw (Sprite);
}

//Load texture function
bool loadTexture (sf::Texture* Texture , std::string ImagePath)
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
	Texture->LoadFromImage (Image);	
	
	//Everything is okay
	return true;
    }

}

bool isDigit (std::string String)
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

std::string getFile (std::string File)
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