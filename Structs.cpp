#include "Structs.hpp"

//Enumeration operators

//Tile type | operator
TileType operator| (const TileType& First , const TileType& Second)
{
    return (TileType) ((int) First | (int) Second);
}
