#include "Engine.hpp"

/*!
 * Default constructor for Venom::Engine.
*/

Venom::Engine::Engine ()
    : Position (0) , 
      SpeedX (0.0f) , 
      SpeedY (0.0f)
{
}


/*!
 * Copy constructor for Venom::Engine.
 * @param Source Engine to be copied.
*/

Venom::Engine::Engine (const Engine& Source)
    : Position (Source.Position) , 
      SpeedX (Source.SpeedX) , 
      SpeedY (Source.SpeedY) 
{
}

/*!
 * Argument constructor for Venom::Engine.
 * @param Position Box position.
 * @param SpeedX The X Speed.
 * @param SpeedY The Y Speed.
*/

Venom::Engine::Engine (Venom::Box& Position , float SpeedX , float SpeedY)
    : Position (&Position) ,
      SpeedX (SpeedX) ,
      SpeedY (SpeedY)
{
}

/*!
 * Default constructor for Venom::Engine.
*/

Venom::Engine::~Engine ()
{
    //Nothing to do
}

/*!
 * Move the X coordinate.
 * @param X The X Speed.
 * @return The new X coordinate.
*/

float Venom::Engine::addX (float X)
{
    this->Position->addX (X);
    
    return this->Position->getX ();
}


/*!
 * Move the Y coordinate.
 * @param Y The Y Speed.
 * @return : The new Y coordinate.
*/

float Venom::Engine::addY (float Y)
{
    this->Position->addY (Y);
    
    return this->Position->getX ();
}

/*!
 * Move the X and Y coordinates.
 * @param X The X Speed.
 * @param Y The Y Speed.
*/

void Venom::Engine::move (float X , float Y)
{
    this->addX (X);
    this->addY (Y);
}

/*!
 * Set X coordinate.
 * @return The new X coordinate.
*/

float Venom::Engine::setX (float X)
{
    this->Position->setX (X);
    
    return this->Position->getX ();
}


/*!
 * Set Y coordinate.
 * @return The new Y coordinate.
*/

float Venom::Engine::setY (float Y)
{
    this->Position->setY (Y);
    
    return this->Position->getY ();
}

/*!
 * Set X and Y coordinates.
 * @param X The new X coordinate.
 * @param Y The new Y coordinate.
*/

void Venom::Engine::set (float X , float Y)
{
    this->setX (X);
    this->setY (Y);
}


/*!
 * Set X and Y coordinates.
 * @param Position The new Position. 
*/

void Venom::Engine::set (const Venom::Point& Position)
{
    this->Position->set (Position);
}

/*!
 * Set X speed.
 * @param SpeedX The new X speed.
 * @return The new X speed.
*/

float Venom::Engine::setSpeedX (float SpeedX)
{
    this->SpeedX = SpeedX;
    
    return this->SpeedY;
}

/*!
 * Set Y speed
 * @param SpeedY The new Y speed.
 * @return The new Y speed.
*/

float Venom::Engine::setSpeedY (float SpeedY)
{
    this->SpeedY = SpeedY;
    
    return this->SpeedY;
}

/*!
 * Set X and Y speed.
 * @param SpeedX The new X speed.
 * @param SpeedY The new Y speed.
*/

void Venom::Engine::setSpeed (float SpeedX , float SpeedY)
{
    this->setSpeedX (SpeedX);
    this->setSpeedY (SpeedY);
}

/*!
 * Get speed X for const Venom::Engine objects.
 * @return SpeedX.
*/

float Venom::Engine::getSpeedX () const
{
    return this->SpeedX;
}

/*!
 * Get speed Y for const Venom::Engine objects.
 * @return SpeedY.
*/

float Venom::Engine::getSpeedY () const
{
    return this->SpeedY;
}


/*!
 * Get speed X.
 * @return SpeedX.
*/

float Venom::Engine::getSpeedX ()
{
    return static_cast <const Venom::Engine&> (*this).getSpeedX ();
}

