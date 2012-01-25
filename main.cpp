#include <iostream>

#include "Map.hpp"
#include "TileSet.hpp"

void showFlags ()
{
    TileSet Set ("Set.txt");

    unsigned int i = 0;
    
    for (i = 0 ; i < Set.size () ; i++)
    {
	std::cerr << i;
	if (Set [i].Type & TYPE_OPEN)
	{
	    std::cerr << " has the open flag on ";
	}
	if (Set [i].Type & TYPE_CLOSED)
	{
	    std::cerr << " has the closed flag on ";
	}
	if (Set [i].Type & TYPE_HIDE)
	{	    
	    std::cerr << " has the hide flag on ";
	}	
	if (Set [i].Type & TYPE_EVENT)
	{	    
	    std::cerr << " has the event flag on ";
	}
	if (Set [i].Type & TYPE_MOVABLE)
	{
	    std::cerr << " has the movable flag on ";
	}
	
	std::cerr << std::endl;
    }
}

int main(int argc, char *argv[])
{
    sf::VideoMode VMode (800 , 600 , 32);
    sf::RenderWindow Window (VMode , "Epic-Quest");
    
    showFlags ();

    //Map
    Map MyMap ("Set.txt" , "Map.txt");
    
    //Events
    sf::Event Event;    
    
    //Enable vertical sync
    Window.EnableVerticalSync (true);

    //Game loop
    while (Window.IsOpen ())
    {
	while (Window.PollEvent (Event))
	{
	    if (Event.Type == sf::Event::Closed)
	    {
		Window.Close ();
	    }
	}
	
	Window.Clear ();
	
	MyMap.draw (Window);

	Window.Display ();
    }
    
    
    return 0;
}
