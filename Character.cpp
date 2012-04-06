#include "Character.hpp"

/*
 * Default constructor for the Venom::Character class.
 */
Venom::Character::Character ()
    : Engine () , Bullets ()
{
    //Call default constructors
}

/*
 * Copy constructor for the Venom::Character class.
 */
Venom::Character::Character (const Venom::Character& Source)
    : Engine (Source) , Bullets (Source.Bullets)
{
    //Call copy constructors
}

/*
 * Argument constructor for the Venom::Character class.
 * @param Position Character Position.
 * @param VelX Character X velocity.
 * @param VelY Character Y velocity.
 * @param BulletVelX Bullet X velocity.
 * @param BulletVelY Bullet Y velocity.
 * @param BulletWidth Bullet Width.
 * @param BulletHeight Bullet Height.
 * @param Window Window to get input from.
 */
Venom::Character::Character (Venom::Box& Position , float VelX , float VelY , float BulletVelX , 
			     float BulletVelY , float BulletWidth , float BulletHeight , sf::RenderWindow& Window)
    : Engine (Position , VelX , VelY , Window) , 
      Bullets (Position , BulletVelX , BulletVelY , BulletWidth , BulletHeight , Window)
{
    //Call argument constructors.
}

/*!
 * Default destructor.
 */
Venom::Character::~Character ()
{
}


/*!
 * Default assignment operator for the Venom::Character class.
 * @param Source Character to be copied.
 */
Venom::Character& Venom::Character::operator= (const Venom::Character& Source)
{
    Engine::operator= (Source);

    this->Bullets = Source.Bullets;

    return *this;
}

/*
 * Shoot bullets.
 */
void Venom::Character::attack ()
{
    this->Bullets.attack ();
}

/*
 * Update physics, input, and movement.
 */
void Venom::Character::update ()
{
    this->Bullets.update ();
    this->handleInput ();
}

/*
 * Get amount of bullets for const Venom::Character objects.
 * @return Amount of bullets.
 */
std::size_t Venom::Character::size () const
{
    return this->Bullets.size ();
}

/*
 * Get amount of bullets.
 * @return Amount of bullets.
 */
std::size_t Venom::Character::size ()
{
    return static_cast <const Venom::Character&> (*this).size ();
}

/*
 * Get a bullet's position for const Venom::Character objects.
 * @param Index The bullet to get.
 * @return A bullet's position.
 */
const Venom::Box& Venom::Character::at (std::size_t Index) const
{
    return this->Bullets.at (Index);
}

/*
 * Get a bullet's position.
 * @param Index The bullet to get.
 * @return A bullet's position.
 */
const Venom::Box& Venom::Character::at (std::size_t Index)
{
    return static_cast <const Venom::Character&> (*this).at (Index);
}
