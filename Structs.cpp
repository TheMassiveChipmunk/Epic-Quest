#include "Structs.hpp"

//Tile type | operator
TileType operator| (const TileType& First , const TileType& Second)
{
    return (TileType) ((int) First | (int) Second);
}
