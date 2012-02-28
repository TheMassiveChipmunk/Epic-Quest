#include "Venom.hpp"
#include "Point.hpp"
#include "Box.hpp"

void printPoint (const Venom::Point& Point);

int main(int argc , char* argv[])
{    
    const Venom::Box Box (34.0f , 340.0f , 40.0f , 40.0f);
    const Venom::Box Box2 (Box);

    return 0;
}

void printPoint (const Venom::Point& Point)
{
    std::cout << "(" << Point.getX () << " , " << Point.getY () << ")" << std::endl;
}
