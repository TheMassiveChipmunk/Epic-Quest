#include "Venom.hpp"
#include "Util.hpp"

#include "ObjectEngine.hpp"
#include "Enums.hpp"

#include <cstdlib>
#include <ctime>

/*
  The main function currently only for debugging
*/

Venom::Enums::Event Movement (sf::RenderWindow* Window)
{
    if (rand () % 20 == 4)
    {
	return Venom::Enums::SHOT | Venom::Enums::UP;
    }
    
    return Venom::Enums::UP;
}

void Collision  (sf::IntRect& Rect)
{
}

void printRect (sf::IntRect Rect)
{
    std::cerr << "(" << Rect.Left << " , " << Rect.Top << ")" << std::endl;
}

int main(int argc , char* argv[])
{
    sf::RenderWindow Window (sf::VideoMode (600 , 600 , 32) , "Hello World");

    sf::Texture Texture;
    Texture.LoadFromFile ("Data/Images/Green.png");

    sf::Sprite Sprite (Texture);
    
    Venom::ObjectEngine::BulletEngine Engine;
        
    Engine.setSpeed (0.0f , 1.0f);
    Engine.setDimensions (20.0f , 20.0f);
    Engine.setEvent (Movement);
    Engine.setCollision (Collision);
    Engine.setWindow (Window);
    
    for (unsigned int i = 0 ; i < 1000 ; i++)
    {
	Engine.update ();

	Window.Draw (Sprite);
	
	Window.Display ();

	Sprite.SetPosition (Engine.at (0).Left , Engine.at (0).Top);
	
	printRect (Engine.at (0));
    }

    return 0;
}
