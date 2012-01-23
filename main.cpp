#include <iostream>

#include <SFML/Graphics.hpp>

#include "Map.hpp"
#include "Util.hpp"
#include "TileSet.hpp"

const std::string MAP_FILE = "Map.txt";
const std::string SET_FILE = "TileSet.txt";

int main(int argc, char *argv[])
{
    //Video mode
    sf::VideoMode VMode (800 , 600 , 23);
    
    //Window
    sf::RenderWindow Window (VMode , "Epic-Quest");

    //Enable vertical sync
    Window.EnableVerticalSync (true);

    //Event
    sf::Event Event;

    //Map
    Map MyMap (SET_FILE , MAP_FILE);
    
    MyMap.printMap ();

    //Game loop
    while (Window.IsOpen ())
    {
	//Get events
	while (Window.PollEvent (Event))
	{
	    if (Event.Type == sf::Event::Closed)
	    {
		Window.Close ();
	    }
	}
	
	//Draw map
	MyMap.drawMap (Window);

	//Display window
	Window.Display ();
    }

    return 0;
}
