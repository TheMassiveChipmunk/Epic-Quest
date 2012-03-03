#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "Venom.hpp"
#include "Point.hpp"
#include "Box.hpp"

namespace Venom
{
    /*!
     * Engine base class.
     */
    class Engine
    {	
	/* A pointer to the current position. */
	Venom::Box* Position;
	
	/* X speed. */
	float SpeedX;
	
	/* Y speed. */
	float SpeedY;
    public:
	/*! 
	 * Default constructor for the Venom::Engine class. 
	 */
	Engine ();
	
	/*!
	 * Copy constructor for the Venom::Engine class.
	 * @param Source Venom::Engine to copy.
	 */
	Engine (const Engine& Source);
	
	/*! 
	 * Argument constructor for the Venom::Engine class. 
	 * @param Position A reference to a Venom::Box object.
	 * @param SpeedX The speed to increment the X axis.
	 * @param SpeedY The speed to increment the Y axis.
	 */
	Engine (Venom::Box& Position , float SpeedX , float SpeedY);

	/*! 
	 *  Virtual Destructor (For memory reasons). 
	 */
	virtual ~Engine ();

	/*! 
	 * Add X to the X coordinate of the object.
	 * @param X Amount to increment the X axis.
	 * @return Returns the new X coordinate of the object. 
	 */
	virtual float addX (float X);

	/*! 
	 * Add Y to the Y coordinate of the object.
	 * @param Y Amount to increment the Y axis. 
	 * @return Returns the new Y coordinate of the object. 
	 */
	virtual float addY (float Y);
	
	/*!
	 * Add X and Y to the current position of the object. 
	 * @param X Amount to increment the X axis.
	 * @param Y Amount to increment the Y axis. 
	 */
	virtual void move (float X , float Y);

	/*!
	 * Set the X coordinate of the object.
	 * @param X New X coordinate.
	 * @return Returns the new X position. 
	 */
	virtual float setX (float X);
	
	/*! 
	 * Set the Y coordinate of the object.
	 * @param Y New Y coordinate.
	 * @return Returns the new Y position. 
	 */
	virtual float setY (float Y);
	
	/*! 
	 * Set the X and Y coordinates of the object. 
	 * @param X New X coordinate.
	 * @param Y New Y coordinate.
	 */
	virtual void set (float X , float Y);
	
	/*! 
	 * Set the X and Y coordinates of the object. 
	 * @param Position Venom::Point to copy.
	 */
	virtual void set (const Venom::Point& Position);
	
	/*! 
	 * Set the X speed of the object.
	 * @param SpeedX New X speed.
	 * @return Returns the new X speed. 
	 */
	virtual float setSpeedX (float SpeedX);
	
	/*! 
	 * Set the Y speed of the object.
	 * @param SpeedY New Y speed.
	 * @return Returns the new Y speed. 
	 */
	virtual float setSpeedY (float SpeedY);
	
	/*! 
	 * Set the X and Y speeds of the object. 
	 * @param SpeedX New X speed.
	 * @param SpeedY New Y speed.
	 */
	virtual void setSpeed (float SpeedX , float SpeedY);
	
	/*!
	 * Gets the current X speed.
	 * @return X speed.
	 */
	virtual float getSpeedX ();
	
	/*!
	 * Gets the current Y speed.
	 * @return Y speed.
	 */
	virtual float getSpeedY ();
	
	/*!
	 * Gets the current X speed for const Venom::Engine objects.
	 * @return X speed.
	 */
	virtual float getSpeedX () const;
	
	/*!
	 * Gets the current Y speed for const Venom::Engine objects.
	 * @return Y speed.
	 */
	virtual float getSpeedY () const;
	
	/*!
	 * Gets the current X coordinate.
	 * @return X coordinate.
	 */
	virtual float getX ();
	
	/*!
	 * Gets the current Y coordinate.
	 * @return Y coordinate.
	 */
	virtual float getY ();

	/*!
	 * Gets the current X coordinate for const Venom::Engine objects.
	 * @return X coordinate.
	 */
	virtual float getX () const;
	
	/*!
	 * Gets the current Y coordinate for const Venom::Engine objects.
	 * @return Y coordinate.
	 */
	virtual float getY () const;
	
	/*!
	 * Gets the Venom::Engine's Venom::Box.
	 * @return Venom::Engine box.
	 */
	virtual const Venom::Box& get ();
	
	/*!
	 * Gets the Venom::Engine's Venom::Box for const Venom::Engine objects.
	 * @return Venom::Engine box.
	 */
	virtual const Venom::Box& get () const;
	
	/*!
	 * Sets the width of the box.
	 * @param Width New box width.
	 * @return The new box width.
	 */
	virtual float setWidth (float Width);

	/*!
	 * Sets the height of the box.
	 * @param Height New box height.
	 * @return The new box height.
	 */
	virtual float setHeight (float Height);
	
	/*!
	 * Sets both width and height of the box.
	 * @param Width New box width.
	 * @param Height New box height.
	 */
	virtual void setDimensions (float Width , float Height);
	
	/*!
	 * Gets the current box width.
	 * @return Box width.
	 */
	virtual float getWidth ();

	/*!
	 * Gets the current box height.
	 * @return Box height.
	 */
	virtual float getHeight ();

	/*!
	 * Gets the current box height for const Venom::Engine objects.
	 * @return Box height.
	 */	
	virtual float getWidth () const;

	/*!
	 * Gets the current box height for const Venom::Engine objects.
	 * @return Box height.
	 */
	virtual float getHeight () const;
	
	/*!
	 * Checks for collision with another Venom::Engine.
	 * @param Source Venom::Engine to check collision against.
	 * @return True on collision otherwise false.
	 */
	virtual bool collides (const Engine& Source);
	
	/*!
	 * Checks for collision with another Venom::Engine for const Venom::Engine objects.
	 * @param Source Venom::Engine to check collision against.
	 * @return True on collision otherwise false.
	 */
	virtual bool collides (const Engine& Source) const;
	
	/*!
	 * Checks if there is a collision between the two points.
	 * @param Source Venom::Engine to check collision against.
	 * @return True on collision otherwise false.
	 */
	bool operator== (const Engine& Source);
	
	/*!
	 * Checks if there is a collision between the two points for const Venom::Engine objects.
	 * @param Source Venom::Engine to check collision against.
	 * @return True on collision otherwise false.
	 */
	bool operator== (const Engine& Source) const;
	
	/*!
	 * Copies two Venom::Engine objects.
	 * @param Source Venom::Engine to be copied.
	 * @return A reference to this.
	 */
	Venom::Engine& operator= (const Engine& Source);
    };
}

#endif /* _ENGINE_HPP_ */
