#include "../include/Engine.hpp"

/*
 * Default constructor for Venom::Engine.
*/
Venom::Engine::Engine ()
    : Position (0) , 
      VelX (0.0f) , 
      VelY (0.0f) ,
      SpeedX (0.0f) ,
      SpeedY (0.0f)
{
}


/*
 * Copy constructor for Venom::Engine.
 * @param Source Engine to be copied.
*/
Venom::Engine::Engine (const Engine& Source)
    : Position (Source.Position) , 
      VelX (Source.VelX) , 
      VelY (Source.VelY) ,
      SpeedX (0.0f) ,
      SpeedY (0.0f) ,
      Window (Source.Window)
{
}

/*
 * Argument constructor for Venom::Engine.
 * @param Position Box position.
 * @param VelX The X velocity.
 * @param VelY The Y velocity.
 * @param Window Window to get input from.
*/
Venom::Engine::Engine (Venom::Box& Position , float VelX , float VelY , sf::RenderWindow& Window)
    : Position (&Position) ,
      VelX (VelX) ,
      VelY (VelY) ,
      SpeedX (0.0f) ,
      SpeedY (0.0f) ,
      Window (&Window) 
{
}

/*
 * Default constructor for Venom::Engine.
*/
Venom::Engine::~Engine ()
{
    //Nothing to do
}

/*
 * Set Renderwindow.
 * @param Window Window to be copied.
 */
void Venom::Engine::setWindow (sf::RenderWindow& Window)
{
    this->Window = &Window;
}

/*
 * Move the X coordinate.
 * @param X The X velocity.
 * @return The new X coordinate.
*/
float Venom::Engine::addX (float X)
{    
    this->Position->addX (X);
    
    return this->Position->getX ();
}


/*
 * Move the Y coordinate.
 * @param Y The Y velocity.
 * @return : The new Y coordinate.
*/
float Venom::Engine::addY (float Y)
{
    this->Position->addY (Y);
    
    return this->Position->getX ();
}

/*
 * Move the X and Y coordinates.
 * @param X The X velocity.
 * @param Y The Y velocity.
*/
void Venom::Engine::add (float X , float Y)
{
    this->addX (X);
    this->addY (Y);
}

/*
 * Set X coordinate.
 * @return The new X coordinate.
*/
float Venom::Engine::setX (float X)
{
    this->Position->setX (X);
    
    return this->Position->getX ();
}


/*
 * Set Y coordinate.
 * @return The new Y coordinate.
*/
float Venom::Engine::setY (float Y)
{
    this->Position->setY (Y);
    
    return this->Position->getY ();
}

/*
 * Set X and Y coordinates.
 * @param X The new X coordinate.
 * @param Y The new Y coordinate.
*/
void Venom::Engine::set (float X , float Y)
{
    this->setX (X);
    this->setY (Y);
}


/*
 * Set X and Y coordinates.
 * @param Position The new Position. 
*/
void Venom::Engine::set (const Venom::Point& Position)
{
    this->Position->set (Position);
}

/*
 * Set X velocity.
 * @param VelX The new X velocity.
 * @return The new X velocity.
*/
float Venom::Engine::setVelX (float VelX)
{
    this->VelX = VelX;
    
    return this->VelY;
}

/*
 * Set Y velocity
 * @param VelY The new Y velocity.
 * @return The new Y velocity.
*/
float Venom::Engine::setVelY (float VelY)
{
    this->VelY = VelY;
    
    return this->VelY;
}

/*
 * Set X and Y velocity.
 * @param VelX The new X velocity.
 * @param VelY The new Y velocity.
*/
void Venom::Engine::setVel (float VelX , float VelY)
{
    this->setVelX (VelX);
    this->setVelY (VelY);
}

/*
 * Get velocity X for const Venom::Engine objects.
 * @return VelX.
*/
float Venom::Engine::getVelX () const
{
    return this->VelX;
}

