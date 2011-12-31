#include "CharacterBase.hpp"

bool CharacterBase::isTouchable ()
{
    //Is the user invincible
    return this->Touchable;
}

sf::IntRect* CharacterBase::getBullet (int iIndex)
{
    //Get bullet position
    return &(this->Bullets [iIndex].Position);
}

sf::IntRect* CharacterBase::getCharacter ()
{
    //Get player position
    return &(this->Position);
}
