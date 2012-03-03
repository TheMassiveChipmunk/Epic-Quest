#include "Venom.hpp"
#include "Point.hpp"
#include "Box.hpp"
#include "Engine.hpp"

void printPoint (const Venom::Point& Point);

int main(int argc , char* argv[])
{
    return 0;
}

void printPoint (const Venom::Point& Point)
{
    std::cout << "(" << Point.getX () << " , " << Point.getY () << ")" << std::endl;
}
