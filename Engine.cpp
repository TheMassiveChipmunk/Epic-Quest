#include "Engine.hpp"

/*
  @brief : Default constructor for Venom::Engine
*/

Venom::Engine::Engine ()
    : Position (0) , 
      SpeedX (0.0f) , 
      SpeedY (0.0f)
{
}


/*
  @brief : Copy constructor for Venom::Engine
  @Source : Engine to be copied
*/

Venom::Engine::Engine (const Engine& Source)
    : Position (Source.Position) , 
      SpeedX (Source.SpeedX) , 
      SpeedY (Source.SpeedY) 
{
}

/*
  @brief : Argument constructor for Venom::Engine
  @Source : Box position
  @SpeedX : X Speed
  @SpeedY : Y Speed
*/

Venom::Engine::Engine (Venom::Box& Position , float SpeedX , float SpeedY)
    : Position (&Position) ,
      SpeedX (SpeedX) ,
      SpeedY (SpeedY)
{
}

/*
  @brief : Default constructor for Venom::Engine
*/

Venom::Engine::~Engine ()
{
    //Nothing to do
}

/*
  @brief : Move the X coordinate
  @X : X Speed
  @return : The new X coordinate
*/

float Venom::Engine::addX (float X)
{
    this->Position->addX (X);
    
    return this->Position->getX ();
}


/*
  @brief : Move the Y coordinate
  @Y : Y Speed
  @return : The new Y coordinate
*/

float Venom::Engine::addY (float Y)
{
    this->Position->addY (Y);
    
    return this->Position->getX ();
}

/*
  @brief : Move the X and Y coordinates
  @X : X Speed
  @Y : Y Speed
*/

void Venom::Engine::move (float X , float Y)
{
    this->addX (X);
    this->addY (Y);
}

/*
  @brief : Set X coordinate
  @return : New X coordinate
*/

float Venom::Engine::setX (float X)
{
    this->Position->setX (X);
    
    return this->Position->getX ();
}


/*
  @brief : Set Y coordinate
  @return : New Y coordinate
*/

float Venom::Engine::setY (float Y)
{
    this->Position->setY (Y);
    
    return this->Position->getY ();
}

/*
  @brief : Set X and Y coordinates
  @X : New X coordinate
  @Y : New Y coordinate
*/

void Venom::Engine::set (float X , float Y)
{
    this->setX (X);
    this->setY (Y);
}


/*
  @brief : Set X and Y coordinates
  @Position : New Position 
*/

void Venom::Engine::set (const Venom::Point& Position)
{
    this->Position->set (Position);
}

/*
  @brief : Set X speed
  @SpeedX : New X speed
  @return : New X speed
*/

float Venom::Engine::setSpeedX (float SpeedX)
{
    this->SpeedX = SpeedX;
    
    return this->SpeedY;
}

/*
  @brief : Set Y speed
  @SpeedY : New Y speed
  @return : New Y speed
*/

float Venom::Engine::setSpeedY (float SpeedY)
{
    this->SpeedY = SpeedY;
    
    return this->SpeedY;
}

/*
  @brief : Set X and Y speed
  @SpeedX : New X speed
  @SpeedY : New Y speed
*/

void Venom::Engine::setSpeed (float SpeedX , float SpeedY)
{
    this->setSpeedX (SpeedX);
    this->setSpeedY (SpeedY);
}

/*
  @brief : Get speed X for const Venom::Engine objects
  @return : SpeedX
*/

float Venom::Engine::getSpeedX () const
{
    return this->SpeedX;
}

/*
  @brief : Get speed Y for const Venom::Engine objects
  @return : SpeedY
*/

float Venom::Engine::getSpeedY () const
{
    return this->SpeedY;
}


/*
  @brief : Get speed X
  @return : SpeedX
*/

float Venom::Engine::getSpeedX ()
{
    return static_cast <const Venom::Engine&> (*this).getSpeedX ();
}

/*
  @brief : Get speed Y
  @return : SpeedY
*/

float Venom::Engine::getSpeedY ()
{
    return static_cast <const Venom::Engine&> (*this).getSpeedY ();
}


/*
  @brief : Get X position for const Venom::Engine objects
  @return : X position
*/

float Venom::Engine::getX () const
{
    return this->Position->getX ();
}

/*
  @brief : Get Y position for const Venom::Engine objects
  @return : Y position
*/

float Venom::Engine::getY () const
{
    return this->Position->getY ();
}

/*
  @brief : Get position for const Venom::Engine objects
  @return : Position
*/

const Venom::Box& Venom::Engine::get () const
{
    return *(this->Position);
}

/*
  @brief : Get X position
  @return : X Position
*/

float Venom::Engine::getX ()
{
    return static_cast <const Venom::Engine&> (*this).getX ();
}


/*
  @brief : Get Y position
  @return : Y Position
*/

float Venom::Engine::getY ()
{
    return static_cast <const Venom::Engine&> (*this).getY ();
}

/*
  @brief : Get position
  @return : position
*/

const Venom::Box& Venom::Engine::get ()
{
    return static_cast <const Venom::Engine&> (*this).get ();
}

/*
  @brief : Set Width
  @return : New Width
*/

float Venom::Engine::setWidth (float Width)
{
    this->Position->setWidth (Width);
    
    return this->Position->getWidth ();
}

/*
  @brief : Set Height
  @return : New Height
*/

float Venom::Engine::setHeight (float Height)
{
    this->Position->setHeight (Height);
    
    return this->Position->getHeight ();
}

/*
  @brief : Set Height and Width
*/

void Venom::Engine::setDimensions (float Width , float Height)
{
    this->Position->setDimensions (Width , Height);
}

/*
  @brief : Get Width for const Venom::Engine objects
  @return : Width
*/

float Venom::Engine::getWidth () const
{
    return this->Position->getWidth ();
}

/*
  @brief : Get Height for const Venom::Engine objects
  @return : Height
*/

float Venom::Engine::getHeight () const
{
    return this->Position->getHeight ();
}

/*
  @brief : Get Width
  @return : Width
*/

float Venom::Engine::getWidth ()
{
    return static_cast <const Venom::Engine&> (*this).getWidth ();
}

/*
  @brief : Get Height
  @return : Height
*/

float Venom::Engine::getHeight ()
{
    return static_cast <const Venom::Engine&> (*this).getHeight ();
}

/*
  @brief : Check for a collision for const Venom::Engine objects
  @return : True for a collision false if not
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
  @brief : Check for a collision
  @return : True for a collision false if not
*/

bool Venom::Engine::collides (const Engine& Source)
{
    return static_cast <const Venom::Engine&> (*this).collides (Source);
}

/*
  @brief : Comparison operator for Venom::Engine to check collision for const Venom::Engine objects
  @return : True if they are colliding false if they are not
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
  @brief : Comparison operator for Venom::Engine to check collision
  @return : True if they are colliding false if they are not
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
  @brief : Assignment operator for Venom::Engine
  @Source : Engine to be copied
  @return : A reference to this
*/

Venom::Engine& Venom::Engine::operator= (const Engine& Source)
{
    this->Position = Source.Position;
    this->SpeedX = Source.SpeedX;
    this->SpeedY = Source.SpeedY;
    
    return *this;
}
