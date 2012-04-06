#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "Util.hpp"
#include "Point.hpp"
#include "Box.hpp"

#include <SFML/Graphics.hpp>

namespace Venom
{
    /*!
     * Engine base class.
     */
    class Engine
    {
    protected:
	/*! A pointer to the current position. */
	Venom::Box* Position;
	
	/*! X velocity. */
	float VelX;
	
	/*! Y velocity. */
	float VelY;

	/*! X Speed. */
	float SpeedX;
	
	/*! Y Speed. */
	float SpeedY;
	
	/*! A pointer to the window to get input from. */
	sf::RenderWindow* Window;
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
	 * @param VelX The velocity to increment the X axis.
	 * @param VelY The velocity to increment the Y axis.
	 * @param Window The Window to get input from.
	 */
	Engine (Venom::Box& Position , float VelX , float VelY , sf::RenderWindow& Window);

	/*! 
	 *  Virtual Destructor (For memory reasons). 
	 */
	virtual ~Engine ();

	/*!
	 * Set the Renderwindow.
	 * @param Window Window to be copied.
	 */
	virtual void setWindow (sf::RenderWindow& Window);
	
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
	virtual void add (float X , float Y);

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
	 * Set the X velocity of the object.
	 * @param VelX New X velocity.
	 * @return Returns the new X velocity. 
	 */
	virtual float setVelX (float VelX);
	
	/*! 
	 * Set the Y velocity of the object.
	 * @param VelY New Y velocity.
	 * @return Returns the new Y velocity. 
	 */
	virtual float setVelY (float VelY);
	
	/*! 
	 * Set the X and Y velocitys of the object. 
	 * @param VelX New X velocity.
	 * @param VelY New Y velocity.
	 */
	virtual void setVel (float VelX , float VelY);
	
	/*!
	 * Gets the current X velocity.
	 * @return X velocity.
	 */
	virtual float getVelX ();
	
	/*!
	 * Gets the current Y velocity.
	 * @return Y velocity.
	 */
	virtual float getVelY ();
	
	/*!
	 * Gets the current X velocity for const Venom::Engine objects.
	 * @return X velocity.
	 */
	virtual float getVelX () const;
	
	/*!
	 * Gets the current Y velocity for const Venom::Engine objects.
	 * @return Y velocity.
	 */
	virtual float getVelY () const;
	
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
	 * Checks for collision with another Venom::Box.
	 * @param Source Venom::Box to check collision against.
	 * @return True on collision otherwise false.
	 */
	virtual bool collides (const Venom::Box& Source);

	/*!
	 * Checks for collision with another Venom::Box.
	 * @param Source Venom::Box to check collision against.
	 * @return True on collision otherwise false.
	 */
	virtual bool collides (const Venom::Box& Source) const;

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
	
	/*!
	 * Handles all input.
	 */
	virtual void handleInput () = 0;
    
	/*!
	 * Updates all movement, input, and physics.
	 */
	virtual void update () = 0;

	/*!
	 * Attacks with a weapon
	 */
	virtual void attack () = 0;
    };
}

#endif /* _ENGINE_HPP_ */
