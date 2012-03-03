#include "Point.hpp"

/*!
 * Default constructor for the Venom::Point class.
 */

Venom::Point::Point ()
    : X (0.0f) , 
      Y (0.0f)
{
}

/*!
 * Constructor for the Venom::Point class.
 * @param X X point.
 * @param Y Y point.
 */

Venom::Point::Point (float X , float Y)
    : X (X) ,
      Y (Y)
{
}

/*!
 * Copy constructor for the Venom::Point class.
 * @param Source The Point to copy.
 */

Venom::Point::Point (const Venom::Point& Source)
    : X (Source.X) , 
      Y (Source.Y)
{    
}

/*!
  Making an empty destructor.
 */

Venom::Point::~Point ()
{
    //Nothing to do :-)
}

/*!
 * Set X data member.
 * @param X The New X point.
 * @return The New X point.
 */

float Venom::Point::setX (float X)
{
    this->X = X;
    
    return this->X;
}

/*!
 * Set Y data member.
 * @param Y The New Y point.
 * @return The New Y point.
 */

float Venom::Point::setY (float Y)
{
    this->Y = Y;
    
    return this->Y;
}

/*!
 * Set X and Y data members.
 * @param X The New X point.
 * @param Y The New Y point.
 */

void Venom::Point::set (float X , float Y)
{
    this->setX (X);
    this->setY (Y);
}


/*!
 * Increase X coordinate.
 * @param X Amount to increase X by.
 * @return The New X coordinate.
 */

float Venom::Point::addX (float X)
{
    this->X += X;
    return this->X;
}

/*!
 * Increase Y coordinate.
 * @param Y The Amount to increase Y by.
 * @return The New Y coordinate.
 */

float Venom::Point::addY (float Y)
{
    this->Y += Y;
    return this->Y;
}

/*!
 * Increase X and Y coordinates.
 * @param X The Amount to increase X by.
 * @param Y The Amount to increase Y by.
 */

void Venom::Point::move (float X , float Y)
{
    this->addX (X);
    this->addY (Y);
}

/*!
 * Get X data member for constant point objects.
 * @return The X data member.
 */

float Venom::Point::getX () const
{
    return this->X;
} 


/*!
 * Get Y data member for constant point objects.
 * @return Y data member.
 */

float Venom::Point::getY () const
{
    return this->Y;
} 

/*!
 * Get X data member.
 * @return The X data member.
 */

float Venom::Point::getX ()
{
    //Using constant getX to avoid code redundancy
    return static_cast <const Venom::Point&> 
	(*this).getX ();
}

/*!
 * @brief Get Y data member.
 * @return The Y data member.
 */

float Venom::Point::getY () 
{
    //Using constant getY to avoid code redundancy
    return static_cast <const Venom::Point&> 
	(*this).getY ();
}

/*!
 * Overloading the assignment operator for the Venom::Point class.
 * @param Source The Point to be copied.
 * @return A reference to this.
 */

Venom::Point& Venom::Point::operator= (const Venom::Point& Source)
{
    this->X = Source.X;
    this->Y = Source.Y;
    
    return *this;
}

/*!
 * Overloading the comparison operator for a const Venom::Point object.
 * @param Source Point to be compared.
 * @return True is they are the same and false if they are not.
 */

bool Venom::Point::operator== (const Venom::Point& Source) const
{
    if (this->X == Source.X && 
	this->Y == Source.Y)
    {
	return true;
    }
    
    return false;
}

/*!
 * Overloading the comparison operator.
 * @param Source The Point to be compared.
 * @return True is they are the same and false if they are not.
 */

bool Venom::Point::operator== (const Venom::Point& Source)
{
    //Using constant operator to avoid code redundancy
    if (static_cast <const Venom::Point&> (*this) == Source)
    {
	return true;
    }
    
    return false;
}
