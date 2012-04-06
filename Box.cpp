#include "Box.hpp"

/*
 * Default constructor for the Venom::Box class.
 */
Venom::Box::Box ()
    : Width (0.0f) , 
      Height (0.0f)
{
}

/*
 * Copy constructor for the Venom::Box class. 
 * @param Source Venom::Box to be copied.
 */
Venom::Box::Box (const Box& Source)
    : Point (Source.Point) ,
      Width (Source.Width) , 
      Height (Source.Height)
{
}

/*
 * Argument constructor for the Venom::Box class.
 * @param X The X coordinate.
 * @param Y The Y coordinate.
 * @param Width The Box Width.
 * @param Height The Box Height.
*/
Venom::Box::Box (float X , float Y , float Width , float Height)
    : Point (X , Y) , 
      Width (Width) ,
      Height (Height)
{
}

/*
 * Argument constructor for the Venom::Box class.
 * @param Point The X and Y coordinates.
 * @param Width Box Width.
 * @param Height Box Height.
 */
Venom::Box::Box (const Venom::Point& Point , float Width , float Height)
    : Point (Point) ,
      Width (Width) ,
      Height (Height)
{
}

/*
 * Default constructor.
 */
Venom::Box::~Box ()
{
    //Nothing to do
}

/*
 * Set the X coordinate.
 * @param X The X coordinate.
 * @return The new X coordinate.
 */
float Venom::Box::setX (float X)
{
    return this->Point.setX (X);
}

/*
 * Set the Y coordinate.
 * @param Y The Y coordinate.
 * @return The new Y coordinate.
 */
float Venom::Box::setY (float Y)
{
    return this->Point.setY (Y);
}

/*
 * Set the X and Y coordinates.
 * @param X The X coordinate.
 * @param Y The Y coordinate.
 */
void Venom::Box::set (float X , float Y)
{
    this->Point.set (X , Y);
}

/*
 * Set the X and Y coordinates.
 * @param Source Point to be copied.
 */
void Venom::Box::set (const Venom::Point& Source)
{
    this->Point = Source;
}


/*
 * Increase X coordinate.
 * @param X Amount to increase X coordinate.
 * @return The new X coordinate.
 */
float Venom::Box::addX (float X)
{
    return this->Point.addX (X);
}

/*
 * Increase Y coordinate.
 * @param Y Amount to increase Y coordinate.
 * @return The new Y coordinate.
 */
float Venom::Box::addY (float Y)
{
    return this->Point.addY (Y);
}

/*
  @brief : Increase X and Y coordinates.
  @param X : Amount to increase X coordinate.
  @param Y : Amount to increase Y coordinate.
 */
void Venom::Box::add (float X , float Y)
{
    this->Point.add (X , Y);
}

/*
 * Set the Box Width.
 * @param Width The Box Width.
 * @return The new Box Width.
 */
float Venom::Box::setWidth (float Width)
{
    this->Width = Width;
    return this->Width;
}

/*
 * Set the Box Height.
 * @param Height The Box Height.
 * @return The new Box Height.
 */
float Venom::Box::setHeight (float Height)
{
    this->Height = Height;
    return this->Height;
}

/*
 * Set the Box Height.
 * @param Height The Box Height.
 * @return The new Box Height.
 */
void Venom::Box::setDimensions (float Width , float Height)
{
    this->setWidth (Width);
    this->setHeight (Height);
}

/*
 * Get the X coordinate for const Venom::Box objects.
 * @return The X coordinate.
 */
float Venom::Box::getX () const
{
    return this->Point.getX ();
}


/*
 * Get the Y coordinate for const Venom::Box objects.
 * @return The Y coordinate.
 */
float Venom::Box::getY () const
{
    return this->Point.getY ();
}


/*
 * Get the X coordinate.
 * @return The X coordinate.
 */
float Venom::Box::getX ()
{
    //Using constant getX to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getX ();
}

/*
 * @brief Get the Y coordinate.
 * @return The Y coordinate.
 */
float Venom::Box::getY ()
{
    //Using constant getY to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getY ();
}

/*
 * Get box point for const Venom::Box objects.
 * @return The Box point.
 */
const Venom::Point& Venom::Box::get () const
{
    return this->Point;
}

/*
 * Get the Box point.
 * @return The Box point.
 */
const Venom::Point& Venom::Box::get ()
{
    return (static_cast <const Venom::Box&> (*this)).get (); 
}

/*
 * Get the Width of the Box for const Venom::Box objects
 * @return The Box Width.
 */
float Venom::Box::getWidth () const
{
    return this->Width;
}

/*
 * Get the Height of the Box for const Venom::Box objects.
 * @return The Box Height.
 */
float Venom::Box::getHeight () const
{
    return this->Height;
}

/*
 * Get the Width of the Box. 
 * @return The Box Width.
 */
float Venom::Box::getWidth () 
{
    //Using constant getWidth to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getWidth ();
}

/*
 * Get the Height of the Box. 
 * @return The Box Height.
 */
float Venom::Box::getHeight () 
{
    //Using constant getHeight to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).getHeight ();
}

/*
 * Check if there is a collision for const Venom::Box objects.
 * @param Source The Box to check.
 * @return True if there is a collision false if there is not.
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
 * Check if there is a collision.
 * @param Source The Box to check.
 * @return True if there is a collision false if there is not.
 */
bool Venom::Box::collides (const Box& Source)
{
    //Using constant collides to avoid code redundancy
    return (static_cast <const Venom::Box&> (*this)).collides (Source);
}

/*
 * Venom::Box assignment operator.
 * @param Source Venom::Box to be copied.
 * @return A reference to this.
 */
Venom::Box& Venom::Box::operator= (const Box& Source)
{
    this->Point = Source.Point;
    this->Width = Source.Width;
    this->Height = Source.Height;
    
    return *this;
}

/*
 * Venom::Box comparison operator for a const Venom::Box object.
 * @param Source Venom::Box to be copied.
 * @return True if they are equal false if they are not.
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
 * Venom::Box comparison operator.
 * @param Source Venom::Box to be copied.
 * @return True if they are equal false if they are not.
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
