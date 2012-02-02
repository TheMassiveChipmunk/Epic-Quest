#include "Venom.hpp"
#include "Util.hpp"

#define protected public

#include "ObjectEngine.hpp"

#include <cstdlib>
#include <ctime>

/*
  The main function currently only for debugging
*/

bool Movement (sf::RenderWindow* Window)
{
    return true;
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
    
    Venom::ObjectEngine::ObjectEngine Engine;
        
    Engine.setSpeed (1.0f , 2.0f);
    Engine.setDimensions (20.0f , 20.0f);
    Engine.setMovement (Movement);
    Engine.setCollision (Collision);
    Engine.setWindow (Window);
    
    for (int i = 0 ; i < 1000 ; i++)
    {
	Engine.update ();
	
	printRect (Engine.getPosition ());
    }

    return 0;
}
