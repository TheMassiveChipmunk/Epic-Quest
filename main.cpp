#include <iostream>
#include <sstream>

#include <vector>

#include <unistd.h>

#include "Level.hpp"
#include <SFML/Audio.hpp>

const unsigned int WORLDS = 2;
const unsigned int LEVELS = 4;

int main(int argc , char* argv[])
{    
    srand ((unsigned) time (NULL));

    sf::VideoMode Mode (800 , 600 , 32);
    sf::RenderWindow Window (Mode , "Epic-Quest!");

    sf::Image Icon;
    Icon.LoadFromFile ("Data/Images/Misc/Icon.png");

    Window.EnableVerticalSync (true);
    Window.SetIcon (Icon.GetWidth () , Icon.GetHeight () , Icon.GetPixelsPtr ());

    unsigned int i = 0;
    unsigned int j = 0;
    std::stringstream Stream;
    Venom::Level Level ("Data/Maps/World-1/tileset.txt" , "Data/Maps/World-1/map-1.txt" , Window);
    
    for (i = 1 ; i < WORLDS + 1 ; i++)
    {	
	for (j = 1 ; j < LEVELS + 1 ; j++)
	{
	    while (Level.state ((j * i - 1) * 100 + j * i  * 100) == Venom::STATE_PLAYING)
	    {
		Level.update ();
		
		Window.Clear ();
		Level.draw ();

		Window.Display ();
	    }	
	    
	    if (Level.state ((j * i - 1) * 100 + j * i * 100) == Venom::STATE_DEAD)
	    {
		sleep (3);
		return 0;
	    }
	    else if (Level.state ((j * i - 1) * 100 + j * i * 100) == Venom::STATE_KILLED_ALL)
	    {
		Window.Clear (sf::Color (rand () % 255 + 1 , rand () % 255 + 1 , rand () % 255 + 1));
		
		Stream.clear ();
		
		std::string Greeting ("");
		
		Stream << "Congratulations! You have just beaten world " 
		       << i << " - " 
		       << j << "!" << std::endl
		       << "Get ready." << std::endl
		       << "3" << std::endl
		       << "2" << std::endl
		       << "1" << std::endl;
		
		std::getline (Stream , Greeting);
		
		Venom::drawText (Greeting , 30.0f , (Window.GetWidth () / 2) - 300 , (Window.GetHeight () / 2) , Window);
		
		Window.Display ();
		
		sleep (4);
		
		if (i == WORLDS && j == LEVELS)
		{
		    return 0;
		}
		
		Window.Clear (sf::Color (0 , 0 , 255));
		
		std::getline (Stream , Greeting);
		
		Venom::drawText (Greeting , 30.0f , (Window.GetWidth () / 2) - 50 , (Window.GetHeight () / 2) , Window);
		
		Window.Display ();
		
		sleep (2);
		
		Window.Clear (sf::Color (0 , 100 , 0));
		
		std::getline (Stream , Greeting);
		
		Venom::drawText (Greeting , 30.0f , (Window.GetWidth () / 2) - 25 , (Window.GetHeight () / 2) , Window);
		
		Window.Display ();
		
		sleep (1);
		
		Window.Clear (sf::Color (0 , 150 , 0));
		
		std::getline (Stream , Greeting);
		
		Venom::drawText (Greeting , 30.0f , (Window.GetWidth () / 2) - 25 , (Window.GetHeight () / 2) , Window);
		
		Window.Display ();
		
		sleep (1);
		
		Window.Clear (sf::Color (0 , 255 , 0));
		
		std::getline (Stream , Greeting);
		
		Venom::drawText (Greeting , 30.0f , (Window.GetWidth () / 2) - 25 , (Window.GetHeight () / 2) , Window);
		
		Window.Display ();
		
		sleep (1);
	    }
	    
	    std::string NextLevel ("");
	    
	    Stream.clear ();
	    
	    Stream << "Data/Maps/World-" << i << "/map-" << j + 1 << ".txt";
	    Stream >> NextLevel;

	    Level.loadMap (NextLevel);
	}

	std::string NextSet ("");
	std::string NextLevel ("");
	
	Stream.clear ();
	
	Stream << "Data/Maps/World-" << i << "/map-1.txt";
	Stream >> NextLevel;
	
	Stream.clear ();

	Stream << "Data/Maps/World-" << i + 1 << "/tileset.txt";
	Stream >> NextSet;

	Level.loadSet (NextSet);
	Level.loadMap (NextLevel);
    }
}
    
