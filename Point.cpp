#include "Point.hpp"

/*
  @brief : Default constructor for the Venom::Point class
 */

Venom::Point::Point ()
    : X (0.0f) , 
      Y (0.0f)
{
}

/*
  @brief : Constructor for the Venom::Point class
  @X : X point
  @Y : Y point
 */

Venom::Point::Point (float X , float Y)
    : X (X) ,
      Y (Y)
{
}

/*
  @brief : Copy constructor for the Venom::Point class
  @Source : Point to copy
 */

Venom::Point::Point (const Venom::Point& Source)
    : X (Source.X) , 
      Y (Source.Y)
{    
}

/*
  @brief : Making an empty destructor
 */

Venom::Point::~Point ()
{
    //Nothing to do :-)
}

/*
  @brief : Set X data member
  @X : New X point
  @Return : New X point
 */

float Venom::Point::setX (float X)
{
    this->X = X;
    
    return this->X;
}

/*
  @brief : Set Y data member
  @Y : New Y point
  @Return : New Y point
 */

float Venom::Point::setY (float Y)
{
    this->Y = Y;
    
    return this->Y;
}

/*
  @brief : Set X and Y data members
  @X : New X point
  @Y : New Y point
 */

void Venom::Point::set (float X , float Y)
{
    this->setX (X);
    this->setY (Y);
}


/*
  @brief : Increase X coordinate
  @X : Amount to increase X by
  @Return : New X coordinate
 */

float Venom::Point::addX (float X)
{
    this->X += X;
    return this->X;
}

/*
  @brief : Increase Y coordinate
  @Y : Amount to increase Y by
  @Return : New Y coordinate
 */

float Venom::Point::addY (float Y)
{
    this->Y += Y;
    return this->Y;
}

/*
  @brief : Increase X and Y coordinates
  @X : Amount to increase X by
  @Y : Amount to increase Y by
 */

void Venom::Point::move (float X , float Y)
{
    this->addX (X);
    this->addY (Y);
}

/*
  @brief : Get X data member for constant point objects
  @Return : X data member
 */

float Venom::Point::getX () const
{
    return this->X;
} 


/*
  @brief : Get Y data member for constant point objects
  @Return : Y data member
 */

float Venom::Point::getY () const
{
    return this->Y;
} 

/*
  @brief : Get X data member
  @Return : X data member
 */

float Venom::Point::getX ()
{
    //Using constant getX to avoid code redundancy
    return static_cast <const Venom::Point&> 
	(*this).getX ();
}

/*
  @brief : Get Y data member
  @Return : Y data member
 */

float Venom::Point::getY () 
{
    //Using constant getY to avoid code redundancy
    return static_cast <const Venom::Point&> 
	(*this).getY ();
}

/*
  @brief : Overloading the assignment operator for the Venom::Point class
  @Source : Point to be copied
  @Return : A reference to this
 */

Venom::Point& Venom::Point::operator= (const Venom::Point& Source)
{
    this->X = Source.X;
    this->Y = Source.Y;
    
    return *this;
}

/*
  @brief : Overloading the comparison operator for a const Venom::Point object
  @Source : Point to be compared
  @Return : True is they are the same and false if they are not
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

/*
  @brief : Overloading the comparison operator 
  @Source : Point to be compared
  @Return : True is they are the same and false if they are not
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
