#include "Venom.hpp"
#include "Util.hpp"
#include "Engine.hpp"
#include "Painter.hpp"

#include <cstdlib>
#include <ctime>

int main(int argc , char* argv[])
{
    sf::VideoMode Mode (640 , 480 , 32);
    sf::RenderWindow Window (Mode , "Painter Test");

    sf::IntRect Rect (0.0f , 0.0f , 40.0f , 40.0f);

    Venom::Painter Painter (Window);
    Venom::PlayerEngine Engine (40.0f , 40.0f , 
				0.0f , 20.0f , 
				Window , Rect);

    Painter.addEngine (Engine , "/home/felix/Blue.png");
    Painter.addEngine (Engine.getBullets () , "/home/felix/Green.png");
    
    Window.EnableVerticalSync (true);
    
    while (Window.IsOpen ())
    {
	Engine.update ();

	Window.Clear ();
	Painter.draw ();
	Window.Display ();	
    }

    return 0;
}
