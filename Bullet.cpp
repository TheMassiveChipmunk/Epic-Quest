#include "Bullet.hpp"

/*
 * Default bullet constructor for the Venom::Bullet class.
 */
Venom::Bullet::Bullet ()
    : Engine ()
{
    //Just call base constructor.
}

/*
 * Copy constructor for the Venom::Bullet class.
 * @param Source Bullet engine to be copied.
 */
Venom::Bullet::Bullet (const Bullet& Source)
    : Engine (Source) ,
      Width (Source.Width) , 
      Height (Source.Height)
{
}

/*
 * Argument constructor for the Venom::Bullet class.
 * @param Position A reference to a position on the screen.
 * @param VelX The X velocity of the bullet.
 * @param VelY The Y velocity of the bullet.
 * @param Width Bullet Width.
 * @param Height Bullet Height.
 * @param Window Window to get input from.
 */
Venom::Bullet::Bullet (Venom::Box& Position , float VelX , float VelY , float Width , float Height , sf::RenderWindow& Window)
    : Engine (Position , VelX , VelY , Window) ,
      Width (Width) , 
      Height (Height)

{
}

/*
  Default destructor for the Venom::Bullet class.
*/
Venom::Bullet::~Bullet ()
{
    //Nothing to do
}


/*!
 * Default assignment operator for the Venom::Bullet class.
 * @param Source Bullet to be copied.
 */
Venom::Bullet& Venom::Bullet::operator= (const Venom::Bullet& Source)
{
    Engine::operator= (Source);
    this->Width = Source.Width; 
    this->Height = Source.Height;

    return *this;
}
/*
 * Get the amount of bullets shot for const Venom::Bullet objects.
 * @return The amount of bullets shot.
 */
std::size_t Venom::Bullet::size () const
{
    return this->Points.size ();
}

/*
 * Get the amount of bullets shot.
 * @return The amount of bullets shot.
 */
std::size_t Venom::Bullet::size ()
{
    return static_cast <const Venom::Bullet&> (*this).size ();
}

/*
 * Gets a bullet at a specified index for const Venom::Box objects.
 * @param Index The bullet to get.
 * @return A const Venom::Box containing a bullets point.
 */
const Venom::Box& Venom::Bullet::at (std::size_t Index) const
{
    return this->Points.at (Index);
}

/*
 * Gets a bullet at a specified index.
 * @param Index The bullet to get.
 * @return A const Venom::Box containing a bullets point.
 */
const Venom::Box& Venom::Bullet::at (std::size_t Index)
{
    return static_cast <const Venom::Bullet&> (*this).at (Index);
}

/*
 * Update physics
 */
void Venom::Bullet::update ()
{
    std::vector <Venom::Box>::iterator it;

    //Update all shot bullets.
    for (it = this->Points.begin () ; it != this->Points.end () ; it++)
    {
	it->add (this->VelX , this->VelY);
    }

    this->SpeedX = 0.0f;
    this->SpeedY = 0.0f;

    //Delete any bullets out side of the map
    for (it = this->Points.begin () ; it != this->Points.end () ; it++)
    {
	if (!Venom::inBound (*it , this->Window->GetWidth () , this->Window->GetHeight ()))
	{
	    if (this->Points.size () > 1)
	    {
		this->Points.erase (it);
		break;
	    }
	}
    }
}

/*
 * Handle input.
 */
void Venom::Bullet::handleInput ()
{
    //Nothing to do
}

/*
 * Add a bullet to the Points vector.
 */
void Venom::Bullet::attack ()
{
    //Add a bullet to the bullet vector.
    if (this->VelY < 0)
    {
	this->Points.push_back (Venom::Box 
				(this->Position->getX () , 
				 this->Position->getY () - 0.5f * this->Position->getHeight () ,
				 this->Position->getWidth () ,
				 this->Position->getHeight ()));
    }
    else
    {
	this->Points.push_back (Venom::Box 
				(this->Position->getX () , 
				 this->Position->getY () + 0.5f * this->Position->getHeight () ,
				 this->Position->getWidth () ,
				 this->Position->getHeight ()));
    }
}
