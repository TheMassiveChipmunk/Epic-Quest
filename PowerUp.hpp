#include <iostream>

#include <vector>
#include <map>

#include <SFML/Graphics.hpp>

#include "CharacterBase.hpp"

const int POWER_UPS = 3;
const int MACHINE_GUN_LIMIT = 60;

enum PowerUp
{
    POWER_UP_MACHINE_GUN , POWER_UP_ONE_UP , 
    POWER_UP_INVINCIBLE
};

PowerUp PowerArray [POWER_UPS] = 
{
    POWER_UP_MACHINE_GUN , POWER_UP_ONE_UP , 
    POWER_UP_INVINCIBLE
};

class PowerUpManager
{
    std::map <PowerUp , int> PowerMap;
    std::vector <PowerUp> PowerUpHistory;

    CharacterBase* Character;
    sf::RenderWindow* Window;
public:
    PowerUpManager (CharacterBase* , sf::RenderWindow*);

    void usePowerUp (PowerUp);
    void addPowerUp (PowerUp , int , int);
};