/*
 * Get velocity Y for const Venom::Engine objects.
 * @return VelY.
*/
float Venom::Engine::getVelY () const
{
    return this->VelY;
}


/*
 * Get velocity X.
 * @return VelX.
*/
float Venom::Engine::getVelX ()
{
    return static_cast <const Venom::Engine&> (*this).getVelX ();
}

/*
 * Get velocity Y.
 * @return VelY.
*/
float Venom::Engine::getVelY ()
{
    return static_cast <const Venom::Engine&> (*this).getVelY ();
}


/*
 * Get X position for const Venom::Engine objects.
 * @return The X position.
*/
float Venom::Engine::getX () const
{
    return this->Position->getX ();
}

/*
 * Get Y position for const Venom::Engine objects.
 * @return The Y position.
*/
float Venom::Engine::getY () const
{
    return this->Position->getY ();
}

/*
 * Get position for const Venom::Engine objects.
 * @return Box's Position.
*/
const Venom::Box& Venom::Engine::get () const
{
    return *(this->Position);
}

/*
 * Get X coordinate.
 * @return The X coordinate.
*/
float Venom::Engine::getX ()
{
    return static_cast <const Venom::Engine&> (*this).getX ();
}


/*
 * Get Y.
 * @return The Y coordinate.
*/
float Venom::Engine::getY ()
{
    return static_cast <const Venom::Engine&> (*this).getY ();
}

/*
 * Get position.
 * @return position.
*/
const Venom::Box& Venom::Engine::get ()
{
    return static_cast <const Venom::Engine&> (*this).get ();
}

/*
 * Set Width.
 * @return The new Width.
*/
float Venom::Engine::setWidth (float Width)
{
    this->Position->setWidth (Width);
    
    return this->Position->getWidth ();
}

/*
 * Set Height.
 * @return The new Height.
*/
float Venom::Engine::setHeight (float Height)
{
    this->Position->setHeight (Height);
    
    return this->Position->getHeight ();
}

/*
 * Set Height and Width.
*/
void Venom::Engine::setDimensions (float Width , float Height)
{
    this->Position->setDimensions (Width , Height);
}

/*
 * Get Width for const Venom::Engine objects.
 * @return Width.
*/
float Venom::Engine::getWidth () const
{
    return this->Position->getWidth ();
}

/*
 * Get Height for const Venom::Engine objects.
 * @return Height.
*/
float Venom::Engine::getHeight () const
{
    return this->Position->getHeight ();
}

/*
 * Get Width.
 * @return Width.
*/
float Venom::Engine::getWidth ()
{
    return static_cast <const Venom::Engine&> (*this).getWidth ();
}

/*
 * Get Height.
 * @return Height.
*/
float Venom::Engine::getHeight ()
{
    return static_cast <const Venom::Engine&> (*this).getHeight ();
}

/*
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

/*
 * Check for a collision.
 * @return True for a collision false if not.
*/
bool Venom::Engine::collides (const Engine& Source)
{
    return static_cast <const Venom::Engine&> (*this).collides (Source);
}

/*
 * Check for a collision for const Venom::Engine objects.
 * @return True for a collision false if not.
*/
bool Venom::Engine::collides (const Venom::Box& Source) const
{
    if (this->get ().collides (Source))
    {
	return true;
    }
    
    return false;
}

/*
 * Check for a collision for Venom::Engine objects.
 * @return True for a collision false if not.
*/
bool Venom::Engine::collides (const Venom::Box& Source)
{
    return static_cast <const Venom::Engine&> (*this).collides (Source);
}

/*
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

/*
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

/*
 * Assignment operator for Venom::Engine.
 * @param Source Engine to be copied.
 * @return A reference to this.
*/
Venom::Engine& Venom::Engine::operator= (const Engine& Source)
{
    this->Position = Source.Position;
    this->VelX = Source.VelX;
    this->VelY = Source.VelY;
    this->Window = Source.Window;
    
    return *this;
}