/*!
 * Get speed Y.
 * @return SpeedY.
*/

float Venom::Engine::getSpeedY ()
{
    return static_cast <const Venom::Engine&> (*this).getSpeedY ();
}


/*!
 * Get X position for const Venom::Engine objects.
 * @return The X position.
*/

float Venom::Engine::getX () const
{
    return this->Position->getX ();
}

/*!
 * Get Y position for const Venom::Engine objects.
 * @return The Y position.
*/

float Venom::Engine::getY () const
{
    return this->Position->getY ();
}

/*!
 * Get position for const Venom::Engine objects.
 * @return Box's Position.
*/

const Venom::Box& Venom::Engine::get () const
{
    return *(this->Position);
}

/*!
 * Get X coordinate.
 * @return The X coordinate.
*/

float Venom::Engine::getX ()
{
    return static_cast <const Venom::Engine&> (*this).getX ();
}


/*!
 * Get Y.
 * @return The Y coordinate.
*/

float Venom::Engine::getY ()
{
    return static_cast <const Venom::Engine&> (*this).getY ();
}

/*!
 * Get position.
 * @return position.
*/

const Venom::Box& Venom::Engine::get ()
{
    return static_cast <const Venom::Engine&> (*this).get ();
}

/*!
 * Set Width.
 * @return The new Width.
*/

float Venom::Engine::setWidth (float Width)
{
    this->Position->setWidth (Width);
    
    return this->Position->getWidth ();
}

/*!
 * Set Height.
 * @return The new Height.
*/

float Venom::Engine::setHeight (float Height)
{
    this->Position->setHeight (Height);
    
    return this->Position->getHeight ();
}

/*!
 * Set Height and Width.
*/

void Venom::Engine::setDimensions (float Width , float Height)
{
    this->Position->setDimensions (Width , Height);
}

/*!
 * Get Width for const Venom::Engine objects.
 * @return Width.
*/

float Venom::Engine::getWidth () const
{
    return this->Position->getWidth ();
}

/*!
 * Get Height for const Venom::Engine objects.
 * @return Height.
*/

float Venom::Engine::getHeight () const
{
    return this->Position->getHeight ();
}

/*!
 * Get Width.
 * @return Width.
*/

float Venom::Engine::getWidth ()
{
    return static_cast <const Venom::Engine&> (*this).getWidth ();
}

/*!
 * Get Height.
 * @return Height.
*/

float Venom::Engine::getHeight ()
{
    return static_cast <const Venom::Engine&> (*this).getHeight ();
}

/*!
 * Check for a collision for const Venom::Engine objects.
 * @return True for a collision false if not.
*/

bool Venom::Engine::collides (const Engine& Source) const
{
    if (this->Position->collides (*(Source.Position)))
    {
	return true;
    }
    
    return false;
}

/*!
 * Check for a collision.
 * @return True for a collision false if not.
*/

bool Venom::Engine::collides (const Engine& Source)
{
    return static_cast <const Venom::Engine&> (*this).collides (Source);
}

/*!
 * Comparison operator for Venom::Engine to check collision for const Venom::Engine objects.
 * @return True if they are colliding false if they are not.
*/

bool Venom::Engine::operator== (const Engine& Source) const
{
    if (this->collides (Source))
    {
	return true;
    }
    
    return false;
}

/*!
 * Comparison operator for Venom::Engine to check collision.
 * @return True if they are colliding false if they are not.
*/

bool Venom::Engine::operator== (const Engine& Source)
{
    if (static_cast <const Venom::Engine&> (*this) == Source)
    {
	return true;
    }
    
    return false;
}

/*!
 * Assignment operator for Venom::Engine.
 * @param Source Engine to be copied.
 * @return A reference to this.
*/

Venom::Engine& Venom::Engine::operator= (const Engine& Source)
{
    this->Position = Source.Position;
    this->SpeedX = Source.SpeedX;
    this->SpeedY = Source.SpeedY;
    
    return *this;
}
