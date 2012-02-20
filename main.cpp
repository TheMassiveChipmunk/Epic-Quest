#include "Venom.hpp"
#include "Util.hpp"
#include "Engine.hpp"
#include "Painter.hpp"

#include <cstdlib>
#include <ctime>

int main(int argc , char* argv[])
{
    srand ((unsigned) time (0));

    sf::VideoMode Mode (800 , 600 , 32);
    sf::RenderWindow Window (Mode , "Painter Test");

    sf::IntRect Rect (0.0f , 0.0f , 40.0f , 40.0f);
    sf::IntRect Rect2 (40.0f , 40.0f , 40.0f , 40.0f);

    Venom::Painter Painter (Window);
    Venom::PlayerEngine Engine (40.0f , 40.0f , 
				0.0f , -60.0f , 
				Window , Rect);

    Venom::EnemyEngine Enemy (0.0f , 2.0f , 
			      4.0f , 4.0f ,
			      Window , Rect2);

    Painter.addEngine (Engine , "/home/felix/Blue.png");
    Painter.addEngine (Engine.getBullets () , "/home/felix/Green.png");        
    
    Painter.addEngine (Enemy , "/home/felix/Green.png");
    Painter.addEngine (Enemy.getBullets () , "/home/felix/Blue.png");        

    Window.EnableVerticalSync (true);
    
    while (Window.IsOpen ())
    {
	Engine.update ();
	Enemy.update ();

	Window.Clear ();
	Painter.draw ();
	Window.Display ();	
    }

    return 0;
}
