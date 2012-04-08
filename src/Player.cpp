#include "../include/Player.hpp"

/*
 * Default constructor for the Venom::Player class.
 */
Venom::Player::Player ()
    : Character ()
{
}

/*
 * Copy constructor for the Venom::Player class.
 */
Venom::Player::Player (const Player& Source)
    : Character (Source)
{
}
/*
 * Argument constructor for the Venom::Player class.
 */
Venom::Player::Player (Venom::Box& Position , float VelX , float VelY , float BulletVelX , 
		       float BulletVelY , float BulletWidth , float BulletHeight , sf::RenderWindow& Window)
    : Character (Position , VelX , VelY , BulletVelX , BulletVelY , BulletWidth , BulletHeight , Window)
{
}

/*
 * Default destructor for the Venom::Player class.
 */
Venom::Player::~Player ()
{
    //Nothing to do.
}


/*!
 * Default assignment operator for the Venom::Player class.
 * @param Source Player to be copied.
 */
Venom::Player& Venom::Player::operator= (const Venom::Player& Source)
{
    Character::operator= (Source);

    return *this;
}

/*
 * Handle keyboard input.
 */
void Venom::Player::handleInput ()
{
    //Allow shooting
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Space) && 
	this->Clock.getElapsedTime ().asMilliseconds () > 300)
    {
	this->attack ();
	this->Clock.restart ();
    }
    
    //Navigate though the screen
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))
    {
	this->addY (-this->VelX);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))
    {
	this->addY (this->VelX);
    }
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left))
    {
	this->addX (-this->VelY);
    }
    else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right))
    {
	this->addX (this->VelY);
    }

    Venom::keepBounds (*(this->Position) , this->Window->getSize ().x , this->Window->getSize ().y);
}
