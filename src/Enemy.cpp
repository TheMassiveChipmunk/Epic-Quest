#include "../include/Enemy.hpp"

/*
 * Default constructor for the Venom::Enemy class.
 */
Venom::Enemy::Enemy ()
    : Character ()
{
    this->Clock.restart ();
}

Venom::Enemy::Enemy (const Venom::Enemy& Source)
    : Character (Source)
{
    this->Clock.restart ();
}

/*
 * Argument constructor for the Venom::Enemy class.
 * @param Position Player Position.
 * @param VelX Player X velocity.
 * @param VelY Player Y velocity.
 * @param BulletVelX Bullet X velocity.
 * @param BulletVelY Bullet Y velocity.
 * @param BulletWidth Bullet Width.
 * @param BulletHeight Bullet Height.
 * @param Window Window to get input from.
 */
Venom::Enemy::Enemy (Venom::Box& Position , float VelX , float VelY , float BulletVelX , 
		     float BulletVelY , float BulletWidth , float BulletHeight , sf::RenderWindow& Window)    
    : Character (Position , VelX , VelY , BulletVelX , BulletVelY , BulletWidth , BulletHeight , Window)
{
    //Call argument constructors.
}


/*!
 * Default destructor
 */
Venom::Enemy::~Enemy ()
{
}


/*!
 * Default assignment operator.
 * @param Source Enemy to be copied.
 */
Venom::Enemy& Venom::Enemy::operator= (const Venom::Enemy& Source)
{
    Character::operator= (Source);

    return *this;
} 

/*!
 * Check if we should shoot and update X and Y coordinates.
 */
void Venom::Enemy::handleInput ()
{    
    if (this->Clock.getElapsedTime ().asMilliseconds () > (rand () % 3000) + 1000)
    {
	this->attack ();
	this->Clock.restart ();
    }

    this->add (this->VelX , this->VelY);
}
