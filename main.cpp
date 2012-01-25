#include <iostream>

#include "Map.hpp"
#include "TileSet.hpp"

int main(int argc, char *argv[])
{
    sf::VideoMode VMode (800 , 600 , 32);
    sf::RenderWindow Window (VMode , "Epic-Quest");

    Map MyMap ("Set.txt" , "Map.txt");
    
    sf::Event Event;

    Window.EnableVerticalSync (true);

    while (Window.IsOpen ())
    {
	while (Window.PollEvent (Event))
	{
	    if (Event.Type == sf::Event::Closed)
	    {
		Window.Close ();
	    }
	}
	
	MyMap.draw (Window);

	Window.Display ();
    }
    
    
    return 0;
}
