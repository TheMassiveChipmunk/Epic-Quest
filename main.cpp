#include "Venom.hpp"
#include "Point.hpp"
#include "Box.hpp"
#include "Engine.hpp"

void printPoint (const Venom::Point& Point);

int main(int argc , char* argv[])
{    
    Venom::Box Box (34.0f , 340.0f , 40.0f , 40.0f);
    Venom::Box Box2 (Box);

    Venom::Engine Engine (Box , 560.0f , 40.0f);
    const Venom::Engine Engine2 (Box , 20.0f , 10.0f);
    
    std::cout << Engine.getWidth () << std::endl;
    std::cout << Engine.getHeight () << std::endl;
    std::cout << Engine.getSpeedX () << std::endl;
    std::cout << Engine.getSpeedY () << std::endl;

    return 0;
}

void printPoint (const Venom::Point& Point)
{
    std::cout << "(" << Point.getX () << " , " << Point.getY () << ")" << std::endl;
}
