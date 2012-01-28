#include <iostream>
#include <sstream>

#include <string>

#include "Map.hpp"
#include "TileSet.hpp"

int main(int argc, char *argv[])
{
    sf::VideoMode VMode (800 , 600 , 32);
    sf::RenderWindow Window (VMode , "Epic-Quest");

    sf::Texture Texture;
    sf::IntRect Rect (0 , 0 , TILE_WIDTH , TILE_HEIGHT);

    Texture.LoadFromFile ("Data/Images/Yellow.png");

    sf::Sprite Sprite (Texture);

    //Map
    Map MyMap ("Set.txt" , "Map.txt");

    //Debugging
    MyMap.showFlags ();
    
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
	    if (Event.Type == sf::Event::KeyPressed)
	    {
		const int SPEED = 4;
		if (Event.Key.Code == sf::Keyboard::Escape)
		{
		    Window.Close ();
		}
		if (Event.Key.Code == sf::Keyboard::Up)
		{
		    Rect.Top -= SPEED;
		}
		if (Event.Key.Code == sf::Keyboard::Down)
		{
		    Rect.Top += SPEED;
		}
		if (Event.Key.Code == sf::Keyboard::Right)
		{
		    Rect.Left += SPEED;
		}
		if (Event.Key.Code == sf::Keyboard::Left)
		{
		    Rect.Left -= SPEED;
		}
	    }
	}

	Sprite.SetPosition (Rect.Left , Rect.Top);
	MyMap.update (Rect);
	
	MyMap.draw (Window);
	Window.Draw (Sprite);

	Window.Display ();

	Window.Clear ();

	sf::Sleep (sf::Seconds (0.01));
    }
    
    return 0;
}
