#include "PowerUp.hpp"

PowerUpManager::PowerUpManager (CharacterBase* Character , sf::RenderWindow* Window)
{
    //Set Character
    this->Character = Character;
    this->Window = Window;

    //Temp Counter
    int i = 0;

    //Initialize Power Map    
    for (i = 0 ; i < POWER_UPS ; i++)
    {
	this->PowerMap [PowerArray [i]] = i;
    }
}

void PowerUpManager::usePowerUp (PowerUp Power)
{
    //Check what type of power up
    if (this->PowerMap [Power] == 0)
    {
	//Character gets machine gun
	this->Character->iBulletLimit = MACHINE_GUN_LIMIT;
    }
}

void PowerUpManager::addPowerUp (PowerUp , int , int)
{
    //
}
