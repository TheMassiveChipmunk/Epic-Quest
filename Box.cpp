#include "Box.hpp"

/*
  @brief : Default constructor for the Venom::Box class
 */

Venom::Box::Box ()
    : Width (0.0f) , 
      Height (0.0f)
{
}

/*
  @brief : Copy constructor for the Venom::Box class 
  @Source : Venom::Box to be copied
 */

Venom::Box::Box (const Box& Source)
    : Point (Source.Point) ,
      Width (Source.Width) , 
      Height (Source.Height)
{
}

/*
  @brief : Argument constructor for the Venom::Box class
  @X : X coordinate
  @Y : Y coordinate
  @Width : Box Width
  @Height : Box Height
*/

Venom::Box::Box (float X , float Y , float Width , float Height)
    : Point (X , Y) , 
      Width (Width) ,
      Height (Height)
{
}

/*
  @brief : Argument constructor for the Venom::Box class
  @Point : X and Y coordinate
  @Width : Box Width
  @Height : Box Height
 */

Venom::Box::Box (const Venom::Point& Point , float Width , float Height)
    : Point (Point) ,
      Width (Width) ,
      Height (Height)
{
}

/*
  @brief : Destructor constructor
 */

Venom::Box::~Box ()
{
    //Nothing to do
}

/*
  @brief : Set the X coordinate
  @X : X coordinate
  @Return : The new X coordinate
 */

float Venom::Box::setX (float X)
{
    return this->Point.setX (X);
}

/*
  @brief : Set the Y coordinate
  @Y : Y coordinate
  @Return : The new Y coordinate
 */

float Venom::Box::setY (float Y)
{
    return this->Point.setY (Y);
}

/*
  @brief : Set the X and Y coordinates
  @X : X coordinate
  @Y : Y coordinate
 */

void Venom::Box::set (float X , float Y)
{
    this->Point.set (X , Y);
}

/*
  @brief : Set the X and Y coordinates
  @Source : Point to be copied 
 */

void Venom::Box::set (const Venom::Point& Source)
{
    this->Point = Source;
}


/*
  @brief : Increase X coordinate
  @X : Amount to increase X coordinate
  @Return : New X coordinate
 */

float Venom::Box::addX (float X)
{
    return this->Point.addX (X);
}

/*
  @brief : Increase Y coordinate
  @Y : Amount to increase Y coordinate
  @Return : New Y coordinate
 */

float Venom::Box::addY (float Y)
{
    return this->Point.addY (Y);
}

/*
  @brief : Increase X and Y coordinates
  @X : Amount to increase X coordinate
  @Y : Amount to increase Y coordinate
 */

void Venom::Box::move (float X , float Y)
{
    this->Point.move (X , Y);
}

/*
  @brief : Set the Box Width
  @Width : Box Width
  @Return : The new Box Width
 */

float Venom::Box::setWidth (float Width)
{
    this->Width = Width;
    return this->Width;
}

/*
  @brief : Set the Box Height
  @Height : Box Height
  @Return : The new Box Height
 */

float Venom::Box::setHeight (float Height)
{
    this->Height = Height;
    return this->Height;
}

/*
  @brief : Set the Box Height
  @Height : Box Height
  @Return : The new Box Height
 */

void Venom::Box::setDimensions (float Width , float Height)
{
    this->setWidth (Width);
    this->setHeight (Height);
}

/*
  @brief : Get the X coordinate for const Venom::Box objects
  @Return : X coordinate
 */

float Venom::Box::getX () const
{
    return this->Point.getX ();
}


/*
  @brief : Get the Y coordinate for const Venom::Box objects
  @Return : Y coordinate
 */

float Venom::Box::getY () const
{
    return this->Point.getY ();
}


/*
  @brief : Get the X coordinate
  @Return : X coordinate
 */

float Venom::Box::getX ()
{
    //Using constant getX to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getX ();
}

/*
  @brief : Get the Y coordinate
  @Return : Y coordinate
 */

float Venom::Box::getY ()
{
    //Using constant getY to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getY ();
}

/*
  @brief : Get box point for const Venom::Box objects
  @Return : Box point
 */

const Venom::Point& Venom::Box::getPoint () const
{
    return this->Point;
}

/*
  @brief : Get box point
  @Return : Box point
 */

const Venom::Point& Venom::Box::getPoint ()
{
    return (static_cast <const Venom::Box&> (*this)).getPoint (); 
}

/*
  @brief : Get the Width of the Box for const Venom::Box objects
  @Return : Box Width
 */

float Venom::Box::getWidth () const
{
    return this->Width;
}

/*
  @brief : Get the Height of the Box for const Venom::Box objects
  @Return : Box Height
 */

float Venom::Box::getHeight () const
{
    return this->Height;
}

/*
  @brief : Get the Width of the Box 
  @Return : Box Width
 */

float Venom::Box::getWidth () 
{
    //Using constant getWidth to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getWidth ();
}

/*
  @brief : Get the Height of the Box 
  @Return : Box Height
 */

float Venom::Box::getHeight () 
{
    //Using constant getHeight to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getHeight ();
}

/*
  @brief : Check if there is a collision for const Venom::Box objects
  @Source : Box to check
  @Return : True if there is a collision false if there is not
 */

bool Venom::Box::collides (const Box& Source) const
{
    if (this->getX () < Source.getX () + Source.Width && 
	this->getX () + this->Width >  Source.getX () && 
        this->getY () < Source.getY () + Source.Height && 
	this->getY () + this->Height > Source.getY ())
    {
	return true;
    }
    else
    {
	return false;
    }
}

/*
  @brief : Check if there is a collision
  @Source : Box to check
  @Return : True if there is a collision false if there is not
 */

bool Venom::Box::collides (const Box& Source)
{
    //Using constant collides to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).collides (Source);
}

/*
  @brief : Venom::Box assignment operator
  @Source : Venom::Box to be copied
  @Return : A reference to this
 */

Venom::Box& Venom::Box::operator= (const Box& Source)
{
    this->Point = Source.Point;
    this->Width = Source.Width;
    this->Height = Source.Height;
    
    return *this;
}

/*
  @brief : Venom::Box comparison operator for a const Venom::Box object
  @Source : Venom::Box to be copied
  @Return : True if they are equal false if they are not
 */

bool Venom::Box::operator== (const Box& Source) const
{
    if (this->Point == Source.Point &&
	this->Width == Source.Width &&
	this->Height == Source.Height)
    {
	return true;
    }
    
    return false;
}

/*
  @brief : Venom::Box comparison operator
  @Source : Venom::Box to be copied
  @Return : True if they are equal false if they are not
 */

bool Venom::Box::operator== (const Box& Source)
{
    //Using constant comparison operator to avoid code redundancy
    if (static_cast <const Venom::Box&> (*this) == Source)
    {
	return true;
    }
    
    return false;
}
